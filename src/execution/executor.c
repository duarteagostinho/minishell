/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:49:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/02 14:16:54 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wait_cmds(t_shell *shell)
{
	t_cmd *cmd;
	cmd = shell->cmd;
	signal_setup(shell, IGNORE);
	while (cmd)
	{
		if (cmd->pid)
		{
			waitpid(cmd->pid, &shell->exit_status, 0);
			if (WIFSIGNALED(shell->exit_status))
			{
				if (WTERMSIG(shell->exit_status) == SIGINT)
					shell->exit_status = 130;
				else if (WTERMSIG(shell->exit_status) == SIGQUIT)
					shell->exit_status = 131;
			}
			else if (WIFEXITED(shell->exit_status))
				shell->exit_status = WEXITSTATUS(shell->exit_status);
		}
		cmd = cmd->next;
	}
	signal_setup(shell, PARENT);
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
		if (!is_single)
			signal_setup(shell(), CHILD);
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		close(in);
		close(out);
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
	signal_setup(shell(), PARENT);
	close(in);
	close(out);
}
void	executor(t_shell *shell, int in, int out)
{
	t_cmd	*cmd;
	load_redirections(shell);
	in = dup(STDIN_FILENO);
	cmd = shell->cmd;
	while (cmd)
	{
		out = dup(STDOUT_FILENO);
		apply_redirections(shell);
		if (cmd->redirect_out)
			out = cmd->redirect_out;
		if (cmd->redirect_in)
			in = cmd->redirect_in;
		if (cmd->next && !cmd->redirect_out)
		{
			pipe(cmd->pipes);
			out = close_fd(cmd->pipes[1], out);
		}
		exec_cmd(cmd, in, out, (!shell->cmd->next && is_builtin(cmd->args[0])));
		if (cmd->next && !cmd->redirect_out)
			in = close_fd(cmd->pipes[0], in);
		cmd = cmd->next;
	}
	wait_cmds(shell);
}
