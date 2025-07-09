/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:17:40 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/06/09 21:22:38 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

int	env(t_shell *shell, t_vtr args)
{
	t_env_node	*current;

	current = shell->env->head;
	if (get_sizeof_args(args) != 0)
		return (EXIT_FAILURE);
	else
	{
		while (current)
		{
			printf("%s=%s\n", current->key, current->value);
			current = current->next;
		}
	}
	return (EXIT_SUCCESS);
}
