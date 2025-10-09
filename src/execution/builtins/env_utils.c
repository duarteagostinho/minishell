/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:37:34 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 19:44:19 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_str	get_env_val(t_vtr env, const t_str key)
{
	int		i;
	int		len;
	t_str	val;

	i = -1;
	len = ft_strlen(key);
	while (env[++i])
	{
		if (!ft_strncmp(env[i], key, len))
		{
			val = ft_strchr(env[i], '=');
			if (val)
				return (val + 1);
			break ;
		}
	}
	return (NULL);
}

t_vtr	realloc_env(t_vtr env, const t_str new_var, int size)
{
	int		i;
	t_vtr	new_env;

	i = -1;
	if (size < 0)
		size = 0;
	new_env = ft_calloc(size + 1, sizeof(t_str));
	if (!new_env)
		return (NULL);
	while (++i < size - 1 && env && env[i])
		new_env[i] = ft_strdup(env[i]);
	if (new_var)
	{
		new_env[i] = ft_strdup(new_var);
		free(new_var);
	}
	if (env)
		free_vtr(env);
	return (new_env);
}

void	add_env_var(t_vtr *env, const t_str key, const t_str var)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(key);
	while ((*env)[++i])
	{
		if (!ft_strncmp((*env)[i], key, len))
		{
			free((*env)[i]);
			(*env)[i] = ft_strdup(var);
			if (var)
				free(var);
			return ;
		}
	}
	*env = realloc_env(*env, var, get_sizeof_args(*env) + 1);
}

void	rmv_env_var(t_vtr *env, const t_str key)
{
	int		i;
	int		j;
	int		len;
	int		size;
	t_vtr	new_env;

	i = -1;
	len = ft_strlen(key);
	size = get_sizeof_args(*env);
	new_env = ft_calloc(size, sizeof(t_str));
	if (!new_env)
		return ;
	j = 0;
	while ((*env)[++i])
	{
		if (!ft_strncmp((*env)[i], key, len)
			&& ((*env)[i][len] == '=' || (*env)[i][len] == '\0'))
			continue ;
		new_env[j++] = ft_strdup((*env)[i]);
	}
	free_vtr(*env);
	*env = new_env;
}
