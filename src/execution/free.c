/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:50:41 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/08 02:47:31 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

void free_vtr(t_vtr args)
{
	int	i;

	i = -1;
	if (!args)
		return ;
	while (args[++i])
		free(args[i]);
	free(args);
}

void  free_list(void *list, t_lst type)
{
	if (list && type == REDIRECT)
	{
		t_rdir	*current;
		t_rdir	*next;

		current = (t_rdir *)list;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
	else if (list && type == COMMAND)
	{
		t_cmd	*current;
		t_cmd	*next;

		current = (t_cmd *)list;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
}

void  free_shell(t_shell *shell)
{
	if (shell)
	{
		if (shell->cmd->args)
			free_vtr(shell->cmd->args);
		if (shell->cmd->redirect)
			free_list(shell->cmd->redirect, REDIRECT);
		if (shell->cmd)
			free_list(shell->cmd, COMMAND);
		if (shell->env)
			free_vtr(shell->env);
		if (shell->exports)
			free_vtr(shell->exports);
		free(shell);
	}
}
