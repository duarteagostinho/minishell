/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:37:34 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/25 16:39:40 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

t_str get_env_val(t_vtr env, const t_str key)
{
	int	  i;
	int	  len;

	i = -1;
	len = ft_strlen(key);
	while (env[++i])
	{
		if (!ft_strncmp(env[i], key, len))
			return (ft_strchr(env[i], '=') + 1);
	}
	return (NULL);
}

t_vtr	realloc_env(t_vtr env, const t_str new_var, int size)
{
	int	  i;
	t_vtr new_env;

	if (size < 0)
		size = 0;
	new_env = ft_calloc(size + 1, sizeof(t_str));
	if (!new_env)
		return (NULL);
	i = -1;
	while (env[++i])
		new_env[i] = env[i];
	if (new_var)
		new_env[i] = new_var;
	free(env);
	return (new_env);
}

int  add_env_var(t_vtr env, const t_str key, const t_str val)
{
	int		i;
	size_t	len;
	t_str	tmp;
	t_str	new_var;

	i = -1;
	len = ft_strlen(key);
	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (EXIT_FAILURE);
	new_var = ft_strjoin(tmp, val);
	free(tmp);
	if (!new_var)
		return (EXIT_FAILURE);
	while (env[++i])
	{
		if (!ft_strncmp(env[i], key, len))
		{
			free(env[i]);
			env[i] = new_var;
			return (EXIT_SUCCESS);
		}
	}
	env = realloc_env(env, new_var, get_sizeof_args(env) + 1);
	return (EXIT_SUCCESS);
}

int  rmv_env_var(t_vtr env, const t_str key)
{
	int	  i;
	int	  len;

	i = -1;
	len = ft_strlen(key);
	printf("a\n");
	while (env[++i])
	{
		if (!ft_strncmp(env[i], key, len))
		{
			printf("b\n");
			free(env[i]);
			while (env[i + 1])
			{
				env[i] = env[i + 1];
				i++;
			}
			env = realloc_env(env, NULL, get_sizeof_args(env) - 1);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}
