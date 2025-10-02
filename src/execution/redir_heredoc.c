/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:55:07 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/02 14:01:52 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_child(int write_fd, char *delimiter, t_shell *shell)
{
	char	*line;

	while (1)
	{
		shell->exit_status = 0;
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(write_fd, line, ft_strlen(line));
		write(write_fd, "\n", 1);
		free(line);
	}
	close(write_fd);
	exit(0);
}

static int	create_heredoc_pipe(int *fds)
{
	if (pipe(fds) == -1)
	{
		perror("pipe");
		return (0);
	}
	return (1);
}

static int	fork_heredoc(int *fds, t_rdir *redir, t_shell *shell)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close(fds[0]);
		close(fds[1]);
		return (-1);
	}
	if (pid == 0)
		heredoc_child(fds[1], redir->args[1], shell);
	return (pid);
}

void	handle_heredoc(t_rdir *redir, t_shell *shell, char **env)
{
	int	fds[2];
	int	pid;

	(void)env;
	if (!redir || !redir->args[1])
		return ;
	if (!create_heredoc_pipe(fds))
		return ;
	pid = fork_heredoc(fds, redir, shell);
	if (pid == -1)
		return ;
	close(fds[1]);
	waitpid(pid, NULL, 0);
	redir->fd = fds[0];
}
