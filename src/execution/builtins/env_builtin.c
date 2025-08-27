/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:17:40 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/07 23:30:12 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

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
