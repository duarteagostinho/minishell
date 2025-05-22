/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:22:47 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/06 15:28:31 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_dig(int n)
{
	size_t	i;

	i = 1;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	digits;
	char	*string;

	nbr = n;
	digits = count_dig(n);
	if (n < 0)
	{
		digits++;
		nbr *= -1;
	}
	string = (char *)malloc(digits + 1);
	if (!string)
		return (NULL);
	string[digits] = '\0';
	while (digits--)
	{
		string[digits] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		string[0] = '-';
	return (string);
}
/* #include <limits.h>
int main()
{
	printf("%s\n", ft_itoa(1904));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-1904));
	return 0;
} */