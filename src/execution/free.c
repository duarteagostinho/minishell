/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:50:41 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/25 16:31:47 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_vtr(t_vtr args, int size)
{
	int	i;

	i = -1;
	if (!args)
		return ;
	while (++i < size)
		free(args[i]);
	free(args);
}

void  free_cmds(t_cmd *commands)
{
	t_cmd	*curr;
	t_cmd	*next;

	curr = commands;
	while (curr)
	{
		next = curr->next;
		if (curr->args)
			free_vtr(curr->args, get_sizeof_args(curr->args));
		if (curr->redirect)
			free_rdirs(curr->redirect);
		free(curr);
		curr = next;
	}
}

void	free_rdirs(t_rdir *redirects)
{
	t_rdir	*current;
	t_rdir	*next;

	current = redirects;
	while (current)
	{
		next = current->next;
		if (current->args[0])
			free(current->args[0]);
		if (current->args[1])
			free(current->args[1]);
		free(current);
		current = next;
	}
}

void  free_shell(t_shell *shell)
{
	if (shell)
	{
		if (shell->cmd)
			free_cmds(shell->cmd);
		if (shell->env)
			free_vtr(shell->env, get_sizeof_args(shell->env));
	}
}
