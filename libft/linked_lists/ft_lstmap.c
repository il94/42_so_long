/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:30:43 by ilyes             #+#    #+#             */
/*   Updated: 2022/09/01 00:17:45 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*li;

	li = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == NULL)
		{
			while (li)
			{
				new = li->next;
				(*del)(li->content);
				free(li);
				li = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&li, new);
		lst = lst->next;
	}
	return (li);
}
