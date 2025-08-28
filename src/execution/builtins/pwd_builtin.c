#include "minishell.h"

int	get_sizeof_args(t_vtr args)
{
	int	size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

int	pwd(t_shell *shell)
{
	t_str pwd;

	(void)shell;
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (EXIT_FAILURE);
	printf("%s\n", pwd);
	free(pwd);
	return (EXIT_SUCCESS);
}
