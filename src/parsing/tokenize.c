/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:59:29 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/03 18:52:11 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

t_token assign_type(char tok)
{
  /*Assign a type based on the input char.

Parameters
tok	The input char to assign a tyoe for.
Returns
The assigned type for the the input char.*/
}

t_token which_type(char* token)
{
/*Set the type of token.

Takes an input string('token') and chooses the type of token it represents. Only sets if the token is a pipe or some redirection, otherwise sets type to NONE.

Parameters
s	The input string ('token') to identify the type for.
Returns
The type of token identified.*/
}

t_lexer_list  *create_lexer_list(char **input_arr)
{
  /*Allocates memory for the lexer list.

Creates a double-linked list using the size of the input array. Calculates size of input array. and allocates memory for the lexer list. If malloc fails, displays error message, returns NULL.

Parameters
input_array	The array with the substrings('tokens').
Returns
A pointer to the head of the allocated list, or NULL if allocation failed.*/
}

t_lexer_list  *fill_lexer_list(char **input_arr)
{
  /*Fills the lexer list using the input array.

Calls create_lexer_list() to allocates a double-linked list with as many nodes as substrings in input_array. Fills each node of the list with information about each 'token'.

Parameters
input_array	The array with the substrings('tokens').
Returns
A pointer to the head of the filled lexer list, or NULL on failure.*/
}

t_lexer_list  *tokenize(t_shell *shell)
{
  /*Tokenizes the input string and creates the lexer list.

Tokenizes the input by creating an array of substrings. Creates a linked list of lexer tokens using the substrings. Returns a pointer to the head of the lexer linked list. if malloc fails for input_array or lexer list, display message and return NULL.

Parameters
shell	The shell data structure (main data structure). @ return The head of the lexer list if successful, otherwise NULL.
*/
}

