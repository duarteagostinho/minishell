/* DEBUG: Temporary debug program to test parsing */
#include "../lib/minishell.h"
#include <stdio.h>

static void	mark_redirection(char *line, char *new_line, int *i, int *k)
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

static char *marker(char *line, int *i, int *k)
{
	int		quote;
	char	*new_line;

	quote = 0;
	new_line = ft_calloc(ft_strlen(line) * 3 + 1, sizeof(char));
	while (line[++(*i)])
	{
		if ((line[*i] == '\'' || line[*i] == '"') && !quote)
			quote = line[*i];
		else if (line[*i] == quote)
			quote = 0;
		if (line[*i] == '|' && !quote)
			new_line[*k] = '\x1E';
		else if (line[*i] == ' ' && !quote)
			new_line[*k] = '\x1F';
		else if ((line[*i] == '>' || line[*i] == '<') && !quote)
		{
			mark_redirection(line, new_line, i, k);
			continue ;
		}
		else
			new_line[*k] = line[*i];
		(*k)++;
	}
	return (new_line);
}

char *prepare_line(char *line)
{
	int i = -1;
	int k = 0;
	return marker(line, &i, &k);
}

static char *remove_redirections(char *cmd_str)
{
	char	*clean_cmd;
	int		i;
	int		j;
	char	quote;

	clean_cmd = ft_calloc(ft_strlen(cmd_str) + 1, sizeof(char));
	i = 0;
	j = 0;
	quote = 0;
	while (cmd_str[i])
	{
		if (cmd_str[i] == '"' || cmd_str[i] == '\'')
		{
			quote = cmd_str[i];
			clean_cmd[j++] = cmd_str[i++];  // Keep the opening quote
			while (cmd_str[i] && cmd_str[i] != quote)
				clean_cmd[j++] = cmd_str[i++];
			if (cmd_str[i])
				clean_cmd[j++] = cmd_str[i++];  // Keep the closing quote
		}
		else if (cmd_str[i] == '>' || cmd_str[i] == '<')
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

char *remove_quotes(char *str)
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

int main(void)
{
    char *test_line = "export PAGMAN=\"ls -lah\"";
    printf("Original: [%s]\n", test_line);
    
    char *prepared = prepare_line(test_line);
    printf("Prepared: [");
    for (int i = 0; prepared[i]; i++) {
        if (prepared[i] == '\x1E') printf("|");
        else if (prepared[i] == '\x1F') printf("_");
        else printf("%c", prepared[i]);
    }
    printf("]\n");
    
    char *clean = remove_redirections(prepared);
    printf("Clean: [");
    for (int i = 0; clean[i]; i++) {
        if (clean[i] == '\x1E') printf("|");
        else if (clean[i] == '\x1F') printf("_");
        else printf("%c", clean[i]);
    }
    printf("]\n");
    
    char **split = ft_split(clean, '\x1F');
    for (int i = 0; split[i]; i++) {
        printf("Split[%d]: [%s]\n", i, split[i]);
        char *no_quotes = remove_quotes(split[i]);
        printf("NoQuotes[%d]: [%s]\n", i, no_quotes);
        free(no_quotes);
    }
    
    free(prepared);
    free(clean);
    return 0;
}
