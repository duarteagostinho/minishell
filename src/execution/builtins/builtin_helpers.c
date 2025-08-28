#include "minishell.h"

void	ft_swap(void **a, void **b)
{
	void *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_valid_id(const t_str key)
{
	int	i;

	i = 0;
	if (!key || !key[i] || (!ft_isalpha(key[i]) && key[i] != '_'))
		return (EXIT_FAILURE);
	while (key[i] && (ft_isalnum(key[i]) || key[i] == '_'))
		i++;
	if (key[i] != '\0' && key[i] != '=')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_func  is_builtin(t_str command)
{
	size_t	size;

	size = ft_strlen(command);
	if (!ft_strncmp("env", command, size))
		return (env);
	else if (!ft_strncmp("export", command, size))
		return (ft_export);
	else if (!ft_strncmp("exit", command, size))
		return (ft_exit);
	else if (!ft_strncmp("echo", command, size))
		return (echo);
	else if (!ft_strncmp("pwd", command, size))
		return (pwd);
	else if (!ft_strncmp("cd", command, size))
		return (cd);
	else if (!ft_strncmp("unset", command, size))
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
		if (access(path, X_OK) == 0)
			return (free_vtr(paths), free(tmp), path);
	}
	return (free_vtr(paths), free(tmp),	free(path), NULL);
}
