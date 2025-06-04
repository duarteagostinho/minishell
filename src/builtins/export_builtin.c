/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:41:25 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/06/03 01:15:52 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/minishell.h"

t_shell	*parse_export(t_shell *shell, vector args)
{
	while (args)
	{
		if (ft_isalpha(**args))
			*args++;
		while (*args && (ft_isalnum(**args) || **args == '_'))
			*shell->env->head->key++ = **args++;
		if (**args == '=')
			*args++;
		while (*args && ft_isalnum(**args))
			*shell->env->head->value++ = **args++;
		if (**args != '\0')
			return (NULL);
		shell->env->head = shell->env->head->next;
		args++;
	}
	return (shell);
}

int	export(t_shell *shell, vector args)
{

}

int	export_args(t_shell *shell, vector args)
{

}

int	export_no_args(t_shell *shell, string arg)
{

}

void  exporting(t_shell *shell, string arg)
{
	
}
