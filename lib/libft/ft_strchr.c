/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:25:53 by duandrad          #+#    #+#             */
/*   Updated: 2025/07/15 18:38:54 by duandrad         ###   ########.fr       */
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