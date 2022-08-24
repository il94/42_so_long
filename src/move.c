/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:19:37 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/24 14:09:44 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_player_sprite_direction(t_game *game)
{
	if (game->move_up)
	{
		if (game->player.direction == 'l' || game->player.direction == 'L')
			game->player.direction = 'l';
		else
			game->player.direction = 'r';
	}
	else if (game->move_right)
		game->player.direction = 'R';
	else if (game->move_down)
	{
		if (game->player.direction == 'l' || game->player.direction == 'L')
			game->player.direction = 'L';
		else
			game->player.direction = 'R';
	}
	else if (game->move_left)
		game->player.direction = 'L';
}

void	get_player_direction(t_game *game, t_pos *pos_trgt, t_pos *cell_trgt)
{
	if (game->move_up)
	{
		pos_trgt->y--;
		cell_trgt->y--;
	}
	else if (game->move_right)
	{
		pos_trgt->x++;
		cell_trgt->x++;
	}
	else if (game->move_down)
	{
		pos_trgt->y++;
		cell_trgt->y++;
	}
	else if (game->move_left)
	{
		pos_trgt->x--;
		cell_trgt->x--;
	}
}

void	change_enemy_direction(t_game *game, char code, int i)
{
	if (code == 'D')
		game->map[game->enemies[i].pos.y][game->enemies[i].pos.x] = 'R';
	else if (code == 'R')
		game->map[game->enemies[i].pos.y][game->enemies[i].pos.x] = 'U';
	else if (code == 'U')
		game->map[game->enemies[i].pos.y][game->enemies[i].pos.x] = 'L';
	else if (code == 'L')
		game->map[game->enemies[i].pos.y][game->enemies[i].pos.x] = 'D';
}

void	get_enemy_direction(t_game *game, t_pos *pos, t_pos *cell)
{
	if (game->map[pos->y][pos->x] == 'M')
		game->map[pos->y][pos->x] = 'D';
	if (game->map[pos->y][pos->x] == 'D')
	{
		pos->y++;
		cell->y++;
	}
	else if (game->map[pos->y][pos->x] == 'R')
	{
		pos->x++;
		cell->x++;
	}
	else if (game->map[pos->y][pos->x] == 'U')
	{
		pos->y--;
		cell->y--;
	}
	else if (game->map[pos->y][pos->x] == 'L')
	{
		pos->x--;
		cell->x--;
	}
}

void	move_all_enemies(t_game *game)
{
	int		i;
	t_pos	pos;
	t_pos	cell;

	i = 0;
	while (i < game->enemies->index)
	{
		pos = game->enemies[i].pos;
		cell = game->enemies[i].cell;
		get_enemy_direction(game, &pos, &cell);
		move_enemy(game, pos, cell, i);
		i++;
	}
	iterate_elements(game->map, game->enemies->index, game->enemies, spawn_enemy);
}