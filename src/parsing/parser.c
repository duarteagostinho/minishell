#include "minishell.h"

static void	mark_redirection(char* line, char **new_line, int *i)
{
	*(*new_line)++ = '3';
	*(*new_line)++ = line[*i];
	if (line[*i + 1] == line[*i])
		*(*new_line)++ = line[++(*i)];
	**new_line = '3';
}

static void	mark_pipes(char *line, char *new_line)
{
	int	i;
	int	c;

	c = 0;
	i = -1;
	while (line[++i])
	{
		*new_line = line[i];
		if ((line[i] == '"' || line[i] == '\'') && !c)
			c = line[i];
		else if (c == line[i])
			c = 0;
		else if (line[i] == '|' && !c)
			*new_line = '2';
		else if (line[i] == ' ' && !c)
			*new_line = '3';
		else if (line[i] == '>' || line[i] == '<')
			mark_redirection(line, &new_line, &i);
		else
			*new_line = line[i];
		new_line++;
	}
}

char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	char	*clean;
	char	quote;

	if (!str)
		return (NULL);
	clean = ft_calloc(1, ft_strlen(str) + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				clean[j++] = str[i++];
			if (str[i])
				i++;
		}
		else
			clean[j++] = str[i++];
	}
	clean[j] = '\0';
	return (clean);
}

static void	free_args(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static char	**process_args(char *cmd_str)
{
	int		i;
	char	**args;
	char	**split;

	if (!cmd_str)
		return (NULL);
	split = ft_split(cmd_str, '3');
	i = 0;
	while (split[i])
		i++;
	args = ft_calloc(sizeof(char *), i + 1);
	if (!args)
	{
		free_args(split);
		return (NULL);
	}
	i = -1;
	while (split[++i])
		args[i] = remove_quotes(split[i]);
	args[i] = NULL;
	free_args(split);
	return (args);
}

int	skip_whitespace(char *line, int start)
{
	int	i;

	i = start;
	while (line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
	return (i);
}

int	get_last_quote(char *line)
{
	int		i;
	char	quote;
	i = -1;
	while (line[++i])
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			quote = line[i++];
			while (line)
		}
	}
}


char	*valid_syntax(char *line)
{
	int		i;
	char	quote;
	char	redir;

	i = 0;
	if (line[i] == '|' || line[ft_strlen(line) - 1] == '|')
		return (ERR_SYN_PIPE);
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			quote = line[i++];
			while (line[i] && line[i] != quote)
				i++;
			if (!line[i])
				return (ERR_SYN_QUOTES);
			i++;
		}
		else if (line[i] == '|')
		{
			if (line[i + 1] == line[i])
				return (ERR_SYN_PIPE);
			i++;
			i = skip_whitespace(line, i);
			if (line[i] == '|' || !line[i])
				return (ERR_SYN_PIPE);
		}
		else if (line[i] == '>' || line[i] == '<')
		{
			redir = line[i];
			if (line[i + 1] == redir)
				i += 2;
			i++;
			i = skip_whitespace(line, i);
			if (!line[i] || line[i] == '|' || line[i] == '<' || line[i] == '>')
				return (ERR_SYN_RD);
			while (line[i] && line[i] != ' ' &&
				line[i] == '|' || line[i] == '<' || line[i] == '>')
			{
				if (line[i] == quote)
					
			}
		}
		else
			i++;
	}
	return (NULL);
}

t_cmd	*parser(char *line)
{
	int		i;
	char	**cmds;
	t_cmd	*commands;
	t_cmd	*curr;
	char	*new_line;

	printf("line = %s\n", line);
	if (valid_syntax(line))
	{
		printf("%s\n", valid_syntax(line));
		return (NULL);
	}
	new_line = ft_calloc(ft_strlen(line) + 1, 3);
	if (!new_line)
		return (NULL);
	mark_pipes(line, new_line);
	cmds = ft_split(new_line, '2');
	if (!cmds)
		return (free(new_line), NULL);
	commands = malloc(sizeof(t_cmd));
	if (!commands)
		return (free(new_line), NULL);
	commands->next = NULL;
	commands->redirect = NULL;
	commands->redirect_in = STDIN_FILENO;
	commands->redirect_out = STDOUT_FILENO;
	curr = commands;
	i = 0;
	while(cmds[i])
	{
		if (i > 0)
		{
			curr->next = malloc(sizeof(t_cmd));
			if (!curr->next)
				return (free(new_line), NULL);
			curr = curr->next;
			curr->next = NULL;
			curr->redirect = NULL;
			curr->redirect_in = STDIN_FILENO;
			curr->redirect_out = STDOUT_FILENO;
		}
		curr->args = process_args(cmds[i]);
		curr->redirect = extract_redirections(cmds[i]);
		i++;
	}
	curr = commands;
	while (curr)
	{
		i = -1;
		while (curr->args && curr->args[++i])
			printf("%i - cmd: %s\n", i, curr->args[i]);
		curr = curr->next;
	}
	free_args(cmds);
	return (free(new_line), commands);
}
