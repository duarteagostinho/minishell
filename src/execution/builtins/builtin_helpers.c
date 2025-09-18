/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:59:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/25 16:27:59 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

int	commands_size(t_cmd *cmd)
{
	t_cmd	*curr;
	int		size;

	curr = cmd;
	size = 0;
	while (curr && ++size)
		curr = curr->next;
	return (size);
}

void	ft_swap(void **a, void **b)
{
	void *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_valid_id(const t_str key)
{
	int	i;

	i = 0;
	if (!key || !key[i] || (!ft_isalpha(key[i]) && key[i] != '_'))
		return (EXIT_FAILURE);
	while (key[i] && (ft_isalnum(key[i]) || key[i] == '_'))
		i++;
	if (key[i] != '\0' && key[i] != '=')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	exec_command(t_shell *shell, t_cmd *cmd)
{
	size_t	size;

	size = ft_strlen(cmd->args[0]) + 1;
	if (!ft_strncmp("env", cmd->args[0], size))
		return (env(shell));
	else if (!ft_strncmp("export", cmd->args[0], size))
		return (ft_export(shell));
	else if (!ft_strncmp("exit", cmd->args[0], size))
		return (ft_exit(shell));
	else if (!ft_strncmp("echo", cmd->args[0], size))
		return (echo(shell));
	else if (!ft_strncmp("pwd", cmd->args[0], size))
		return (pwd(shell));
	else if (!ft_strncmp("cd", cmd->args[0], size))
		return (cd(shell));
	else if (!ft_strncmp("unset", cmd->args[0], size))
		return (unset(shell));
	return (-1);
}

t_str is_external(t_shell *shell)
{
	int	  i;
	t_str tmp;
	t_str path;
	t_vtr paths;

	i = -1;
	paths = ft_split(get_env_val(shell->env, "PATH"), ':');
	if (!paths)
		return (NULL);
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, shell->cmd->args[0]);
		if (access(path, X_OK) == 0)
			return (free_vtr(paths), free(tmp), path);
	}
	return (free_vtr(paths), free(tmp),	free(path), NULL);
}
