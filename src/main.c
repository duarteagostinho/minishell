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
	int i;
  char  *prompt;

  i = 0;
  (void) ac;
  prompt = NULL;
  while(av[i])
  {
    prompt = readl_prompt(av[1]);
    ft_printf("prompt = %s\n", prompt);
    i++;
  }
  return 0;
}
