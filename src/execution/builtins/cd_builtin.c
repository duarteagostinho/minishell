#include "minishell.h"

int	update_pwd(t_shell *shell, t_str lwd, t_str cwd)
{
	t_vtr env;

	env = shell->env;
	if (!add_env_var(env, "PWD", cwd) || !add_env_var(env, "OLDPWD", lwd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);	
}

int	cd_no_args(t_shell *shell)
{
	t_str		cwd;
	t_str		home;

	cwd = getcwd(NULL, 0);
	home = get_env_val(shell->env, "HOME");
	if (!home || chdir(home) == -1)
		return (EXIT_FAILURE);
	return (free(home), update_pwd(shell, cwd, getcwd(NULL, 0)));
}

int	cd(t_shell *shell)
{
	t_str cwd;

	cwd = getcwd(NULL, 0);
	if (get_sizeof_args(shell->cmd->args) == 1)
		return (cd_no_args(shell));
	else if (get_sizeof_args(shell->cmd->args) == 2)
	{
		if (chdir(shell->cmd->args[1]) == -1)
			return (EXIT_FAILURE);
		return (update_pwd(shell, cwd, getcwd(NULL, 0)));
	}
	return (EXIT_FAILURE);
}
