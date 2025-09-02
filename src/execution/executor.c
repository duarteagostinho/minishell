/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:49:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/02 17:00:00 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_external(t_shell *shell)
{
	pid_t	pid;
	t_str	ext_path;

	pid = fork();
	ext_path = is_external(shell);
	if (pid == 0)
	{
		
		execve(ext_path, shell->cmd->args, shell->env);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
		restore_redirections(shell);
	}
}

void  execute_cmd(t_shell *shell)
{
	t_func	builtin;
	t_str	ext_path;

	setup_redirection(shell);
	if (shell->cmd->redirect)
		exec_redirections(shell);
	builtin = is_builtin(shell->cmd->args[0]);
	if (builtin)
	{
		builtin(shell);
		restore_redirections(shell);
	}
	else
	{
		ext_path = is_external(shell);
		if (ext_path)
			exec_external(shell);
	}
}

void  executor(t_shell *shell)
{
	if (shell->cmd)
		execute_cmd(shell);
}
