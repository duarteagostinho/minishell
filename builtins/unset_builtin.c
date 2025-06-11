/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:43:32 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/06/03 18:48:59 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

void	del_var(t_shell *shell, char *arg)
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

void	unset_arg(t_shell *shell, char *arg, int *fails)
{
	if (arg && (ft_isalpha(*arg) || *arg == '_'))
		del_var(shell, arg);
	else
		fails++;
}

int	unset(t_shell *shell, char **args)
{
	int	fails;

	fails = 0;
	while (++args)
		unset_arg(shell, *args, &fails);
	if (fails > 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
