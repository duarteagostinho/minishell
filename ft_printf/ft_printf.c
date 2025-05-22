/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:19:32 by duandrad          #+#    #+#             */
/*   Updated: 2024/11/20 18:52:54 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char type, va_list *pt)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += printchar(va_arg(*pt, int));
	else if (type == 's')
		count += printstr(va_arg(*pt, char *));
	else if (type == 'p')
		count += printptr(va_arg(*pt, void *));
	else if (type == 'd' || type == 'i')
		count += printdig((long)va_arg(*pt, int));
	else if (type == 'u')
		count += printu(va_arg(*pt, unsigned int));
	else if (type == 'x')
		count += printlowx((long)va_arg(*pt, unsigned int));
	else if (type == 'X')
		count += printupx((long)va_arg(*pt, unsigned int));
	else if (type == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	pt;
	int		ret;

	if (!format)
		return (-1);
	va_start(pt, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ret = print_format(*(++format), &pt);
			if (ret < 0)
				return (-1);
			count += ret;
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(pt);
	return (count);
}
