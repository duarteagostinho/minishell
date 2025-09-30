#include "minishell.h"

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
