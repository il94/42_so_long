/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:52:31 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/25 18:53:48 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_all_environnement(t_game *game)
{
	int	i;

	if (!game->environnement_displayed)
	{
		read_map_with_struct(game, ALL, put_environnement);
		game->environnement_displayed = TRUE;
	}
	put_around_player(game, game->player.pos);
	i = 0;
	while (i < game->enemies->index)
		put_around_enemy(game, game->enemies[i++].pos);
	i = 0;
	while (i < game->coins->index)
		put_environnement(game, game->coins[i++].pos);
	if (game->scrolling_bar.cell.y > 0 && game->scrolling_bar.cell.y < 48)
		put_around_bar(game, game->scrolling_bar.pos);
	if (game->bar_displayed)
		draw(&game->render, &game->scrolling_bar, game->scrolling_bar.cell, MENU);
}

void	put_wall_to_player(t_game *game)
{
	t_pos	pos_trgt;
	int	i;

	i = 0;
	if (game->star_appeared)
		i += 5;
	pos_trgt.x = game->player.pos.x - 1;
	pos_trgt.y = game->player.pos.y + 1;
	while (pos_trgt.x <= game->player.pos.x + 1)
	{
		if (is(WALL, game->map[pos_trgt.y][pos_trgt.x]))
			put_wall(game, &game->render, &game->sprites_environnement[i], pos_trgt);
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
			put_environnement(game, pos_trgt);
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
		put_environnement(game, pos_trgt);
		pos_trgt.y++;
	}
	pos_trgt.y = pos_enemy.y;
	pos_trgt.x--;
	while (pos_trgt.x <= pos_enemy.x + 1)
	{
		put_environnement(game, pos_trgt);
		pos_trgt.x++;
	}
}

void	put_around_bar(t_game *game, t_pos pos_scrolling_bar)
{
	t_pos	pos_trgt;

	pos_trgt = pos_scrolling_bar;
	while (pos_trgt.x <= game->max.x - 1)
	{
		put_environnement(game, pos_trgt);
		pos_trgt.x++;
	}
}
