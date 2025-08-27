/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:43:07 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:06:36 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	void	*next_node;

	if (!list || !del)
		return ;
	while (*list)
	{
		next_node = (*list)->next;
		ft_lstdelone(*list, del);
		*list = next_node;
	}
}
