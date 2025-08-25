/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:42:40 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/22 00:00:34 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dsz)
{
	size_t	sln;

	sln = ft_strlen(src);
	if (dsz == 0)
		return (sln);
	if (sln + 1 < dsz)
		ft_memcpy(dest, src, sln + 1);
	else
	{
		ft_memcpy(dest, src, dsz - 1);
		dest[dsz - 1] = 0;
	}
	return (sln);
}
