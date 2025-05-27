/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:24:42 by duandrad          #+#    #+#             */
/*   Updated: 2025/05/19 16:15:41 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minishell.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

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

bool	check_pipe_syntax(t_lexer_list *lexer)
{
	/* 

Performs a pipe syntax check on the given list of lexems t_lexer_list *lexer.

Checks the lexer list for a syntax error with pipes, by checking if a valid token is encounterd after a PIPE token.

Parameters
    lexer	A pointer to the lexer list.

Returns
    bool true if syntax is correct, otherwise false. 

 */
}

t_lexer_list	*lexer(t_shell *shell)
{
	/*Lexical analysis and tokenization of the input string.

Performs the lexical analysis and tokenization of the input string.

First frees the previous 'rl_copy' if it exists, then creates a clean copy of the input string and removes leading/trailing whitespaces.

Checks the syntax of the quotes. If syntax is incorrect, print message, set g_exit_code and return NULL.

Calls tokenize() to tokenize the clean copy and returns the head of the returned lexer list.

Parameters
    shell	The shell data structure (main data structure). @ return A pointer to the head of the lexer list if successful, otherwise NULL. */
}

bool	parser(t_shell *shell)
{
	/*
Parses the input using the lexer.

Performs the parsing operation using the lexer. It first frees the existing lexer list if it exists. Then uses lexer() to generate a new list. If it failes to produce a new list, returns false. Else returns true.

Parameters
    shell	The shell data structure (main data structure).

Returns
    true if parsing is successful, false otherwise. 

*/
}

bool	check_quote_syntax(const string *input)
{
	/* 

Check the syntax of quotes in the input string.

Checks if the syntax of quoted parts (single or double quotes) in the input string is valid. Opening and closing quotes need to be correctly matched. Handles escape characters. If all quoted parts are correct, return true, else return false.

Parameters
    input	The string to be checked.

Returns
    Bool Returns true if all parts are valid, otherwise returns false. 

 */
}

string	replace_with_clean(string rl_copy, size_t start, size_t end)
{
	/* 

Removes characters from a string that are before and after a given index.

Creates a new string containing characters from the input string (rl_copy) starting from the 'start' index up to the 'end' index. If allocation fails, a error message is displayed and NULL is returned.

Parameters
    rl_copy	The input string.
    start	The starting index.
    end	The ending index.

Returns
    A new allocated string with the pulled portion of the input string, or NULL if malloc failed. 

 */
}

t_token assign_type(char tok)
{
  /*Assign a type based on the input char.

Parameters
tok	The input char to assign a tyoe for.
Returns
The assigned type for the the input char.*/
}

t_token which_type(string token)
{
/*Set the type of token.

Takes an input string('token') and chooses the type of token it represents. Only sets if the token is a pipe or some redirection, otherwise sets type to NONE.

Parameters
s	The input string ('token') to identify the type for.
Returns
The type of token identified.*/
}

t_lexer_list  *create_lexer_list(char **input_arr)
{
  /*Allocates memory for the lexer list.

Creates a double-linked list using the size of the input array. Calculates size of input array. and allocates memory for the lexer list. If malloc fails, displays error message, returns NULL.

Parameters
input_array	The array with the substrings('tokens').
Returns
A pointer to the head of the allocated list, or NULL if allocation failed.*/
}

t_lexer_list  *fill_lexer_list(char **input_arr)
{
  /*Fills the lexer list using the input array.

Calls create_lexer_list() to allocates a double-linked list with as many nodes as substrings in input_array. Fills each node of the list with information about each 'token'.

Parameters
input_array	The array with the substrings('tokens').
Returns
A pointer to the head of the filled lexer list, or NULL on failure.*/
}

t_lexer_list  *tokenize(t_shell *shell)
{
  /*Tokenizes the input string and creates the lexer list.

Tokenizes the input by creating an array of substrings. Creates a linked list of lexer tokens using the substrings. Returns a pointer to the head of the lexer linked list. if malloc fails for input_array or lexer list, display message and return NULL.

Parameters
shell	The shell data structure (main data structure). @ return The head of the lexer list if successful, otherwise NULL.
*/
}

