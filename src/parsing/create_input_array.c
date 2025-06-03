/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:33:33 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/03 18:49:39 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../lib/minishell.h"

int len_substr(char* str)
{
	int	i;
	int	sub_len;

	i = -1;
	while (str[++i])
	{
		if (ft_isspace(str[i]) || is_token(str[i]))
			return (i);
		no_delim_found(str, &i);
	}
	return (i);
}

int count_elements(char* rl_copy)
{
  /*Count the number of elements in the input string.

Takes an input and counts the substrings('tokens') in it. Makes use of len_substr() to get the length of each substring. Returns the number of substrings found.

Parameters
rl_copy	The string for which to count the number of substrings.
Returns
The number of substrings('tokens') in the input string.*/
	int	i;
	int	tokens;

	tokens = 0;
	i = -1;
	while (rl_copy[++i])
	{
		if (len_substr(rl_copy))
			
	}
}

int find_token(char **input_arr, char **input, int index)
{
  /*Finds predefined tokens in the input string and adds it to the input_array.

Finds tokens in the input string and adds them to the input_array. It calls is_token() and is_token2() to check for existing valid tokens. If a token is found, a substring is created and added to the input_array.

Parameters
input_array	Pointer to the array of strings.
input	Pointer to the input string.
index	Current index in the input_array.
Returns
index The updated index after adding a substring/token to the array of strings.*/
}


char  **fill_input_array(char **input_array,char* input)
{
  /*Fills the array of strings with substrings('tokens') from the input string.

Takes an input string, splits it into substrings('tokens') and fills the given array of strings with these substrings('tokens'). The function iterates over the input, calls find_token() to find predefined 'tokens' and adds them to the array. Also handles whitespace separated substrings and adds them to the array.

Parameters
input_array	Pointer to the array of strings to fill.
input	The input string.
Returns
input_array The array of strings with the tokens and whitespace separated substrings.*/
}

char  **create_input_array(t_shell *shell)
{
  /*Create an array of input strings for tokenization.

Creates an array of tokens from shell->rl_copy(removed leading and trailing whitespaces). Calculates the number of elements needed for the array and allocates for it. Calls fill_input_array() to fill the array with substrings ('tokens').

Parameters
shell	The main data structure.
Returns
An array of substrings('tokens').*/
}

