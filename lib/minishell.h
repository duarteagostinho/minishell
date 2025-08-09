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
# define ERR_EXIT "numeric argument required\n"
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

typedef struct s_rdir
{
	t_vtr				args[2];
	int					fd;
	struct s_rdir		*next;
}	t_rdir;

typedef struct s_cmd
{
	t_vtr				args;
	struct s_cmd		*next;
	t_rdir				*redirect;
	int					redirect_in;
	int					redirect_out;
}	t_cmd;

typedef struct s_shell
{
	t_cmd				*cmd;
	t_vtr				env;
	t_vtr				exports;
}	t_shell;

typedef enum e_lst {
	REDIRECT,
	COMMAND
}	t_lst;

typedef int		(*t_func)(t_shell *);

t_cmd	*parser(char *line);
t_rdir	*handle_red(char *type, char *filename, int fd);
t_rdir	*extract_redirections(char *cmd_str);
char	*remove_quotes(char *str);

/*EXECUTION FUNCTIONS*/
void		unset_arg(t_shell *shell, t_str arg, t_arr fails);
void		del_var(t_shell *shell, t_str arg);
void		handle_single(t_shell *shell);
void		free_shell(t_shell *shell);
void		close_fds(t_rdir *current);
void		executor(t_shell *shell);
void		init_shell(t_vtr envp);
void		lvl_up(t_shell *shell);
void		free_vtr(t_vtr args);
int			cd(t_shell *shell);
int			pwd(t_shell *shell);
int			env(t_shell *shell);
int			echo(t_shell *shell);
int			unset(t_shell *shell);
int			check_flag(t_vtr args);
int			ft_exit(t_shell *shell);
int			ft_export(t_shell *shell);
int			cd_no_args(t_shell *shell);
int			get_sizeof_args(t_vtr args);
int			is_valid_id(const t_str key);
int			export_no_args(t_shell *shell);
int			count_commands(t_cmd *commands);
int			exporting(t_shell *shell, t_str arg);
int			export_args(t_shell *shell, t_vtr args);
int			rmv_env_var(t_vtr env, const t_str key);
int			update_pwd(t_shell *shell, t_str lwd, t_str cwd);
int			realloc_env(t_vtr *env, const t_str new_var, int act);
int			add_env_var(t_vtr env, const t_str key, const t_str val);
t_str		get_env_val(t_vtr env, const t_str key);
t_shell		*shell(void);

#endif
