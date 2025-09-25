/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:00:16 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/21 02:42:01 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!str || !f)
		return (NULL);
	res = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = (*f)(i, str[i]);
		i++;
	}
	return (res);
}
