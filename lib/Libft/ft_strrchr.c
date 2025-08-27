/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:10:54 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/22 21:26:40 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*occ;

	occ = NULL;
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
			occ = (char *)str;
		str++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return (occ);
}
