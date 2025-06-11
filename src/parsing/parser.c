/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:01:37 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/11 16:57:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static   void mark_pipes(char* line, char *new_line)
{
	int i;
	int c;

	c = 0;
	i = -1;

	while (line[++i])
	{
		new_line[i] = line[i];
		if ((line[i] == '"' || line[i] == '\'') && !c)
			c = line[i];
		else if (c == line[i])
			c = 0;
		else if (line[i] == '|' && !c)
			new_line[i] = '2';
	}
}

t_cmd *parser(char* line)
{
	char *new_line = ft_calloc(ft_strlen(line) + 1, 3);

	mark_pipes(line, new_line);
	printf("parser: %s\n", new_line);
	return (NULL);
}

// bool	check_pipe_syntax(t_lexer_list *lexer)
// {
// 	/* 

// Performs a pipe syntax check on the given list of lexems t_lexer_list *lexer.

// Checks the lexer list for a syntax error with pipes, by checking if a valid token is encounterd after a PIPE token.

// Parameters
//     lexer	A pointer to the lexer list.

// Returns
//     bool true if syntax is correct, otherwise false. 

//  */
// }

// t_lexer_list	*lexer(t_shell *shell)
// {
// 	/*Lexical analysis and tokenization of the input string.

// Performs the lexical analysis and tokenization of the input string.

// First frees the previous 'rl_copy' if it exists, then creates a clean copy of the input string and removes leading/trailing whitespaces.

// Checks the syntax of the quotes. If syntax is incorrect, print message, set g_exit_code and return NULL.

// Calls tokenize() to tokenize the clean copy and returns the head of the returned lexer list.

// Parameters
//     shell	The shell data structure (main data structure). @ return A pointer to the head of the lexer list if successful, otherwise NULL. */
// }

// bool	parser(t_shell *shell)
// {
// 	/*
// Parses the input using the lexer.

// Performs the parsing operation using the lexer. It first frees the existing lexer list if it exists. Then uses lexer() to generate a new list. If it failes to produce a new list, returns false. Else returns true.

// Parameters
//     shell	The shell data structure (main data structure).

// Returns
//     true if parsing is successful, false otherwise. 

// */
// }

