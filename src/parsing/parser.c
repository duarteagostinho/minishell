/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:01:37 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/18 15:06:26 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void mark_pipes(char* line, char *new_line)
{
	int i;
	int c;

	c = 0;
	i = -1;

	while (line[++i])
	{
		*new_line = line[i];
		if ((line[i] == '"' || line[i] == '\'') && !c)
			c = line[i];
		else if (c == line[i])
			c = 0;
		else if (line[i] == '|' && !c)
			*new_line = '2';
		else if (line[i] == ' ' && !c)
			*new_line = '3';
		else if (line[i] == '>' && !c)

		new_line++;
	}
}

t_cmd	*parser(char* line)
{
	char	*new_line = ft_calloc(ft_strlen(line) + 1, 3);
	char	**str_cmds;
	int		i;

	mark_pipes(line, new_line);
	str_cmds = ft_split(new_line, '2');
	i = -1;
	while (str_cmds && str_cmds[++i])
		printf("%i - cmd: %s\n", i, str_cmds[i]);
	return (free(new_line), NULL);
}
// echo<<tes hello >g

//echo3<<3tes3hello33>3g
