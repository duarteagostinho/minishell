#include "../../lib/minishell.h"

t_str	mark_unquoted_whitespace(t_str str)
{
	int	 i;
	char quote;

	if (!str)
		return (NULL);
	i = 0;
	quote = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && quote == 0)
			quote = str[i];
		else if (str[i] == quote)
			quote = 0;
		if ((str[i] == ' ' || str[i] == '\t') && quote == 0)
			str[i] = '\x1F';
		i++;
	}
	return (str);
}
