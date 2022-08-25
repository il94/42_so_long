/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scrolling_bar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:39:53 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/25 18:49:52 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_bar(t_data *dst, t_data *sprites, int size_bar)
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

void	put_move_count(t_game *game)
{
	char	*steps;
	int		i;
	t_pos	pos_trgt;

	steps = ft_itoa(game->player_steps);
	i = ft_strlen(steps);
	pos_trgt.x = ((game->max.x * CELL) + (i * CELL / 2) + CELL / 2) / 2;
	pos_trgt.y = 20;
	i--;
	if (pos_trgt.x < game->max.x * CELL)
	{
		while (i >= 0)
		{
			draw(&game->scrolling_bar, &game->sprites_bar[steps[i] - '0'], pos_trgt, MOVE_COUNTER);
			if (pos_trgt.x - (CELL / 2) >= 48)
				pos_trgt.x -= (CELL / 2);
			else
				pos_trgt.x = 48;
			i--;
		}
		put_step_on_bar(&game->scrolling_bar, &game->sprites_bar[13], pos_trgt, game->player_steps);
	}
	else
		game->max_player_steps = TRUE;
	free(steps);
}

void	put_step_on_bar(t_data *dst, t_data *sprites, t_pos pos_trgt, int player_steps)
{
	pos_trgt.x -= 45;
	if (player_steps < 2)
		draw(dst, &sprites[0], pos_trgt, MOVE_COUNTER);
	else
		draw(dst, &sprites[1], pos_trgt, MOVE_COUNTER);
}

void	scroll_bar(t_data *dst, t_data *scrolling_bar, t_bool bar_displayed)
{
	if (bar_displayed && scrolling_bar->cell.y < 48)
	{
		draw(dst, scrolling_bar, scrolling_bar->cell, MENU);
		scrolling_bar->cell.y++;
	}
	else if (!bar_displayed && scrolling_bar->cell.y > 0)
	{
		draw(dst, scrolling_bar, scrolling_bar->cell, MENU);
		scrolling_bar->cell.y--;
	}
}
