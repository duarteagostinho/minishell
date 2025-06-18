/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:01:37 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/18 18:33:49 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void mark_redirection(char* line, char **new_line, int *i)
{
	*(*new_line)++ = '3';
	*(*new_line)++ = line[*i];
	if (line[*i + 1] == line[*i])
		*(*new_line)++ = line[++(*i)];
	**new_line = '3';
}


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
		else if (line[i] == '>' || line[i] == '<')
			mark_redirection(line, &new_line, &i);
		else
			*new_line = line[i];
		new_line++;
	}
}
static t_redirect	*handle_red(char *type, char *filename, int fd)
{
	t_redirect	*red;
	
	if (!type || !filename)
		return (NULL);
	red = malloc(sizeof(t_redirect));
	if (!red)
		return (NULL);
	red->args[0] = ft_strdup(type);
	if (!red->args[0])
	{
		free(red);
		return (NULL);
	}
	red->args[1] = ft_strdup(filename);
	if (!red->args[1])
	{
		free(red->args[0]);
		free(red);
		return (NULL);
	}
	red->fd = fd;
	red->next = NULL;
	return (red);
}

t_cmd	*parser(char* line)
{
	t_cmd	*commands;
	char	*new_line = ft_calloc(ft_strlen(line) + 1, 3);
	int		i;

	commands = malloc(sizeof(t_cmd*));
	mark_pipes(line, new_line);
	commands->args = ft_split(new_line, '2');
	commands->redirect = 
	i = -1;
	while (commands->args && commands->args[++i])
		printf("%i - cmd: %s\n", i, commands->args[i]);
	return (free(new_line), NULL);
}
