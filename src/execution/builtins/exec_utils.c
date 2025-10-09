/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:05:33 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 18:43:24 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_io(t_cmd *cmd, t_arr in, t_arr out)
{
	if (cmd->redirect_out)
		*out = close_fd(cmd->redirect_out, *out);
	if (cmd->redirect_in)
		*in = close_fd(cmd->redirect_in, *in);
}

void	destroy_fds(void)
{
	int			fd;
	struct stat	fd_info;

	fd = 2;
	while (++fd < FOPEN_MAX)
	{
		if (fstat(fd, &fd_info) == 0)
			close(fd);
	}
}

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

t_str	get_path(t_shell *shell, t_str name)
{
	int		i;
	t_str	path;
	t_vtr	paths;

	i = -1;
	if (!access(name, X_OK) || is_builtin(name))
		return (name);
	paths = ft_split(shell->path, ':');
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
	if (!ft_strcmp("env", name))
		return (1);
	else if (!ft_strcmp("export", name))
		return (1);
	else if (!ft_strcmp("exit", name))
		return (1);
	else if (!ft_strcmp("echo", name))
		return (1);
	else if (!ft_strcmp("pwd", name))
		return (1);
	else if (!ft_strcmp("cd", name))
		return (1);
	else if (!ft_strcmp("unset", name))
		return (1);
	return (0);
}
