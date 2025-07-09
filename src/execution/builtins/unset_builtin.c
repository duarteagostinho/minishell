/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:43:32 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/07/09 13:26:22 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
void	del_var(t_shell *shell, t_str arg)
{
	t_env_node	*dummy;
	t_env_node	*current;
	t_env_node	*temp;

	dummy = malloc(sizeof(t_env_node));
	dummy->next = shell->env->head;
	current = dummy;
	while (current->next)
	{
		if (!ft_strcmp(arg, current->next->key))
		{
			temp = current->next->next;
			free(current->next);
			current->next = temp;
			break ;
		}
		current = current->next;
	}
	shell->env->head = dummy->next;
	free(dummy);
}

void	unset_arg(t_shell *shell, t_str arg, t_arr fails)
{
	if (arg && (ft_isalpha(*arg) || *arg == '_'))
		del_var(shell, arg);
	else
		fails++;
}

int	unset(t_shell *shell, t_vtr args)
{
	int	fails;

	fails = 0;
	while (++args)
		unset_arg(shell, *args, &fails);
	if (fails > 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}*/