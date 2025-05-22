/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:34:30 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/18 18:23:12 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (printstr("(nil)"));
	count = printstr("0x");
	count += printlowx((unsigned long)ptr);
	return ((unsigned long)count);
}
