/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:35:28 by ilyes             #+#    #+#             */
/*   Updated: 2022/09/01 00:37:47 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	if (lst == NULL)
		return ;
	else
	{
		while (temp != NULL)
		{
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
		}
	}
}
