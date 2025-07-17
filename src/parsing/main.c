#include "minishell.h"

static void	print_commands(t_cmd *commands)
{
	t_cmd	*curr;
	int		cmd_num;
	int		i;

	curr = commands;
	cmd_num = 0;
	while (curr)
	{
		printf("Command %d:\n", cmd_num);
		if (curr->args)
		{
			printf("  Args: ");
			i = 0;
			while (curr->args[i])
			{
				printf("[%s] ", curr->args[i]);
				i++;
			}
			printf("\n");
		}
		printf("  Redirect in: %d, out: %d\n", curr->redirect_in, curr->redirect_out);
		if (curr->redirect)
			printf("  Has redirections\n");
		printf("\n");
		curr = curr->next;
		cmd_num++;
	}
}

char	*_get_cwd()
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
		return (NULL);
	return (path);
}

static void	run_prompt(char **env)
{
	char	*line;
	t_cmd	*commands;
	t_shell	shell;

	shell.env = env;
	shell.exit_status = 0;
	
	while (1)
	{
		printf(COLOR_RESET GRN"%s"COLOR_RESET, _get_cwd());
		line = readline(PRP" $> "WHT);
		if (!line)
			return ;
		if (ft_strlen(line) > 0)
			add_history(line);
		
		commands = parser(line, env, &shell);
		if (commands)
		{
			printf("\n--- Parsing ---\n");
			print_commands(commands);
		}
		free(line);
	}
}

int	main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	run_prompt(env);
	return (0);
}
