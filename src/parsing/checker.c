#include "../../lib/minishell.h"

t_str	check_redir(t_str line)
{
	int		i;
	char	redir;

	i = 0;
	if ((line[i] == '>' && line[i + 1] == '<') || (line[i] == '<' &&
		line[i + 1] == '>'))
		return (ERR_SYN_RD);
	else if ((line[i] == '>' && line[i + 1] == '>' && line[i + 2] == '>') ||
		(line[i] == '<' && line[i + 1] == '<' && line[i + 2] == '<'))
			return (ERR_SYN_RD);
	redir = line[i];
	if (line[i + 1] == redir)
		i += 2;
	else
		i++;
	i = skip_whitespace(line, i);
	if (!line[i] || line[i] == '|' || line[i] == '<' || line[i] == '>')
		return (ERR_SYN_RD);
	return (NULL);
}
t_str	quotes_valid(t_str line)
{
	int	i;
	int	quote_end;

	i = 0;
	while (line[i] && line[i] != ' ' &&
		line[i] != '|' && line[i] != '<' && line[i] != '>')
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			quote_end = get_last_quote(&line[i]);
			if (quote_end < 0)
				return (ERR_SYN_QUOTES);
			i += quote_end + 1;
		}
		else
			i++;
	}
	return (NULL);
}

t_str	handle_quotes(t_str line, t_arr i)
{
	char	quote;

	quote = line[*i];
	(*i)++;
	while (line[*i] && line[*i] != quote)
		(*i)++;
	if (!line[*i])
		return (ERR_SYN_QUOTES);
	(*i)++;
	return (NULL);
}

t_str	handle_pipes(t_str line, t_arr i)
{
	if (line[*i + 1] == line[*i])
		return (ERR_SYN_PIPE);
	(*i)++;
	*i = skip_whitespace(line, *i);
	if (line[*i] == '|' || !line[*i])
		return (ERR_SYN_PIPE);
	return (NULL);
}

t_str	handle_redirections(t_str line, t_arr i)
{
	int	quote_end;

	if (check_redir(&line[*i]))
		return (ERR_SYN_RD);
	if (line[*i + 1] == line[*i])
		*i += 2;
	else
		(*i)++;
	*i = skip_whitespace(line, *i);
	if (quotes_valid(&line[*i]))
		return (ERR_SYN_QUOTES);
	while (line[*i] && line[*i] != ' ' && line[*i] != '|' && 
		line[*i] != '<' && line[*i] != '>')
	{
		if (line[*i] == '"' || line[*i] == '\'')
		{
			quote_end = get_last_quote(&line[*i]);
			if (quote_end < 0)
				return (ERR_SYN_QUOTES);
			*i += quote_end + 1;
		}
		else
			(*i)++;
	}
	return (NULL);
}
