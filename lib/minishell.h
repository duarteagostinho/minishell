/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:50:34 by duandrad          #+#    #+#             */
/*   Updated: 2025/06/11 17:48:25 by duandrad         ###   ########.fr       */
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

# define PARENT 1
# define CHILD 2
# define IGNORE 3
# define ERR_SYN_QUOTES "Syntax error: quotes unclosed\n"
# define ERR_SYN_RD "Syntax error: redirections\n"
# define ERR_SYN_PIPE "Syntax error: pipes\n"
# define EXIT_SYN_QUOTES 2
# define EXIT_SYN_RD 2
# define EXIT_SYN_PIPE 2
# define OK 100
# define NOT_FOUND 101
# define FAILED 102
# define FAIL_SYCALL_PARENT 1
# define FAIL_SYCALL_CHILD 2
# define MALLOC_ERROR 202

typedef enum s_token
{
	NONE = 0,
	PIPE = 1,
	TRUNCATE = 2,
	APPEND = 3,
	REDIRECT_INPUT = 4,
	HEREDOC = 5
}	t_token;

typedef struct s_redirect
{
	char				args[2];
	int					fd;
	struct s_redirect	*next;
}	t_redirect;


typedef struct s_cmd
{
	char				**args;
	struct s_cmd		*next;
	t_redirect			*redirect;
	int					redirect_in;
	int					redirect_out;
}	t_cmd;


typedef struct s_shell
{
	t_cmd	*cmd;
	char	**env;
}	t_shell;

/*EXECUTION FUNCTIONS*/
// int		get_sizeof_args(char **args);

/*PARSING FUNCTIONS*/
t_cmd	*parser(char* line);

#endif
