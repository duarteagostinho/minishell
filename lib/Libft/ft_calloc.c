/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:35:53 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/25 22:29:37 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmb, size_t sz)
{
	void	*res;

	if ((nmb * sz) / nmb != sz)
		return (NULL);
	res = malloc(nmb * sz);
	if (!res)
		return (NULL);
	ft_memset(res, '\0', nmb * sz);
	return (res);
}
