/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:44:45 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/21 23:57:08 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nbr)
{
	char	*str;
	char	arr[11];
	int		i;
	int		sgn;

	i = 11;
	sgn = (nbr > 0) - (nbr < 0);
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		arr[--i] = (nbr % 10) * sgn + '0';
		nbr /= 10;
	}
	if (sgn < 0)
		arr[--i] = '-';
	str = ft_calloc((11 - i) + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (ft_memcpy(str, arr + i, (11 - i)));
}
