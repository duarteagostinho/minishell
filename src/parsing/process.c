#include "../../lib/minishell.h"

static void	mark_redirection(t_str line, t_vtr new_line, t_arr i)
{
	*(*new_line)++ = '\x1F';
	*(*new_line)++ = line[*i];
	if (line[*i + 1] == line[*i])
		*(*new_line)++ = line[++(*i)];
	*(*new_line)++ = '\x1F';
}

static void	mark_pipes(t_str line, t_str new_line)
{
	int	i;
	int	c;

	c = 0;
	i = -1;
	while (line[++i])
	{
		if ((line[i] == '"' || line[i] == '\'') && !c)
			c = line[i];
		else if (c == line[i])
			c = 0;
		else if (line[i] == '|' && !c)
			*new_line = '\x1E';
		else if (line[i] == ' ' && !c)
			*new_line = '\x1F';
		else if (line[i] == '>' || line[i] == '<')
		{
			mark_redirection(line, &new_line, &i);
			continue;
		}
		else
			*new_line = line[i];
		new_line++;
	}
}

t_str	remove_quotes(t_str str)
{
	int		i;
	int		j;
	t_str	clean;
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

t_str	prepare_line(t_str line)
{
	t_str	new_line;

	new_line = ft_calloc(ft_strlen(line) + 1, 3);
	if (!new_line)
		return (NULL);
	mark_pipes(line, new_line);
	return (new_line);
}

static t_str	remove_redirections(t_str cmd_str)
{
	t_str	clean_cmd;
	int		i;
	int		j;

	clean_cmd = ft_calloc(ft_strlen(cmd_str) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (cmd_str[i])
	{
		if (cmd_str[i] == '>' || cmd_str[i] == '<')
		{
			if (cmd_str[i + 1] == cmd_str[i])
				i += 2;
			else
				i++;
			while (cmd_str[i] && cmd_str[i] == '\x1F')
				i++;
			while (cmd_str[i] && cmd_str[i] != '\x1F')
				i++;
		}
		else
			clean_cmd[j++] = cmd_str[i++];
	}
	clean_cmd[j] = '\0';
	return (clean_cmd);
}

t_vtr	process_args(t_str cmd_str)
{
	int		i;
	t_vtr	args;
	t_vtr	split;
	t_str	clean_cmd;

	clean_cmd = remove_redirections(cmd_str);
	if (!clean_cmd)
		return (NULL);
	split = ft_split(clean_cmd, '\x1F');
	free(clean_cmd);
	i = 0;
	while (split[i])
		i++;
	args = ft_calloc(sizeof(char *), i + 1);
	if (!args)
	{
		free_vtr(split);
		return (NULL);
	}
	i = -1;
	while (split[++i])
		args[i] = remove_quotes(split[i]);
	args[i] = NULL;
	free_vtr(split);
	return (args);
}
