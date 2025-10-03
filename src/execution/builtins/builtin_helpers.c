/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:59:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/03 18:41:48 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	commands_size(t_cmd *cmd)
{
	t_cmd	*curr;
	int		size;

	curr = cmd;
	size = 0;
	while (curr && ++size)
		curr = curr->next;
	return (size);
}

void	ft_swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_valid_id(const t_str key)
{
	int	i;

	i = 0;
	if (!key || !key[i] || (!ft_isalpha(key[i]) && key[i] != '_'))
		return (EXIT_FAILURE);
	while (key[i] && (ft_isalnum(key[i]) || key[i] == '_'))
		i++;
	if (key[i] != '\0' && key[i] != '=')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	exec_builtin(t_shell *shell, t_cmd *cmd)
{
	if (!ft_strcmp("env", cmd->args[0]))
		return (env(shell));
	else if (!ft_strcmp("export", cmd->args[0]))
		return (ft_export(shell));
	else if (!ft_strcmp("exit", cmd->args[0]))
		return (ft_exit(shell));
	else if (!ft_strcmp("echo", cmd->args[0]))
		return (echo(shell));
	else if (!ft_strcmp("pwd", cmd->args[0]))
		return (pwd(shell));
	else if (!ft_strcmp("cd", cmd->args[0]))
		return (cd(shell));
	else if (!ft_strcmp("unset", cmd->args[0]))
		return (unset(shell));
	return (-1);
}
