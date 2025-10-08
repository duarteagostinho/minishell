/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_exp_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:09:10 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/08 09:56:13 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_value_to_expanded(t_str value, t_str expanded, int *pos)
{
	int	j;

	if (!value)
		return ;
	j = 0;
	while (value[j])
		expanded[(*pos)++] = value[j++];
}

bool	has_unquoted_heredoc(t_str str)
{
	int		i;
	char	quote;

	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				i++;
			if (str[i])
				i++;
		}
		else if (str[i] == '<' && str[i + 1] == '<')
			return (true);
		else
			i++;
	}
	return (false);
}
