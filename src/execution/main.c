#include "../../lib/minishell.h"

static void	run_prompt(void)
{
	t_str prompt;

	while (1)
	{
		printf(COLOR_RESET GRN"%s"COLOR_RESET, getcwd(NULL, 0));
		prompt = readline(PRP" $> "WHT);
		if (!prompt)
			return ;
		parser(prompt);
	}
}

int	main(int ac, t_vtr av, t_vtr env)
{
	(void) av;
	(void) env;
	if (ac == 1)
		run_prompt();
	else
		return (write(2, "Too many arguments!\n", 20));
	return (0);
}
