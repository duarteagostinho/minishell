/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:49:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/30 14:41:35 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	int	pid;

	pid = -1;
	if (!shell->in_child)
	{
		if (exec_command(shell, shell->cmd) < 0)
			pid = fork();
		if (pid == 0)
		{
			signal_setup(shell, CHILD);
			if (shell->cmd->redirect)
				apply_redirections(shell);
			exec_external(shell, shell->cmd);
			ft_exit(shell);
		}
		else if (pid > 0)
		{
			signal_setup(shell, IGNORE);
			waitpid(pid, &shell->exit_status, 0);
			signal_setup(shell, PARENT);
		}
		return ;
	}
	if (shell->cmd->redirect && !shell->in_child)
		apply_redirections(shell);
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
			shell->in_child = 1;
			if (get_cmd(shell->cmd, i)->redirect)
			{
				t_cmd *temp = shell->cmd;
				shell->cmd = get_cmd(shell->cmd, i);
				apply_redirections(shell);
				shell->cmd = temp;
			}
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
		waitpid(get_cmd(shell->cmd, i)->pid, &shell->exit_status, 0);
	signal_setup(shell, PARENT);
}

void  executor(t_shell *shell)
{
	int	cmd_size;
	int	i;
	t_cmd *current_cmd;
	
	cmd_size = commands_size(shell->cmd);
	i = 0;
	current_cmd = shell->cmd;
	while (i < cmd_size && current_cmd)
	{
		if (current_cmd->redirect)
		{
			t_cmd *temp = shell->cmd;
			shell->cmd = current_cmd;
			load_redirections(shell);
			shell->cmd = temp;
		}
		current_cmd = current_cmd->next;
		i++;
	}
	if (cmd_size == 1)
		exec_single(shell, get_cmd(shell->cmd, 0));
	else if (cmd_size > 1)
		exec_pipes(shell, cmd_size, -1);
	signal_setup(shell, PARENT);
	shell->exit_status = (shell->exit_status >> 8) & 0xFF;
}
