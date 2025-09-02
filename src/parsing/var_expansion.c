/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:45:43 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/02 15:06:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

t_str	extract_var_name(t_str str, int start)
{
	int		i;
	int		len;
	t_str	name;

	if (!str || start < 0)
		return (NULL);
	i = start - 1;
	len = 0;
	while (str[++i] && (ft_isalnum(str[i]) || str[i] == '_'))
		len++;
	if (len == 0)
		return (NULL);
	name = malloc(len + 1);
	if (!name)
		return (NULL);
	i = 0;
	while (i < len)
	{
		name[i] = str[start + i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

static void	expand_special_var(t_str str, t_arr i, t_str exp, t_arr k, t_shell *shell)
{
	t_str	value;
	int		j;
	
	if (str[*i + 1] == '$')
		value = ft_itoa(getpid());
	else if (str[*i + 1] == '?')
		value = ft_itoa(shell->exit_status);
	else
		value = NULL;
	if (value)
	{
		j = 0;
		while (value[j])
		{
			exp[*k + j] = value[j];
			j++;
		}
		*k += j;
		free(value);
	}
	*i += 2;
}

static void	expand_env_var(t_str str, t_arr i, t_str expanded, t_arr pos, t_vtr env)
{
	t_str	var_name;
	t_str	var_value;
	int		j;

	var_name = extract_var_name(str, *i + 1);
	if (var_name)
	{
		var_value = get_env_val(env, var_name);
		if (var_value)
		{
			j = 0;
			while (var_value[j])
			{
				expanded[*pos + j] = var_value[j];
				j++;
			}
			*pos += j;
		}
		*i += ft_strlen(var_name) + 1;
		free(var_name);
	}
	else
		expanded[(*pos)++] = str[(*i)++];
}

t_str	expand_variables(t_str str, t_vtr env, t_shell *shell)
{
	t_str	expanded;
	int		final_len;
	int		i;
	int		pos;

	final_len = calculate_expansion_length(str, env, shell);
	expanded = malloc(final_len + 1);
	i = 0;
	pos = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			if (str[i + 1] == '$' || str[i + 1] == '?')
				expand_special_var(str, &i, expanded, &pos, shell);
			else if (ft_isalnum(str[i + 1]) || str[i + 1] == '_')
				expand_env_var(str, &i, expanded, &pos, env);
			else
				expanded[pos++] = str[i++];
		}
		else
			expanded[pos++] = str[i++];
	}
	expanded[pos] = '\0';
	return (expanded);
}
