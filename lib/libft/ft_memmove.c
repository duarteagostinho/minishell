/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:18:58 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/02 14:58:13 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*destination;

	source = (unsigned char *) src;
	destination = (unsigned char *) dest;
	if (!dest && !src && n != 0)
		return (0);
	if (destination > source)
	{
		while (n-- > 0)
			destination[n] = source[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dest);
}
/* int main()
{
	char *dest = "";
	char src[] = "Hello";
	printf("%p\n", memmove(dest, src, 6));
	printf("%p", ft_memmove(dest, src, 6));
} */
