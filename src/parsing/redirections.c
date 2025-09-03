/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:20:54 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/03 03:35:28 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

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

static t_str	extract_filename(t_str cmd_str, t_arr i)
{
	t_str	temp;
	t_str	filename;
	int		start;

	while (cmd_str[*i] && cmd_str[*i] == '\x1F')
		(*i)++;
	start = *i;
	while (cmd_str[*i] && cmd_str[*i] != '\x1F')
		(*i)++;
	if (start == *i)
		return (NULL);
	temp = ft_substr(cmd_str, start, *i - start);
	if (!temp)
		return (NULL);
	filename = remove_quotes(temp);
	free(temp);
	return (filename);
}

static void	add_redir(t_rdir **head, t_rdir **curr, t_rdir *new)
{
	if (!new)
		return ;
	if (!*head)
		*head = new;
	else
		(*curr)->next = new;
	(*curr) = new;
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

t_rdir	*extract_redirections(t_str cmd_str)
{
	t_rdir	*head;
	t_rdir	*curr;
	int		i;
	t_str	type;
	int		fd;
	t_str	filename;
	char	quote;

	i = 0;
	quote = 0;
	head = NULL;
	curr = NULL;
	while (cmd_str[i])
	{
		if (!quote && (cmd_str[i] == '\'' || cmd_str[i] == '"'))
			quote = cmd_str[i];
		else if (cmd_str[i] == quote)
			quote = 0;
		else if (!quote && (type = get_redir_type(cmd_str, &i, &fd))
			&& (filename = extract_filename(cmd_str, &i)))
		{
			add_redir(&head, &curr, handle_red(type, filename, fd));
			free(filename);
			continue;
		}
		i++;
	}
	
	return (head);
}
