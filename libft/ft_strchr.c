/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:25:53 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/04 17:23:46 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	str = (char *) s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return (str + i);
		i++;
	}
	if (str[i] == (char) c)
		return (str + i);
	return (NULL);
}

/* int main()
{
	printf(";%s;\n", ft_strchr("teste", 'e'));
	printf(";%s;\n", strchr("teste", 'e'));
	return 0;
} */