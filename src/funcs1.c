/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:24:42 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/03 18:48:48 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"

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

t_environ_node	*create_environ_node(char* var)
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


t_environ_node	*get_node(t_environ_list *environ, char* key)
{
	/* Find an node by the key from an environment variables linked list.

Searches for an node with a specific key, given as parameter, in the environment variables linked list, given as parameter. Returns the matching node.

Parameters
[in]	environ	A pointer to the environment linked list.
[in]	key	The KEY ov the environment variable to search for.
Returns
A pointer the the found node, or NULL if not found or parameters are invalid. */
}

void	set_path_executor(t_executor *list, t_environ_list *env)
{
	/* Sets the path variable for t_executor nodes.

Sets the path variable for t_executor nodes in the provided linked list. If PATH doesn't exist then t_executor->path remains at default(NULL);

Parameters
list	A pointer to the head of the t_executor linked list.
environ	A pointer to the environ linked list. */
}

int	process_out_append(t_executor *current, t_lexer_list *lexer)
{
/* Processes output redirections and append for the given node of the executor list.

Handles output redirections and append for the given executor list node by calling its subfunctions. Has some edgecase handling.

Parameters
current	A pointer to the current t_executor node.
lexer	A pointer to the current lexer list node.
Returns
OK if successful, FAILED if an error occurs, NOT_FOUND if not applicable. */
}

int	get_size_execs(t_lexer_list *lexer)
{
/* Calculates the number of consecutive NONE type lexer list nodes.

Calculates the number of command arguments based on the number of consecutive NONE type tokens in the lexer list. Each NONE token represents one of the following: a command(executable/buildin), a command option(-i –version), or a command argument(filenames, etc).

Parameters
lexer	A pointer to the current lexer list node.
Returns
The number of consecutive NONE type tokens found. */
}

