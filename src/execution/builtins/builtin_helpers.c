/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:59:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/03 01:12:23 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

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

t_func  is_builtin(t_str command)
{
	if (!ft_strncmp("env", command, 4))
		return (env);
	else if (!ft_strncmp("export", command, 7))
		return (ft_export);
	else if (!ft_strncmp("exit", command, 5))
		return (ft_exit);
	else if (!ft_strncmp("echo", command, 5))
		return (echo);
	else if (!ft_strncmp("pwd", command, 4))
		return (pwd);
	else if (!ft_strncmp("cd", command, 3))
		return (cd);
	else if (!ft_strncmp("unset", command, 6))
		return (unset);
	return (NULL);
}

t_str is_external(t_shell *shell)
{
	int	  i;
	t_str tmp;
	t_str path;
	t_vtr paths;

	path = shell->cmd->args[0];
	if (access(path, X_OK) == 0)
		return (path);
	i = -1;
	paths = ft_split(get_env_val(shell->env, "PATH"), ':');
	if (!paths)
		return (NULL);
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, shell->cmd->args[0]);
		if (access(path, X_OK) == 0)
			return ( free_vtr(paths), free(tmp), path);
		free(tmp);
		free(path);
	}
	return (printf("Command not found %s\n", path), free_vtr(paths), free(tmp),	free(path), NULL);
}
