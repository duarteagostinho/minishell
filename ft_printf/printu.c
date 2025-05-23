/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:36:10 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/17 21:24:19 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printu(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
		count += printchar(n + '0');
	else
	{
		count += printu(n / 10);
		count += printu(n % 10);
	}
	return (count);
}
