/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:23:05 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 18:48:30 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lvl_up(t_shell *shell)
{
	int		lvl;
	t_str	tmp;
	t_str	sh_lvl;
	t_str	new_lvl;

	lvl = ft_atoi(get_env_val(shell->env, "SHLVL"));
	sh_lvl = ft_strdup("SHLVL=");
	tmp = ft_itoa(++lvl);
	new_lvl = ft_str_add(&sh_lvl, tmp);
	free(tmp);
	add_env_var(&shell->env, "SHLVL", new_lvl);
}

static void	empty_env(t_shell *shell)
{
	t_str	cwd;
	t_str	pwd;
	t_str	shlvl;

	shell->env = ft_calloc(3, sizeof(t_str));
	shell->exports = ft_calloc(3, sizeof(t_str));
	cwd = getcwd(NULL, 0);
	pwd = ft_strdup("PWD=");
	pwd = ft_str_add(&pwd, cwd);
	shlvl = ft_strdup("SHLVL=1");
	add_env_var(&shell->env, "PWD", pwd);
	add_env_var(&shell->env, "SHLVL", shlvl);
	free(cwd);
}

void	init_shell(t_vtr env)
{
	int	i;
	int	j;

	i = -1;
	if (env && *env)
	{
		shell()->env = ft_calloc(get_sizeof_args(env) + 1, sizeof(t_str));
		shell()->exports = ft_calloc(get_sizeof_args(env), sizeof(t_str));
		while (env[++i])
			shell()->env[i] = ft_strdup(env[i]);
		shell()->home = get_env_val(env, "HOME");
		shell()->path = get_env_val(env, "PATH");
	}
	else
		empty_env(shell());
	lvl_up(shell());
	i = -1;
	j = -1;
	while (shell()->env[++i])
	{
		if (ft_strncmp(shell()->env[i], "_=", 2))
			shell()->exports[++j] = ft_strdup(shell()->env[i]);
	}
}
