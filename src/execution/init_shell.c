#include "minishell.h"

static void  lvl_up(t_shell *shell)
{
	int	  sh_lvl;
	t_str new_lvl;

	sh_lvl = ft_atoi(get_env_val(shell->env, "SHLVL"));
	new_lvl = ft_itoa(++sh_lvl);
	add_env_var(shell->env, "SHLVL", new_lvl);
	free(new_lvl);
}

static void empty_env(t_vtr env)
{
	add_env_var(env, "PWD", getcwd(NULL, 0));
	add_env_var(env, "SHLVL", "1");
}

void  init_shell(t_vtr env)
{
	int	  i;

	i = -1;
	if (env && *env)
	{
		shell()->env = ft_calloc(get_sizeof_args(env) + 1, sizeof(t_str));
		while (env[++i])
			shell()->env[i] = ft_strdup(env[i]);
	}
	else
		empty_env(shell()->env);
	lvl_up(shell());
}
