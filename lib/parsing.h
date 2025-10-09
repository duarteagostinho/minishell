/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:40:51 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 10:43:35 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "types.h"

/* PARSING UTILS */
t_str		get_special_value(t_str str, int *i, t_shell *shell);
t_str		get_env_value(t_str str, int *i, t_vtr env);
t_str		extract_filename(t_str cmd_str, t_arr i);
t_str		mark_unquoted_whitespace(t_str str);
t_str		remove_redirections(t_str cmd_str);
int			skip_var_name(t_str str, int i);
int			handle_expansion(t_str str, int *i, t_vtr env, t_shell *shell);
int			process_dollar_sign(t_str str, int i, t_vtr env, t_shell *shell);
void		copy_quote_block(t_str clean_cmd, int *j, t_str cmd_str, int *i);
void		expand_loop(t_str str, t_str expanded, int final_len, t_vtr env);
void		copy_value_to_expanded(t_str value, t_str expanded, int *pos);
void		add_redir(t_rdir **head, t_rdir **curr, t_rdir *new_redir);
void		handle_special_expansion(t_expand_ctx *ctx);
void		handle_dollar_expansion(t_expand_ctx *ctx);
void		skip_redirection(t_str cmd_str, int *i);
void		handle_env_expansion(t_expand_ctx *ctx);
void		update_quote_state(char c, char *quote);
bool		has_unquoted_heredoc(t_str str);

/* PARSING FUNCTIONS */
t_str		expand_variables(t_str str, t_vtr env, t_shell *shell);
t_cmd		*parser(t_str line, t_vtr env, t_shell *shell);
t_str		handle_redirections(t_str line, t_arr i);
t_str		extract_var_name(t_str str, int start);
t_rdir		*extract_redirections(t_str cmd_str);
t_str		handle_quotes(t_str line, t_arr i);
t_str		handle_pipes(t_str line, t_arr i);
t_vtr		process_args(t_str cmd_str);
t_str		remove_quotes(t_str str);
t_str		prepare_line(t_str line);
t_cmd		*init_command_list(void);
int			get_last_quote(t_str line);
int			ft_strcmp(char *s1, char *s2);
int			skip_whitespace(t_str line, int start);
int			get_env_var_length(t_str str, int i, t_vtr env);
int			get_special_var_length(t_str str, int i, t_shell *shell);
int			calculate_expansion_length(t_str str, t_vtr env, t_shell *shell);
void		fill_commands(t_vtr cmds, t_cmd *curr);
void		cmds_config(t_config_ctx *ctx);

#endif