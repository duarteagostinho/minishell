/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:08:01 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 19:26:06 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*start;

	start = dest;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (start);
}
