/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:43:32 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 19:44:37 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_shell *shell, t_cmd *cmd)
{
	int		i;
	t_vtr	vars;
	int		ret;

	i = 0;
	ret = EXIT_SUCCESS;
	vars = cmd->args;
	while (vars[++i])
	{
		if (!is_valid_id(cmd, vars[i]))
		{
			ret = EXIT_FAILURE;
			continue ;
		}
		if (get_env_val(shell->env, vars[i]))
			rmv_env_var(&shell->env, vars[i]);
		if (get_env_val(shell->exports, vars[i]))
			rmv_env_var(&shell->exports, vars[i]);
	}
	return (ret);
}
