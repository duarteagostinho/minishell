/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:49:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/02 13:39:39 by duandrad         ###   ########.fr       */
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
	int	fds;
	t_shell temp_shell;

	fds = 2;
	if (!is_single)
		cmd->pid = fork();
	if (cmd->pid == 0)
	{
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		close(in);
		close(out);
		if (cmd->pipes[0] > 2 && cmd->pipes[0] != in && cmd->pipes[0] != out)
			close(cmd->pipes[0]);
		if (cmd->pipes[1] > 2 && cmd->pipes[1] != in && cmd->pipes[1] != out)
			close(cmd->pipes[1]);
		if (cmd->redirect)
		{
			temp_shell = *shell();
			temp_shell.cmd = cmd;
			apply_redirections(&temp_shell);
		}
		if (!is_single)
			signal_setup(shell(), CHILD);
		if (exec_builtin(shell(), cmd) < 0)
		{
			while (++fds < FOPEN_MAX)
				close(fds);
			execve(cmd->args[0], cmd->args, shell()->env);
			cmd_error(cmd->args[0]);
			ft_exit(shell());
		}
		if (is_single)
			return ;
		ft_exit(shell());
	}
}

void  executor(t_shell *shell, int in, int out)
{
	t_cmd	*cmd;

	in = dup(STDIN_FILENO);
	cmd = shell->cmd;
	while (cmd)
	{
		out = dup(STDOUT_FILENO);
		shell->cmd = cmd;
		load_redirections(shell);
		if (cmd->next)
			pipe(cmd->pipes);
		if (cmd->redirect_out)
		 	out = close_fd(cmd->redirect_out, out);
		else if (cmd->next)
			out = close_fd(cmd->pipes[1], out);
		if (cmd->redirect_in)
		 	in = close_fd(cmd->redirect_in, in);
		if (cmd->args && cmd->args[0])
			exec_cmd(cmd, in, out, (!shell->cmd->next && is_builtin(cmd->args[0])));
		close(out);
		if (cmd->next)
		{
			close(in);
			in = cmd->pipes[0];
		}
		cmd = cmd->next;
	}
	close(in);
	wait_cmds(shell);
}
