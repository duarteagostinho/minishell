/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:59:34 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/13 14:39:53 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <bsd/string.h> */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if (size == 0)
		return (size + slen);
	i = 0;
	dlen = ft_strlen(dst);
	if (size <= dlen)
		return (size + slen);
	while (src[i] && dlen + i < size - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
/* int main()
{
	char *src = "teste";
	char *dst = NULL;
	printf(":%ld:\n", ft_strlcat(dst, src, 0));
	printf(":%ld:\n", strlcat(dst, src, 0));
	return 0;
} */
