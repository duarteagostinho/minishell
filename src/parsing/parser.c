/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:50:41 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/17 16:59:48 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_str	type_check(t_str full_line, t_arr i)
{
	t_str	error;

	if (full_line[*i] == '"' || full_line[*i] == '\'')
	{
		error = handle_quotes(full_line, i);
		if (error)
			return (error);
	}
	else if (full_line[*i] == '|')
	{
		error = handle_pipes(full_line, i);
		if (error)
			return (error);
	}
	else if (full_line[*i] == '>' || full_line[*i] == '<')
	{
		error = handle_redirections(full_line, i);
		if (error)
			return (error);
	}
	return (NULL);
}

static t_str	valid_syntax(t_str line)
{
	int		i;
	t_str	error;

	if (!line || !*line)
		return (NULL);
	i = skip_whitespace(line, 0);
	if (!line[i])
		return (ERR_EMPTY_INP);
	if (line[i] == '|' || line[ft_strlen(line) - 1] == '|')
		return (ERR_SYN_PIPE);
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\''
			|| line[i] == '|' || line[i] == '>'
			|| line[i] == '<')
		{
			error = type_check(line, &i);
			if (error)
				return (error);
		}
		else
			i++;
	}
	return (NULL);
}

t_cmd	*parser(t_str line, t_vtr env, t_shell *shell)
{
	t_vtr	cmds;
	t_str	temp;
	t_cmd	*commands;
	t_str	new_line;
	int		k;

	k = 0;
	if (!line || !*line)
		return (NULL);
	new_line = prepare_line(line);
	if (!new_line)
		return (NULL);
	cmds = ft_split(new_line, '\x1E');
	if (!cmds)
		return (free(new_line), NULL);
	cmds_config(cmds, &k, &temp, commands);
	if (!commands)
		return (free(new_line), NULL);
	fill_commands(cmds, commands);
	free_vtr(cmds);
	free(new_line);
	return (commands);
}
