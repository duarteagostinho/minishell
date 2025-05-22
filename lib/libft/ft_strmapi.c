/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duarte <duarte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:04:22 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/07 13:54:28 by duarte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*source;
	char	*mapi;

	i = 0;
	source = (char *) s;
	if (!s)
		return (NULL);
	mapi = malloc(ft_strlen(source) + 1);
	if (!mapi)
		return (NULL);
	while (source[i])
	{
		mapi[i] = f(i, source[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
/* 
char fall(unsigned int l, char c)
{
	return (c + l);
}
int main()
{
	char test[] = "hello";
	printf("%s", ft_strmapi(test, fall));
} */