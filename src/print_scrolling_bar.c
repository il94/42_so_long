/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stepbar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:39:53 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/26 16:34:22 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_bar(t_img *dst, t_img *sprites, int size_bar)
{
	t_pos	pos_trgt;

	pos_trgt.x = 0;
	pos_trgt.y = 0;
	draw(dst, &sprites[10], pos_trgt, FULL);
	pos_trgt.x++;
	while (pos_trgt.x < size_bar)
	{
		draw(dst, &sprites[11], pos_trgt, FULL);
		pos_trgt.x++;
	}
	draw(dst, &sprites[12], pos_trgt, FULL);
}

void	put_move_count(t_game *game, t_img *dst, t_img *sprites)
{
	char	*steps;
	int		i;
	t_pos	cell_trgt;

	steps = ft_itoa(game->player_steps);
	i = ft_strlen(steps);
	cell_trgt.x = ((game->max.x * CELL) + (i * CELL / 2) + CELL / 2) / 2;
	cell_trgt.y = 20;
	i--;
	if (cell_trgt.x < game->max.x * CELL)
	{
		while (i >= 0)
		{
			draw(dst, &sprites[steps[i] - '0'], cell_trgt, MOVE_COUNTER);
			if (cell_trgt.x - (CELL / 2) >= 48)
				cell_trgt.x -= (CELL / 2);
			else
				cell_trgt.x = 48;
			i--;
		}
		put_step(dst, &sprites[13], cell_trgt, game->player_steps);
	}
	else
		game->max_player_steps = TRUE;
	free(steps);
}

void	put_step(t_img *dst, t_img *sprites, t_pos pos_trgt, int player_steps)
{
	pos_trgt.x -= 45;
	if (player_steps < 2)
		draw(dst, &sprites[0], pos_trgt, MOVE_COUNTER);
	else
		draw(dst, &sprites[1], pos_trgt, MOVE_COUNTER);
}

void	scroll_bar(t_img *dst, t_data *src, t_img *sprite, t_bool bar_display)
{
	if (bar_display && src->cell.y < 48)
	{
		draw(dst, sprite, src->cell, MENU);
		src->cell.y++;
	}
	else if (!bar_display && src->cell.y > 0)
	{
		draw(dst, sprite, src->cell, MENU);
		src->cell.y--;
	}
}
