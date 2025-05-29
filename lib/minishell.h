/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:50:34 by duandrad          #+#    #+#             */
/*   Updated: 2025/05/19 15:05:17 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

#define PARENT 1
#define CHILD 2
#define IGNORE 3
#define ERR_SYN_QUOTES "Syntax error: quotes unclosed\n"
#define ERR_SYN_RD "Syntax error: redirections\n"
#define ERR_SYN_PIPE "Syntax error: pipes\n"
#define EXIT_SYN_QUOTES 2
#define EXIT_SYN_RD 2
#define EXIT_SYN_PIPE 2
#define OK 100
#define NOT_FOUND 101
#define FAILED 102
#define FAIL_SYCALL_PARENT 1
#define FAIL_SYCALL_CHILD 2
#define MALLOC_ERROR 202

typedef char* string;
typedef char** vector;
typedef int* array;

typedef enum	s_token
{
	NONE = 0,
	PIPE = 1,
	TRUNCATE = 2,
	APPEND = 3,
	REDIRECT_INPUT = 4,
	HEREDOC = 5
}	t_token;

typedef struct	s_lxr_list
{
	string				str;
	t_token				type;
	int					index;
	struct s_lxr_list	*prev;
	struct s_lxr_list	*next;
}	t_lxr_list;

typedef struct	s_shell
{
	string					rl_input;
	string					rl_copy;
	struct s_env_list		*environ;
	struct s_lxr_list		*lx_head;
	struct s_exec			*exec;
}	t_shell;


typedef	struct	s_info
{
	int			wstatus;
	t_shell		*shell;
	int			stdin_copy;
	pid_t * 	pids;
}	t_info;

typedef struct s_env_node
{
	string	key;
	string	value;
	struct s_env_node	*next;
}	t_env_node;

typedef struct s_exec
{
	int				id;
	int				size;
	int				fd_in;
	int				fd_out;
	bool			truncate;
	bool			append;
	bool			redirect_input;
	bool			heredoc;
	string			path;
	string			execs;
	struct s_exec	*prev;
	struct s_exec	*next;
}	t_exec;

typedef struct s_expander
{
	string	beginning;
	string	res;
	string	invalid;
	string	env_val;
	string	var;
	string	str;
	string	conv;
	int		pos;
	int		len;
	int		recently_invalid;
	int		expanded;
	int		flag;
}	t_expander;

typedef struct s_env_list
{
	struct s_env_node	*head;
	int						size;
}	t_env_list;


void  unset_arg(t_shell *shell, string arg, array fails);
void  del_var(t_shell *shell, string arg);
int	  unset(t_shell *shell, vector args);
char  *readl_prompt(char  *prompt);
int	  pwd(void);


#endif
