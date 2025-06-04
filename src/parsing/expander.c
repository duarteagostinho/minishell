/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:05:13 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/02 00:06:20 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

int expand_var(t_shell *shell, char **cmd, t_expander *exp, int pos)
{
/*Expand variables.

This function is expanding variables. It iterates through the command string, identifies variables and replaces them with the corresponding values.

Parameters
[in]	shell	A pointer to the shell struct.
[in,out]	str	A pointer to the command string.
[in,out]	exp	A pointer to the expander struct.
[in]	pos	The current position in the result string.
Returns
The updated position in the result string after expansion.*/
}

bool  expander(t_shell *shell)
{
/*Starting point of variable expansion.

This function is the starting point for expanding variables.It iterates through each command and applies variable expansion if needed or just copies from the input.

Parameters
[in,out]	shell	A pointer to the shell struct.
*/
}

