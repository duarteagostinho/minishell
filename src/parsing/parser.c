/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:01:37 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/02 00:02:59 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

bool	check_pipe_syntax(t_lexer_list *lexer)
{
	/* 

Performs a pipe syntax check on the given list of lexems t_lexer_list *lexer.

Checks the lexer list for a syntax error with pipes, by checking if a valid token is encounterd after a PIPE token.

Parameters
    lexer	A pointer to the lexer list.

Returns
    bool true if syntax is correct, otherwise false. 

 */
}

t_lexer_list	*lexer(t_shell *shell)
{
	/*Lexical analysis and tokenization of the input string.

Performs the lexical analysis and tokenization of the input string.

First frees the previous 'rl_copy' if it exists, then creates a clean copy of the input string and removes leading/trailing whitespaces.

Checks the syntax of the quotes. If syntax is incorrect, print message, set g_exit_code and return NULL.

Calls tokenize() to tokenize the clean copy and returns the head of the returned lexer list.

Parameters
    shell	The shell data structure (main data structure). @ return A pointer to the head of the lexer list if successful, otherwise NULL. */
}

bool	parser(t_shell *shell)
{
	/*
Parses the input using the lexer.

Performs the parsing operation using the lexer. It first frees the existing lexer list if it exists. Then uses lexer() to generate a new list. If it failes to produce a new list, returns false. Else returns true.

Parameters
    shell	The shell data structure (main data structure).

Returns
    true if parsing is successful, false otherwise. 

*/
}

