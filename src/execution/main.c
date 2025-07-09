#include "minishell.h"

char	*_get_cwd()
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
		return (NULL);
	return (path);
}

static void	run_prompt(void)
{
	char	*line;

	while (1)
	{
		printf(COLOR_RESET GRN"%s"COLOR_RESET, _get_cwd());
		line = readline(PRP" $> "WHT);
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
