/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:03:52 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/03 18:51:55 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

char*  interpolate(t_shell *shell, char* str)
{
/*Interpolates variables and handles quotes within a shell command.

This function processes variable interpolation and handles quotes (single or double) within the shell prompt. It iterates through the prompt string, expanding variables and preserving quoted strings.

Parameters
[in]	shell	A pointer to the shell struct.
[in,out]	str	A pointer to the command string to be processed.
[in]	inter	A pointer to the expander struct.
Returns
A dynamically allocated string containing the processed contents or NULL on failure.
*/
}