int len_substr(string str)
{
  /*Calculates the length of a substring('token') until a delimiter or a token is found.

Takes an input string and finds the length of the substring('token') until a delimiter(whitespaces) or token('<', '>', '|') is encountered. Iterates over the string while checking for delimiter and token. If delimiter is not found, call no_delim_found() to modify the len. Returns the len of the substring until the delimiter or token.

Parameters
str	The input string to find the lenght of substring for.
Returns
len The lenght of the substring until the delimiter or token is found.*/
}

int count_elements(string rl_copy)
{
  /*Count the number of elements in the input string.

Takes an input and counts the substrings('tokens') in it. Makes use of len_substr() to get the length of each substring. Returns the number of substrings found.

Parameters
rl_copy	The string for which to count the number of substrings.
Returns
The number of substrings('tokens') in the input string.*/
}

int find_token(char **input_arr, char **input, int index)
{
  /*Finds predefined tokens in the input string and adds it to the input_array.

Finds tokens in the input string and adds them to the input_array. It calls is_token() and is_token2() to check for existing valid tokens. If a token is found, a substring is created and added to the input_array.

Parameters
input_array	Pointer to the array of strings.
input	Pointer to the input string.
index	Current index in the input_array.
Returns
index The updated index after adding a substring/token to the array of strings.*/
}


char  **fill_input_array(char **input_array,string input)
{
  /*Fills the array of strings with substrings('tokens') from the input string.

Takes an input string, splits it into substrings('tokens') and fills the given array of strings with these substrings('tokens'). The function iterates over the input, calls find_token() to find predefined 'tokens' and adds them to the array. Also handles whitespace separated substrings and adds them to the array.

Parameters
input_array	Pointer to the array of strings to fill.
input	The input string.
Returns
input_array The array of strings with the tokens and whitespace separated substrings.*/
}

char  **create_input_array(t_shell *shell)
{
  /*Create an array of input strings for tokenization.

Creates an array of tokens from shell->rl_copy(removed leading and trailing whitespaces). Calculates the number of elements needed for the array and allocates for it. Calls fill_input_array() to fill the array with substrings ('tokens').

Parameters
shell	The main data structure.
Returns
An array of substrings('tokens').*/
}

void	no_delim_found(string str, int *len)
{
	/* Checks if there is a quote('\'' or '"') at the current position the given string.

The function is called when no delimiter(whitespace) is found. Checks if the current position in the string is a quote ('\'' or '"') and calls skip_quotes() to skip over the quoted section. Otherwise it incremets the lenght(and current position).

Parameters
str	The input string.
*len	A pointer to the lenght(and current index) of the string.
 */
}

int	get_size_executor(t_lexer_list *head)
{
	/* Calculates the number of t_executor elements/nodes needed.

Calculates the number of t_executor elements/nodes needed based on the number of pipe token in the lexer linked list. Each pipe token represents a new t_executor node. Example: 2 pipe token -> 2 + 1 t_executor nodes.

Parameters
head	A pointer to the head of the lexer linked list.
Returns
The size of the t_executor linked list. */
}

t_executor	*create_executor_list(int size)
{
/* Create a linked list of t_executor nodes/elements.

Allocates memory for a linked list of t_executor nodes, based on the size.

Parameters
size	The size of the t_executor linked list.
Returns
A pointer to the linked list, or NULL if allocation fails. */
}

void	set_executor_defaults(t_executor *node)
{
	/* Sets default values for a t_executor node.

Initializes the variables of a t_executor node with default values. They include filediscriptors and bools.

Parameters
node	A pointer to the t_executor node to initialize.
 */
}

t_executor	*init_executor_list(int size)
{
	/* Initializes the t_executor linked list.

Initializes the t_executor linked list, by first calling create_executor_list() to allocate memory for it. It sets every nodes id and overall size, then calls set_executor_defaults() for setting default values.

Parameters
size	The amount of nodes in the t_executor linked list.
Returns
A pointer to the initialized t_executor linked list, or NULL on error. */
}

t_executor	*prepare_executor(t_shell *shell)
{
	/* Prepare a linked list of t_executor elements for the executor.

Prepares a linked list of t_executor elements by calculating the number of elements needed, initializing them and filling them with the relevant data from the lexer linked list and the environ linked list.

Parameters
shell	A pointer to the main data structure.
Returns
A pointer to the t_executor linked list, or NULL on error. */
}

