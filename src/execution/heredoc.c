/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:55:07 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/09 15:35:05 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_heredoc_content(bool expand, int fd, t_str delimiter, t_cmd *cmd)
{
	t_str	line;

	signal_setup(shell(), HEREDOC);
	while (1)
	{
		shell()->exit_status = 0;
		line = readline("> ");
		if (!line)
			ft_exit(shell(), cmd);
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		process_heredoc_line(line, expand, fd, shell());
		free(line);
	}
}

void	create_heredoc_file(t_str file, t_str delimit, t_cmd *cmd, bool exp)
{
	int			fd;
	struct stat	f_info;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0640);
	if (fd == -1)
	{
		if (stat(file, &f_info) == -1)
			open_error(file, 1);
		else if (access(file, W_OK) == -1)
			open_error(file, 0);
		free(delimit);
		ft_exit(shell(), cmd);
	}
	write_heredoc_content(exp, fd, delimit, cmd);
	close(fd);
	free(delimit);
	ft_exit(shell(), cmd);
}

void	open_heredoc_file(t_rdir *redir)
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

void	handle_heredoc(t_rdir *redir, t_shell *shell, t_cmd *cmd)
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
		create_heredoc_file("/tmp/heredoc_tmp", clean_delm, cmd, exp);
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
				handle_heredoc(redir, shell, cmd);
			signal_setup(shell, PARENT);
			redir = redir->next;
		}
		cmd = cmd->next;
	}
}
