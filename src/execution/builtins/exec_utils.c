/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:05:33 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/03 18:35:53 by mrapp-he         ###   ########.fr       */
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
	int		i;
	t_str	path;
	t_vtr	paths;

	i = -1;
	if (!access(name, X_OK) || is_builtin(&name))
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

int	is_builtin(t_vtr args)
{
	if (ft_strlen(args[0]) == 0)
		return (-1);	
	if (!ft_strcmp("env", args[0]))
		return (1);
	else if (!ft_strcmp("export", args[0]))
		return (1);
	else if (!ft_strcmp("exit", args[0]))
		return (1);
	else if (!ft_strcmp("echo", args[0]))
		return (1);
	else if (!ft_strcmp("pwd", args[0]))
		return (1);
	else if (!ft_strcmp("cd", args[0]))
		return (1);
	else if (!ft_strcmp("unset", args[0]))
		return (1);
	return (0);
}
