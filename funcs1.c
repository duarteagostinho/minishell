/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:24:42 by duandrad          #+#    #+#             */
/*   Updated: 2025/05/19 14:49:56 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

pid_t	ft_getpid(void)
{
	pid_t	pid;

	
	pid = getpid();
	if (pid < 1)
		return (-1);
	return (pid);
}

void	signal_setup(int process)
{
/*	if (process == PARENT)
	else if (process == CHILD)
	else if (process == IGNORE)

Sets up signal handlers.

configures signal handlers based on the provided process type. For the parent process, SIGINT is set to parent_handler_sig, and the SIGQUIT signal is ignored. For the child process, both SIGINT and SIGQUIT are set to their default behavior. For IGNORE, both SIGINT and SIGQUIT are ignored.

Parameters
[in]	process	An int representing the process type (PARENT or CHILD, IGNORE).

	*/
}

void	check_exitcode(int wstatus, bool *is_print)
{
	/* Checks the exit code of a child process and update g_exit_code.

Checks the exit code of a child process and updates g_exit_code based on wether the process exited normally or was terminated by a signal. If the process exited normally, the exit status is used. If the process was terminated bt a signal, the signalnumber is added to the base (128) to set the exit code.

Parameters
[in]	wstatus	The status of the child process.
[in,out]	is_print	A pointer to a boolean indicating wether to print the SIGQUIT message.
 */
}

t_shell	*init_shell(char **envp)
{
	/* Initializes the main data structure (shell environment).

Starts the process of initializing the shell's main data structure, which includes components such as the environment variables in a linked list and other relevant information.

Parameters
[in]	envp	A 2D char array of environment variables.
Returns
A pointer to the initialized main data structure (shell environment). */
}

t_environ_list	*init_environ(char **envp)
{
	/* Initializes the environment variables linked list.

Initializes a linked list to store environment variables based on the provided 2D array of environment variables.

Parameters
[in]	envp	A 2D array of environment variables.
Returns
A pointer to the initialized environment variables linked list,
 or NULL in case of memory allocation failure. */
}

t_environ_list	*empty_environ(t_environ_list *environ)
{
	/* Initializes environment variables for an empty environment.

Initializes environment variables for an empty environment, such as adding the "PWD" and "SHLVL" variables to the provided environment variables linked list.

Parameters
[in]	environ	A pointer to the environment variables linked list.
Returns
A pointer to the updated environment variables linked list, or Null in case of failure to obtain CWD. */
}

void	lvl_up(t_shell *shell)
{
	/* Increases the shell level (SHLVL) environment variable.

Increments the value of the shell level (SHLVL) environment variable. If the variable doesn't exist, it is added with a value of 1.

Parameters
[in,out]	shell	A pointer to the shell data structure.
 */
}

t_environ_node	*create_environ_node(string var)
{
	/* Creates an node for an environment variable linked list.

Creates and initializes an node using the provided parameter string. The string is typically in the format "KEY=VALUE", where KEY is the variable name and VALUE is its value ("duhh").

Parameters
[in]	var	The string representing the environment variable in the "KEY=VALUE" format.
Returns
A pointer to the created environment variable node, or NULL in case of memory allocation error or invalid input. */
}

t_environ_node	*add_back_env_node(t_environ_list *env, t_environ_node *node)
{
	/* 
Adds an node to the end of an environment variables linked list.

Adds a given node to the end of an environment variable linked list. The linked list's size is incremented accordingly.

Parameters
[in,out]	environ	A pointer to the environment variables linked list.
[in]	node	A pointer to the node to be added.
Returns
A pointer to the added node, or NULL if input parameters are invalid. */
}


t_environ_node	*get_node(t_environ_list *environ, string key)
{
	/* Find an node by the key from an environment variables linked list.

Searches for an node with a specific key, given as parameter, in the environment variables linked list, given as parameter. Returns the matching node.

Parameters
[in]	environ	A pointer to the environment linked list.
[in]	key	The KEY ov the environment variable to search for.
Returns
A pointer the the found node, or NULL if not found or parameters are invalid. */
}


char	**free_str_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i]);
	free(arr);
	return (NULL);
}


