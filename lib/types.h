/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:40:48 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/09 09:58:00 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "includes.h"

typedef char*	t_str;
typedef char**	t_vtr;
typedef int*	t_arr;

typedef struct s_rdir
{
	char			*args[2];
	int				fd;
	struct s_rdir	*next;
}	t_rdir;

typedef struct s_cmd
{
	t_vtr				args;
	struct s_cmd		*next;
	int					pipes[2];
	pid_t				pid;
	t_rdir				*redirect;
	int					redirect_in;
	int					redirect_out;
	bool				skip_exec;
}	t_cmd;

typedef struct s_shell
{
	t_cmd				*cmd;
	t_vtr				env;
	t_vtr				exports;
	t_str				path;
	t_str				home;
	int					exit_status;
	int					in_child;
}	t_shell;

typedef struct s_expand_ctx
{
	t_str	str;
	int		*i;
	t_str	expanded;
	int		*pos;
	t_vtr	env;
	t_shell	*shell;
}	t_expand_ctx;

typedef struct s_config_ctx
{
	t_vtr	cmds;
	int		*k;
	t_cmd	**commands;
	t_vtr	env;
	t_shell	*shell;
}	t_config_ctx;

#endif