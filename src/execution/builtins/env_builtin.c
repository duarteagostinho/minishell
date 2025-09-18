/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:17:40 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/09/03 15:30:40 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/minishell.h"

static void	cmd_error(t_str cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found...\n", 2);
}

int	exec_external(t_shell *shell, t_cmd *cmd)
{
	int	  	i;
	t_str	tmp;
	t_str	path;
	t_vtr	paths;

	i = -1;
	if (!access(cmd->args[0], X_OK)
	&& !execve(cmd->args[0], cmd->args, shell->env))
		return (EXIT_SUCCESS);
	paths = ft_split(get_env_val(shell->env, "PATH"), ':');
	if (!paths)
		return (EXIT_FAILURE);
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (free_vtr(paths), EXIT_FAILURE);
		path = ft_strjoin(tmp, cmd->args[0]);
		if (path && !access(path, X_OK)
		&& !execve(path, cmd->args, shell->env))
			return (free_vtr(paths), free(tmp), free(path), EXIT_SUCCESS);
	}
	cmd_error(cmd->args[0]);
	return (free_vtr(paths), free(tmp),	free(path), EXIT_FAILURE);
}

int	env(t_shell *shell)
{
	int		i;

	i = -1;
	if (get_sizeof_args(shell->cmd->args) < 1)
		return (EXIT_FAILURE);
	while (shell->env[++i])
		printf("%s\n", shell->env[i]);
	return (EXIT_SUCCESS);
}
