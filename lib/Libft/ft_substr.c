/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:22:38 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/22 00:17:19 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int strt, size_t len)
{
	char	*ss;
	size_t	sz;

	if (!str)
		return (NULL);
	sz = ft_strlen(str);
	if (strt >= sz)
		return (ft_strdup(""));
	if (len > sz - strt)
		len = sz - strt;
	ss = ft_calloc(len + 1, sizeof(char));
	if (!ss)
		return (NULL);
	ft_memcpy(ss, str + strt, len);
	return (ss);
}
