/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:06:26 by duandrad          #+#    #+#             */
/*   Updated: 2024/12/02 13:33:10 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2);
int		check(char *buff);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	long long	bytes;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytes = 1;
	while (1)
	{
		if (*buffer == '\0')
			bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(line);
			return (NULL);
		}
		if (bytes)
			line = ft_strjoin(line, buffer);
		if (check(buffer) || bytes == 0)
			break ;
	}
	return (line);
}

/*int main()
{
	int fd = open("txt.txt", O_RDONLY);
	char *line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	 while ((line = get_next_line(fd)))
	 {
	 	printf("%s", line);
	 	free(line);
	 }
	return 0;
}*/
