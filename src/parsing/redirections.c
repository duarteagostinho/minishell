/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:20:54 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/18 14:38:57 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_str	get_redir_type(t_str cmd_str, t_arr i, t_arr fd)
{
	if (cmd_str[*i] == '>')
	{
		*fd = STDOUT_FILENO;
		if (cmd_str[*i + 1] == '>')
		{
			(*i) += 2;
			return (">>");
		}
		(*i)++;
		return (">");
	}
	else if (cmd_str[*i] == '<')
	{
		*fd = STDIN_FILENO;
		if (cmd_str[*i + 1] == '<')
		{
			(*i) += 2;
			return ("<<");
		}
		(*i)++;
		return ("<");
	}
	return (NULL);
}

static t_rdir	*handle_red(t_str type, t_str filename, int fd)
{
	t_rdir	*red;

	if (!type || !filename)
		return (NULL);
	red = malloc(sizeof(t_rdir));
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

static t_rdir	*extract_one_redir(t_str cmd_str, int *i)
{
	t_str	type;
	int		fd;
	t_str	filename;
	t_rdir	*red;

	type = get_redir_type(cmd_str, i, &fd);
	if (!type)
		return (NULL);
	filename = extract_filename(cmd_str, i);
	if (!filename)
		return (NULL);
	red = handle_red(type, filename, fd);
	free(filename);
	return (red);
}

static void	handle_quote(char *quote, char c)
{
	if (!*quote)
		*quote = c;
	else if (c == *quote)
		*quote = 0;
}

t_rdir	*extract_redirections(t_str cmd_str)
{
	t_rdir	*head;
	t_rdir	*curr;
	t_rdir	*red;
	int		i;
	char	quote;

	head = NULL;
	curr = NULL;
	quote = 0;
	i = -1;
	while (cmd_str[++i])
	{
		if (cmd_str[i] == '\'' || cmd_str[i] == '"')
			handle_quote(&quote, cmd_str[i]);
		else if (!quote)
		{
			red = extract_one_redir(cmd_str, &i);
			if (red)
				add_redir(&head, &curr, red);
			continue ;
		}
	}
	return (head);
}
