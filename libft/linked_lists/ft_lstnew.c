/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:43:31 by ilyes             #+#    #+#             */
/*   Updated: 2022/09/01 00:40:13 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

t_list	*ft_lstnew(void)
{
	t_list	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return (0);
	element->pos.x = 0;
	element->pos.y = 0;
	element->cell.x = 0;
	element->cell.y = 0;
	element->dir = '0';
	element->prev = NULL;
	element->next = NULL;
	return (element);
}
