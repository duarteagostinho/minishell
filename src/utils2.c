/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:44:00 by duandrad          #+#    #+#             */
/*   Updated: 2025/05/27 11:44:29 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

bool	is_token(char to_check)
{
	if (to_check == '<' || to_check == '>' || to_check == '|')
		return (true);
	return (false);
}

bool	close_outputfile(int fd)
{
	if (close(fd) == 0)
		return (true);
	else
		return (false);
}


int	pwd(void)
{
	string curr_dir;

  curr_dir = getcwd(NULL, 0);
  if (!curr_dir)
    return (EXIT_FAILURE);
  ft_putstr_fd(curr_dir, 1);
  free(curr_dir);
  return (EXIT_SUCCESS);
}

bool  is_arg_nbr(string arg)
{
  int i;

  i = 0;
  while (arg[i] == '-' || arg[i] == '+')
    i++;
  while (arg[i])
  {
    if (ft_isdigit(arg[i]) != 0)
      return (false);
    i++;
  }
  return (true);
}

