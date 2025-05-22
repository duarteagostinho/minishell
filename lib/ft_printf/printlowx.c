/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlowx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:35:42 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/18 16:20:54 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printlowx(unsigned long nbr)
{
	int		count;
	char	*symbs;

	symbs = "0123456789abcdef";
	count = 0;
	if (nbr < 16)
		return (printchar(symbs[nbr]));
	else
	{
		count = printlowx(nbr / 16);
		return (count + printlowx(nbr % 16));
	}
}
