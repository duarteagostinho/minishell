/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:19:32 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/26 22:57:56 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

int	echo(t_shell *shell)
{
	int		i;
	t_vtr	args;

	i = 1;
	args = shell->cmd->args;
	if (get_sizeof_args(args) == 1)
		printf("\n");
	else if (get_sizeof_args(args) > 1)
	{
		while (args[i] && args[i][0] == '-'
		&& args[i][1] == 'n')
			i++;
		while (args[i])
		{
			printf("%s", args[i]);
			if (args[i + 1])
				printf(" ");
			i++;
		}
		if (args[1][0] != '-' && args[1][1] != 'n')
			printf("\n");
	}
	return (EXIT_SUCCESS);
}