char	**combine_execs(char **resplit, char **new_execs, char **execs)
{
	/* Combine resplit array with execs array into new_execs array.

Takes 2 arrays of strings, 'resplit' and 'execs', combines them into a new array 'new_execs'. Also frees the memory of the input arrays.

!!!!!Warning!!!!!
The memory for new_execs is allocated outside of the function.

Parameters
[in]	resplit	The first array of strings.
[in,out]	new_execs	The resulting array of strings after combining.
[in]	execs	The second array of strings.
Returns
new_execs The combined array of strings. */
}

int	after_expand(t_executor *current)
{
	/* Process the execs array of the current executor node after expansion.

Takes a node of the executor list, splits its execs array (execution command) and combines the resulting strings with the existing execs array.

Parameters
[in,out]	current	The current executor node.
Returns
The result of the process (OK, NOT_FOUND, or FAILED). */
}

bool	check_execs_after_expand(t_shell *shell)
{
	/* Checks and processes execution commands after expansion.

Iterates through the executor list ands calls after_expand() on each of the nodes of that list. Retuns true if all processing is successfull, or false if any processing fails.

Parameters
[in,out]	shell	The main data structure.
Returns
True if all processing succeeds, false if any processing fails.
 */
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

int	process_in_heredoc(t_executor *current, t_lexer_list *lexer)
{
/* Processes input redirections and heredoc for the given node of the executor list.

Handles input redirections and heredoc for the given executor list node by calling its subfunctions. Has some edgecase handling.

Parameters
current	A pointer to the current t_executor node.
lexer	A pointer to the current lexer list node.
Returns
OK if successful, FAILED if an error occurs, NOT_FOUND if not applicable. */
}

int	process_command(t_executor *current, t_lexer_list *lexer)
{
/* Processes the command part for the given node of the executor list.

Handles the command part of the given executor list node by creating an array of command arguments.

Parameters
current	A pointer to the current t_executor node.
lexer	A pointer to the current lexer list node.
Returns
OK if successful, FAILED if an error occurs, NOT_FOUND if not applicable. */
}

t_executor	*process_lexemes(t_executor *list,
	 t_executor *current, t_lexer_list **lexer)
{
/* Processes lexemes and sets values in the given t_executor node.

Processes lexemes in the lexer linked list and populates the executor linked list accordingly. It handles output redirections, input redirections inclusive heredoc and command executions. On error, frees the entire t_executor linked list and returns NULL.

Parameters
list	A pointer to the t_executor linked list.
current	A pointer to the current t_executor node.
lexer	A pointer to the lexer linked list.
Returns
A pointer to the updated t_executor node, or NULL on error. */
}

t_executor	*fill_executor_list(t_shell *shell, t_executor *list)
{
/* Fills the t_executor linked list with info about the parsed commands.

Fills the t_executor linked list by processing the lexer linked list and setting values in a t_executor node for each command and its operation.

Parameters
shell	A pointer to the main data structure.
list	A pointer the t_executor linked list to be filled.
Returns
A pointer to the filled t_executor linked list, or NULL on error. */
}

bool	open_outputfile(t_executor *curr, t_lexer_list *lexer)
{
/* Handles opening an output file.

Handles opening an output file for the given t_executor node, based on the given lexer list token type. It supports truncating and appending to the file.

Parameters
current	A pointer to the current t_executor node.
lexer	A pointer to the current t_lexer_list node.
Returns
True if the file is opened and closed successfully, false on error. */
}

bool	get_input(int fd, string delim)
{
/* Reads input for a here-document until a specified delimiter.

Reads input from the user, displaying a prompt, until the specified delimiter is entered. The input is written to the given file descriptor. Also handles ctrl-d (end-of-file from readline).

Parameters
fd	The file descriptor to write the input to.
delimiter	The delimiter that signals the end of the here-document.
Returns
True if successful, false on error. */
}

int	create_heredoc(string delm)
{
/* Creates a here-document file and gathers input.

Creates a temporary file for a here-document, gathers input for it by calling get_input().
Returns a file descriptor to the created file.

Parameters
delimiter	The delimiter that signals the end of the here-document.

Returns
The file descriptor of the created here-document, or -1 on error. */
}

bool	open_inputfile(t_executor *curr, t_lexer_list *lexer)
{
/* Handles opening an input file.

Handles opening an input file for the given t_executor node, based on the given lexer list token type. It supports input redirection and here-document.

Parameters
current	A pointer to the current t_executor node.
lexer	A pointer to the current t_lexer_list node.
Returns
True if the file is opened successfully, false on error. */
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

void	update_old(t_shell *shell, string old)
{
/* Update OLDPWD.

Updates the OLDPWD environment variable with the value of the previous working directory before the change.

Parameters
[in]	shell	A pointer to the shell struct.
[in]	old	The previous working directory.
 */
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

void  exporting(t_shell *shell, string str)
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

void  delete_variable(t_shell *shell, string arg)
{
/*Deletes an environment variable.

This function deletes an environment variable specified by its name (arg) from the shell's environment linked list. It finds the variable to delete and removes it from the linked list, freeing the associated memory.

Parameters
[in,out]	shell	A pointer to the shell struct.
[in]	arg	The name of the environment variable to delete.*/
}

void  unset_arg(t_shell *shell, string arg, int *fails)
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

bool  expander(t_shell *shell)
{
/*Starting point of variable expansion.

This function is the starting point for expanding variables.It iterates through each command and applies variable expansion if needed or just copies from the input.

Parameters
[in,out]	shell	A pointer to the shell struct.
*/
}

int expand_var(t_shell *shell, char **cmd, t_expander *exp, int pos)
{
/*Expand variables.

This function is expanding variables. It iterates through the command string, identifies variables and replaces them with the corresponding values.

Parameters
[in]	shell	A pointer to the shell struct.
[in,out]	str	A pointer to the command string.
[in,out]	exp	A pointer to the expander struct.
[in]	pos	The current position in the result string.
Returns
The updated position in the result string after expansion.*/
}

string  handle_quotes(t_shell *shell, char **cmd,
                      char end_quote, t_expander * inter)
{
/*Handles quoted strings within a shell command.

This function processes quoted strings within a shell command, including variable expansions if present. It handles both single (' ') and double (" ") quotes.

Parameters
[in]	shell	A pointer to the shell struct.
[in,out]	str	A pointer to the command string to be processed.
[in]	end_quote	The character that marks the end of the quoted string (' ' or " ").
[in,out]	inter	A pointer to the expander struct.
Returns
A dynamically allocated string with the processed contents.
*/
}

string  interpolate(t_shell *shell, string str)
{
/*Interpolates variables and handles quotes within a shell command.

This function processes variable interpolation and handles quotes (single or double) within the shell prompt. It iterates through the prompt string, expanding variables and preserving quoted strings.

Parameters
[in]	shell	A pointer to the shell struct.
[in,out]	str	A pointer to the command string to be processed.
[in]	inter	A pointer to the expander struct.
Returns
A dynamically allocated string containing the processed contents or NULL on failure.
*/
}

t_expander  *init_expander(string str)
{
/*Initializes the expander struct for variable expansion.

This function initializes the expander struct used during variable expansion. It allocates memory for various fields and sets their initial values.

Parameters
[in]	str	The input string to be expanded.
Returns
A pointer to the initialized expander struct or NULL on allocation failure.
*/
}

string  realloc_str(string original, int pos)
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

string  ft_strjoin_expander(const string s1, const string s2)
{
/*Concatenates two strings and expands the memory as needed.

This function takes two input strings, s1 and s2, and concatenates them into a new string. The memory for the resulting string is dynamically allocated to accommodate both input strings. The memory for s1 is freed before returning the result.

Parameters
s1	The first input string.
s2	The second input string.
Returns
A pointer to the concatenated string, or NULL if memory allocation fails.*/
}

string  ft_charjoin_expander(const string s, const char c)
{
/*Concatenates character to the end of a string.

This function takes an input string s and a character c, and concatenates the character to the end of the string. The memory for the resulting string is dynamically allocated to accommodate the additional character. The memory for the original string is freed before returning the result.

Parameters
s	The input string.
c	The character to concatenate.
Returns
A pointer to the concatenated string, or NULL if memory allocation fails.
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
