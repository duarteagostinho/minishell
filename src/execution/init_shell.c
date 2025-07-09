/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:23:05 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/06/18 21:32:17 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

t_env_list	*empty_env(t_env_list *env)
{
	env->head = create_env_node("PWD");
	env->head->value = getcwd(NULL, 0);
	if (!env->head->value)
		return (NULL);
	add_back_env_node(env, create_env_node("SHLVL=1"));
	return (env);
}

t_env_list	*init_env(t_vtr envp)
{
	t_env_list	*env;

	env = ft_calloc(1, sizeof(t_env_list));
	if (!envp || !*envp)
		return (empty_env(env));
	while (envp)
	{
		if (!add_back_env_node(env, create_env_node(*envp++)))
			return (NULL);
	}
	return (env);
}

void  init_shell(t_vtr envp)
{
	ft_bzero(shell(), sizeof(t_shell));
	shell()->env = init_env(envp);
	lvl_up(shell());
}

void  lvl_up(t_shell *shell)
{
	int			lvl;
	t_str		new_lvl;
	t_env_node	*current;

	current = shell->env->head;
	while (current)
	{
		if (!ft_strcmp("SHLVL", current->key))
		{
			lvl = ft_atoi(current->value);
			break ;
		}
		current = current->next;
	}
	if (current)
	{
		free(current->value);
		current->value = ft_itoa(++lvl);
	}
	else
		add_back_env_node(shell->env, create_env_node("SHLVL=1"));
}
