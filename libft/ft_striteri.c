/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:59:15 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/12 18:52:54 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}

/* void f(unsigned int n, char *str)
{
	*str += n;
} */

/* 
int main()
{
	char *test = "hello";
	ft_striteri(test, f);
	printf("%s", test);
	return 0;
} */
/* int main(void)
{
	char s[] = "";
	ft_striteri(s, f);	
	printf("%s\n", s);
	char s1[] = "0";
	ft_striteri(s1, f);
	printf("%s\n", s1);
	char s2[] = "0000000000";
	ft_striteri(s2, f);
	printf("%s\n", s2);
	return (0);
*/