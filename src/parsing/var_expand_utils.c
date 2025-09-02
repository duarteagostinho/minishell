/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:15:43 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/02 13:17:36 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

void	process_variable(t_str str, int *i, t_str expanded, 
						int *pos, t_vtr env, t_shell *shell)
{
	if (str[*i + 1] == '$' || str[*i + 1] == '?')
	{
		*pos = *i;
		expand_special_var(str, i, expanded, shell);
		*i = *pos;
	}
	else if (ft_isalnum(str[*i + 1]) || str[*i + 1] == '_')
	{
		*pos = *i;
		expand_env_var(str, i, expanded, env);
		*i = *pos;
	}
	else
		expanded[(*pos)++] = str[(*i)++];
}

int	get_special_var_length(t_str str, int i, t_shell *shell)
{
	t_str	value;
	int		len;

	if (str[i + 1] == '$')
		value = ft_itoa(getpid());
	else if (str[i + 1] == '?')
		value = ft_itoa(shell->exit_status);
	else
		return (0);
	if (!value)
		return (0);
	len = ft_strlen(value);
	free(value);
	return (len);
}

int	get_env_var_length(t_str str, int i, t_vtr env)
{
	t_str	var_name;
	t_str	var_value;
	int		len;

	var_name = extract_var_name(str, i + 1);
	if (!var_name)
		return (0);
	var_value = get_env_val(env, var_name);
	free(var_name);
	if (!var_value)
		return (0);
	len = ft_strlen(var_value);
	return (len);
}

int	calculate_expansion_length(t_str str, t_vtr env, t_shell *shell)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			if (str[i + 1] == '$' || str[i + 1] == '?')
				len += get_special_var_length(str, i++, shell);
			else if (ft_isalnum(str[i + 1]) || str[i + 1] == '_')
			{
				len += get_env_var_length(str, i, env);
				i += get_var_name_length(str, i + 1);
			}
			else
				len++;
		}
		else
			len++;
	}
	return (len);
}

int	get_var_name_length(t_str str, int start)
{
	int	i;
	int	len;

	i = start;
	len = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
	{
		len++;
		i++;
	}
	return (len);
}
