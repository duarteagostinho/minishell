#ifndef MINISHELL_H
# define MINISHELL_H

#  include <stdio.h>
#  include <unistd.h>
#  include <fcntl.h>
#  include <stdlib.h>
#  include <stdarg.h>
#  include <readline/readline.h>
#  include <readline/history.h>
#  include <stdbool.h>
#  include <signal.h>
#  include <sys/wait.h>
#  include "libft/libft.h"

#  define PARENT 1
#  define CHILD 2
#  define IGNORE 3
#  define ERR_EXIT "Error: numeric argument required\n"
#  define ERR_SYN_QUOTES "Syntax error: quotes unclosed\n"
#  define ERR_SYN_RD "Syntax error: redirections\n"
#  define ERR_SYN_PIPE "Syntax error: pipes\n"
#  define ERR_EMPTY_INP "Error: Empy input\n"
#  define GRN "\e[4;32m"
#  define PRP "\e[0;35m"
#  define WHT "\e[1;37m"
#  define RED "\e[1;31m"
#  define LG_RED "\e[0;31m"
#  define COLOR_RESET "\e[0m"

typedef char*	t_str;
typedef char**	t_vtr;
typedef int*	t_arr;

typedef struct s_rdir
{
	char			*args[2];
	int				fd;
	struct s_rdir		*next;
}	t_rdir;

typedef struct s_cmd
{
	t_vtr			args;
	t_rdir			*redirect;
	int				redirect_in;
	int				redirect_out;
	int				pipe_fd[2];
	struct s_cmd		*next;
}	t_cmd;

typedef struct s_shell
{
	t_cmd			*cmd;
	t_vtr			env;
	int				exit_status;
}	t_shell;

typedef int		(*t_func)(t_shell *);

/* PARSING FUNCTIONS */
int			skip_whitespace(t_str line, int start);
int			get_last_quote(t_str line);
t_str		remove_quotes(t_str str);
t_str		handle_quotes(t_str line, t_arr i);
t_str		prepare_line(t_str line);
t_str		handle_pipes(t_str line, t_arr i);
t_rdir		*extract_redirections(t_str cmd_str);
t_str		extract_var_name(t_str str, int start);
int			ft_strcmp(char *s1, char *s2);
t_str		handle_redirections(t_str line, t_arr i);
int			get_special_var_length(t_str str, int i, t_shell *shell);
int			get_env_var_length(t_str str, int i, t_vtr env);
int			calculate_expansion_length(t_str str, t_vtr env, t_shell *shell);
t_str		expand_variables(t_str str, t_vtr env, t_shell *shell);
t_str		mark_unquoted_whitespace(t_str str);
t_cmd		*parser(t_str line, t_vtr env, t_shell *shell);
t_vtr		process_args(t_str cmd_str);
t_vtr		word_split(t_str str);

/*EXECUTION FUNCTIONS*/
void		input_redir(t_rdir *redir);
void		output_redir(t_rdir *redir);
void		append_redir(t_rdir *redir);
void		handle_heredoc(t_rdir *redir, t_shell *shell, t_vtr env);
void		setup_redirection(t_shell *shell);
void		restore_redirections(t_shell *shell);
void		exec_redirections(t_shell *shell);
void		close_redirects(t_shell *shell);
void		free_rdirs(t_rdir *redirects);
void		handle_single(t_shell *shell);
void		ft_swap(void **a, void **b);
void		free_shell(t_shell *shell);
void  		free_cmds(t_cmd *commands);
void		executor(t_shell *shell);
void		exec_external(t_shell *shell);
void		init_shell(t_vtr env);
void		free_vtr(t_vtr args);
int			cd(t_shell *shell);
int			pwd(t_shell *shell);
int			env(t_shell *shell);
int			echo(t_shell *shell);
int			unset(t_shell *shell);
int			ft_exit(t_shell *shell);
int			ft_export(t_shell *shell);
int			cd_no_args(t_shell *shell);
int			get_sizeof_args(t_vtr args);
int			is_valid_id(const t_str key);
int			export_no_args(t_shell *shell);
int			exporting(t_shell *shell, t_str arg);
int			export_args(t_shell *shell, t_vtr args);
int			rmv_env_var(t_vtr env, const t_str key);
int			update_pwd(t_shell *shell, t_str lwd, t_str cwd);
int			add_env_var(t_vtr *env, const t_str key, const t_str val);
t_vtr		realloc_env(t_vtr env, const t_str new_var, int size);
t_str		get_env_val(t_vtr env, const t_str key);
t_str		is_external(t_shell *shell);
t_func		is_builtin(t_str command);
t_shell		*shell(void);

#endif
