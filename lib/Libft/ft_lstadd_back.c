/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 02:23:33 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:04:08 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new_node)
{
	t_list	*last_node;

	if (!list || !new_node)
		return ;
	last_node = ft_lstlast(*list);
	if (last_node)
		last_node->next = new_node;
	else
		*list = new_node;
}
