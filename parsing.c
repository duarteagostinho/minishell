/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:20:18 by duandrad          #+#    #+#             */
/*   Updated: 2025/05/16 17:38:34 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*readl_prompt(char  *prompt)
{
	char	*line;

	line = NULL;
	if (!prompt || !*prompt)
			return (NULL);
	line = readline(prompt);
	if (!line || !*line)
		return (NULL);
	return (line);
}
#include <unistd.h>

typedef char *string;


void mark_pipes(string line, char x)
{
	int i;
	int c;

	c = 0;
	i = -1;

	while (line[++i])
	{
		if ((line[i] == '"' || line[i] == '\'') && !c)
			c = line[i];
		else if (c == line[i])
			c = 0;
		else if (line[i] == x && !c)
			line[i] = 2;
	}

}

typedef enum s_type{
	HEREDOC,
	CREATE,
	APPEND,
	READ,
}	t_type;

typedef struct s_fd {
	int fd;
	string file;
	t_type type;
	struct  s_fd *next;
	
}		t_fd;

typedef struct s_cmd {
	string line;
	string *matrix;
	int write;
	int read;

	t_fd *fd;
	struct s_cmd *next;
}		t_cmd;


string *parsed(string line)
{
	string *matix;

	if (*line)
		return (NULL);
	mark_pipes(line);
	matrix = ft_split(line, 2)
}
