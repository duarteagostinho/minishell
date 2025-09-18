/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_exp_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:09:10 by duandrad          #+#    #+#             */
/*   Updated: 2025/09/18 15:13:10 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_value_to_expanded(t_str value, t_str expanded, int *pos)
{
	int	j;

	if (!value)
		return ;
	j = 0;
	while (value[j])
		expanded[(*pos)++] = value[j++];
}
