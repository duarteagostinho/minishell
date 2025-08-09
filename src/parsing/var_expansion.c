#include "minishell.h"

char	*extract_var_name(char *str, int start)
{
	int		i;
	int		len;
	char	*name;

	if (!str || start < 0)
		return (NULL);
	i = start - 1;
	len = 0;
	while (str[++i] && (ft_isalnum(str[i]) || str[i] == '_'))
		len++;
	if (len == 0)
		return (NULL);
	name = malloc(len + 1);
	if (!name)
		return (NULL);
	i = 0;
	while (i < len)
	{
		name[i] = str[start + i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

static char	*get_env_value(char *var_name, char **env)
{
	int		i;
	int		var_len;
	int		j;

	if (!var_name || !env)
		return (NULL);
	var_len = ft_strlen(var_name);
	i = 0;
	while (env[i])
	{
		j = 0;
		while (j < var_len && env[i][j] && env[i][j] == var_name[j])
			j++;
		if (j == var_len && env[i][j] == '=')
			return (&env[i][j + 1]);
		i++;
	}
	return (NULL);
}

static int	get_special_var_length(char *str, int i, t_shell *shell)
{
	(void)shell;
	if (str[i + 1] == '$')
		return (10);
	else if (str[i + 1] == '?')
		return (3);
	return (0);
}

static int	get_env_var_length(char *str, int i, char **env)
{
	char	*var_name;
	char	*var_value;
	int		len;

	var_name = extract_var_name(str, i + 1);
	if (!var_name)
		return (0);
	var_value = get_env_value(var_name, env);
	if (var_value)
		len = ft_strlen(var_value);
	else
		len = 0;
	free(var_name);
	return (len);
}

static int	skip_var_name(char *str, int i)
{
	char	*var_name;
	int		new_i;

	var_name = extract_var_name(str, i + 1);
	if (var_name)
	{
		new_i = i + ft_strlen(var_name) + 1;
		free(var_name);
		return (new_i);
	}
	return (i + 1);
}

static int	process_dollar_sign(char *str, int i, char **env, t_shell *shell)
{
	int	len_added;

	len_added = 0;
	if (str[i + 1] == '$' || str[i + 1] == '?')
		len_added = get_special_var_length(str, i, shell);
	else if (ft_isalnum(str[i + 1]) || str[i + 1] == '_')
		len_added = get_env_var_length(str, i, env);
	else
		len_added = 1;
	return (len_added);
}


static int	calculate_expansion_length(char *str, char **env, t_shell *shell)
{
	int		i;
	int		final_len;

	i = 0;
	final_len = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			final_len += process_dollar_sign(str, i, env, shell);
			if (str[i + 1] == '$' || str[i + 1] == '?')
				i += 2;
			else if (ft_isalnum(str[i + 1]) || str[i + 1] == '_')
				i = skip_var_name(str, i);
			else
				i++;
		}
		else
		{
			final_len++;
			i++;
		}
	}
	return (final_len);
}

static void	expand_special_var(char *str, int *i, char *expanded, int *pos, t_shell *shell)
{
	char	*value;
	int		j;
	
	if (str[*i + 1] == '$')
		value = ft_itoa(getpid());
	else if (str[*i + 1] == '?')
		value = ft_itoa(shell->exit_status);
	else
		value = NULL;
	if (value)
	{
		j = 0;
		while (value[j])
		{
			expanded[*pos + j] = value[j];
			j++;
		}
		*pos += j;
		free(value);
	}
	*i += 2;
}

static void	expand_env_var(char *str, int *i, char *expanded, int *pos, char **env)
{
	char	*var_name;
	char	*var_value;
	int		j;

	var_name = extract_var_name(str, *i + 1);
	if (var_name)
	{
		var_value = get_env_value(var_name, env);
		if (var_value)
		{
			j = 0;
			while (var_value[j])
			{
				expanded[*pos + j] = var_value[j];
				j++;
			}
			*pos += j;
		}
		*i += ft_strlen(var_name) + 1;
		free(var_name);
	}
	else
		expanded[(*pos)++] = str[(*i)++];
}

char	*expand_variables(char *str, char **env, t_shell *shell)
{
	char	*expanded;
	int		final_len;
	int		i;
	int		pos;

	final_len = calculate_expansion_length(str, env, shell);
	expanded = malloc(final_len + 1);
	i = 0;
	pos = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			if (str[i + 1] == '$' || str[i + 1] == '?')
				expand_special_var(str, &i, expanded, &pos, shell);
			else if (ft_isalnum(str[i + 1]) || str[i + 1] == '_')
				expand_env_var(str, &i, expanded, &pos, env);
			else
				expanded[pos++] = str[i++];
		}
		else
			expanded[pos++] = str[i++];
	}
	expanded[pos] = '\0';
	return (expanded);
}
