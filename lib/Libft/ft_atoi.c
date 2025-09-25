/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:01:05 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/21 23:54:09 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nbr)
{
	int	res;
	int	sgn;

	res = 0;
	sgn = 1;
	while (*nbr == ' ' || (*nbr >= '\t' && *nbr <= '\r'))
		nbr++;
	if (*nbr == '+' || *nbr == '-')
	{
		sgn = (*nbr == '+') - (*nbr == '-');
		nbr++;
	}
	while (ft_isdigit(*nbr))
	{
		res = (res * 10) + (*nbr - '0');
		nbr++;
	}
	return (res * sgn);
}
