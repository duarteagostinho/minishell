/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:40:50 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 19:22:22 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "types.h"

/*EXECUTION FUNCTIONS*/
void		process_heredoc_line(t_str line, bool expand, int fd, t_shell *sh);
void		print_export(t_vtr val, int out, int has_equal, int size);
void		add_env_var(t_vtr *env, const t_str key, const t_str val);
void		handle_heredoc(t_rdir *redir, t_shell *shell, t_cmd *cmd);
void		cmd_error(t_str cmd, t_str arg, int error);
void		close_or_save(int in, int out, int check);
void		signal_setup(t_shell *shell, int process);
void		set_io(t_cmd *cmd, t_arr in, t_arr out);
void		wait_heredocs(t_shell *shell, int pid);
void		executor(t_shell *shell, int in, int out);
void		rmv_env_var(t_vtr *env, const t_str key);
void		exit_error(t_shell *shell, int error);
void		open_error(t_str filename, int error);
void		load_redirections(t_shell *shell);
void		close_redirects(t_shell *shell);
void		apply_redirections(t_cmd *cmd);
void		load_heredocs(t_shell *shell);
void		free_rdirs(t_rdir *redirects);
void		ft_swap(void **a, void **b);
void		free_shell(t_shell *shell);
void		free_cmds(t_cmd *commands);
void		init_shell(t_vtr env);
void		free_vtr(t_vtr args);
void		destroy_fds(void);
int			is_builtin(t_str name);
int			get_sizeof_args(t_vtr args);
int			ft_echo(t_cmd *cmd, int out);
int			ft_pwd(t_shell *shell, int out);
int			close_fd(int new_fd, int old_fd);
int			ft_cd(t_shell *shell, t_cmd *cmd);
int			ft_exit(t_shell *shell, t_cmd *cmd);
int			ft_unset(t_shell *shell, t_cmd *cmd);
int			is_valid_id(t_cmd *cmd, const t_str key);
int			ft_env(t_shell *shell, t_cmd *cmd, int out);
int			ft_export(t_shell *shell, t_cmd *cmd, int out);
int			exec_builtin(t_shell *shell, t_cmd *cmd, int out);
t_vtr		realloc_env(t_vtr env, const t_str new_var, int size);
t_str		get_env_val(t_vtr env, const t_str key);
t_str		get_path(t_shell *shell, t_str name);
t_str		ft_str_add(t_vtr str, t_str add);
bool		check_delm(t_rdir *redir);
t_shell		*shell(void);

#endif