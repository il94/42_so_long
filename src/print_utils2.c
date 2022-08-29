/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:52:31 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/29 06:26:46 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_all_land(t_game *game)
{
	int		i;
	t_list	*start;

	i = 0;
	if (!game->land_displayed)
	{
		read_map_with_struct(game, ALL, put_land);
		game->land_displayed = TRUE;
	}
	put_around_player(game, game->player.pos);
	start = game->enemies;
	while (game->enemies)
	{
		put_around_enemy(game, game->enemies->pos);
		game->enemies = game->enemies->next;
	}
	game->enemies = start;
	start = game->coins;
	while (game->coins)
	{
		put_land(game, game->coins->pos);
		game->coins = game->coins->next;
	}
	game->coins = start;	
	if (game->stepbar.cell.y > 0 && game->stepbar.cell.y < 48)
		put_around_bar(game, game->stepbar.pos);
	if (game->bar_display)
		draw(&game->s_render, &game->s_stepbar, game->stepbar.cell, MENU);
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

void	put_around_player(t_game *game, t_pos pos_player)
{
	t_pos	pos_trgt;

	pos_trgt = pos_player;
	pos_trgt.y -= 2;
	if (pos_trgt.y < 0)
		pos_trgt.y = 0;
	while (pos_trgt.y <= pos_player.y + 1)
	{
		pos_trgt.x = pos_player.x - 1;
		if (pos_trgt.x < 0)
			pos_trgt.x = 0;
		while (pos_trgt.x <= pos_player.x + 1)
		{
			put_land(game, pos_trgt);
			pos_trgt.x++;
		}
		pos_trgt.y++;
	}
}

void	put_around_enemy(t_game *game, t_pos pos_enemy)
{
	t_pos	pos_trgt;

	pos_trgt = pos_enemy;
	pos_trgt.y--;
	while (pos_trgt.y <= pos_enemy.y + 1)
	{
		put_land(game, pos_trgt);
		pos_trgt.y++;
	}
	pos_trgt.y = pos_enemy.y;
	pos_trgt.x--;
	while (pos_trgt.x <= pos_enemy.x + 1)
	{
		put_land(game, pos_trgt);
		pos_trgt.x++;
	}
}

void	put_around_bar(t_game *game, t_pos pos_stepbar)
{
	t_pos	pos_trgt;

	pos_trgt = pos_stepbar;
	while (pos_trgt.x <= game->max.x - 1)
	{
		put_land(game, pos_trgt);
		pos_trgt.x++;
	}
}
