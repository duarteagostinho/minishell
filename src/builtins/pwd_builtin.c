/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:16:27 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/06/03 00:40:52 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

int	get_sizeof_args(vector args)
{
	int	size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

int	pwd(void)
{
	string	pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (EXIT_FAILURE);
	ft_putstr_fd(pwd, 1);
	free(pwd);
	return (EXIT_SUCCESS);
}
