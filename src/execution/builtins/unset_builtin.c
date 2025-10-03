/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:43:32 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/03 13:17:59 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset(t_shell *shell)
{
	int		i;
	t_vtr	vars;

	i = 0;
	vars = shell->cmd->args;
	while (vars[++i])
	{
		if (is_valid_id(vars[i]))
			return (EXIT_FAILURE);
		shell->env = rmv_env_var(shell->env, vars[i]);
		if (!shell->env)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
