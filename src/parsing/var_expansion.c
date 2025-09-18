/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:45:43 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/18 16:27:28 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_str	get_special_value(t_str str, int *i, t_shell *shell)
{
	*i += 2;
	if (str[*i - 1] == '$')
		return (ft_itoa(getpid()));
	else if (str[*i - 1] == '?')
		return (ft_itoa(shell->exit_status));
	else
		return (NULL);
}

t_str	get_env_value(t_str str, int *i, t_vtr env)
{
	t_str	var_name;
	t_str	value;

	var_name = extract_var_name(str, *i + 1);
	if (var_name)
	{
		value = get_env_val(env, var_name);
		*i += ft_strlen(var_name) + 1;
		free(var_name);
		return (value);
	}
	else
	{
		*i += 1;
		return (NULL);
	}
}

t_str	expand_variables(t_str str, t_vtr env, t_shell *shell)
{
	t_str	expanded;
	int		final_len;

	if (!str)
		return (NULL);
	final_len = calculate_expansion_length(str, env, shell);
	if (final_len <= 0)
		return (ft_strdup(""));
	expanded = malloc(final_len + 1);
	if (!expanded)
		return (NULL);
	expand_loop(str, expanded, final_len, env);
	return (expanded);
}
