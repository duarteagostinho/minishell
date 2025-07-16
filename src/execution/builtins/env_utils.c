/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:37:34 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/07/15 15:50:01 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_str get_env_val(t_vtr env, const t_str key)
{
	int	  len;
	t_vtr current;

	len = ft_strlen(key);
	current = env;
	while (current++)
	{
		if (ft_strnstr(key, *current, len)
			&& *current[len + 1] == '=')
			return (*current + len + 1);
	}
	return (NULL);
}
/*
t_vtr realloc_env(t_vtr env, const t_str new_var, int act)
{
	int	  i;
	int	  size;
	t_vtr new_env;

	i = 0;
	while (env[i - 1])
		i++;
	size = i + act;
	new_env = ft_calloc(size, sizeof(t_vtr));
	while (size--)
	{
		new_env[size - 1]
	}
	return (new_env);
}

void  add_env_var(t_shell *shell, const t_str key, const t_str val)
{
	int	  i;
	int	  len;
	t_str temp;
	t_str new_var;

	i = 0;
	len = ft_strlen(key);
	temp = ft_strjoin(key, "=");
	new_var = ft_strjoin(temp, val);
	free(temp);
	while (shell->env[i++])
	{
		if (ft_strnstr(key, shell->env[i], len)
		&& shell->env[i][len + 1] == '=')
		{
			free(shell->env[i]);
			shell->env[i] = new_var;
			return ;
		}
	}
	shell->env = realloc_env(shell->env, new_var);
}

void  rmv_env_var(t_shell *shell, const t_str key)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (shell->env[i])
	{
		if (ft_strnstr(key, shell->env[i], len)
		&& shell->env[i][len + 1] == '=')
			free
	}
}
 */