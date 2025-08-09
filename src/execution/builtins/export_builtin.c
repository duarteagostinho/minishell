/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:41:25 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/07 23:29:47 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

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
	int	i;

	i = -1;
	if (!shell->env || !*shell->env)
		return (EXIT_FAILURE);
	while (args[++i])
	{
		if (!exporting(shell, args[i]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	export_no_args(t_shell *shell)
{
	int	  i;
	t_vtr var;

	i = -1;
	if (!shell->exports || !*shell->exports)
		return (EXIT_FAILURE);
	while (shell->exports[++i])
	{
		var = ft_split(shell->exports[i], '=');
		if (!var)
			return (EXIT_FAILURE);
		printf("declare -x %s=\"%s\"\n", var[0], var[1]);
		free(var);
	}
	return (EXIT_SUCCESS);
}

int  exporting(t_shell *shell, t_str arg)
{
	t_vtr var;

	var = ft_split(arg, '=');
	if (!shell->env || !*shell->env || !arg || !*arg || !var || !is_valid_id(var[0]))
		return (EXIT_FAILURE);
	if (!add_env_var(shell->env, var[0], var[1]) || !add_env_var(shell->exports, var[0], var[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
