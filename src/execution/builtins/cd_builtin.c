/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:35:35 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/08 22:09:42 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(t_shell *shell, t_cmd *cmd, t_str lwd, t_str cwd)
{
	t_str	pwd;
	t_str	old_pwd;
	t_str	tmp1;
	t_str	tmp2;

	if (!cwd)
		return (cmd_error(cmd->args[0], strerror(errno), 0));
	pwd = ft_strdup("PWD=");
	old_pwd = ft_strdup("OLDPWD=");
	pwd = ft_str_add(&pwd, cwd);
	old_pwd = ft_str_add(&old_pwd, lwd);
	tmp1 = ft_strdup(pwd);
	tmp2 = ft_strdup(old_pwd);
	add_env_var(&shell->env, "PWD", pwd);
	add_env_var(&shell->env, "OLDPWD", old_pwd);
	add_env_var(&shell->exports, "PWD", tmp1);
	add_env_var(&shell->exports, "OLDPWD", tmp2);
	free(cwd);
	free(lwd);
}

int	ft_cd(t_shell *shell, t_cmd *cmd)
{
	int		size;
	t_str	cwd;
	t_str	home;

	size = get_sizeof_args(cmd->args);
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (cmd_error(cmd->args[0], strerror(errno), 0), EXIT_FAILURE);
	home = shell->home;
	if (size > 0 && size < 3)
	{
		if (size == 2)
			home = cmd->args[1];
		if (!home || chdir(home) == -1)
		{
			free(cwd);
			return (cmd_error(cmd->args[0], strerror(errno), 0), EXIT_FAILURE);
		}
		update_pwd(shell, cmd, cwd, getcwd(NULL, 0));
		return (EXIT_SUCCESS);
	}
	else if (size > 2)
		cmd_error(cmd->args[0], NULL, 2);
	free(cwd);
	return (EXIT_FAILURE);
}
