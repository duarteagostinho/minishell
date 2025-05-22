/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printupx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:35:42 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/18 16:25:22 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printupx(unsigned long nbr)
{
	int		count;
	char	*symbs;

	symbs = "0123456789ABCDEF";
	count = 0;
	if (nbr < 16)
		return (printchar(symbs[nbr]));
	else
	{
		count = printupx(nbr / 16);
		return (count + printupx(nbr % 16));
	}
}
