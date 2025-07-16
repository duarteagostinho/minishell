#include "minishell.h"

void	free_args(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
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
			while (line[i] && line[i] != quote)
				i++;
			if (!line[i])
				return (-1);
			else
				return (i);
		}
		i++;
	}
	return (0);
}