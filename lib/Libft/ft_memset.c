/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:34:56 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 19:34:56 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int ascii, size_t n)
{
	unsigned char	*temp_mem;

	temp_mem = (unsigned char *)mem;
	while (n--)
		*temp_mem++ = (unsigned char)ascii;
	return (mem);
}
