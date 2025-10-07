/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:50:00 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/07 18:14:53 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_heredocs(t_shell *shell, int pid)
{
	waitpid(pid, &shell->exit_status, 0);
	if (WIFSIGNALED(shell->exit_status))
	{
		if (WTERMSIG(shell->exit_status) == SIGINT)
			shell->exit_status = 130;
		else if (WTERMSIG(shell->exit_status) == SIGQUIT)
			shell->exit_status = 131;
	}
	else if (WIFEXITED(shell->exit_status))
		shell->exit_status = WEXITSTATUS(shell->exit_status);
}

static char	*expand_heredoc_line(char *str, t_vtr env, t_shell *shell)
{
	t_expand_ctx	ctx;
	int				i;
	int				pos;
	char			*expanded;
	int				final_len;

	i = 0;
	pos = 0;
	final_len = calculate_expansion_length(str, env, shell);
	if (final_len <= 0)
		expanded = ft_strdup("");
	expanded = malloc(final_len + 1);
	if (!expanded)
		return (NULL);
	ctx = (t_expand_ctx){str, &i, expanded, &pos, env, shell};
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
			handle_dollar_expansion(&ctx);
		else
			expanded[pos++] = str[i++];
	}
	expanded[pos] = '\0';
	return (expanded);
}

void	process_heredoc_line(char *line, bool expand, int fd, t_shell *shell)
{
	char	*exp_line;

	if (expand == true)
	{
		exp_line = expand_heredoc_line(line, shell->env, shell);
		ft_putstr_fd(exp_line, fd);
		free(exp_line);
	}
	else
		ft_putstr_fd(line, fd);
	write(fd, "\n", 1);
}

bool	check_delm(t_rdir *redir)
{
	bool	expand;
	char	*delimiter;
	int		i;

	expand = true;
	delimiter = redir->args[1];
	i = -1;
	while (delimiter[++i])
	{
		if (delimiter[i] == '"' || delimiter[i] == '\'')
		{
			expand = false;
			break ;
		}
	}
	return (expand);
}
