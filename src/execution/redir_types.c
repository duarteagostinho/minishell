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
	int		fds[2];
	int		pid;
	
	pipe(fds);
	pid = fork();
	if (pid)
	{
		close(fds[1]);
		waitpid(pid, NULL, 0);
		redir->fd = fds[0];
		return ;
	}
	close(fds[0]);
	while (1)
	{
		shell->exit_status = 0;
		line = readline("> ");
		if (!line)
		{
			close(fds[1]);
			ft_exit(shell);
		}
		line = expand_variables(line, env, shell);
		if (ft_strcmp(line, redir->args[1]) == 0)
		{
			free(line);
			break;
		}
		else
		{
			write(fds[1], line, ft_strlen(line));
			write(fds[1], "\n", 1);
		}
		free(line);
	}	
	close(fds[1]);
	ft_exit(shell);
}
