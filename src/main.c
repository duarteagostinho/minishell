/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:11:35 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/03 19:44:28 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	run_prompt(t_vtr env)
{
	t_str	prompt;

	signal_setup(shell(), PARENT);
	init_shell(env);
	while (1)
	{
		prompt = readline(PRP" $> "WHT);
		if (!prompt)
			ft_exit(shell());
		if (ft_strlen(prompt))
			add_history(prompt);
		shell()->cmd = parser(prompt, shell()->env, shell());
		free(prompt);
		if (shell()->cmd)
		{
			executor(shell(), STDIN_FILENO, STDOUT_FILENO);
			if (!access("/tmp/heredoc_tmp", R_OK))
				unlink("/tmp/heredoc_tmp");
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
	if (ac == 1)
		run_prompt(env);
	else
		return (write(2, "Too many arguments!\n", 20));
	return (0);
}
