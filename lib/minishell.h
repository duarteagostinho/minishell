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
# define PARENT 1
# define CHILD 2
# define IGNORE 3
# define ERR_SYN_QUOTES "Syntax error: quotes unclosed\n"
# define ERR_SYN_RD "Syntax error: redirections\n"
# define ERR_SYN_PIPE "Syntax error: pipes\n"

typedef struct s_redirect
{
	char				*args[2];
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
	t_cmd				*cmd;
	char				**env;
}	t_shell;

t_cmd	*parser(char *line);

#endif