/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_exec_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:13:41 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/02 00:16:42 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

int	process_out_append(t_executor *current, t_lexer_list *lexer)
{
/* Processes output redirections and append for the given node of the executor list.

Handles output redirections and append for the given executor list node by calling its subfunctions. Has some edgecase handling.

Parameters
current	A pointer to the current t_executor node.
lexer	A pointer to the current lexer list node.
Returns
OK if successful, FAILED if an error occurs, NOT_FOUND if not applicable. */
}

int	process_in_heredoc(t_executor *current, t_lexer_list *lexer)
{
/* Processes input redirections and heredoc for the given node of the executor list.

Handles input redirections and heredoc for the given executor list node by calling its subfunctions. Has some edgecase handling.

Parameters
current	A pointer to the current t_executor node.
lexer	A pointer to the current lexer list node.
Returns
OK if successful, FAILED if an error occurs, NOT_FOUND if not applicable. */
}

int	process_command(t_executor *current, t_lexer_list *lexer)
{
/* Processes the command part for the given node of the executor list.

Handles the command part of the given executor list node by creating an array of command arguments.

Parameters
current	A pointer to the current t_executor node.
lexer	A pointer to the current lexer list node.
Returns
OK if successful, FAILED if an error occurs, NOT_FOUND if not applicable. */
}

t_executor	*process_lexemes(t_executor *list,
	 t_executor *current, t_lexer_list **lexer)
{
/* Processes lexemes and sets values in the given t_executor node.

Processes lexemes in the lexer linked list and populates the executor linked list accordingly. It handles output redirections, input redirections inclusive heredoc and command executions. On error, frees the entire t_executor linked list and returns NULL.

Parameters
list	A pointer to the t_executor linked list.
current	A pointer to the current t_executor node.
lexer	A pointer to the lexer linked list.
Returns
A pointer to the updated t_executor node, or NULL on error. */
}

t_executor	*fill_executor_list(t_shell *shell, t_executor *list)
{
/* Fills the t_executor linked list with info about the parsed commands.

Fills the t_executor linked list by processing the lexer linked list and setting values in a t_executor node for each command and its operation.

Parameters
shell	A pointer to the main data structure.
list	A pointer the t_executor linked list to be filled.
Returns
A pointer to the filled t_executor linked list, or NULL on error. */
}

