#include "minishell.h"

void  close_redirects(t_shell *shell)
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
	int		fd;

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
	t_rdir	*redir;

	redir = shell->cmd->redirect;
	while (redir)
	{
		if (ft_strncmp(redir->args[0], "<<", 3) == 0)
			handle_heredoc(redir, shell, shell->env);
		else if (ft_strncmp(redir->args[0], ">>", 3) == 0)
			open_with_options(redir, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (ft_strncmp(redir->args[0], "<", 2) == 0)
			open_with_options(redir, O_RDONLY, 0);
		else if (ft_strncmp(redir->args[0], ">", 2) == 0)
			open_with_options(redir, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		redir = redir->next;
	}
}

void	apply_redirections(t_shell *shell)
{
	t_rdir	*curr;
	t_rdir	*prev;

	prev = NULL;
	curr = shell->cmd->redirect;
	while (curr)
	{
		if (prev)
			close(prev->fd);
		if (ft_strncmp(curr->args[0], "<", 2) == 0)
			dup2(curr->fd, STDIN_FILENO);
		else if (ft_strncmp(curr->args[0], ">", 2) == 0
			|| ft_strncmp(curr->args[0], ">>", 3) == 0)
			dup2(curr->fd, STDOUT_FILENO);
		else if (ft_strncmp(curr->args[0], "<<", 3) == 0)
			dup2(curr->fd, STDIN_FILENO);
		prev = curr;
		curr = curr->next;
	}
}
