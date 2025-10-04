/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:55:07 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/04 13:06:34 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wait_heredocs(t_shell *shell, int pid)
{
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
}

static void	write_heredoc_content(int fd, char *delimiter, t_shell *shell)
{
	char	*line;

	signal_setup(shell, HEREDOC);
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

static void	create_heredoc_file(char *filename, char *delimiter, t_shell *shell)
{
	int			fd;
	struct stat	f_info;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0640);
	if (fd == -1)
	{
		if (stat(filename, &f_info) == -1)
			open_error(filename, 1);
		else if (access(filename, W_OK) == -1)
			open_error(filename, 0);
		ft_exit(shell);
	}
	write_heredoc_content(fd, delimiter, shell);
	close(fd);
	ft_exit(shell);
}

void	load_heredocs(t_shell *shell)
{
	t_rdir	*redir;
	t_cmd	*cmd;

	cmd = shell->cmd;
	while (cmd)
	{
		redir = cmd->redirect;
		while (redir)
		{
			if (!ft_strncmp(redir->args[0], "<<", 3))
				handle_heredoc(redir, shell);
			signal_setup(shell, PARENT);
			redir = redir->next;
		}
		cmd = cmd->next;
	}
}

void	handle_heredoc(t_rdir *redir, t_shell *shell)
{
	pid_t		pid;
	struct stat	f_info;

	if (!redir || !redir->args[1])
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		create_heredoc_file("/tmp/heredoc_tmp", redir->args[1], shell);
	signal_setup(shell, IGNORE);
	wait_heredocs(shell, pid);
	redir->fd = open("/tmp/heredoc_tmp", O_RDONLY);
	if (redir->fd == -1)
	{
		if (stat("/tmp/heredoc_tmp", &f_info) == -1)
			open_error("/tmp/heredoc_tmp", 1);
		else if (access("/tmp/heredoc_tmp", R_OK) == -1)
			open_error("/tmp/heredoc_tmp", 0);
	}
}
