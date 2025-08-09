/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:47:06 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/08 02:56:19 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

static void	exit_error(t_shell *shell)
{
	t_str sh_id;
	t_str value;

	sh_id = "minishell";
	value = shell->cmd->args[1];
	perror(ERR_EXIT);
	printf("%s: %s: %s: %s", sh_id, "exit", value, ERR_EXIT);
	free_shell(shell);
	exit(2);
}

int	ft_exit(t_shell *shell)
{
	int	  i;
	t_str code;

	i = 0;
	code = shell->cmd->args[1];
	if (code[i] == '-')
		i++;
	while (ft_isdigit(code[i]))
		i++;
	if (code[i])
		exit_error(shell);
	free_shell(shell);
	exit(ft_atoi(code) % 256);
	return (EXIT_SUCCESS);
}
