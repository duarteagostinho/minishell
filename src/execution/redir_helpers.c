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

void	exec_redirections(t_shell *shell)
{
	t_rdir	*redir;

	redir = shell->cmd->redirect;
	while (redir)
	{
		if (ft_strncmp(redir->args[0], "<<", 3) == 0)
			handle_heredoc(redir, shell, shell->env);
		redir = redir->next;
	}
}

void	apply_redirections(t_shell *shell)
{
	t_rdir	*redir;

	redir = shell->cmd->redirect;
	while (redir)
	{
		if (ft_strncmp(redir->args[0], "<<", 3) == 0)
			dup2(redir->fd, STDIN_FILENO);
		else if (ft_strncmp(redir->args[0], ">>", 3) == 0)
			append_redir(redir);
		else if (ft_strncmp(redir->args[0], "<", 2) == 0)
			input_redir(redir);
		else if (ft_strncmp(redir->args[0], ">", 2) == 0)
			output_redir(redir);
		redir = redir->next;
	}
}
