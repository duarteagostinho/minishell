/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:49:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/08 02:24:38 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

// void  close_redirects(t_rdir *redirect)
// {
//
// }

void  handle_single(t_shell *shell)
{
	t_func	builtin;
	t_str	ext_path;
	pid_t	pid;

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
