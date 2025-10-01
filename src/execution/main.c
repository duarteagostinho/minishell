#include "minishell.h"

void	print_commands(t_cmd *commands)
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
		{
			t_rdir *r;

			r = curr->redirect;
			while (r)
			{
				printf("  Has redirections\n");
				printf("  Redir type = %s, redir->fd = %d\n", r->args[0], r->fd);
				r = r->next;
			}
		}
		printf("\n");
		curr = curr->next;
		cmd_num++;
	}
}

static void	run_prompt(t_vtr env)
{
	t_str prompt;

	signal_setup(shell(), PARENT);
	init_shell(env);
	while (1)
	{
		prompt = readline(PRP" $> "WHT);
		if (!prompt)
		{
			printf("ctrl+d\n");
			ft_exit(shell());
		}
		if (ft_strlen(prompt))
			add_history(prompt);
		shell()->cmd = parser(prompt, shell()->env, shell());
		free(prompt);
		if (shell()->cmd)
		{
			// printf("\n--- Parsing ---\n");
			// print_commands(shell()->cmd);
			load_redirections(shell());
			executor(shell(), STDIN_FILENO, STDOUT_FILENO);
			free_cmds(shell()->cmd);
			shell()->cmd = NULL;
		}
	}
}

t_shell	*shell(void)
{
	static t_shell	shell;

	return (&shell);
}

int	main(int ac, t_vtr av, t_vtr env)
{
	(void) av;
	if(!*env)
	{
		printf("NO ENVIRONMENT!!!\n");
		//TODO
	}
	if (ac == 1)
		run_prompt(env);
	else
		return (write(2, "Too many arguments!\n", 20));
	return (0);
}
