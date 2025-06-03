/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_arr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:38:47 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/03 18:51:49 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"
#include <stdbool.h>

int	skip_quotes(char* str)
{
	int		i;
	char	quote;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				i++;
			if (str[i] == quote)
				i++;
			break;
		}
		i++;
	}
	return (i);
}

void	no_delim_found(char* str, int *len)
{
	if (str[*len] == '\"' || str[*len] == '\'')
		*len += skip_quotes(&str[*len]);
	else
		(*len)++;
}

bool	is_token(char to_check)
{
	if (to_check == '<' || to_check == '>' || to_check == '|')
		return (true);
	return (false);
}

bool  is_token2(char to_check)
{
	if (to_check == '<' || to_check == '>')
		return (true);
	return (false);
}
