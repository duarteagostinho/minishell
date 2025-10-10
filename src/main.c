/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:11:35 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/10 13:03:26 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*shell(void)
{
	static t_shell	shell;

	return (&shell);
}

static void	run_prompt(void)
{
	t_str	prompt;

	signal_setup(shell(), PARENT);
	while (1)
	{
		prompt = readline(PRP" $> "WHT);
		if (!prompt)
			ft_exit(shell(), shell()->cmd);
		if (!*prompt)
			shell()->exit_status = 0;
		if (ft_strlen(prompt))
			add_history(prompt);
		shell()->cmd = parser(prompt, shell()->env, shell());
		free(prompt);
		if (shell()->cmd)
		{
			load_redirections(shell());
			executor(shell(), STDIN_FILENO, STDOUT_FILENO);
			close_redirects(shell());
			if (!access("/tmp/heredoc_tmp", R_OK))
				unlink("/tmp/heredoc_tmp");
			free_cmds(shell()->cmd);
			shell()->cmd = NULL;
		}
	}
}

int	main(int ac, t_vtr av, t_vtr env)
{
	(void) av;
	if (ac == 1)
	{
		init_shell(env);
		run_prompt();
	}
	else
		return (ft_putendl_fd("Too many arguments", 2), 1);
	return (0);
}
