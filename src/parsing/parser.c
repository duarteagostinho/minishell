/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:50:41 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/09 17:29:03 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_str	type_check(t_str full_line, t_arr i)
{
	t_str	error;

	if (full_line[*i] == '"' || full_line[*i] == '\'')
	{
		error = handle_quotes(full_line, i);
		if (error)
			return (error);
	}
	else if (full_line[*i] == '|')
	{
		error = handle_pipes(full_line, i);
		if (error)
			return (error);
	}
	else if (full_line[*i] == '>' || full_line[*i] == '<')
	{
		error = handle_redirections(full_line, i);
		if (error)
			return (error);
	}
	return (NULL);
}

static t_str	valid_syntax(t_str line)
{
	int		i;
	t_str	error;

	error = NULL;
	if (!line || !*line)
		return (NULL);
	i = skip_whitespace(line, 0);
	if (!line[i])
		return (NULL);
	if (line[i] == '|' || line[ft_strlen(line) - 1] == '|')
		return (ERR_SYN_PIPE);
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\''
			|| line[i] == '|' || line[i] == '>'
			|| line[i] == '<')
		{
			error = type_check(line, &i);
			if (error)
				return (error);
		}
		else
			i++;
	}
	return (NULL);
}

static t_str	heredoc_expansion(t_str token, t_vtr env, t_shell *shell)
{
	t_str	heredoc_pos;
	t_str	b4_heredoc;
	t_str	delimiter;
	t_str	res;
	int		pos;

	heredoc_pos = ft_strnstr(token, "<<", ft_strlen(token));
	if (!heredoc_pos)
		return (expand_variables(token, env, shell));
	pos = heredoc_pos - token + 2;
	b4_heredoc = ft_substr(token, 0, pos);
	delimiter = ft_strtrim(token + pos, " \t");
	if (!b4_heredoc || !delimiter)
		return (free(b4_heredoc), free(delimiter), NULL);
	res = expand_variables(b4_heredoc, env, shell);
	free(b4_heredoc);
	if (!res)
		return (free(delimiter), NULL);
	b4_heredoc = ft_strjoin(res, delimiter);
	free(res);
	free(delimiter);
	return (b4_heredoc);
}

void	cmds_config(t_config_ctx *ctx)
{
	t_str	temp;
	t_str	here_doc;

	while (ctx->cmds[*(ctx->k)])
	{
		temp = ctx->cmds[*(ctx->k)];
		here_doc = ft_strnstr(temp, "<<", ft_strlen(temp));
		if (here_doc)
			ctx->cmds[*(ctx->k)] = heredoc_expansion(temp,
					ctx->env, ctx->shell);
		else
		{
			ctx->cmds[*(ctx->k)] = expand_variables(temp, ctx->env, ctx->shell);
		}
		free(temp);
		mark_unquoted_whitespace(ctx->cmds[*(ctx->k)]);
		(*(ctx->k))++;
	}
	*(ctx->commands) = init_command_list();
}

t_cmd	*parser(t_str line, t_vtr env, t_shell *shell)
{
	t_vtr	cmds;
	t_cmd	*commands;
	t_str	new_line;
	int		k;

	commands = NULL;
	k = 0;
	if (!line || !*line)
		return (NULL);
	if (valid_syntax(line))
	{
		printf("%s", valid_syntax(line));
		return (NULL);
	}
	new_line = prepare_line(line);
	if (!new_line)
		return (NULL);
	cmds = ft_split(new_line, '\x1E');
	if (!cmds)
		return (free(new_line), NULL);
	cmds_config(&(t_config_ctx){cmds, &k, &commands, env, shell});
	fill_commands(cmds, commands);
	free_vtr(cmds);
	free(new_line);
	return (commands);
}
