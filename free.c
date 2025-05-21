/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:46:46 by duandrad          #+#    #+#             */
/*   Updated: 2025/05/19 15:47:19 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


char	**free_str_arr(char **arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

void	free_environ(t_environ_list *environ)
{
	t_environ_node	*tmp;

	if (!environ)
		return ;
	while (environ->head)
	{
		tmp = environ->head;
		environ->head = environ->head->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	free(environ);
}

t_lexer_list	*free_lex(t_lexer_list *lex_head)
{
	t_lexer_list	*tmp;

	while (lex_head)
	{
		tmp = lex_head->next;
		free(lex_head->str);
		free(lex_head->index);
		free(lex_head->type);
		lex_head = tmp;
	}
	return (NULL);
}

t_executor	*free_exec_list(t_executor *list)
{
	t_executor	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list->append);
		free(list->execs);
		free(list->fd_in);
		free(list->fd_out);
		
	}
}
