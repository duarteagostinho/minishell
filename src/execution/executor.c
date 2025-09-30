/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:49:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/25 23:31:23 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void  wait_cmds(t_shell *shell)
{
	t_cmd *cmd;

	cmd = shell->cmd;
	while (cmd)
	{
		waitpid(cmd->pid, &shell->exit_status, 0);
		cmd = cmd->next;
	}
	shell->exit_status = (shell->exit_status >> 8) & 0xFF;
}

static int	close_fd(int new_fd, int old_fd)
{
	close(old_fd);
	return (new_fd);
}

static void	exec_cmd(t_cmd *cmd, int in, int out, int is_single)
{
	if (!is_single)
		cmd->pid = fork();
	if (cmd->pid == 0)
	{
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		close(in);
		close(out);
		if (!is_single)
			signal_setup(shell(), CHILD);
		if (exec_builtin(shell(), cmd) < 0)
		{
			execve(cmd->args[0], cmd->args, shell()->env);
			cmd_error(cmd->args[0]);
			ft_exit(shell());
		}
		if (is_single)
			return ;
		ft_exit(shell());
	}
	close(in);
	close(out);
}

void  executor(t_shell *shell, int in, int out)
{
	t_cmd	*cmd;

	in = dup(STDIN_FILENO);
	cmd = shell->cmd;
	while (cmd)
	{
		out = dup(STDOUT_FILENO);
		if (cmd->next)
		{
			pipe(cmd->pipes);
			out = close_fd(cmd->pipes[1], out);
		}
		// if (cmd->redirect_out)
		// 	out = close_fd(cmd->redirect_out, out);
		// if (cmd->redirect_in)
		// 	in = close_fd(cmd->redirect_in, in);
		exec_cmd(cmd, in, out, (!shell->cmd->next && is_builtin(cmd->args[0])));
		in = close_fd(cmd->pipes[0], in);
		cmd = cmd->next;
	}
	wait_cmds(shell);
}
