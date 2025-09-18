/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:40:54 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/18 17:22:01 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../lib/minishell.h"

static void	parent_sig_handler(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_replace_line(NULL, 0);
	rl_on_new_line();
	rl_redisplay();
}

void  signal_setup(t_shell *shell, int process)
{
	if (process == PARENT)
    {
        shell->in_child = 0;
        shell->sig.sa_handler = parent_sig_handler;
        sigemptyset(&shell->sig.sa_mask);
        shell->sig.sa_flags = SA_RESTART;
        sigaction(SIGINT, &shell->sig, NULL);
        shell->sig.sa_handler = SIG_IGN;
        sigaction(SIGQUIT, &shell->sig, NULL);
    }
    else if (process == CHILD)
    {
        shell->in_child = 1;
        shell->sig.sa_handler = SIG_DFL;
        sigemptyset(&shell->sig.sa_mask);
        shell->sig.sa_flags = 0;
        sigaction(SIGINT, &shell->sig, NULL);
        sigaction(SIGQUIT, &shell->sig, NULL);
    }
    else if (process == IGNORE)
    {
        shell->in_child = 0;
        shell->sig.sa_handler = SIG_IGN;
        sigemptyset(&shell->sig.sa_mask);
        shell->sig.sa_flags = 0;
        sigaction(SIGINT, &shell->sig, NULL);
        sigaction(SIGQUIT, &shell->sig, NULL);
    }
}
