/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:45:51 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 19:34:40 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int ascii, size_t n)
{
	unsigned char	*temp_mem;

	temp_mem = (unsigned char *)mem;
	while (n--)
	{
		if (*temp_mem == (unsigned char)ascii)
			return ((void *)temp_mem);
		temp_mem++;
	}
	return (NULL);
}
