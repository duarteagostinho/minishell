#include "minishell.h"

void free_vtr(t_vtr args)
{
	int	i;

	i = -1;
	if (!args)
		return ;
	while (args[++i])
	{
		if (args[i])
			free(args[i]);
	}
	free(args);
}

void  free_cmds(t_cmd *commands)
{
	t_cmd	*current;
	t_cmd	*next;

	current = commands;
	while (current)
	{
		next = current->next;
		if (current->args)
			free_vtr(current->args);
		if (current->redirect)
			free_rdirs(current->redirect);
		free(current);
		current = next;
	}
}

void	free_rdirs(t_rdir *redirects)
{
	t_rdir	*current;
	t_rdir	*next;

	current = redirects;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void  free_shell(t_shell *shell)
{
	if (shell)
	{
		if (shell->cmd)
			free_cmds(shell->cmd);
		if (shell->env)
			free_vtr(shell->env);
	}
}
