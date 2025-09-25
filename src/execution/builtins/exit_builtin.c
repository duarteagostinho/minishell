/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:47:06 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/25 16:48:11 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_error(t_shell *shell, int error)
{
	if (!shell->in_child)
	{	
		ft_putstr_fd("minishell: exit: ", 2);
		if (error == 1)
		{
			ft_putstr_fd("too many arguments\n", 2);
			return ;
		}
		ft_putstr_fd(shell->cmd->args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
	}
	free_shell(shell);
	exit(2);
}

static int	exit_code(t_shell *shell)
{
	int		i;
	t_str	code;

	i = 0;
	if (!shell->cmd->args[1] || shell->in_child)
		return (shell->exit_status);
	code = shell->cmd->args[1];
	if (code[i] == '-' || code[i] == '+')
		i++;
	while (ft_isdigit(code[i]))
		i++;
	if (code[i])
		exit_error(shell, 0);
	return (ft_atoi(code) % 256);
}

int	ft_exit(t_shell *shell)
{
	int	code;

	if (!shell->in_child)
		printf("exit\n");
	if (!shell->cmd)
		return (free_shell(shell), exit(0), EXIT_SUCCESS);
	if (get_sizeof_args(shell->cmd->args) > 2
	&& !ft_strncmp(shell->cmd->args[0], "exit", 5))
		return (exit_error(shell, 1), EXIT_FAILURE);
	code = exit_code(shell);
	free_shell(shell);
	exit(code);
	return (EXIT_SUCCESS);
}
