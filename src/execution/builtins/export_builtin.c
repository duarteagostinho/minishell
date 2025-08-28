#include "minishell.h"

static int		is_sorted(t_vtr env)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (env[++i] && env[i + 1])
	{
		j = i + 1;
		while (env[++j])
		{
			len = 1;
			while (!ft_strncmp(env[i], env[j], len))
				len++;
			if (ft_strncmp(env[i], env[j], ++len) > 0)
				return (0);
		}
	}
	return (1);
}

static t_vtr	sort_env(t_vtr env)
{
	int		i;
	int		j;
	int		len;

	while (!is_sorted(env))
	{
		i = -1;
		while (env[++i] && env[i + 1])
		{
			j = i + 1;
			while (env[++j])
			{
				len = 1;
				while (!ft_strncmp(env[i], env[j], len))
					len++;
				if (ft_strncmp(env[i], env[j], len) > 0)
					ft_swap((void *)&env[i], (void *)&env[j]);
			}
		}
	}
	return (env);
}

int	ft_export(t_shell *shell)
{
	if (!shell->env || !*shell->env)
		return (EXIT_FAILURE);
	if (get_sizeof_args(shell->cmd->args) == 1)
		return (export_no_args(shell));
	else if (get_sizeof_args(shell->cmd->args) > 1)
		return (export_args(shell, shell->cmd->args));
	return (EXIT_FAILURE);
}

int	export_args(t_shell *shell, t_vtr args)
{
	int		i;
	t_vtr	var;

	i = 0;
	printf("%i\n", get_sizeof_args(shell->env));
	while (args[++i])
	{
		printf("b\n");
		var = ft_split(args[i], '=');
		if (is_valid_id(var[0])
		|| add_env_var(shell->env, var[0], var[1]))
			return (EXIT_FAILURE);
		free_vtr(var);
	}
	printf("%i\n", get_sizeof_args(shell->env));
	return (EXIT_SUCCESS);
}

int	export_no_args(t_shell *shell)
{
	int		i;
	t_vtr	var;
	t_vtr	exports;

	i = -1;
	exports = ft_calloc(get_sizeof_args(shell->env) + 1, sizeof(t_str));
	while (shell->env[++i])
		exports[i] = ft_strdup(shell->env[i]);
	i = -1;
	exports = sort_env(exports);
	while (exports[++i])
	{
		var = ft_split(exports[i], '=');
		if (!var)
			return (EXIT_FAILURE);
		printf("declare -x %s=\"%s\"\n", var[0], get_env_val(exports, var[0]));
		free_vtr(var);
	}
	free_vtr(exports);
	return (EXIT_SUCCESS);
}
