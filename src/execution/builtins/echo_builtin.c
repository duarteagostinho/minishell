/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:19:32 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/07 23:31:16 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

int	echo(t_shell *shell)
{
	t_vtr current;
	int	  flags;

	flags = check_flag(shell->cmd->args);
	current = shell->cmd->args + flags;
	if (get_sizeof_args(shell->cmd->args) == 1)
		write(1, "\n", 1);
	else if (get_sizeof_args(shell->cmd->args) > 1)
	{
		while (*current)
		{
			printf("%s", *current);
			if (*(current + 1))
				printf(" ");
			current++;
		}
		if (flags == 0)
			printf("\n");
	}
	return (EXIT_SUCCESS);
}
