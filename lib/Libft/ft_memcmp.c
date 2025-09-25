/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:57:56 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 19:29:05 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *mem1, const void *mem2, size_t n)
{
	unsigned char	*temp_mem1;
	unsigned char	*temp_mem2;

	temp_mem1 = (unsigned char *)mem1;
	temp_mem2 = (unsigned char *)mem2;
	while (n--)
	{
		if (*temp_mem1 != *temp_mem2)
			return (*temp_mem1 - *temp_mem2);
		temp_mem1++;
		temp_mem2++;
	}
	return (0);
}
