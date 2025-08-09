/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:59:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/08/08 02:00:12 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_id(const t_str key)
{
	int	i;

	i = 0;
	if (!key || !key[i] || !ft_isalpha(key[i]) || key[i] != '_')
		return (0);
	while (key[i] && (ft_isalnum(key[i]) || key[i] == '_'))
		i++;
	if (key[i] != '\0' && key[i] != '=')
		return (0);
	return (1);
}

int	check_flag(t_vtr args)
{
	int	flags;

	flags = 0;
	while (*args)
	{
		while (**args)
		{
			if (**args++ == '-' && **args == 'n')
				flags++;
			(*args)++;
		}
		args++;
	}
	return (flags);
}

int	count_commands(t_cmd *commands)
{
	int	  count;
	t_cmd *current;

	count = 0;
	current = commands;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_func  is_builtin(t_str command)
{
	if (!ft_strcmp("env", command))
		return (env);
	else if (!ft_strcmp("export", command))
		return (ft_export);
	else if (!ft_strcmp("exit", command))
		return (ft_exit);
	else if (!ft_strcmp("echo", command))
		return (echo);
	else if (!ft_strcmp("pwd", command))
		return (pwd);
	else if (!ft_strcmp("cd", command))
		return (cd);
	else if (!ft_strcmp("unset", command))
		return (unset);
	return (NULL);
}

t_str is_external(t_shell *shell)
{
	int	  i;
	t_str tmp;
	t_str path;
	t_vtr paths;

	i = -1;
	paths = ft_split(get_env_val(shell->env, "PATH"), ':');
	if (!paths)
		return (NULL);
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, shell->cmd->args[0]);
		if (access(path, X_OK))
		{
			free_vtr(paths);
			return (free(tmp), path);
		}
		free(tmp);
		free(path);
	}
	return (NULL);
}
