/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_rl_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:32:02 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/03 18:49:20 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"


int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char*	replace_with_clean(char* rl_copy, size_t start, size_t end)
{
	char*	clean;
	size_t	size;
	size_t	i;

	if (end < start)
		return (NULL);
	size = end - start + 1;
	clean = malloc(sizeof(char) * (size + 1));
	if (!clean)
	{
		ft_putstr_fd("Malloc error!\n", 2);
		return (NULL);
	}
	i = 0;
	while (start <= end)
		clean[i++] = rl_copy[start++];
	clean[i] = '\0';
	return (clean);
}


char*	clean_rl_copy(char* rl_copy)
{
	char*	clean;
	int		i;
	int		j;

	i = 0;
	j = -1;
	clean = malloc(sizeof(char) * ft_strlen(rl_copy) + 1);
	if (!clean)
		return (NULL);
	while (ft_isspace(rl_copy[i]))
		i++;
	while (rl_copy[i])
		clean[++j] = rl_copy[i++];
	clean[++j] = '\0';
	return (clean);
}
