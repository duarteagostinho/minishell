/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:59:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/06/09 20:32:43 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

int	is_valid_id(const t_str key)
{
	t_str copy;

	copy = key;
	if (!*copy || !ft_isalpha(*copy) || *copy != '_')
		return (1);
	while (*copy && (ft_isalnum(*copy) || *copy == '_'))
		copy++;
	if (*copy == '=')
		copy++;
	if (*copy != '\0')
		return (1);
	return (0);
}

int	check_flag(t_vtr args)
{
	int	flags;

	flags = 0;
	while (*args)
	{
		while (**args)
		{
			if (**args++ == '-' && **args == 'n')
				flags++;
			(*args)++;
		}
		args++;
	}
	return (flags);
}
