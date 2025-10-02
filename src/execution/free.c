/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:50:41 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/02 13:48:34 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_vtr(t_vtr args)
{
	int	i;

	i = -1;
	if (!args)
		return ;
	while (args[++i])
		free(args[i]);
	free(args);
}

void	free_cmds(t_cmd *commands)
{
	t_cmd	*curr;
	t_cmd	*next;

	curr = commands;
	while (curr)
	{
		next = curr->next;
		if (curr->args)
			free_vtr(curr->args);
		if (curr->redirect)
			free_rdirs(curr->redirect);
		free(curr);
		curr = next;
	}
}

void	free_rdirs(t_rdir *redirects)
{
	t_rdir	*curr;
	t_rdir	*next;

	curr = redirects;
	while (curr)
	{
		next = curr->next;
		if (curr->args[0])
			free(curr->args[0]);
		if (curr->args[1])
			free(curr->args[1]);
		free(curr);
		curr = next;
	}
}

void	free_shell(t_shell *shell)
{
	if (shell)
	{
		if (shell->cmd)
			free_cmds(shell->cmd);
		if (shell->env)
			free_vtr(shell->env);
	}
}
