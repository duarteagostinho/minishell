/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:22:29 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/03 18:45:07 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_printf/ft_printf.h"
#include "lib/minishell.h"

int	pwd(void)
{
	char* curr_dir;

  curr_dir = getcwd(NULL, 0);
  if (!curr_dir)
    return (EXIT_FAILURE);
  ft_putstr_fd(curr_dir, 1);
  free(curr_dir);
  return (EXIT_SUCCESS);
}


int	main(int ac, vector av)
{
	char*	line;

	while (line = readline())
	{
		ft_printf("%s\n", line);
	}
}
