/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:37:40 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/28 00:44:32 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_shift_drawing_x(t_pos index, t_pos trgt, t_shift shift)
{
	if (shift == FULL)
		return (index.y + (CELL * trgt.x));
	else if (shift == BOT || shift == CENTER)
		return (index.y + trgt.x - (CELL / 2));
	else if (shift == HAMMER_LEFT_1)
		return (index.y + trgt.x - (CELL / 3));
	else if (shift == HAMMER_LEFT_2)
		return (index.y + trgt.x - CELL + (CELL / 6));
	else if (shift == HAMMER_RIGHT_1)
		return (index.y + trgt.x - CELL);
	else if (shift == HAMMER_RIGHT_2)
		return (index.y + trgt.x - (CELL / 6));
	else if (shift == MENU || shift == MOVE_COUNTER)
		return (index.y + trgt.x);
}

int	get_shift_drawing_y(t_pos index, t_pos trgt, t_shift shift)
{
	if (shift == FULL)
		return (index.x + (CELL * trgt.y));
	else if (shift == BOT)
		return (index.x + trgt.y - CELL + (CELL / 6));
	else if (shift == CENTER)
		return (index.x + trgt.y - (CELL / 2));
	else if (shift == HAMMER_LEFT_1)
		return (index.x + trgt.y - (CELL + (CELL / 3)));
	else if (shift == HAMMER_LEFT_2)
		return (index.x + trgt.y - CELL);
	else if (shift == HAMMER_RIGHT_1)
		return (index.x + trgt.y - (CELL + (CELL / 3)));
	else if (shift == HAMMER_RIGHT_2 || shift == MENU)
		return (index.x + trgt.y - CELL);
	else if (shift == MOVE_COUNTER)
		return (index.x + trgt.y);
}

int	draw(t_img *dst_img, t_img *src_img, t_pos trgt, t_shift shift)
{
	t_pos	px;
	char	*dst;
	int		x;
	int		y;
	int		color;

	px.y = 0;
	while (px.y < src_img->width)
	{
		px.x = 0;
		while (px.x < src_img->height)
		{
			x = get_shift_drawing_x(px, trgt, shift);
			y = get_shift_drawing_y(px, trgt, shift);
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

void	put_all_element(t_img *dst, t_data *src, t_img *sprites, t_shift shift)
{
	int	frequency;
	int	scale;
	int	index_sprite;
	int	i;

	i = 0;
	frequency = src->speed_animation / sprites->sprite_count;
	while (i < src->index)
	{
		index_sprite = 0;
		scale = 0;
		while (index_sprite < sprites->sprite_count)
		{
			if (src->state >= scale && src->state <= scale + frequency)
				draw(dst, &sprites[index_sprite], src[i].cell, shift);
			index_sprite++;
			scale += frequency;
		}
		i++;
	}
}

void	put_element(t_img *dst, t_data *src, t_img *sprites, t_shift shift)
{
	int	scale;
	int	frequency;
	int	index_sprite;

	index_sprite = 0;
	scale = 0;
	frequency = src->speed_animation / sprites->sprite_count;
	while (index_sprite < sprites->sprite_count)
	{
		if (src->state >= scale && src->state <= scale + frequency)
			draw(dst, &sprites[index_sprite], src->cell, shift);
		scale += frequency;
		index_sprite++;
	}
}

void	put_lelement(t_img *dst, t_llist *src, t_img *sprites, t_shift shift)
{
	int	scale;
	int	frequency;
	int	index_sprite;

	index_sprite = 0;
	scale = 0;
	frequency = src->speed_animation / sprites->sprite_count;
	while (index_sprite < sprites->sprite_count)
	{
		if (src->state >= scale && src->state <= scale + frequency)
			draw(dst, &sprites[index_sprite], src->cell, shift);
		scale += frequency;
		index_sprite++;
	}
}
