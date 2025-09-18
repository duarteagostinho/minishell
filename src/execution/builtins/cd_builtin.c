/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:35:35 by duandrad          #+#    #+#             */
/*   Updated: 2025/08/31 19:37:23 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	update_pwd(t_shell *shell, t_str lwd, t_str cwd)
{
	if (!add_env_var(&shell->env, "PWD", cwd) || !add_env_var(&shell->env, "OLDPWD", lwd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);	
}

int	cd(t_shell *shell)
{
	t_str	cwd;
	t_str	home;

	cwd = getcwd(NULL, 0);
	home = get_env_val(shell->env, "HOME");
	if (get_sizeof_args(shell->cmd->args) == 1)
	{
		if (!home || chdir(home) == -1)
			return (EXIT_FAILURE);
		return (update_pwd(shell, cwd, getcwd(NULL, 0)));
	}
	else if (get_sizeof_args(shell->cmd->args) == 2)
	{
		if (chdir(shell->cmd->args[1]) == -1)
			return (EXIT_FAILURE);
		return (update_pwd(shell, cwd, getcwd(NULL, 0)));
	}
	return (EXIT_FAILURE);
}
