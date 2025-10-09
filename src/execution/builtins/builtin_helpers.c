/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:59:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 15:35:30 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(t_vtr val, int out, int has_equal, int size)
{
	int	i;

	i = 0;
	ft_putstr_fd("declare -x ", out);
	ft_putstr_fd(val[0], out);
	if (!has_equal)
		return (ft_putchar_fd('\n', out));
	ft_putchar_fd('=', out);
	ft_putchar_fd('"', out);
	if (size > 0)
	{
		while (val[++i])
			ft_putstr_fd(val[i], out);
	}
	ft_putendl_fd("\"", out);
}

void	ft_swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_valid_id(t_cmd *cmd, const t_str key)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	if (!key || !key[i] || (!ft_isalpha(key[i]) && key[i] != '_'))
		error++;
	while (key[i] && (ft_isalnum(key[i]) || key[i] == '_'))
		i++;
	if (key[i] != '\0' && key[i] != '=')
		error++;
	if (error)
		return (cmd_error(cmd->args[0], key, 1), 0);
	return (1);
}

int	exec_builtin(t_shell *shell, t_cmd *cmd, int out)
{
	if (!ft_strcmp("env", cmd->args[0]))
		return (ft_env(shell, cmd, out));
	else if (!ft_strcmp("export", cmd->args[0]))
		return (ft_export(shell, cmd, out));
	else if (!ft_strcmp("exit", cmd->args[0]))
		return (ft_exit(shell, cmd));
	else if (!ft_strcmp("echo", cmd->args[0]))
		return (ft_echo(cmd, out));
	else if (!ft_strcmp("pwd", cmd->args[0]))
		return (ft_pwd(shell, out));
	else if (!ft_strcmp("cd", cmd->args[0]))
		return (ft_cd(shell, cmd));
	else if (!ft_strcmp("unset", cmd->args[0]))
		return (ft_unset(shell, cmd));
	return (-1);
}
