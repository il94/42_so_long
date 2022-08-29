/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:58:45 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/29 20:03:52 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_hbox	get_hbox_range(t_range range)
{
	t_hbox	result;

	result.left = 24;
	result.right = 24;
	result.down = 24;
	result.up = 24;
	if (range == H_HIT_LEFT)
		result.left = 48;
	else if (range == H_COIN || range == H_HIT_RIGHT)
		result.left = 12;
	if (range == H_HIT_RIGHT)
		result.right = 48;
	else if (range == H_COIN || range == H_HIT_LEFT)
		result.right = 12;
	if (range == H_JUMP)
		result.down = 12;
	else if (range == H_HIT_B)
		result.down = 48;
	if (range == H_HIT_B)
		result.up = 12;
	else if (range == H_JUMP)
		result.up = 48;
	return (result);
}

int	check_hbox(t_pos player_cell, t_list *element, t_range range)
{
	t_hbox	size;

	size = get_hbox_range(range);
	while (element)
	{
		if (element->cell.x >= player_cell.x - size.left
			&& element->cell.x <= player_cell.x + size.right
			&& element->cell.y >= player_cell.y - size.up
			&& element->cell.y <= player_cell.y + size.down)
			return (1);
		element = element->next;
	}
	return (0);
}

void	remove_element(char **map, t_list *element, t_list **start)
{
	map[element->pos.y][element->pos.x] = '0';
	if (element == *start)
	{
		*start = element->next;
		if (*start)
			(*start)->prev = NULL;
	}
	else
		ft_lstdelone(element);
	free(element);
}

void	hbox_remove(char **map, t_pos player, t_list **element, t_range range)
{
	t_list	*temp;
	t_hbox	size;

	temp = *element;
	size = get_hbox_range(range);
	while (temp)
	{
		if (temp->cell.x >= player.x - size.left
			&& temp->cell.x <= player.x + size.right
			&& temp->cell.y >= player.y - size.down
			&& temp->cell.y <= player.y + size.up)
		{
			if (range == H_COIN)
				system("cvlc sound/coin.wav &");
			else
				system("cvlc sound/goomba.wav &");
			remove_element(map, temp, element);
		}
		if (temp)
			temp = temp->next;
	}
}
