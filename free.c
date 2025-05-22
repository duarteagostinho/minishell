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
{/*

Frees the allocated memory of a linked list of t_executor elements.

Frees the memory of each node in the linked list, also frees the allocated members path and execs of each node. The entire linked list is freed. Its pointer is set to NULL.

Parameters
    list	A pointer to the head of the t_executor linked list.

Returns
    Always NULL. 

*/}

void  free_heap(t_shell *shell)
{
	/* Frees the memory used by the main data structure (shell environment).

Releases the memory allocated for the main data structure and it's components, including the environment list, readline input, etc.

Parameters
    [in,out]	shell	A pointer to the shell structure to be freed.  */
}

