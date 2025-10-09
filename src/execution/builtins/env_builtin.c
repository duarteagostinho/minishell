/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:17:40 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 15:35:18 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_shell *shell, t_cmd *cmd, int out)
{
	int		i;

	i = -1;
	if (get_sizeof_args(cmd->args) < 1)
		return (EXIT_FAILURE);
	while (shell->env[++i])
		ft_putendl_fd(shell->env[i], out);
	return (EXIT_SUCCESS);
}
