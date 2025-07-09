/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:19:32 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/07/09 13:18:04 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(t_vtr args)
{
	t_vtr current;
	int	  flags;

	flags = check_flag(args);
	current = args + flags;
	if (get_sizeof_args(args) == 1)
		write(1, "\n", 1);
	else if (get_sizeof_args(args) > 1)
	{
		while (*current)
		{
			printf("%s", *current);
			if (*(current + 1))
				printf(" ");
			current++;
		}
		if (flags == 0)
			printf("\n");
	}
	return (EXIT_SUCCESS);
}
