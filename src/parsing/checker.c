#include "minishell.h"

char	*check_redir(char *line)
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
char	*quotes_valid(char *line)
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

char	*handle_quotes(char *line, int *i)
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

char	*handle_pipes(char *line, int *i)
{
	if (line[*i + 1] == line[*i])
		return (ERR_SYN_PIPE);
	(*i)++;
	*i = skip_whitespace(line, *i);
	if (line[*i] == '|' || !line[*i])
		return (ERR_SYN_PIPE);
	return (NULL);
}

char	*handle_redirections(char *line, int *i)
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