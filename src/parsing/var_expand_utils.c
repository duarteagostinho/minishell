/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:39:44 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/18 16:22:02 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_special_expansion(t_expand_ctx *ctx)
{
	t_str	value;

	value = get_special_value(ctx->str, ctx->i, ctx->shell);
	if (value)
	{
		copy_value_to_expanded(value, ctx->expanded, ctx->pos);
		free(value);
	}
}

void	handle_env_expansion(t_expand_ctx *ctx)
{
	t_str	value;

	value = get_env_value(ctx->str, ctx->i, ctx->env);
	copy_value_to_expanded(value, ctx->expanded, ctx->pos);
}

void	handle_dollar_expansion(t_expand_ctx *ctx)
{
	if (ctx->str[*(ctx->i) + 1] == '$' || ctx->str[*(ctx->i) + 1] == '?')
		handle_special_expansion(ctx);
	else if (ft_isalnum(ctx->str[*(ctx->i) + 1])
		|| ctx->str[*(ctx->i) + 1] == '_')
		handle_env_expansion(ctx);
	else
		ctx->expanded[(*(ctx->pos))++] = ctx->str[(*(ctx->i))++];
}

void	expand_loop(t_str str, t_str expanded, int final_len, t_vtr env)
{
	t_expand_ctx	ctx;
	int				i;
	int				pos;
	char			quote;

	i = 0;
	pos = 0;
	quote = 0;
	ctx = (t_expand_ctx){str, &i, expanded, &pos, env, shell()};
	while (str[i] && pos < final_len)
	{
		if ((str[i] == '\'' || str[i] == '"') && quote == 0)
			quote = str[i];
		else if (str[i] == quote)
			quote = 0;
		if (str[i] == '$' && str[i + 1] && quote != '\'')
			handle_dollar_expansion(&ctx);
		else
			expanded[pos++] = str[i++];
	}
	expanded[pos] = '\0';
}

t_str	mark_unquoted_whitespace(t_str str)
{
	int		i;
	char	quote;

	if (!str)
		return (NULL);
	i = 0;
	quote = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && quote == 0)
			quote = str[i];
		else if (str[i] == quote)
			quote = 0;
		if ((str[i] == ' ' || str[i] == '\t') && quote == 0)
			str[i] = '\x1F';
		i++;
	}
	return (str);
}
