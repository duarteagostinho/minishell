/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:47:10 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/11 17:07:51 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
# include <readline/readline.h>
# include <readline/history.h>
static void run_prompt()
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			return ;
		parser(line);
	}
}

int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	(void) env;
	run_prompt();
  	return 0;
}
