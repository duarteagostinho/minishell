/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:47:39 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/18 16:28:53 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_special_var_length(t_str str, int i, t_shell *shell)
{
	(void)shell;
	if (str[i + 1] == '$')
		return (10);
	else if (str[i + 1] == '?')
		return (3);
	return (0);
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
	if (var_value)
		len = ft_strlen(var_value);
	else
		len = 0;
	free(var_name);
	return (len);
}

int	skip_var_name(t_str str, int i)
{
	t_str	var_name;
	int		new_i;

	var_name = extract_var_name(str, i + 1);
	if (var_name)
	{
		new_i = i + ft_strlen(var_name) + 1;
		free(var_name);
		return (new_i);
	}
	return (i + 1);
}

int	process_dollar_sign(t_str str, int i, t_vtr env, t_shell *shell)
{
	int	len_added;

	len_added = 0;
	if (str[i + 1] == '$' || str[i + 1] == '?')
		len_added = get_special_var_length(str, i, shell);
	else if (ft_isalnum(str[i + 1]) || str[i + 1] == '_')
		len_added = get_env_var_length(str, i, env);
	else
		len_added = 1;
	return (len_added);
}

int	calculate_expansion_length(t_str str, t_vtr env, t_shell *shell)
{
	int		i;
	int		final_len;
	char	quote;

	i = 0;
	final_len = 0;
	quote = 0;
	while (str[i])
	{
		update_quote_state(str[i], &quote);
		if (str[i] == '$' && str[i + 1] && quote != '\'')
			final_len += handle_expansion(str, &i, env, shell);
		else
		{
			final_len++;
			i++;
		}
	}
	return (final_len);
}
