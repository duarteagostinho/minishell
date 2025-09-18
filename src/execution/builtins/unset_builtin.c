#include "minishell.h"

int	unset(t_shell *shell)
{
	int	  	i;
	t_vtr	vars;

	i = 0;
	vars = shell->cmd->args;
	printf("%i\n", get_sizeof_args(shell->env));
	while (vars[++i])
	{
		printf("1\n");
		if (is_valid_id(vars[i])
		|| rmv_env_var(shell->env, vars[i]))
			return (EXIT_FAILURE);
	}
	printf("%i\n", get_sizeof_args(shell->env));
	return (EXIT_SUCCESS);
}
