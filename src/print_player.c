/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:41:22 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/26 17:11:07 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_player_hit(t_img *dst, t_data *src, t_img *sprite, t_bool *hit)
{
	static int	state;

	if (src->direction == 'L' && state < 3)
		draw(dst, &sprite[0], src->cell, HAMMER_LEFT_1);
	else if (src->direction == 'L')
		draw(dst, &sprite[1], src->cell, HAMMER_LEFT_2);
	if (src->direction == 'l' && state < 3)
		draw(dst, &sprite[2], src->cell, HAMMER_LEFT_1);
	else if (src->direction == 'l')
		draw(dst, &sprite[3], src->cell, HAMMER_LEFT_2);
	if (src->direction == 'R' && state < 3)
		draw(dst, &sprite[4], src->cell, HAMMER_RIGHT_1);
	else if (src->direction == 'R')
		draw(dst, &sprite[5], src->cell, HAMMER_RIGHT_2);
	if (src->direction == 'r' && state < 3)
		draw(dst, &sprite[6], src->cell, HAMMER_RIGHT_1);
	else if (src->direction == 'r')
		draw(dst, &sprite[7], src->cell, HAMMER_RIGHT_2);
	state++;
	if (state > 30)
	{
		*hit = FALSE;
		state = 0;
	}
}

void	put_player_jump(t_img *dst, t_data *src, t_img *sprite, t_bool *jump)
{
	static int	state;
	int			frequency_jump;

	frequency_jump = 30;
	if (state < frequency_jump)
	{
		if (src->direction == 'L')
			draw(dst, &sprite[0], src->cell, BOT);
		if (src->direction == 'R')
			draw(dst, &sprite[1], src->cell, BOT);
		state++;
	}
	else
	{
		*jump = FALSE;
		state = 0;
	}
}

void	put_player_walk(t_img *dst, t_data *src, t_img *sprites)
{
	int	frequency;
	int	scale;
	int	sprite_index;

	frequency = src->speed_animation / sprites->sprite_count;
	sprite_index = 0;
	scale = 0;
	while (sprite_index < sprites->sprite_count)
	{
		if (src->state >= scale && src->state <= scale + frequency)
		{
			if (src->direction == 'L')
				draw(dst, &sprites[sprite_index], src->cell, BOT);
			if (src->direction == 'l')
				draw(dst, &sprites[sprite_index + 3], src->cell, BOT);
			if (src->direction == 'R')
				draw(dst, &sprites[sprite_index + 6], src->cell, BOT);
			if (src->direction == 'r')
				draw(dst, &sprites[sprite_index + 9], src->cell, BOT);
		}
		sprite_index++;
		scale += frequency;
	}
}

void	put_player_static(t_img *dst, t_data *src, t_img *sprites)
{
	if (src->direction == 'L')
		draw(dst, &sprites[0], src->cell, BOT);
	if (src->direction == 'l')
		draw(dst, &sprites[1], src->cell, BOT);
	if (src->direction == 'R')
		draw(dst, &sprites[2], src->cell, BOT);
	if (src->direction == 'r')
		draw(dst, &sprites[3], src->cell, BOT);
}
