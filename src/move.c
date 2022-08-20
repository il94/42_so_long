/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:19:37 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/20 19:53:10 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_player_sprite_direction(t_game *game)
{
	if (game->move_up)
	{
		if (game->player_direction == 'l' || game->player_direction == 'L')
			game->player_direction = 'l';
		else
			game->player_direction = 'r';
	}
	else if (game->move_right)
		game->player_direction = 'R';
	else if (game->move_down)
	{
		if (game->player_direction == 'l' || game->player_direction == 'L')
			game->player_direction = 'L';
		else
			game->player_direction = 'R';
	}
	else if (game->move_left)
		game->player_direction = 'L';
}

void	get_player_direction(t_game *game, t_pos *pos_trgt, t_pos *cell_trgt)
{
	if (game->move_up)
	{
		pos_trgt->y -= 1;
		cell_trgt->y -= 2;
	}
	else if (game->move_right)
	{
		pos_trgt->x += 1;
		cell_trgt->x += 2;
	}
	else if (game->move_down)
	{
		pos_trgt->y += 1;
		cell_trgt->y += 2;
	}
	else if (game->move_left)
	{
		pos_trgt->x -= 1;
		cell_trgt->x -= 2;
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
	while (i < game->enemy_index)
	{
		pos = game->enemies[i].pos;
		cell = game->enemies[i].cell;
		get_enemy_direction(game, &pos, &cell);
		move_enemy(game, pos, cell, i);
		i++;
	}
	iterate_elements(game->map, game->enemy_index, game->enemies, spawn_enemy);
}
