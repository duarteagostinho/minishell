/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:09:54 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 17:03:33 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_error(t_shell *shell, int error)
{
	if (!shell->in_child)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		if (error == 1)
		{
			shell->exit_status = 1;
			return (ft_putendl_fd("too many arguments", 2));
		}
		ft_putstr_fd(shell->cmd->args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
	}
	free_shell(shell);
	exit(2);
}

void	open_error(t_str filename, int error)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(filename, 2);
	if (error == 1)
	{
		if (shell()->exit_status != 127)
			shell()->exit_status = 1;
		return (ft_putendl_fd(": No such file or directory", 2));
	}
	ft_putendl_fd(": Permission denied", 2);
}

void	cmd_error(t_str cmd, t_str arg, int error)
{
	shell()->exit_status = 1;
	if (!ft_strncmp(cmd, "./", 2) || *cmd == '/')
	{
		shell()->exit_status = 127;
		return (open_error(cmd, 1));
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (error == 1)
	{
		ft_putstr_fd(": \"", 2);
		ft_putstr_fd(arg, 2);
		return (ft_putendl_fd("\": not a valid identifier", 2));
	}
	if (error == 2)
		return (ft_putendl_fd(": too many arguments", 2));
	if (error == 3)
	{
		shell()->exit_status = 127;
		return (ft_putendl_fd(": command not found", 2));
	}
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(arg, 2);
}
