#include "minishell.h"

static void	mark_redirection(t_str line, t_str new_line, t_arr i, t_arr k)
{
	new_line[(*k)++] = '\x1F';
	new_line[(*k)++] = line[*i];
	if (line[*i + 1] == line[*i])
	{
		(*i)++;
		new_line[(*k)++] = line[*i];
	}
	new_line[(*k)++] = '\x1F';
}

static t_str	marker(t_str line)
{
	int		i;
	int		k;
	int		quote;
	t_str	new_line;

	i = -1;
	k = 0;
	quote = 0;
	new_line = ft_calloc(ft_strlen(line) * 3 + 1, sizeof(char));
	while (line[++i])
	{
		if ((line[i] == '\'' || line[i] == '"') && !quote)
			quote = line[i];
		else if (line[i] == quote)
			quote = 0;
		
		if (line[i] == '|' && !quote)
			new_line[k] = '\x1E';
		else if (line[i] == ' ' && !quote)
			new_line[k] = '\x1F';
		else if ((line[i] == '>' || line[i] == '<') && !quote)
		{
			mark_redirection(line, new_line, &i, &k);
			continue;
		}
		else
			new_line[k] = line[i];
		k++;
	}
	return new_line;
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

	new_line = ft_calloc(ft_strlen(line) * 3 + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	new_line = marker(line);
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
	{
		printf("[%s] ", split[i]);
		i++;
	}
	printf("\n");
	
	args = ft_calloc(sizeof(char *), i + 1);
	if (!args)
	{
		free_vtr(split);
		return (NULL);
	}
	
	i = -1;
	while (split[++i])
	{
		args[i] = remove_quotes(split[i]);
	}
	args[i] = NULL;
	
	i = 0;
	while (args[i])
	{
		printf("[%s] ", args[i]);
		i++;
	}
	printf("\n");
	
	free_vtr(split);
	return (args);
}
