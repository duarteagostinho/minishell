/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:00:57 by duandrad          #+#    #+#             */
/*   Updated: 2024/10/31 12:40:54 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	str = (char *) s;
	i = ft_strlen(str);
	while (i + 1)
	{
		if (str[i] == (char) c)
			return (str + i);
		else
			i--;
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}
/* int main()
{
	char test[] = "helloamigo";
	printf(";%s;\n", ft_strrchr(test, 'z'));
	printf(";%s;\n", strrchr(test, 'z'));
	return (0);
} */