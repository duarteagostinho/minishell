#include "minishell.h"

static char	*get_redir_type(char *cmd_str, int *i, int *fd)
{
	if (cmd_str[*i] == '>')
	{
		*fd = STDOUT_FILENO;
		if (cmd_str[*i + 1] == '>')
		{
			(*i) += 2;
			return (">>");
		}
		(*i)++;
		return (">");
	}
	else if (cmd_str[*i] == '<')
	{
		*fd = STDIN_FILENO;
		if (cmd_str[*i + 1] == '<')
		{
			(*i) += 2;
			return ("<<");
		}
		(*i)++;
		return ("<");
	}
	return (NULL);
}

static char	*extract_filename(char *cmd_str, int *i)
{
	char	*temp;
	char	*filename;
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

static void	add_redir(t_redirect **head, t_redirect **curr, t_redirect *new)
{
	if (!new)
		return ;
	if (!*head)
		*head = new;
	else
		(*curr)->next = new;
	(*curr) = new;
}

static t_redirect	*handle_red(char *type, char *filename, int fd)
{
	t_redirect	*red;

	if (!type || !filename)
		return (NULL);
	red = malloc(sizeof(t_redirect));
	if (!red)
		return (NULL);
	red->args[0] = ft_strdup(type);
	printf("type = ;%s;\n", red->args[0]);
	if (!red->args[0])
	{
		printf("here\n");
		free(red);
		return (NULL);
	}
	red->args[1] = ft_strdup(filename);
	printf("filename = ;%s;\n", red->args[1]);
	if (!red->args[1])
	{
		free(red->args[0]);
		free(red);
		return (NULL);
	}
	red->fd = fd;
	red->next = NULL;
	return (red);
}

t_redirect	*extract_redirections(char *cmd_str)
{
	t_redirect	*head;
	t_redirect	*curr;
	int			i;
	char		*type;
	int			fd;
	char		*filename;

	i = 0;
	head = NULL;
	curr = NULL;
	while (cmd_str[i])
	{
		if ((type = get_redir_type(cmd_str, &i, &fd)) && 
			(filename = extract_filename(cmd_str, &i)))
		{
			add_redir(&head, &curr, handle_red(type, filename, fd));
			free(filename);
		}
		else
			i++;
	}
	return (head);
}
