/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:58:11 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/22 17:18:48 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *st)
{
	char	*trm;
	size_t	bgn;
	size_t	end;

	if (!str || !st)
		return (NULL);
	bgn = 0;
	end = ft_strlen(str);
	while (str[bgn] && ft_strchr(st, str[bgn]))
		bgn++;
	while (end > bgn && ft_strchr(st, str[end - 1]))
		end--;
	trm = ft_calloc((end - bgn) + 1, sizeof(char));
	if (!trm)
		return (NULL);
	ft_memcpy(trm, str + bgn, (end - bgn));
	return (trm);
}
