/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:11:35 by duandrad          #+#    #+#             */
/*   Updated: 2025/10/09 15:57:19 by mrapp-he         ###   ########.fr       */
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
		return (ft_putendl_fd("Too many arguments", 2), 1);
	return (0);
}
