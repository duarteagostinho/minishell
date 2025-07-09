/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:41:25 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/06/15 15:38:41 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

int	ft_export(t_shell *shell, char **args)
{
	if (!shell->env->head)
		return (EXIT_FAILURE);
	if (get_sizeof_args(args) == 1)
		return (export_no_args(shell));
	else if (get_sizeof_args(args) > 1)
		return (export_args(shell, args));
	return (EXIT_FAILURE);
}

int	export_args(t_shell *shell, char **args)
{
	if (!shell->env->head)
		return (EXIT_FAILURE);
	while (*args)
	{
		exporting(shell, *args++);
		if (shell->exit_status == 1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	export_no_args(t_shell *shell)
{
	char  *data[2];

	if (!shell->env->head)
		return (EXIT_FAILURE);
	data[0] = shell->env->head->key;
	data[1] = shell->env->head->value;
	while (shell->env->head)
	{
		if (shell->env->head->is_exported == 1)
			printf("declare -x %s=\"%s\"\n", data[0], data[1]);
		shell->env->head = shell->env->head->next;
	}
	return (EXIT_SUCCESS);
}

void  exporting(t_shell *shell, char *arg)
{
	t_env_node	*new_var;

	if (!shell->env->head || !arg || !split_var(arg))
		shell->exit_status = 1;
	if (!get_node(shell->env, *(split_var(arg))))
	{
		new_var = create_env_node(arg);
		if (!new_var)
		{
			shell->exit_status = 1;
			return ;
		}
		shell->env->head->next = new_var;
		shell->env->head->next->is_exported = 1;
	}
}
