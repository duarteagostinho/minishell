/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:41:07 by duandrad          #+#    #+#             */
/*   Updated: 2025/05/27 11:43:48 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

pid_t	ft_getpid(void)
{
	pid_t	pid;

	
	pid = getpid();
	if (pid < 1)
		return (-1);
	return (pid);
}

int	get_end_quote(const string input, char c)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == c)
			return (i);
	}
	return (i);
}

int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

string	clean_rl_copy(string rl_copy)
{
	string	clean;
  int i;
  int j;

  i = 0;
  j = -1;
  clean = malloc(sizeof(string) * ft_strlen(rl_copy));
  if (!clean)
    return (NULL);
  while (ft_isspace(rl_copy[i]))
    i++;
  while(rl_copy[i])
    clean[++j] = rl_copy[i++];
  clean[j] = '\0';
  return (clean);
}

int	skip_quotes(string str)
{
	int		i;
	char	quote;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				i++;
			if (str[i] == quote)
				i++;
			break;
		}
		i++;
	}
	return (i);
}

