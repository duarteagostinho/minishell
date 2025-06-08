/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote_syn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:53:23 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/03 18:49:06 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

int	get_end_quote(const char* input, char c)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == c)
			return (i);
	}
	return (-1);
}

bool	check_quote_syntax(const char **input)
{
	int		i;
	int		k;
	int		end_quo;

	k = -1;
	if (!input || !*input)
		return (false);
	while (input[++k])
	{
		i = 0;
		while (input[k][i])
		{
			if (input[k][i] == '\"' || input[k][i] == '\'')
			{
				end_quo = get_end_quote(&input[k][i + 1], input[k][i]);
				if (end_quo == -1)
					return (false);
				i += end_quo + 2;
			}
			else
				i++;
		}
	}
	return (true);
}

