#include "minishell.h"

static char	*type_check(char *full_line, int *i)
{
	char	*error;

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

static char	*valid_syntax(char *line)
{
	int		i;
	char	*error;

	if (!line || !*line)
		return (NULL);
	i = skip_whitespace(line, 0);
	if (!line[i])
		return (ERR_EMPTY_INP);
	if (line[i] == '|' || line[ft_strlen(line) - 1] == '|')
		return (ERR_SYN_PIPE);
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'' ||
			line[i] == '|' || line[i] == '>' || line[i] == '<')
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
static t_cmd	*init_command_list(void)
{
	t_cmd	*commands;

	commands = malloc(sizeof(t_cmd));
	if (!commands)
		return (NULL);
	commands->next = NULL;
	commands->redirect = NULL;
	commands->redirect_in = STDIN_FILENO;
	commands->redirect_out = STDOUT_FILENO;
	return (commands);
}

static void	fill_commands(char **cmds, t_cmd *curr)
{
	int	i;

	i = 0;
	while(cmds[i])
	{
		if (i > 0)
		{
			curr->next = malloc(sizeof(t_cmd));
			if (!curr->next)
				return ;
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
}


t_cmd	*parser(char *line, char **env, t_shell *shell)
{
	char	**cmds;
	t_cmd	*commands;
	char	*new_line;
	int k = 0;
	(void)env;
	(void)shell;

	if (!line || !*line)
		return (NULL);
	if (valid_syntax(line))
	{
		printf("%s\n", valid_syntax(line));
		return (NULL);
	}
	new_line = prepare_line(line);
	if (!new_line)
		return (NULL);
	cmds = ft_split(new_line, '\x1E');
	if (!cmds)
		return (free(new_line), NULL);
	while (cmds[k])
	{
		cmds[k] = expand_variables(cmds[k], env, shell);
		k++;
	}
	commands = init_command_list();
	if (!commands)
		return (free(new_line), NULL);
	fill_commands(cmds, commands);
	free_args(cmds);
	free(new_line);
	return (commands);
}
