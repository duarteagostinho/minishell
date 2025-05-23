/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:02:24 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/29 18:16:04 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*checks if theres a newline*/
int	check(char *buff)
{
	int		ret;
	char	*ini;

	ret = 0;
	ini = buff;
	while (*buff)
	{
		if (ret == 1)
			*ini++ = *buff;
		else if (*buff == '\n')
			ret = 1;
		*buff++ = '\0';
	}
	return (ret);
}

/*counts size until newline and includes newline*/
size_t	len_newline(char *buff)
{
	size_t	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i] != '\n' && buff[i])
		i++;
	return (i + (buff[i] == '\n'));
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = len_newline(s1);
	s2_len = len_newline(s2);
	new = malloc(s1_len + s2_len + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
		new[j++] = s1[i++];
	free (s1);
	i = 0;
	while (i < s2_len)
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}
