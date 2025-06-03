/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_out_app.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:21:57 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/02 00:23:18 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

bool	close_outputfile(int fd)
{
	if (close(fd) == 0)
		return (true);
	else
		return (false);
}

bool	open_outputfile(t_executor *curr, t_lexer_list *lexer)
{
/* Handles opening an output file.

Handles opening an output file for the given t_executor node, based on the given lexer list token type. It supports truncating and appending to the file.

Parameters
current	A pointer to the current t_executor node.
lexer	A pointer to the current t_lexer_list node.
Returns
True if the file is opened and closed successfully, false on error. */
}

