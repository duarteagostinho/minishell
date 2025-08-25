/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:43:32 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/25 16:32:36 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

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
