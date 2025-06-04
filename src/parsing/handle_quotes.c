/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:57:25 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/03 18:51:36 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../lib/minishell.h"

char*  handle_quotes(t_shell *shell, char **cmd,
                      char end_quote, t_expander * inter)
{
/*Handles quoted strings within a shell command.

This function processes quoted strings within a shell command, including variable expansions if present. It handles both single (' ') and double (" ") quotes.

Parameters
[in]	shell	A pointer to the shell struct.
[in,out]	str	A pointer to the command string to be processed.
[in]	end_quote	The character that marks the end of the quoted string (' ' or " ").
[in,out]	inter	A pointer to the expander struct.
Returns
A dynamically allocated string with the processed contents.
*/
}

