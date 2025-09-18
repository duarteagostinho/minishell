#include "minishell.h"

void	input_redir(t_rdir *redir)
{
	int		fd;

	fd = open(redir->args[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error: Unable to open fd\n");
		return;
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	output_redir(t_rdir *redir)
{
	int		fd;

	fd = open(redir->args[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Error: Unable to open fd\n");
		return;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	append_redir(t_rdir *redir)
{
	int		fd;

	fd = open(redir->args[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		perror("Error: Unable to open fd\n");
		return;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}



void	handle_heredoc(t_rdir *redir, t_shell *shell, char **env)
{
	char	*line;
	int		fd;
	
	fd = open("tmp_heredoc.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	line = readline(">");
	while (line)
	{
		line = expand_variables(line ,env, shell);
		if (ft_strcmp(line, redir->args[1]) == 0)
		{
			close(fd);
			fd = open("tmp_heredoc.txt", O_RDONLY);
			dup2(fd, STDIN_FILENO);
			close(fd);
			unlink("tmp_heredoc.txt");
			free(line);
			break;
		}
		else
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		free(line);
		line = readline(">");
	}
}
