/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/21 02:44:45 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		tln;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	tln = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(tln, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy((str + ft_strlen(s1)), s2, ft_strlen(s2));
	return (str);
}
