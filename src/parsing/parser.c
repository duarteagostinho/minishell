#include "../../lib/minishell.h"

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

static void	fill_commands(t_vtr cmds, t_cmd *curr)
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


t_cmd	*parser(t_str line, t_vtr env, t_shell *shell)
{
	t_vtr	cmds;
	t_cmd	*commands;
	t_str	new_line;
	int k = 0;

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
		t_str temp = cmds[k];
		cmds[k] = expand_variables(temp, env, shell);
		free(temp);
		k++;
	}
	commands = init_command_list();
	if (!commands)
		return (free(new_line), NULL);
	fill_commands(cmds, commands);
	free_vtr(cmds);
	free(new_line);
	return (commands);
}
