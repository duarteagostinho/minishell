/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:17:36 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/02 00:18:46 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

int	get_size_executor(t_lexer_list *head)
{
	/* Calculates the number of t_executor elements/nodes needed.

Calculates the number of t_executor elements/nodes needed based on the number of pipe token in the lexer linked list. Each pipe token represents a new t_executor node. Example: 2 pipe token -> 2 + 1 t_executor nodes.

Parameters
head	A pointer to the head of the lexer linked list.
Returns
The size of the t_executor linked list. */
}

t_executor	*create_executor_list(int size)
{
/* Create a linked list of t_executor nodes/elements.

Allocates memory for a linked list of t_executor nodes, based on the size.

Parameters
size	The size of the t_executor linked list.
Returns
A pointer to the linked list, or NULL if allocation fails. */
}

void	set_executor_defaults(t_executor *node)
{
	/* Sets default values for a t_executor node.

Initializes the variables of a t_executor node with default values. They include filediscriptors and bools.

Parameters
node	A pointer to the t_executor node to initialize.
 */
}

t_executor	*init_executor_list(int size)
{
	/* Initializes the t_executor linked list.

Initializes the t_executor linked list, by first calling create_executor_list() to allocate memory for it. It sets every nodes id and overall size, then calls set_executor_defaults() for setting default values.

Parameters
size	The amount of nodes in the t_executor linked list.
Returns
A pointer to the initialized t_executor linked list, or NULL on error. */
}

t_executor	*prepare_executor(t_shell *shell)
{
	/* Prepare a linked list of t_executor elements for the executor.

Prepares a linked list of t_executor elements by calculating the number of elements needed, initializing them and filling them with the relevant data from the lexer linked list and the environ linked list.

Parameters
shell	A pointer to the main data structure.
Returns
A pointer to the t_executor linked list, or NULL on error. */
}

