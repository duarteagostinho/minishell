/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:40:54 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/02 14:02:38 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parent_sig_handler(int signal)
{
	(void)signal;
	shell()->exit_status = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_setup(t_shell *shell, int process)
{
	if (process == PARENT)
	{
		shell->in_child = 0;
		signal(SIGINT, parent_sig_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (process == CHILD)
	{
		shell->in_child = 1;
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (process == IGNORE)
	{
		shell->in_child = 0;
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
