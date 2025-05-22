/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:14:54 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/13 16:55:32 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr)
		ft_bzero(ptr, size * nmemb);
	return (ptr);
}

/*  int main()
{
	char test[] = "hello";
	printf("%p", ft_calloc(__SIZE_MAX__, __SIZE_MAX__));
	printf("%p", calloc(__SIZE_MAX__, __SIZE_MAX__));
	return 0;
} */
