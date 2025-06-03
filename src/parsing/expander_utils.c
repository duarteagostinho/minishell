/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:06:50 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/03 18:51:00 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

string  ft_charjoin_expander(const char* s, const char c)
{
/*Concatenates character to the end of a string.

This function takes an input string s and a character c, and concatenates the character to the end of the string. The memory for the resulting string is dynamically allocated to accommodate the additional character. The memory for the original string is freed before returning the result.

Parameters
s	The input string.
c	The character to concatenate.
Returns
A pointer to the concatenated string, or NULL if memory allocation fails.
*/
}

char*  ft_strjoin_expander(const char* s1, const char* s2)
{
/*Concatenates two strings and expands the memory as needed.

This function takes two input strings, s1 and s2, and concatenates them into a new string. The memory for the resulting string is dynamically allocated to accommodate both input strings. The memory for s1 is freed before returning the result.

Parameters
s1	The first input string.
s2	The second input string.
Returns
A pointer to the concatenated string, or NULL if memory allocation fails.*/
}

char*  realloc_str(char* original, int pos)
{
/*Reallocates memory for a string.

This function reallocates memory for a string, extending its size while preserving its existing content. It is used to dynamically expand the result string during variable expansion.

Parameters
[in]	res	The original string to be reallocated.
[in]	pos	The current position in the result string.
Returns
A pointer to the reallocated string or NULL on allocation failure.
*/
}

t_expander  *init_expander(char* str)
{
/*Initializes the expander struct for variable expansion.

This function initializes the expander struct used during variable expansion. It allocates memory for various fields and sets their initial values.

Parameters
[in]	str	The input string to be expanded.
Returns
A pointer to the initialized expander struct or NULL on allocation failure.
*/
}

void  free_exp(t_expander *exp)
{
/*Frees resources associated with the expander struct.

This function deallocates memory used by the expander struct and its associated fields. It ensures that no memory leaks occur during variable expansion.

Parameters
[in]	exp	A pointer to the expander struct to be freed.*/
}

