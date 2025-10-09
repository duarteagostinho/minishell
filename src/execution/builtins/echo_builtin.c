/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:19:32 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 16:57:41 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_flags(t_vtr args)
{
	int	i;
	int	j;
	int	flags;

	i = 0;
	flags = 0;
	while (args[++i])
	{
		j = 0;
		if (args[i][j] == '-')
			j++;
		else
			break ;
		while (args[i][j] == 'n')
			j++;
		if (!args[i][j])
			flags++;
		else
			break ;
	}
	return (flags);
}

int	ft_echo(t_cmd *cmd, int out)
{
	int		i;
	int		has_flags;

	if (get_sizeof_args(cmd->args) == 1)
		return (ft_putchar_fd('\n', out), EXIT_SUCCESS);
	has_flags = check_flags(cmd->args);
	i = 1 + has_flags;
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i], out);
		if (cmd->args[i + 1])
			ft_putchar_fd(' ', out);
		i++;
	}
	if (!has_flags)
		ft_putchar_fd('\n', out);
	return (EXIT_SUCCESS);
}
