/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:00:07 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/25 18:05:10 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_quote_state(char c, char *quote)
{
	if ((c == '\'' || c == '"') && *quote == 0)
		*quote = c;
	else if (c == *quote)
		*quote = 0;
}

int	handle_expansion(t_str str, int *i, t_vtr env, t_shell *shell)
{
	int	len_added;

	len_added = process_dollar_sign(str, *i, env, shell);
	if (str[*i + 1] == '$' || str[*i + 1] == '?')
		*i += 2;
	else if (ft_isalnum(str[*i + 1]) || str[*i + 1] == '_')
		*i = skip_var_name(str, *i);
	else
		(*i)++;
	return (len_added);
}

t_str	extract_filename(t_str cmd_str, t_arr i)
{
	t_str	temp;
	t_str	filename;
	int		start;

	while (cmd_str[*i] && cmd_str[*i] == '\x1F')
		(*i)++;
	start = *i;
	while (cmd_str[*i] && cmd_str[*i] != '\x1F')
		(*i)++;
	if (start == *i)
		return (NULL);
	temp = ft_substr(cmd_str, start, *i - start);
	if (!temp)
		return (NULL);
	filename = remove_quotes(temp);
	free(temp);
	return (filename);
}

t_cmd	*init_command_list(void)
{
	t_cmd	*commands;

	commands = ft_calloc(sizeof(t_cmd), 1);
	if (!commands)
		return (NULL);
	commands->next = NULL;
	commands->redirect = NULL;
	commands->redirect_in = 0;
	commands->redirect_out = 0;
	return (commands);
}

void	fill_commands(t_vtr cmds, t_cmd *curr)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		if (i > 0)
		{
			curr->next = ft_calloc(sizeof(t_cmd), 1);
			if (!curr->next)
				return ;
			curr = curr->next;
			curr->next = NULL;
			curr->redirect = NULL;
			curr->redirect_in = 0;
			curr->redirect_out = 0;
		}
		curr->args = process_args(cmds[i]);
		curr->redirect = extract_redirections(cmds[i]);
		i++;
	}
}
