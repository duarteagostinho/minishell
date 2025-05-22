/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:10:49 by duandrad          #+#    #+#             */
/*   Updated: 2024/10/29 15:30:17 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < len -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/* int main()
{
	char src[] = "hello";
	char dest[5];
	printf(":%ld:\n", ft_strlcpy(dest, src, -1));
	printf(":%s:\n", dest);
	return 0;
} */
