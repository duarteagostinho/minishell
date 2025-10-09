/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:05:00 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/18 15:17:44 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_quote_block(t_str clean_cmd, int *j, t_str cmd_str, int *i)
{
	char	quote;

	quote = cmd_str[*i];
	clean_cmd[(*j)++] = cmd_str[(*i)++];
	while (cmd_str[*i] && cmd_str[*i] != quote)
		clean_cmd[(*j)++] = cmd_str[(*i)++];
	if (cmd_str[*i])
		clean_cmd[(*j)++] = cmd_str[(*i)++];
}

void	skip_redirection(t_str cmd_str, int *i)
{
	if (cmd_str[*i + 1] == cmd_str[*i])
		*i += 2;
	else
		(*i)++;
	while (cmd_str[*i] && cmd_str[*i] == '\x1F')
		(*i)++;
	while (cmd_str[*i] && cmd_str[*i] != '\x1F')
		(*i)++;
	if (cmd_str[*i] == '\x1F')
		(*i)++;
}

t_str	remove_redirections(t_str cmd_str)
{
	int		i;
	int		j;
	t_str	clean_cmd;

	i = 0;
	j = 0;
	clean_cmd = ft_calloc(ft_strlen(cmd_str) + 1, sizeof(char));
	if (!clean_cmd)
		return (NULL);
	while (cmd_str[i])
	{
		if (cmd_str[i] == '"' || cmd_str[i] == '\'')
			copy_quote_block(clean_cmd, &j, cmd_str, &i);
		else if (cmd_str[i] == '>' || cmd_str[i] == '<')
			skip_redirection(cmd_str, &i);
		else
			clean_cmd[j++] = cmd_str[i++];
	}
	clean_cmd[j] = '\0';
	return (clean_cmd);
}
