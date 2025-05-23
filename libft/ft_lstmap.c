/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:51:24 by duarte            #+#    #+#             */
/*   Updated: 2024/11/12 13:48:57 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new_cont;
	void	*n;

	if (!lst || !f || !del)
		return (NULL);
	map = NULL;
	while (lst)
	{
		n = f(lst->content);
		if (!n)
			ft_lstclear(&map, del);
		new_cont = ft_lstnew(n);
		if (!new_cont)
		{
			del(n);
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, new_cont);
		lst = lst->next;
	}
	return (map);
}