char	**get_execs_array(t_lexer_list *lexer, int size)
{
/* Creates an array of the found NONE type tokens from the lexer list.

Allocates memory for an array of NONE tokens. Fills the array with the strings from the consecutive NONE type tokens in the lexer list.

Parameters
lexer	A pointer to the current lexer list node.
int	The size of the array.
Returns
A pointer to the allocated array, or NULL if allocation failed. */
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

int	get_sizeof_args(char **args)
{
/* Retrieves the number of arguments in an array of strings.

This function counts the number of elements (arguments) in an array of strings and returns the count.

Parameters
[in]	args	An array of strings containing command arguments.
Returns
The number of arguments in the array. */
}

int export_no_args(t_shell *shell)
{
/*Handles the "export" command without arguments.

This function is called when the export command is executed without any arguments. It displays the names and values of all currently set environment variables in the "declare -x KEY=VALUE" format.

Parameters
[in]	shell	A pointer to the shell struct.
Returns
An exit status (EXIT_SUCCESS on success, or an error code on failure).*/
}

void  exporting(t_shell *shell, char* str)
{
/*Updates or creates environment variables based on user-provided arguments.

This function processes individual argument strings and sets or modifies environment variables accordingly. It checks for the validity of identifiers and updates their values.

Parameters
[in]	shell	A pointer to the shell struct.
[in]	str	The argument string to be processed and used as an environment variable.*/
}

int export_args(t_shell *shell, char **args)
{
/*Handles the export command with specified arguments.

This function is called when the export command is executed with one or more arguments. It processes the arguments and sets or modifies environment variables accordingly.

Parameters
[in]	shell	A pointer to the shell struct.
[in]	args	An array of strings containing the arguments.
Returns
An exit status (EXIT_SUCCESS on success, or an error code on failure).*/
}

int export(t_shell *shell, char **args)
{
/*Implements the export builtin function.

This function is responsible for executing the export command. It handles cases where the command is executed with or without arguments and calls the appropriate functions to set or display environment variables. When executed with arguments, it processes each argument and sets or modifies the corresponding environment variable. If executed without arguments, it displays the names and values of all currently set environment variables in the "declare -x KEY=VALUE" format.

Parameters
[in]	shell	A pointer to the shell struct.
[in]	args	An array of strings containing the arguments.
Returns
An exit status (EXIT_SUCCESS on success, or an error code on failure).*/
}

int env(t_shell *shell, char **args)
{
/*Displays the environment variables and their values.

This function implements the "env" command, which is used to display the environment variables and their corresponding values to the standard output.

Parameters
[in]	shell	A pointer to the shell struct.
[in]	args	An array of strings containing the arguments.
Returns
An exit status (EXIT_SUCCESS on success, or an error code on failure).*/
}

void  child(t_shell *shell, char **args, int nbr)
{
/*Handles the exit command when executed within a child process.

This function is called when the exit command is executed within a child process. It handles the termination of the child process based on the provided arguments, including the exit status.

Parameters
[in]	shell	A pointer to the shell struct.
[in]	args	An array of strings containing the arguments.
[in]	number	The number of arguments in the array.*/
}

void  handle_child(t_shell *shell, char **args, int nbr)
{
/*Handles the exit command when executed within a child process.

This function is called when the exit command is executed within a child process. It handles the termination of the child process based on the provided arguments, including the exit status.

Parameters
[in]	shell	A pointer to the shell struct.
[in]	args	An array of strings containing the arguments.
[in]	number	The number of arguments in the array.*/
}

int exit_builtin(t_shell *shell, char **args, bool is_child)
{
/*Handles the exit command when executed in a child process.

This function is called when the exit command is executed within a child process. It handles the termination of the child process based on the provided arguments.

Parameters
[in]	shell	A pointer to the shell struct.
[in]	args	An array of strings containing the arguments.
[in]	in_child	A boolean indicating whether the function is called in a child process.
Returns
The exit status of the child process.*/
}

void  delete_variable(t_shell *shell, char* arg)
{
/*Deletes an environment variable.

This function deletes an environment variable specified by its name (arg) from the shell's environment linked list. It finds the variable to delete and removes it from the linked list, freeing the associated memory.

Parameters
[in,out]	shell	A pointer to the shell struct.
[in]	arg	The name of the environment variable to delete.*/
}

void  unset_arg(t_shell *shell, char* arg, int *fails)
{
/*Unsets an environment variable or prints an error message.

This function unsets an environment variable specified by its name (arg) if it's a valid identifier (starts with an alphabetic character or '_'). If the identifier is not valid, it prints an error message and increments the failure count.

Parameters
[in,out]	shell	A pointer to the shell struct.
[in]	arg	The name of the environment variable to unset.
[in,out]	fails	A pointer to the failure count.*/
}

int unset(t_shell *shell, char **args)
{
/*Executes the "unset" command to remove environment variables.

This function processes the "unset" command and removes the specified environment variables based on the provided arguments. It returns EXIT_SUCCESS on success or EXIT_FAILURE if any errors occurred.

Parameters
[in,out]	shell	A pointer to the shell struct.
[in]	args	An array of strings containing the arguments.
Returns
An exit status (EXIT_SUCCESS on success, or EXIT_FAILURE on failure).*/
}

int echo(char **args)
{
/*Implements the "echo" command to display text to the standard output.

This function handles the "echo" command, which displays text to the standard output. It can be called with multiple arguments, and it processes the -n option to omit the trailing newline character.

Parameters
[in]	args	An array of strings containing the arguments.
Returns
An exit status EXIT_SUCCESS always.*/
}

t_expander  *init_expander(char* str)
{
/*Initializes the expander struct for variable expansion.

This function initializes the expander struct used during variable expansion. It allocates memory for various fields and sets their initial values.

Parameters
[in]	str	The input string to be expanded.
Returns
A pointer to the initialized expander struct or NULL on allocation failure.
*/
}

char*  realloc_str(char* original, int pos)
{
/*Reallocates memory for a string.

This function reallocates memory for a string, extending its size while preserving its existing content. It is used to dynamically expand the result string during variable expansion.

Parameters
[in]	res	The original string to be reallocated.
[in]	pos	The current position in the result string.
Returns
A pointer to the reallocated string or NULL on allocation failure.
*/
}

void  close_fds(t_executor *current)
{
/*Close file descriptors based on command redirection settings.

This function is responsible for closing file descriptors associated with input and output redirection, as determined by the settings in the current executor node.

Parameters
[in]	current	A pointer to the executor struct.*/
}

void  handle_single(t_shell *shell)
{
/*Handle the execution of a single command.

The handle_single function first checks if the command is an empty string and fails accordingly. If the command is a builtin it would execute it in the parent process, otherwise it would do a fork and execute the external command in the child process.

Parameters
[in,out]	shell	A pointer to the shell struct.
*/
}

void  executor(t_shell *shell)
{
/*Primary entrypoint of command execution.

The executor function determines whether to handle a single command or multiple command based on the size of commands passed to it.

Parameters
[in,out]	shell	A pointer to the shell struct*/
}

bool  is_builtin(char* cmd)
{
  if(ft_strcmp(cmd, "echo") == 0 ||
     ft_strcmp(cmd, "cd") == 0 ||
     ft_strcmp(cmd, "pwd") == 0 || 
     ft_strcmp(cmd, "export") == 0 || 
     ft_strcmp(cmd, "unset") == 0 || 
     ft_strcmp(cmd, "env") == 0 || 
     ft_strcmp(cmd, "exit") == 0)
      return (true);
  return (false);
}

void  execute_builtin(t_shell *shell)
{
/*Execute a builtin-command.

The execute_builtin function executes the appropriate builtin-command based on the provided command name in the execs array. It sets the global g_exit_code variable to the exit status of the command.

Parameters
[in,out]	shell	A pointer to the shell struct.
*/
}

int handle_single_builtin(t_shell *shell)
{
/*Handle the execution of a single builtin-command.

The handle_single_builtin function checks if the provided command is a builtin, saves the file descriptors, handles standard input and output redirections, executes the builtin-command and restores standard file descriptors.

Parameters
[in,out]	shell	A pointer to the shell struct.
Returns
The status code indicating the execution result.*/
}

void  saving_stds(int *stdin_cpy, int *stdout_cpy)
{
/*Save the stdin and stdout file descriptors.

The saving_stds function saves the stdin and stdout file descriptors by duplicating and storing them.

Parameters
[out]	stdin_cpy	A pointer to store the duplicated stdin file descriptor.
[out]	stdout_cpy	A pointer to store the duplicated stdout file descriptor.
*/
}

bool  restore_stds(int stdin_cpy, int stdout_cpy)
{
/*Restore the stdin and stdout file descriptors.

The restore_stds function restores the standard input and output file descriptors by duplicating the saved file descriptors back to stdin and stdout. It also handles errors if somehow the restoration fails.

Parameters
[in]	stdin_cpy	The duplicated stdin file descriptor.
[in]	stdout_cpy	The duplicated stdout file descriptor.
Returns
Returns true if the restoration is successful, or false if an error occurs.*/
}

void  handle_single_child(t_shell *shell)
{
/*Process creation for execution of non-builtin command.

The handle_single_child function creates a child process and executes a non-built-in command in the child process. It waits for the child process to complete and updates the environment variable "_=".

Parameters
[in,out]	shell	A pointer to the shell struct.*/
}

bool  handle_redirs_single_child(t_shell *shell)
{
/*Handle redirections for single non-builtin command in child process.

The handle_redirections_single_child function handles redirections for a single non-builtin command. It duplicates the file descriptors needed by the child process and closes back the copy.

Parameters
[in,out]	shell	A pointer to the shell struct.
Returns
Returns true if redirections are successfully handled, or false if an error occurs.
*/
}

char*  get_abs_path(t_shell *shell)
{
/*Transform the non-absolut path into one.

The get_absolute_path function constructs the absolute path to an executable by combining it with each directory in the PATH environment variable. If the provided executable path is not absolute and is found in PATH, it is converted to an absolute path.

Parameters
[in]	shell	A pointer to the shell struct.
Returns
The absolute path to the executable if found; otherwise, the original executable name (if not in PATH).*/
}

char*  get_path(t_shell *shell, bool printerror)
{
/*Get the path to an executable or convert it to an absolute path.

The function checks if the input for the command is already an absolute path. If not, it transforms the input to have the correct format else if just copies the absolute path into the path variable.

Parameters
[in]	shell	A pointer to the shell struct.
Returns
The path to the executable or NULL in case of an error.
*/
}

int get_size_env(t_environ_node *current)
{
/*Get the size of the environment list.

The get_size_environ function counts and returns the size of the list of environment variables.

Parameters
[in]	current	A pointer to the head of the environment variable list.
Returns
The number of elements in the linked list.*/
}

char  **create_env_array(t_environ_list *env)
{
/*Create the environment array based on the list size.

The create_environ_array function allocates memory for the environment array. It gets the size of the list from get_size_environ and returns the allocated array.

Parameters
[in]	environ	A pointer to the environment variable linked list.
Returns
A dynamically allocated array of environment variable strings or NULL in case of an error.
*/
}

void  transform_helper(t_environ_node *current, char **env_array)
{
/*Copy environment variables into the env array.

The transform_helper function is responsible for copying the linked list into the environment array used for execve calls. It allocates memory for each environment variable string and combines the key + value with an equal sign.

Parameters
[in]	current	A pointer to the head of the environment variable list.
[out]	environ_array	A pointer to the environment array.
*/
}

char  **transform_env_array(t_shell *shell)
{
/*Copy the environment variables into an array for execve.

The transform_environ_array function creates an environment array for execve. It first allocates memory for the environment array and then calls transform_helper to populate it with environment variable strings.

Parameters
[in]	shell	A pointer to the shell struct.
Returns
A dynamically allocated environment array or NULL in case of an error.*/
}

t_info  *init_info(t_shell  *shell)
{
/*Initializes the t_info structure.

This function allocates memory for the t_info structure, stores process IDs for child processes, a copy of the standard input file descriptor, and a reference to the minishell main data structure.

Parameters
shell	The minishell main data structure.
Returns
A pointer to the initialized t_info structure.
*/
}

void  wait_pipeline(t_info *info, int nbr)
{
/*Wait for child processes to finish execution + update the exit code.

This function waits for the child processes created during command execution to finish and updates the exit code based on their exit status only if the exit status is not 79 (exit without argument). Then it frees the info struct and all it's allocated members.

Parameters
info	Pointer to the t_info structure.
number	Number of child processes to wait for.
*/
}

void  handle_multi(t_shell  *shell, t_executor  *current)
{
/*Handle errors during command execution and set the exit code accordingly.

This function checks for specific error conditions during command execution (e.g., command not found or permission denied) and sets the exit code accordingly before exiting. Afterwards it frees everything in heap.

Parameters
current	The current executor representing a command.
info	Pointer to the t_info structure.*/
}

int handle_redir_pipeline(int *fildes, t_executor *curr, t_info *info)
{
/*Handles file redirections and file descriptor setup.

Sets up file descriptors for a child process in a pipeline, including standard input and output redirection. Manages file descriptors for communication if more commands are in the pipeline.

Parameters
fildes	Array of pipe file descriptors.
current	The current node of the executor list representing a command.
info	Pointer to the t_info structure.
Returns
OKAY on success, FAIL_SYSCALL on failure.
*/
}

void  exec_builtin_child(t_executor *current, t_info *info)
{
/*Executes a built-in command in a child process and exits.

This function executes a built-in command in a child process, sets the exit code accordingly, frees the heap and then exits the child process.

Parameters
current	The current node of the executor list representing a command.
info	Pointer to the t_info structure.*/
}

char*  exec_other_helper(t_executor *curr)
{
/*Helper function to find the executable path.

This function searches for the executable in the directories listed in the PATH environment variable and returns the full path to the executable.

Parameters
current	The current node of the executor list representing a command.
Returns
The full path to the executable or NULL on failure.
*/
}

int exec_other(t_executor *curr, t_info *info)
{
/*Executes a non-built-in command in a child process using execve.

This function executes a non-built-in command in a child process using the execve() system call and sets the exit code accordingly. If the path is not absolute then it uses execute_other_helper() to get one. Before the execve() call the function transforms the env list into a 2D array in order to pass it to execve().

Parameters
current	The current node of the executor list representing a command.
info	Pointer to the t_info structure.
Returns
FAIL_SYSCALL on failure (should not return if successful).
*/
}

int child_handler_multi(int *fildes, t_executor *curr, t_info *info)
{
/*Handles the execution of a child process in a multi-command.

This function handles the execution of a child process, including setting up file descriptors, executing built-in or non-built-in commands, and managing the child process's exit status.

Parameters
fildes	Array of pipe file descriptors.
current	The current node of the executor list representing a command.
info	Pointer to the t_info structure.
Returns
FAIL_SYSCALL_CHILD on failure (should not return if successful).
*/
}

int handle_pipes(int fildes[2])
{
/*Creates a pipe and sets the file descriptors in the given array.

This function creates a pipe using the provided file descriptor array and sets the appropriate file descriptors for communication between commands.

Parameters
fildes	Array to store pipe file descriptors.
Returns
0 on success, -1 on failure.
*/
}

pid_t handle_forks(void)
{
/*Creates a child process using fork() and returns the process ID.

This function creates a child process using the fork() system call and returns the process ID for the child process.

Returns
Process ID of the child process or -1 on failure.
*/
}

int parent_handler_multi(int *fildes, t_executor *curr)
{
/*Handles the parent process during multi-command execution.

This function manages file descriptors for input and output redirection. It manages the pipe for the parent process.

Parameters
fildes	Array of pipe file descriptors.
current	The current node of the executor list representing a command.
Returns
OKAY on success, FAIL_SYSCALL on failure.
*/
}

int handle_pipeline(int *fildes, t_executor *curr, t_info *info, int i)
{
  /*Handles the execution of a pipeline of commands.

This function manages the execution of multiple commands, including creating pipes, forking child processes, calling child and parent handlers and handling error conditions.

Parameters
fildes	Array of pipe file descriptors.
current	The current node of the executor list representing a command.
info	Pointer to the t_info structure.
i	Index of the current command/child in the pipeline.
Returns
OKAY on success, FAIL_SYSCALL/FAIL_SYSCALL_PARENT on failure.*/
}

int g_exit_code(void)
{

}
