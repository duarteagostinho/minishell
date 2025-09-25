/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:39:46 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/21 02:39:52 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *ndl, size_t n)
{
	size_t	ndl_sz;

	ndl_sz = ft_strlen(ndl);
	if (!ndl_sz)
		return ((char *)hs);
	if (!n)
		return (NULL);
	while (*hs && ndl_sz <= n--)
	{
		if (ft_strncmp(hs, ndl, ndl_sz) == 0)
			return ((char *)hs);
		hs++;
	}
	return (NULL);
}
