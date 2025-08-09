/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:43:32 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/07 23:22:59 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

int	unset(t_shell *shell)
{
	int	  i;
	t_vtr var;

	i = -1;
	while (shell->cmd->args[++i])
	{
		var = ft_split(shell->cmd->args[i], '=');
		if (!var || !rmv_env_var(shell->env, var[0]))
			return (EXIT_FAILURE);
		free(var);
	}
	return (EXIT_SUCCESS);
}
