/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:49:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/27 11:56:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void  close_redirects(t_rdir *redirect)
// {
//
// }

void  handle_single(t_shell *shell)
{
	t_func	builtin;
	t_str	ext_path;
	pid_t	pid;

	pid = -1;
	builtin = is_builtin(shell->cmd->args[0]);
	if (builtin && builtin(shell) == EXIT_SUCCESS)
		return ;
	ext_path = is_external(shell);
	if (ext_path)
		pid = fork();
	if (pid == 0)
		execve(ext_path, shell->cmd->args, shell->env);
	else if (pid > 0)
		wait(NULL);
}

void  executor(t_shell *shell)
{
	if (shell->cmd && !shell->cmd->next)
		handle_single(shell);
}
