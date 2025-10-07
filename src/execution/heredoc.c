/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:55:07 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/07 22:08:48 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_heredoc_content(bool expand, int fd, char *delimiter,
	t_shell *shell)
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
		process_heredoc_line(line, expand, fd, shell);
		free(line);
	}
}

static void	create_heredoc_file(char *filename, char *delimiter,
	t_shell *shell, bool expand)
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
		free(delimiter);
		ft_exit(shell);
	}
	signal_setup(shell, HEREDOC);
	write_heredoc_content(expand, fd, delimiter, shell);
	close(fd);
	free(delimiter);
	ft_exit(shell);
}

static void	open_heredoc_file(t_rdir *redir)
{
	struct stat	f_info;

	redir->fd = open("/tmp/heredoc_tmp", O_RDONLY);
	if (redir->fd == -1)
	{
		if (stat("/tmp/heredoc_tmp", &f_info) == -1)
			open_error("/tmp/heredoc_tmp", 1);
		else if (access("/tmp/heredoc_tmp", R_OK) == -1)
			open_error("/tmp/heredoc_tmp", 0);
	}
}

void	handle_heredoc(t_rdir *redir, t_shell *shell)
{
	pid_t		pid;
	char		*clean_delm;
	bool		exp;

	clean_delm = NULL;
	if (!redir || !redir->args[1])
		return ;
	exp = check_delm(redir);
	clean_delm = remove_quotes(redir->args[1]);
	if (!clean_delm)
		return ;
	pid = fork();
	if (pid == -1)
	{
		free(clean_delm);
		return ;
	}
	if (pid == 0)
		create_heredoc_file("/tmp/heredoc_tmp", clean_delm, shell, exp);
	signal_setup(shell, IGNORE);
	wait_heredocs(shell, pid);
	free(clean_delm);
	open_heredoc_file(redir);
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
