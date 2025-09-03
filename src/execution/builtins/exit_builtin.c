/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:47:06 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/20 16:17:09 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

static void	exit_error(t_shell *shell)
{
	t_str	value;

	value = shell->cmd->args[1];
	printf("minishell: exit: %s: %s", value, ERR_EXIT);
	free_shell(shell);
	exit(2);
}

static int	exit_code(t_shell *shell)
{
	int		i;
	t_str	code;

	i = 0;
	if (!shell->cmd->args[1])
		return (shell->exit_status);
	code = shell->cmd->args[1];
	if (code[i] == '-' || code[i] == '+')
		i++;
	while (ft_isdigit(code[i]))
		i++;
	if (code[i])
		exit_error(shell);
	return (ft_atoi(code) % 256);
}

int	ft_exit(t_shell *shell)
{
	int	code;

	printf("exit\n");
	if (shell->cmd->args[1] && shell->cmd->args[2])
	{
		printf("minishell: exit: too many arguments\n");
		return (EXIT_FAILURE);
	}
	code = exit_code(shell);
	free_shell(shell);
	exit(code);
	return (EXIT_SUCCESS);
}
