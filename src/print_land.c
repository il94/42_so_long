/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_land.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:52:31 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/31 20:14:07 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_all_land(t_game *game)
{
	if (!game->land_displayed)
	{
		put_land_everywhere(game);
		game->land_displayed = TRUE;
	}
	put_land_around_player(game, game->player.pos);
	put_land_around_enemies(game, game->enemies);
	put_land_on_coins(game, game->coins);
	if (game->stepbar.cell.y > 0 && game->stepbar.cell.y < 48)
		put_land_around_bar(game, game->stepbar.pos);
	if (game->bar_display)
		draw(&game->s_render, &game->s_stepbar, game->stepbar.cell, MENU);
}

void	put_land_everywhere(t_game *game)
{
	t_pos	pos;

	pos.y = 0;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			put_land(game, pos);
			pos.x++;
		}
		pos.y++;
	}
}

void	put_wall_to_player(t_game *game)
{
	t_pos	pos_trgt;
	int		i;

	i = 0;
	if (game->star_appeared)
		i += 5;
	pos_trgt.x = game->player.pos.x - 1;
	pos_trgt.y = game->player.pos.y + 1;
	while (pos_trgt.x <= game->player.pos.x + 1)
	{
		if (is(WALL, game->map[pos_trgt.y][pos_trgt.x]))
			put_wall(game, &game->s_render, &game->s_land[i], pos_trgt);
		pos_trgt.x++;
	}
}
