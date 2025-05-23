/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:48:16 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/03 19:00:11 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;

	i = 0;
	source = (unsigned char *) s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (source[i] == (unsigned char) c)
			return ((void *)(source + i));
		i++;
	}
	return (NULL);
}
