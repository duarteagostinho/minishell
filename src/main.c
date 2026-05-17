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

#include "../lib/minishell.h"

t_shell	*shell(void)
{
	static t_shell	shell;

	return (&shell);
}

static t_str	make_prompt(void)
{
	t_str	cwd;
	t_str	prompt;
	t_str	tmp;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		cwd = ft_strdup(get_env_val(shell()->env, "PWD"));
	if (!cwd)
		cwd = ft_strdup("");
	if (!cwd)
		return (NULL);
	prompt = ft_strjoin(PRP, cwd);
	free(cwd);
	if (!prompt)
		return (NULL);
	tmp = ft_strjoin(prompt, WHT " $> " COLOR_RESET);
	free(prompt);
	return (tmp);
}

static void	run_prompt(void)
{
	t_str	prompt;
	t_str	input;

	signal_setup(shell(), PARENT);
	while (1)
	{
		prompt = make_prompt();
		input = readline(prompt ? prompt : "");
		free(prompt);
		if (!input)
			ft_exit(shell(), shell()->cmd);
		if (!*input)
			shell()->exit_status = 0;
		if (ft_strlen(input))
			add_history(input);
		shell()->cmd = parser(input, shell()->env, shell());
		free(input);
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
