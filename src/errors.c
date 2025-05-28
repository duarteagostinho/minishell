/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:51:34 by duandrad          #+#    #+#             */
/*   Updated: 2025/05/27 19:52:01 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"
#include <stdio.h>

void  check_errno(t_shell *shell, string path)
{
/*Check and handle errors related to command execution.

The check_errno function checks the value of the errno variable and sets the appropriate exit code and error message based on whether the command was not found or permission was denied.

Parameters
[in]	shell	A pointer to the shell struct containing the executor.
[in]	path	The path to the executable.*/
}

void  get_path_error(string str)
{
/*Handle errors when obtaining an empty path to an executable.

The get_path_error function sets the errno and exit code for when the path is empty or the executable was not found and prints an error message.

Parameters
[in]	str	The name of the executable.*/
}

void  transform_error(char **env_array)
{
/*Error handling while copying the environment list into the array.

The transform_error function is called when an error occurs during the copying process. It frees the allocated memory for the array and reports an error.

Parameters
[in]	environ_array	A pointer to the environment array to be freed.
*/
}
