#include "minishell.h"

void	handle_heredoc(t_rdir *redir, t_shell *shell, char **env)
{
	char	*line;
	int		fds[2];
	int		pid;

	(void)env;
	if (!redir || !redir->args[1])
		return ;
	if (pipe(fds) == -1)
	{
		perror("pipe");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close(fds[0]);
		close(fds[1]);
		return ;
	}
	if (pid > 0)
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
			exit(0);
		}
		if (ft_strcmp(line, redir->args[1]) == 0)
		{
			free(line);
			break;
		}
		write(fds[1], line, ft_strlen(line));
		write(fds[1], "\n", 1);
		free(line);
	}	
	close(fds[1]);
	exit(0);
}
