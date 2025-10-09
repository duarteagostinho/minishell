/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:47:06 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 19:34:57 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_code(t_shell *shell, t_cmd *cmd)
{
	int		i;
	t_str	code;

	i = 0;
	if (!cmd->args || ft_strncmp(cmd->args[0], "exit", 5)
		|| !cmd->args[1] || shell->in_child)
		return (shell->exit_status);
	code = cmd->args[1];
	if (code[i] == '-' || code[i] == '+')
		i++;
	while (ft_isdigit(code[i]))
		i++;
	if (i > 19 || code[i])
		exit_error(shell, 0);
	return (ft_atoi(code) % 256);
}

int	ft_exit(t_shell *shell, t_cmd *cmd)
{
	int	code;

	if (!shell->in_child)
		printf("exit\n");
	if (!shell->cmd)
		return (free_shell(shell), exit(0), EXIT_SUCCESS);
	code = exit_code(shell, cmd);
	if (get_sizeof_args(cmd->args) > 2
		&& !ft_strncmp(cmd->args[0], "exit", 5))
		return (exit_error(shell, 1), EXIT_FAILURE);
	(close(2), close(1), close(0));
	destroy_fds();
	free_shell(shell);
	exit(code);
	return (EXIT_SUCCESS);
}
