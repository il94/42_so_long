/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:37:40 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/25 18:38:41 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_shift_drawing_x(t_pos index, t_pos trgt, t_shift drawing_pos)
{
	if (drawing_pos == FULL)
		return (index.y + (CELL * trgt.x));
	else if (drawing_pos == BOT || drawing_pos == CENTER)
		return (index.y + trgt.x - (CELL / 2));
	else if (drawing_pos == HAMMER_LEFT_1)
		return (index.y + trgt.x - (CELL / 3));
	else if (drawing_pos == HAMMER_LEFT_2)
		return (index.y + trgt.x - CELL + (CELL / 6));
	else if (drawing_pos == HAMMER_RIGHT_1)
		return (index.y + trgt.x - CELL);
	else if (drawing_pos == HAMMER_RIGHT_2)
		return (index.y + trgt.x - (CELL / 6));
	else if (drawing_pos == MENU || drawing_pos == MOVE_COUNTER)
		return (index.y + trgt.x);
}

int	get_shift_drawing_y(t_pos index, t_pos trgt, t_shift drawing_pos)
{
	if (drawing_pos == FULL)
		return (index.x + (CELL * trgt.y));
	else if (drawing_pos == BOT)
		return (index.x + trgt.y - CELL + (CELL / 6));
	else if (drawing_pos == CENTER)
		return (index.x + trgt.y - (CELL / 2));
	else if (drawing_pos == HAMMER_LEFT_1)
		return (index.x + trgt.y - (CELL + (CELL / 3)));
	else if (drawing_pos == HAMMER_LEFT_2)
		return (index.x + trgt.y - CELL);
	else if (drawing_pos == HAMMER_RIGHT_1)
		return (index.x + trgt.y - (CELL + (CELL / 3)));
	else if (drawing_pos == HAMMER_RIGHT_2 || drawing_pos == MENU)
		return (index.x + trgt.y - CELL);
	else if (drawing_pos == MOVE_COUNTER)
		return (index.x + trgt.y);
}

int	draw(t_data *dst_img, t_data *src_img, t_pos trgt, t_shift drawing_pos)
{
	t_pos	px;
	char 	*dst;
	int		x;
	int		y;
	int		color;

	px.y = 0;
	while (px.y < src_img->width)
	{
		px.x = 0;
		while (px.x < src_img->height)
		{
			x = get_shift_drawing_x(px, trgt, drawing_pos);
			y = get_shift_drawing_y(px, trgt, drawing_pos);
			dst = dst_img->addr + y * dst_img->line + x * dst_img->bpp / 8;
			color = *(int *)(src_img->addr + px.x * src_img->line + px.y * 4);
			if (color >= -1 && y >= 0 && x >= 0 && color != *(int *)dst)
				*(int *)dst = color;
			px.x++;
		}
		px.y++;
	}
	return (0);
}

void	put_all_elements(t_data *dst, t_data *src, t_data *sprites, t_shift drawing_pos)
{
	int	frequency;
	int	frequency_count;
	int	index_sprite;
	int	i;

	i = 0;
	frequency = src->speed_animation / sprites->sprite_count;
	while (i < src->index)
	{
		index_sprite = 0;
		frequency_count = 0;
		while (index_sprite < sprites->sprite_count)
		{
			if (src->state >= frequency_count && src->state <= frequency_count + frequency)
				draw(dst, &sprites[index_sprite], src[i].cell, drawing_pos);
			index_sprite++;
			frequency_count += frequency;
		}
		i++;
	}
}

void	put_element(t_data *dst, t_data *src, t_data *sprites, t_shift drawing_pos)
{
	int	frequency_count;
	int	frequency;
	int	index_sprite;

	index_sprite = 0;
	frequency_count = 0;
	frequency = src->speed_animation / sprites->sprite_count;
	while (index_sprite < sprites->sprite_count)
	{
		if (src->state >= frequency_count && src->state <= frequency_count + frequency)
			draw(dst, &sprites[index_sprite], src->cell, drawing_pos);
		frequency_count += frequency;
		index_sprite++;
	}
}
