/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:04:04 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/02 13:46:43 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

static void	mark_redirection(t_str line, t_str new_line, t_arr i, t_arr k)
{
	new_line[(*k)++] = '\x1F';
	new_line[(*k)++] = line[*i];
	if (line[*i + 1] == line[*i])
	{
		(*i)++;
		new_line[(*k)++] = line[*i];
	}
	new_line[(*k)++] = '\x1F';
}

static t_str	marker(t_str line, int *i, int *k)
{
	int		quote;
	t_str	new_line;

	quote = 0;
	new_line = ft_calloc(ft_strlen(line) * 3 + 1, sizeof(char));
	while (line[++(*i)])
	{
		if ((line[*i] == '\'' || line[*i] == '"') && !quote)
			quote = line[*i];
		else if (line[*i] == quote)
			quote = 0;
		if (line[*i] == '|' && !quote)
			new_line[*k] = '\x1E';
		else if (line[*i] == ' ' && !quote)
			new_line[*k] = '\x1F';
		else if ((line[*i] == '>' || line[*i] == '<') && !quote)
		{
			mark_redirection(line, new_line, i, k);
			continue ;
		}
		else
			new_line[*k] = line[*i];
		(*k)++;
	}
	return (new_line);
}

t_str	prepare_line(t_str line)
{
	int		i;
	int		k;
	t_str	new_line;

	i = -1;
	k = 0;
	new_line = marker(line, &i, &k);
	return (new_line);
}

t_vtr	process_args(t_str cmd_str)
{
	int		i;
	int		size;
	t_vtr	args;
	t_vtr	split;
	t_str	clean_cmd;

	clean_cmd = remove_redirections(cmd_str);
	if (!clean_cmd)
		return (NULL);
	split = ft_split(clean_cmd, '\x1F');
	free(clean_cmd);
	size = get_sizeof_args(split);
	if (!split || size < 0)
		return (free_vtr(split), NULL);
	args = ft_calloc(size + 1, sizeof(t_str));
	if (!args)
		return (free_vtr(split), NULL);
	i = -1;
	while (split[++i])
		args[i] = remove_quotes(split[i]);
	free_vtr(split);
	if (args[0])
		args[0] = get_path(shell(), args[0]);
	return (args);
}
