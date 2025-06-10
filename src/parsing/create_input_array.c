/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:33:33 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/06 17:43:25 by duandrad         ###   ########.fr       */
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

int	count_elements(char* rl_copy)
{
	int	i;
	int	tokens;
	int	sub_len;

	tokens = 0;
	i = 0;
	sub_len = 0;
	while (rl_copy[i])
	{
		while (rl_copy[i] && ft_isspace(rl_copy[i]))
			i++;
		if (!rl_copy[i])
			break;
		sub_len = len_substr(&rl_copy[i]);
		if (sub_len > 0)
		{
			tokens++;
			i+= sub_len;
		}
		else
			i++;
	}
	return (tokens);
}
int	process_token_at_position(char **input_arr, char *input, int *i, int *index)
{
	if (input[*i + 1] && is_token2(input[*i + 1]))
	{
		input_arr[(*index)++] = ft_substr(input, *i, 2);
		*i += 2;
		return 1;
	}
	input_arr[(*index)++] = ft_substr(input, *i, 1);
	(*i)++;
	return 1;
}

int	find_token(char **input_arr, char **input, int index)
{
	int		i;
	int		k;

	k = 0;
	while (input[k])
	{
		i = 0;
		while (input[k][i])
		{
			if (is_token(input[k][i]) || is_token2(input[k][i]))
				process_token_at_position(input_arr, input[k], i, index);
			else
				i++;
		}
		k++;
	}
	return (index);
}


char  **fill_input_array(char **input_array,char* input)
{
  /*Fills the array of strings with substrings('tokens') from the input string.

Takes an input string, splits it into substrings('tokens') and fills the given array of strings with these substrings('tokens').
The function iterates over the input, calls find_token() to find predefined 'tokens' and adds them to the array.
Also handles whitespace separated substrings and adds them to the array.

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

