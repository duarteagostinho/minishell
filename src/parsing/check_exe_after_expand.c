/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exe_after_expand.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:11:07 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/02 00:24:47 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

char	**combine_execs(char **resplit, char **new_execs, char **execs)
{
	/* Combine resplit array with execs array into new_execs array.

Takes 2 arrays of strings, 'resplit' and 'execs', combines them into a new array 'new_execs'. Also frees the memory of the input arrays.

!!!!!Warning!!!!!
The memory for new_execs is allocated outside of the function.

Parameters
[in]	resplit	The first array of strings.
[in,out]	new_execs	The resulting array of strings after combining.
[in]	execs	The second array of strings.
Returns
new_execs The combined array of strings. */
}

int	after_expand(t_executor *current)
{
	/* Process the execs array of the current executor node after expansion.

Takes a node of the executor list, splits its execs array (execution command) and combines the resulting strings with the existing execs array.

Parameters
[in,out]	current	The current executor node.
Returns
The result of the process (OK, NOT_FOUND, or FAILED). */
}

bool	check_execs_after_expand(t_shell *shell)
{
	/* Checks and processes execution commands after expansion.

Iterates through the executor list ands calls after_expand() on each of the nodes of that list. Retuns true if all processing is successfull, or false if any processing fails.

Parameters
[in,out]	shell	The main data structure.
Returns
True if all processing succeeds, false if any processing fails.
 */
}

