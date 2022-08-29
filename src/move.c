/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:19:37 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/29 19:52:25 by ilandols         ###   ########.fr       */
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

void	change_enemy_direction(char **map, char direction, t_list *enemy)
{
	if (direction == 'D')
		map[enemy->pos.y][enemy->pos.x] = 'R';
	else if (direction == 'R')
		map[enemy->pos.y][enemy->pos.x] = 'U';
	else if (direction == 'U')
		map[enemy->pos.y][enemy->pos.x] = 'L';
	else if (direction == 'L')
		map[enemy->pos.y][enemy->pos.x] = 'D';
}

void	get_enemy_direction(char **map, t_pos *pos, t_pos *cell)
{
	if (map[pos->y][pos->x] == 'M')
		map[pos->y][pos->x] = 'D';
	if (map[pos->y][pos->x] == 'D')
	{
		pos->y++;
		cell->y++;
	}
	else if (map[pos->y][pos->x] == 'R')
	{
		pos->x++;
		cell->x++;
	}
	else if (map[pos->y][pos->x] == 'U')
	{
		pos->y--;
		cell->y--;
	}
	else if (map[pos->y][pos->x] == 'L')
	{
		pos->x--;
		cell->x--;
	}
}

void	move_all_enemies(t_game *game)
{
	t_list	*start;
	t_pos	pos_trgt;
	t_pos	cell_trgt;

	start = game->enemies;
	while (game->enemies)
	{
		pos_trgt = game->enemies->pos;
		cell_trgt = game->enemies->cell;
		get_enemy_direction(game->map, &pos_trgt, &cell_trgt);
		e_move(game, cell_trgt, pos_trgt, game->enemies);
		game->enemies = game->enemies->next;
	}
	game->enemies = start;
	iterate_elements(game->map, game->enemies, spawn_enemy);
}
