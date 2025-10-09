/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:41:25 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 15:48:51 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_sorted(t_vtr env)
{
	int		i;

	i = -1;
	while (env[++i] && env[i + 1])
	{
		if (ft_strcmp(env[i], env[i + 1]) > 0)
			return (0);
	}
	return (1);
}

void	sort_env(t_vtr *env)
{
	int		i;
	int		swapped;

	while (!is_sorted(*env))
	{
		i = -1;
		swapped = 0;
		while ((*env)[++i] && (*env)[i + 1])
		{
			if (ft_strcmp((*env)[i], (*env)[i + 1]) > 0)
			{
				ft_swap((void *)&(*env)[i], (void *)&(*env)[i + 1]);
				swapped = 1;
			}
		}
		if (!swapped)
			break ;
	}
}

int	export_args(t_shell *shell, t_cmd *cmd, t_vtr args)
{
	int		i;
	t_str	tmp;
	t_vtr	var;

	i = 0;
	while (args[++i])
	{
		if (ft_strchr(args[i], '='))
		{
			var = ft_split(args[i], '=');
			if (!var || (!*var && !is_valid_id(cmd, args[i])))
				return (free_vtr(var), EXIT_FAILURE);
			if (!is_valid_id(cmd, var[0]))
				return (free_vtr(var), EXIT_FAILURE);
			add_env_var(&shell->env, var[0], ft_strdup(args[i]));
			add_env_var(&shell->exports, var[0], ft_strdup(args[i]));
			free_vtr(var);
		}
		else if (is_valid_id(cmd, args[i]))
		{
			tmp = ft_strdup(args[i]);
			add_env_var(&shell->exports, args[i], tmp);
		}
	}
	return (EXIT_SUCCESS);
}

int	export_no_args(t_shell *shell, int out)
{
	int		i;
	t_vtr	var;

	i = -1;
	sort_env(&shell->exports);
	while (shell->exports[++i])
	{
		if (ft_strchr(shell->exports[i], '='))
		{
			var = ft_split(shell->exports[i], '=');
			if (!var)
				return (EXIT_FAILURE);
			print_export(var, out, 1, get_sizeof_args(var));
			free_vtr(var);
		}
		else
			print_export(&shell->exports[i], out, 0, 0);
	}
	return (EXIT_SUCCESS);
}

int	ft_export(t_shell *shell, t_cmd *cmd, int out)
{
	if (!shell->exports || !*shell->exports)
		return (EXIT_FAILURE);
	if (get_sizeof_args(cmd->args) == 1)
		return (export_no_args(shell, out));
	else if (get_sizeof_args(cmd->args) > 1)
		return (export_args(shell, cmd, cmd->args));
	return (EXIT_FAILURE);
}
