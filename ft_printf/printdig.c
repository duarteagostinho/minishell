/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:35:42 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/17 21:22:49 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printdig(long nbr)
{
	int		count;
	char	*symbs;

	symbs = "0123456789";
	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (printdig(-nbr) + 1);
	}
	else if (nbr < 10)
		return (printchar(symbs[nbr]));
	else
	{
		count = printdig(nbr / 10);
		return (count + printdig(nbr % 10));
	}
}
