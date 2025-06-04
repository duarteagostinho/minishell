/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_in_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:20:25 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/03 18:52:09 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

bool	get_input(int fd, char* delim)
{
/* Reads input for a here-document until a specified delimiter.

Reads input from the user, displaying a prompt, until the specified delimiter is entered. The input is written to the given file descriptor. Also handles ctrl-d (end-of-file from readline).

Parameters
fd	The file descriptor to write the input to.
delimiter	The delimiter that signals the end of the here-document.
Returns
True if successful, false on error. */
}

int	create_heredoc(char* delm)
{
/* Creates a here-document file and gathers input.

Creates a temporary file for a here-document, gathers input for it by calling get_input().
Returns a file descriptor to the created file.

Parameters
delimiter	The delimiter that signals the end of the here-document.

Returns
The file descriptor of the created here-document, or -1 on error. */
}

bool	open_inputfile(t_executor *curr, t_lexer_list *lexer)
{
/* Handles opening an input file.

Handles opening an input file for the given t_executor node, based on the given lexer list token type. It supports input redirection and here-document.

Parameters
current	A pointer to the current t_executor node.
lexer	A pointer to the current t_lexer_list node.
Returns
True if the file is opened successfully, false on error. */
}

