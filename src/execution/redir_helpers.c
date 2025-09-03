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
	if (!redir)
		return;
	while(redir)
	{
		if (ft_strncmp(redir->args[0], ">>", 3) == 0)
			append_redir(redir);
		else if (ft_strncmp(redir->args[0], "<<", 3) == 0)
			handle_heredoc(redir);
		else if (ft_strncmp(redir->args[0], "<", 2) == 0)
			input_redir(redir);
		else if (ft_strncmp(redir->args[0], ">", 2) == 0)
			output_redir(redir);
		redir = redir->next;
	}
}

void	setup_redirection(t_shell *shell)
{
	if (shell->cmd->redirect)
	{
		shell->cmd->redirect_in = dup(STDIN_FILENO);
		shell->cmd->redirect_out = dup(STDOUT_FILENO);
	}
	else
	{
		shell->cmd->redirect_in = -1;
		shell->cmd->redirect_out = -1;
	}
}
void	restore_redirections(t_shell *shell)
{
	if(shell->cmd->redirect_in != -1)
	{
		dup2(shell->cmd->redirect_in, STDIN_FILENO);
		close(shell->cmd->redirect_in);
	}
	if (shell->cmd->redirect_out != -1)
	{
		dup2(shell->cmd->redirect_out, STDOUT_FILENO);
		close(shell->cmd->redirect_out);
	}
}

