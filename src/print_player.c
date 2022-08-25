/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:41:22 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/25 18:49:38 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_player_hit(t_data *dst, t_data *src, t_data *sprites, t_bool *is_hitting)
{
	static int	state;

	if (src->direction == 'L' && state < 3)
		draw(dst, &sprites[0], src->cell, HAMMER_LEFT_1);
	else if (src->direction == 'L')
		draw(dst, &sprites[1], src->cell, HAMMER_LEFT_2);
	if (src->direction == 'l' && state < 3)
		draw(dst, &sprites[2], src->cell, HAMMER_LEFT_1);
	else if (src->direction == 'l')
		draw(dst, &sprites[3], src->cell, HAMMER_LEFT_2);
	if (src->direction == 'R' && state < 3)
		draw(dst, &sprites[4], src->cell, HAMMER_RIGHT_1);
	else if (src->direction == 'R')
		draw(dst, &sprites[5], src->cell, HAMMER_RIGHT_2);
	if (src->direction == 'r' && state < 3)
		draw(dst, &sprites[6], src->cell, HAMMER_RIGHT_1);
	else if (src->direction == 'r')
		draw(dst, &sprites[7], src->cell, HAMMER_RIGHT_2);
	state++;
	if (state > 30)
	{
		*is_hitting = FALSE;
		state = 0;
	}
}

void	put_player_jump(t_data *dst, t_data *src, t_data *sprites, t_bool *is_jumping)
{
	static int	state;
	int			frequency_jump;

	frequency_jump = 30;
	if (state < frequency_jump)
	{
		if (src->direction == 'L')
			draw(dst, &sprites[0], src->cell, BOT);
		if (src->direction == 'R')
			draw(dst, &sprites[1], src->cell, BOT);
		state++;
	}
	else
	{
		*is_jumping = FALSE;
		state = 0;
	}
}

void	put_player_walk(t_data *dst, t_data *src, t_data *sprites)
{
	int	frequency;
	int	frequency_count;
	int	number_sprite;

	frequency = src->speed_animation / sprites->sprite_count;
	number_sprite = 0;
	frequency_count = 0;
	while (number_sprite < sprites->sprite_count)
	{
		if (src->state >= frequency_count && src->state <= frequency_count + frequency)
		{
			if (src->direction == 'L')
				draw(dst, &sprites[number_sprite], src->cell, BOT);
			if (src->direction == 'l')
				draw(dst, &sprites[number_sprite + 3], src->cell, BOT);
			if (src->direction == 'R')
				draw(dst, &sprites[number_sprite + 6], src->cell, BOT);
			if (src->direction == 'r')
				draw(dst, &sprites[number_sprite + 9], src->cell, BOT);
		}
		number_sprite++;
		frequency_count += frequency;
	}
}

void	put_player_static(t_data *dst, t_data *src, t_data *sprites)
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
