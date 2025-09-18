#include "minishell.h"

static void	parent_sig_handler(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_replace_line(NULL, 0);
	rl_on_new_line();
	rl_redisplay();
}

void  signal_setup(int process)
{
	if (process == PARENT)
	{
		signal(SIGINT, parent_sig_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (process == CHILD)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (process == IGNORE)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
