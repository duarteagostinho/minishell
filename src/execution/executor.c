/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:49:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 19:47:38 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wait_cmds(t_shell *shell)
{
	t_cmd	*cmd;

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

int	close_fd(int new_fd, int old_fd)
{
	struct stat	fd_info;

	if (fstat(old_fd, &fd_info) == 0)
		close(old_fd);
	return (new_fd);
}

void	close_or_save(int in, int out, int check)
{
	struct stat	fd_info;

	if (check == 1)
	{
		shell()->cmd->pipes[0] = dup(STDIN_FILENO);
		shell()->cmd->pipes[1] = dup(STDOUT_FILENO);
		return ;
	}
	if (fstat(in, &fd_info) == 0)
		close(in);
	if (fstat(out, &fd_info) == 0)
		close(out);
	if (check == 2)
	{
		dup2(shell()->cmd->pipes[0], STDIN_FILENO);
		dup2(shell()->cmd->pipes[1], STDOUT_FILENO);
		(close(shell()->cmd->pipes[0]), close(shell()->cmd->pipes[1]));
	}
}

static void	exec_cmd(t_cmd *cmd, int in, int out, int is_single)
{
	if (!cmd->args)
		return (close_or_save(in, out, 0));
	if (!is_single || !is_builtin(cmd->args[0]))
		cmd->pid = fork();
	if (cmd->pid == 0)
	{
		if (!cmd->next && is_builtin(cmd->args[0]))
			close_or_save(in, out, 1);
		if (!is_builtin(cmd->args[0]) || !is_single)
			signal_setup(shell(), CHILD);
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		if (exec_builtin(shell(), cmd, out) < 0)
		{
			destroy_fds();
			execve(cmd->args[0], cmd->args, shell()->env);
			cmd_error(cmd->args[0], cmd->args[0], 3);
			ft_exit(shell(), cmd);
		}
		if (is_builtin(cmd->args[0]) && is_single)
			return (close_or_save(in, out, 2));
		close_or_save(in, out, 0);
		ft_exit(shell(), cmd);
	}
	close_or_save(in, out, 0);
}

void	executor(t_shell *shell, int in, int out)
{
	t_cmd	*cmd;

	cmd = shell->cmd;
	in = dup(STDIN_FILENO);
	while (cmd)
	{
		out = dup(STDOUT_FILENO);
		apply_redirections(cmd);
		if (cmd->redirect_in || cmd->redirect_out)
			set_io(cmd, &in, &out);
		if (cmd->next && !cmd->redirect_out)
		{
			if (pipe(cmd->pipes) < 0)
				return ;
			out = close_fd(cmd->pipes[1], out);
		}
		if (!cmd->skip_exec)
			exec_cmd(cmd, in, out, (!shell->cmd->next));
		else
			close_or_save(in, out, 0);
		if (cmd->next && !cmd->redirect_out)
			in = close_fd(cmd->pipes[0], in);
		cmd = cmd->next;
	}
	wait_cmds(shell);
}
