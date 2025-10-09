/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:src/execution/exec_redirs.c
/*   exec_redirs.c                                      :+:      :+:    :+:   */
========
/*   exec_redirections.c                                :+:      :+:    :+:   */
>>>>>>>> origin/dev:src/execution/exec_redirections.c
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:50:43 by duandrad          #+#    #+#             */
<<<<<<<< HEAD:src/execution/exec_redirs.c
/*   Updated: 2025/10/09 11:58:42 by mrapp-he         ###   ########.fr       */
========
/*   Updated: 2025/10/08 17:18:29 by duandrad         ###   ########.fr       */
>>>>>>>> origin/dev:src/execution/exec_redirections.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_redirects(t_shell *shell)
{
	if (!shell->cmd->redirect)
		return ;
	if (shell->cmd->redirect && !shell->cmd->redirect->next)
		close(shell->cmd->redirect->fd);
	while (shell->cmd->redirect)
	{
		close(shell->cmd->redirect->fd);
		shell->cmd->redirect = shell->cmd->redirect->next;
	}
}

void	open_with_options(t_rdir *redir, int flags, int mode)
{
	int			fd;
	struct stat	f_info;
<<<<<<<< HEAD:src/execution/exec_redirs.c
	t_str		cleaned_filename;
========
	char		*cleaned_filename;
>>>>>>>> origin/dev:src/execution/exec_redirections.c

	if (flags & O_RDONLY)
		cleaned_filename = ft_strdup(redir->args[1]);
	else
		cleaned_filename = remove_quotes(redir->args[1]);
	if (!cleaned_filename)
	{
		redir->fd = -1;
		return ;
	}
	fd = open(cleaned_filename, flags, mode);
	free(cleaned_filename);
	if (fd == -1)
	{
		if (stat(redir->args[1], &f_info) == -1)
			open_error(redir->args[1], 1);
		else if (access(redir->args[1], W_OK) == -1)
			open_error(redir->args[1], 0);
		redir->fd = -1;
		return ;
	}
	redir->fd = fd;
}

void	load_redirections(t_shell *shell)
{
	t_rdir	*redir;
	t_cmd	*cmd;

	load_heredocs(shell);
	cmd = shell->cmd;
	while (cmd)
	{
		redir = cmd->redirect;
		while (redir)
		{
			if (!ft_strncmp(redir->args[0], ">>", 3))
				open_with_options(redir, O_WRONLY | O_CREAT | O_APPEND, 0644);
			else if (!ft_strncmp(redir->args[0], "<", 2))
				open_with_options(redir, O_RDONLY, 0);
			else if (!ft_strncmp(redir->args[0], ">", 2))
				open_with_options(redir, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (redir->fd == -1)
				break ;
			redir = redir->next;
		}
		cmd = cmd->next;
	}
}

void	apply_redirections(t_cmd *cmd)
{
	t_rdir	*curr;

	curr = cmd->redirect;
	while (curr)
	{
		if (curr->fd == -1)
		{
			cmd->skip_exec = true;
			return ;
		}
		if (!ft_strncmp(curr->args[0], "<", 2))
			cmd->redirect_in = curr->fd;
		else if (!ft_strncmp(curr->args[0], ">", 2)
			|| !ft_strncmp(curr->args[0], ">>", 3))
			cmd->redirect_out = curr->fd;
		else if (!ft_strncmp(curr->args[0], "<<", 3))
			cmd->redirect_in = curr->fd;
		curr = curr->next;
	}
}
