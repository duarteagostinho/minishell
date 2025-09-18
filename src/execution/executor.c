/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:49:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/18 17:12:17 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

static t_cmd	*get_cmd(t_cmd *cmd, int n)
{
	t_cmd	*curr;

	curr = cmd;
	while (curr && n--)
		curr = curr->next;
	return (curr);
}

static void	close_pipes(t_shell *shell, int n)
{
	while (--n >= 0)
	{
		close(get_cmd(shell->cmd, n)->pipes[0]);
		close(get_cmd(shell->cmd, n)->pipes[1]);
	}
}

static void  exec_single(t_shell *shell, t_cmd *cmd)
{
	if (!shell->in_child)
	{
		if (exec_command(shell, shell->cmd) < 0)
			shell->cmd->pid = fork();
		if (shell->cmd->pid == 0)
		{
			signal_setup(shell, CHILD);
			exec_external(shell, shell->cmd);
			ft_exit(shell);
		}
		else if (shell->cmd->pid > 0)
		{
			signal_setup(shell, IGNORE);
			waitpid(shell->cmd->pid, NULL, 0);
			signal_setup(shell, PARENT);
		}
		return ;
	}
	if (exec_command(shell, cmd) < 0)
		exec_external(shell, cmd);
	ft_exit(shell);
}

static void	exec_pipes(t_shell *shell, int size, int i)
{
	while (++i < size)
	{
		if (i < size - 1 && pipe(get_cmd(shell->cmd, i)->pipes) == -1)
			exit(EXIT_FAILURE);
		get_cmd(shell->cmd, i)->pid = fork();
		if (get_cmd(shell->cmd, i)->pid < 0)
			exit(EXIT_FAILURE);
		if (get_cmd(shell->cmd, i)->pid == 0)
		{
			signal_setup(shell, CHILD);
			if (i == 0 || (i > 0 && i < size - 1))
				dup2(get_cmd(shell->cmd, i)->pipes[1], STDOUT_FILENO);
			if (i == size - 1 || (i > 0 && i < size - 1))
				dup2(get_cmd(shell->cmd, i - 1)->pipes[0], STDIN_FILENO);
			close_pipes(shell, size - 1);
			exec_single(shell, get_cmd(shell->cmd, i));
		}
	}
	close_pipes(shell, size - 1);
	signal_setup(shell, IGNORE);
	i = -1;
	while (++i < size)
			waitpid(get_cmd(shell->cmd, i)->pid, NULL, 0);
	signal_setup(shell, PARENT);
}

void  executor(t_shell *shell)
{
	int	cmd_size;

	cmd_size = commands_size(shell->cmd);
	if (cmd_size == 1)
		exec_single(shell, get_cmd(shell->cmd, 0));
	else if (cmd_size > 1)
		exec_pipes(shell, cmd_size, -1);
}
