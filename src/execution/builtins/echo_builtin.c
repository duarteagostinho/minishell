#include "minishell.h"

int	echo(t_shell *shell)
{
	int		i;
	t_vtr	args;

	i = 1;
	args = shell->cmd->args;
	if (get_sizeof_args(args) == 1)
	{
		write(1, "\n", 1);
		return (EXIT_SUCCESS);
	}
	else if (get_sizeof_args(args) > 1)
	{
		printf("i = %d\n", i);
		while (args[i][0] == '-' && args[i][1] == 'n')
			i++;
		while (args[i])
		{
			printf("%s", args[i]);
			if (args[i + 1])
				printf(" ");
			i++;
		}
		if (args[1][0] != '-' && args[1][1] != 'n')
			printf("\n");
	}
	return (EXIT_SUCCESS);
}
