/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:23:05 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/18 18:07:27 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void empty_env(t_shell *shell)
{
	t_str	cwd;

	cwd = getcwd(NULL, 0);
	add_env_var(shell->env, "PWD", cwd);
	add_env_var(shell->env, "SHLVL", "1");
	free(cwd);
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
		empty_env(shell());
	lvl_up(shell());
}
