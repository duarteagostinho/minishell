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
#include <stdlib.h>

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

int	get_end_quote(const string input, char c)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == c)
			return (i);
	}
	return (i);
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

int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
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


string	clean_rl_copy(string rl_copy)
{
	string	clean;
  int i;
  int j;

  i = 0;
  j = -1;
  clean = malloc(sizeof(string) * ft_strlen(rl_copy));
  if (!clean)
    return (NULL);
  while (ft_isspace(rl_copy[i]))
    i++;
  while(rl_copy[i])
    clean[++j] = rl_copy[i++];
  clean[j] = '\0';
  return (clean);
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

int skip_quotes(string str)
{
  int   i;
  char  quote;

  i = 0;
  while (str[i])
  {
    if (str[i] == '"' || str[i] == '\'')
    {
      quote = str[i++];
      while (str[i] && str[i] != quote)
        i++;
      if (str[i] == quote)
        i++;
      break;
    }
    i++;
  }
  return (i);
}
