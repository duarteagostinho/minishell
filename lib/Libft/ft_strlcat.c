/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:28:14 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/22 21:22:55 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsz)
{
	size_t	dln;
	size_t	sln;

	sln = ft_strlen(src);
	if (!dsz)
		return (sln);
	dln = ft_strlen(dest);
	if (dln >= dsz)
		return (dsz + sln);
	if (sln < dsz - dln)
		ft_memcpy(dest + dln, src, sln + 1);
	else
	{
		ft_memcpy(dest + dln, src, dsz - dln - 1);
		dest[dsz - 1] = 0;
	}
	return (dln + sln);
}
