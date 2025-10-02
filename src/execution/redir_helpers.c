/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:50:43 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/02 14:19:58 by duandrad         ###   ########.fr       */
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
	int	 fd;
	fd = open(redir->args[1], flags, mode);
	if (fd < 0)
	{
		perror("Error: Unable to open fd\n");
		return;
	}
	redir->fd = fd;
}
void	load_redirections(t_shell *shell)
{
	t_rdir  *redir;
	redir = shell->cmd->redirect;
	while (redir)
	{
		if (!ft_strncmp(redir->args[0], "<<", 3))
			handle_heredoc(redir, shell, shell->env);
		else if (!ft_strncmp(redir->args[0], ">>", 3))
			open_with_options(redir, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (!ft_strncmp(redir->args[0], "<", 2))
			open_with_options(redir, O_RDONLY, 0);
		else if (!ft_strncmp(redir->args[0], ">", 2))
			open_with_options(redir, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		redir = redir->next;
	}
}
void	apply_redirections(t_shell *shell)
{
	t_rdir  *curr;
	curr = shell->cmd->redirect;
	while (curr)
	{
		if (!ft_strncmp(curr->args[0], "<", 2))
			shell->cmd->redirect_in = curr->fd;
		else if (!ft_strncmp(curr->args[0], ">", 2)
			|| !ft_strncmp(curr->args[0], ">>", 3))
			shell->cmd->redirect_out = curr->fd;
		else if (!ft_strncmp(curr->args[0], "<<", 3))
			shell->cmd->redirect_in = curr->fd;
		curr = curr->next;
	}
}
