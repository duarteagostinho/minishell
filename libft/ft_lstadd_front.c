/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:09:04 by duarte            #+#    #+#             */
/*   Updated: 2024/11/08 15:32:31 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/* int main()
{
	t_list *new1;
	t_list *new2;

	new1= (t_list *)malloc(sizeof(t_list));
	if (!new1)
		return (-1);
	new2= (t_list *)malloc(sizeof(t_list));
	if (!new2)
		return (-1);
	new1->content = "string";
	new1->next = new2;
	new2->content = "ended";
	new2->next = NULL;
	t_list **head = &new1;
	t_list *new3;
	new3 = (t_list *)malloc(sizeof(t_list));
	if (!new3)
		return (-1);
	new3->content = "conteudo";
	new3->next = NULL;
	ft_lstadd_front(head, new3);
	return 0;
}
 */