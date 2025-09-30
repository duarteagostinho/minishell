/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:05:33 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/30 16:39:23 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_str	ft_str_add(t_vtr str, t_str add)
{
	t_str	tmp;

	tmp = ft_strjoin(*str, add);
	if (!tmp)
		return (NULL);
	free(*str);
	*str = tmp;
	return (tmp);
}

void	cmd_error(t_str cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found...\n", 2);
	shell()->exit_status = 127;
}

t_str	get_path(t_shell *shell, t_str name)
{
	int	  	i;
	t_str	path;
	t_vtr	paths;

	i = -1;
	if (!access(name, X_OK) || is_builtin(name))
		return (name);
	paths = ft_split(get_env_val(shell->env, "PATH"), ':');
	if (!paths)
		return (name);
	while (paths[++i])
	{
		ft_str_add(&paths[i], "/");
		ft_str_add(&paths[i], name);
		if (!access(paths[i], X_OK))
		{
			path = ft_strdup(paths[i]);
			return (free_vtr(paths), free(name), path);
		}
	}
	return (free_vtr(paths), name);
}

int	is_builtin(t_str name)
{
	size_t	size;

	size = ft_strlen(name);
	if (!ft_strncmp("env", name, size))
		return (1);
	else if (!ft_strncmp("export", name, size))
		return (1);
	else if (!ft_strncmp("exit", name, size))
		return (1);
	else if (!ft_strncmp("echo", name, size))
		return (1);
	else if (!ft_strncmp("pwd", name, size))
		return (1);
	else if (!ft_strncmp("cd", name, size))
		return (1);
	else if (!ft_strncmp("unset", name, size))
		return (1);
	return (0);
}