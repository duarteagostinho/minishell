/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:55:07 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/02 16:14:53 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_heredoc_content(int fd, char *delimiter, t_shell *shell)
{
	char	*line;

	while (1)
	{
		shell->exit_status = 0;
		line = readline("> ");
		if (!line)
			ft_exit(shell);
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

static int	create_heredoc_file(char *filename, char *delimiter, t_shell *shell)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0640);
	if (fd == -1)
	{
		perror("heredoc open");
		return (-1);
	}
	write_heredoc_content(fd, delimiter, shell);
	close(fd);
	unlink(filename);
	return (fd);
}

void	handle_heredoc(t_rdir *redir, t_shell *shell)
{
	int		fd;
	pid_t	pid;

	if (!redir || !redir->args[1])
		return ;
	pid = fork();
	if (pid == 0)
	{
		signal_setup(shell, HEREDOC);
		fd = create_heredoc_file("/tmp/heredoc_tmp", redir->args[1], shell);
		if (fd == -1)
			return ;
	}
	signal_setup(shell, IGNORE);
	waitpid(pid, &shell->exit_status, 0);
	if (WIFSIGNALED(shell->exit_status))
	{
		if (WTERMSIG(shell->exit_status) == SIGINT)
			shell->exit_status = 130;
		else if (WTERMSIG(shell->exit_status) == SIGQUIT)
			shell->exit_status = 131;
	}
	else if (WIFEXITED(shell->exit_status))
		shell->exit_status = WEXITSTATUS(shell->exit_status);
	redir->fd = open("/tmp/heredoc_tmp", O_RDONLY);
}
