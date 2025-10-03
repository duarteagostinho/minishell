/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:16:27 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/03 13:17:39 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_sizeof_args(t_vtr args)
{
	int	size;

	size = 0;
	if (!args || !*args)
		return (-1);
	while (args[size])
		size++;
	return (size);
}

int	pwd(t_shell *shell)
{
	t_str	pwd;

	(void)shell;
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (EXIT_FAILURE);
	printf("%s\n", pwd);
	free(pwd);
	return (EXIT_SUCCESS);
}
