/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:00:07 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/17 17:00:27 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_cmd	*init_command_list(void)
{
	t_cmd	*commands;

	commands = malloc(sizeof(t_cmd));
	if (!commands)
		return (NULL);
	commands->next = NULL;
	commands->redirect = NULL;
	commands->redirect_in = STDIN_FILENO;
	commands->redirect_out = STDOUT_FILENO;
	return (commands);
}

void	fill_commands(t_vtr cmds, t_cmd *curr)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		if (i > 0)
		{
			curr->next = malloc(sizeof(t_cmd));
			if (!curr->next)
				return ;
			curr = curr->next;
			curr->next = NULL;
			curr->redirect = NULL;
			curr->redirect_in = STDIN_FILENO;
			curr->redirect_out = STDOUT_FILENO;
		}
		curr->args = process_args(cmds[i]);
		curr->redirect = extract_redirections(cmds[i]);
		i++;
	}
}

void	cmds_config(t_vtr cmds, int *k, t_str *temp, t_cmd *commands)
{
	while (cmds[(*k)])
	{
		temp = cmds[*k];
		cmds[*k] = expand_variables(temp, env, shell);
		free(temp);
		mark_unquoted_whitespace(cmds[*k]);
		*k++;
	}
	commands = init_command_list();
}