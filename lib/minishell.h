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
# define GRN "\e[4;32m"
# define PRP "\e[0;35m"
# define WHT "\e[1;37m"
# define RED "\e[1;31m"
# define LG_RED "\e[0;31m"
# define COLOR_RESET "\e[0m"

typedef char*	t_str;
typedef char**	t_vtr;
typedef int*	t_arr;
typedef struct s_redirect
{
	t_vtr				args[2];
	int					fd;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_cmd
{
	t_vtr				args;
	struct s_cmd		*next;
	t_redirect			*redirect;
	int					redirect_in;
	int					redirect_out;
}	t_cmd;

typedef struct s_shell
{
	t_cmd				*cmd;
	t_vtr				env;
}	t_shell;

t_cmd	*parser(char *line);
t_redirect	*handle_red(char *type, char *filename, int fd);
t_redirect	*extract_redirections(char *cmd_str);
char	*remove_quotes(char *str);

/*EXECUTION FUNCTIONS*/
void		unset_arg(t_shell *shell, t_str arg, t_arr fails);
void		update_old(t_shell *shell, t_str pos);
void		exporting(t_shell *shell, t_str arg);
void		del_var(t_shell *shell, t_str arg);
void		handle_single(t_shell *shell);
void		close_fds(t_exec *current);
void		executor(t_shell *shell);
void		init_shell(t_vtr envp);
void		lvl_up(t_shell *shell);
char		**split_var(t_str var);
char		*readl_prompt(t_str prompt);
int			pwd(void);
int			check_flag(t_vtr args);
int			get_sizeof_args(t_vtr args);
int			cd_no_args(t_shell *shell);
int			cd(t_shell *shell, t_vtr args);
int			export_no_args(t_shell *shell);
int			unset(t_shell *shell, t_vtr args);
int			ft_export(t_shell *shell, t_vtr args);
int			export_args(t_shell *shell, t_vtr args);
int			env_var_update(t_shell *shell, t_str pre, t_str pos);
t_shell		*shell(void);
#endif
