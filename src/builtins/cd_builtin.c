/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:35:35 by duandrad          #+#    #+#             */
/*   Updated: 2025/05/28 17:07:42 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"


void	update_old(t_shell *shell, string old)
{
/* Update OLDPWD.

Updates the OLDPWD environment variable with the value of the previous working directory before the change.

Parameters
[in]	shell	A pointer to the shell struct.
[in]	old	The previous working directory.
 */
	shell->environ->head->value
}

int	env_var_update(t_shell *shell, string old, string new)
{
/* Update PWD after directory change.

Updates the environment variable PWD and passes the OLDPWD to the other update function.

Parameters
[in]	shell	A pointer to the shell struct.
[in]	old	The previous working directory.
[in]	new	The new working directory.
Returns
An exit status (EXIT_SUCCESS on success, EXIT_FAILURE on failure). */
}

int	cd_no_args(t_shell *shell)
{
/* Handles the case when changing to a directory with no arguments.

This function is called when the cd command is executed without any arguments. It attempts to change the current working directory to the user's home directory (retrieved from the environment variable HOME).

Parameters
[in]	shell	A pointer to the shell struct.
Returns
An exit status (EXIT_SUCCESS on success, EXIT_FAILURE on failure). */
}

int	cd(t_shell *shell, char **args)
{
/* Handles changing the current working directory with specified arguments.

This function is called when the cd command is executed with one argument, which is the target directory to change to. It checks the number of arguments, validates the input, and attempts to change the current working directory.

Parameters
[in]	shell	A pointer to the shell struct.
[in]	args	An array of strings containing command arguments.
Returns
An exit status (EXIT_SUCCESS on success, EXIT_FAILURE on failure). */
}

