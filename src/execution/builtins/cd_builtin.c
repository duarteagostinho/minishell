/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:35:35 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/15 15:50:07 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

void	update_old(t_shell *shell, t_str pos)
{
	t_env_node	*current;

	current = shell->env->head;
	while (current)
	{
		if (!ft_strcmp(current->key, "OLDPWD"))
		{
			current->value = pos;
			break ;
		}
		current = current->next;
	}
	if (current)
		shell->exit_status = 1;
}

int	env_var_update(t_shell *shell, t_str pre, t_str pos)
{
	t_env_node	*current;

	current = shell->env->head;
	while (current)
	{
		if (!ft_strcmp(current->key, "PWD"))
		{
			current->value = pos;
			break ;
		}
		current = current->next;
	}
	update_old(shell, pre);
	if (!current || shell->exit_status != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	cd_no_args(t_shell *shell)
{
	t_env_node	*current;
	t_str		pos;

	current = shell->env->head;
	pos = getcwd(NULL, 0);
	while (current)
	{
		if (!ft_strcmp(current->key,"$HOME"))
		{
			if (chdir(current->value) == -1)
				return (EXIT_FAILURE);
			break ;
		}
		current = current->next;
	}
	if (current)
		return (env_var_update(shell, pos, getcwd(NULL, 0)));
	return (EXIT_FAILURE);
}

int	cd(t_shell *shell, t_vtr args)
{
	t_str pos;

	pos = getcwd(NULL, 0);
	if (get_sizeof_args(args) == 1)
		return (cd_no_args(shell));
	else if (get_sizeof_args(args) == 2)
	{
		if (chdir(++*args) == -1)
			return (EXIT_FAILURE);
		env_var_update(shell, pos, getcwd(NULL, 0));
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
