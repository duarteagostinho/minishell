/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:06:07 by duandrad          #+#    #+#             */
/*   Updated: 2024/10/29 13:59:08 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* int main()
{
	char test[] = "hello!";
	ft_bzero(test, 6);
	for (int i = 0; i < 6; i++)
		printf("%d", test[i]);
	return 0;
} */