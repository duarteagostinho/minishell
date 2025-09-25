/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:59:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/25 12:15:20 by mrapp-he         ###   ########.fr       */
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
	void *tmp;

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

int	exec_command(t_shell *shell, t_cmd *cmd)
{
	size_t	size;

	size = ft_strlen(cmd->args[0]);
	if (!ft_strncmp("env", cmd->args[0], size))
		return (env(shell));
	else if (!ft_strncmp("export", cmd->args[0], size))
		return (ft_export(shell));
	else if (!ft_strncmp("exit", cmd->args[0], size))
		return (ft_exit(shell));
	else if (!ft_strncmp("echo", cmd->args[0], size))
		return (echo(shell));
	else if (!ft_strncmp("pwd", cmd->args[0], size))
		return (pwd(shell));
	else if (!ft_strncmp("cd", cmd->args[0], size))
		return (cd(shell));
	else if (!ft_strncmp("unset", cmd->args[0], size))
		return (unset(shell));
	return (-1);
}
