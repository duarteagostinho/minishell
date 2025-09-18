#include "minishell.h"

int	env(t_shell *shell)
{
	int		i;

	i = -1;
	if (get_sizeof_args(shell->cmd->args) < 1)
		return (EXIT_FAILURE);
	while (shell->env[++i])
		printf("%s\n", shell->env[i]);
	return (EXIT_SUCCESS);
}
