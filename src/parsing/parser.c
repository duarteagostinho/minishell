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

static char	*remove_quotes(char *str)
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
/* 
static t_redirect	*handle_red(char *type, char *filename, int fd)
{
	t_redirect	*red;

	if (!type || !filename)
		return (NULL);
	red = malloc(sizeof(t_redirect));
	if (!red)
		return (NULL);
	red->args[0] = ft_strdup(type);
	if (!red->args[0])
	{
		free(red);
		return (NULL);
	}
	red->args[1] = ft_strdup(filename);
	if (!red->args[1])
	{
		free(red->args[0]);
		free(red);
		return (NULL);
	}
	red->fd = fd;
	red->next = NULL;
	return (red);
} */

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

/* static t_redirect	*extract_redirections(char *cmd_str)
{
	
} */

t_cmd	*parser(char *line)
{
	int		i;
	char	**cmds;
	t_cmd	*commands;
	char	*new_line;

/* 	if (!valid_syntax(line))
		return (NULL); */
	new_line = ft_calloc(ft_strlen(line) + 1, 3);
	if (!new_line)
		return (NULL);
	commands = malloc(sizeof(t_cmd));
	if (!commands)
		return (free(new_line), NULL);
	commands->next = NULL;
	commands->redirect = NULL;
	commands->redirect_in = STDIN_FILENO;
	commands->redirect_in = STDOUT_FILENO;
	mark_pipes(line, new_line);
	cmds = ft_split(new_line, '2');
	i = -1;
	while(cmds[++i])
		process_args(cmds[i]);
	commands->args = cmds;
	i = -1;
 	while (commands->args && commands->args[++i])
		printf("%i - cmd: %s\n", i, commands->args[i]);

	return (free(new_line), commands);
}
