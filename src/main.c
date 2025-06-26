#include "minishell.h"

char	*_get_cwd()
{
	char	*path;

	getcwd(path, )
}

static void	run_prompt(void)
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

int	main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	(void) env;
	run_prompt();
	return (0);
}
