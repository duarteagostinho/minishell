/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:17:40 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/25 19:07:27 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(t_shell *shell)
{
	int		i;

	i = -1;
	if (get_sizeof_args(shell->cmd->args) < 1)
		return (EXIT_FAILURE);
	while (shell->env[++i])
		printf("%s\n", shell->env[i]);
	return (EXIT_SUCCESS);
}
