/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:47:10 by duandrad          #+#    #+#             */
/*   Updated: 2025/03/03 15:01:35 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int ac, char **av)
{
	int i = 0;
	char **builtins = ft_split(av[1], ' ');
	
	if (ac == 2)
	{
		while (builtins[i])
		{
			ft_printf(BHGRN"%s\n", builtins[i]);
			i++;
		}
	}
}
