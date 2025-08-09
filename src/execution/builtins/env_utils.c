/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:37:34 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/07/10 17:16:43 by mrapp-he         ###   ########.fr       */
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
		if (ft_strnstr(key, env[i], len)
			&& env[i][len + 1] == '=')
			return (env[i] + len + 1);
	}
	return (NULL);
}

int realloc_env(t_vtr *env, const t_str new_var, int act)
{
	int	  i;
	int	  new_size;
	t_vtr new_env;

	i = 0;
	while ((*env)[i])
		i++;
	new_size = i + act;
	if (new_size < 0)
		new_size = 0;
	new_env = ft_calloc(new_size + 1, sizeof(t_str));
	if (!new_env)
		return (EXIT_FAILURE);
	i = -1;
	while ((*env)[++i] && i < new_size)
		new_env[i] = (*env)[i];
	if (act > 0 && new_var)
		new_env[i] = new_var;
	free(*env);
	*env = new_env;
	return (EXIT_SUCCESS);
}

int  add_env_var(t_vtr env, const t_str key, const t_str val)
{
	int	  i;
	t_str tmp;
	t_str new_var;

	i = -1;
	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (EXIT_FAILURE);
	new_var = ft_strjoin(tmp, val);
	free(tmp);
	if (!new_var)
		return (EXIT_FAILURE);
	while (env[++i])
	{
		if (ft_strnstr(key, env[i], ft_strlen(key))
		&& env[i][ft_strlen(key) + 1] == '=')
		{
			free(env[i]);
			env[i] = new_var;
			return (EXIT_SUCCESS);
		}
	}
	return (realloc_env(&env, new_var, 1));
}

int  rmv_env_var(t_vtr env, const t_str key)
{
	int	  i;
	int	  len;

	i = -1;
	len = ft_strlen(key);
	while (env[++i])
	{
		if (ft_strnstr(key, env[i], len)
		&& env[i][len + 1] == '=')
		{
			free(env[i]);
			while (env[i + 1])
			{
				env[i] = env[i + 1];
				i++;
			}
			return (realloc_env(&env, NULL, -1));
		}
	}
	return (EXIT_FAILURE);
}
