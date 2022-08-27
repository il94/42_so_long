/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:19:37 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/28 00:58:08 by ilandols         ###   ########.fr       */
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

// void	change_enemy_direction(t_game *game, char code, int i)
// {
// 	if (code == 'D')
// 		game->map[game->enemies[i].pos.y][game->enemies[i].pos.x] = 'R';
// 	else if (code == 'R')
// 		game->map[game->enemies[i].pos.y][game->enemies[i].pos.x] = 'U';
// 	else if (code == 'U')
// 		game->map[game->enemies[i].pos.y][game->enemies[i].pos.x] = 'L';
// 	else if (code == 'L')
// 		game->map[game->enemies[i].pos.y][game->enemies[i].pos.x] = 'D';
// }

void	change_enemy_direction(t_game *game, char code, t_llist *enemy)
{
	if (code == 'D')
		game->map[enemy->pos.y][enemy->pos.x] = 'R';
	else if (code == 'R')
		game->map[enemy->pos.y][enemy->pos.x] = 'U';
	else if (code == 'U')
		game->map[enemy->pos.y][enemy->pos.x] = 'L';
	else if (code == 'L')
		game->map[enemy->pos.y][enemy->pos.x] = 'D';
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

// void	move_all_enemies(t_game *game)
// {
// 	int		i;
// 	t_pos	pos_trgt;
// 	t_pos	cell_trgt;

// 	i = 0;
// 	while (i < game->enemies->index)
// 	{
// 		pos_trgt = game->enemies[i].pos_trgt;
// 		cell_trgt = game->enemies[i].cell_trgt;
// 		get_enemy_direction(game, &pos_trgt, &cell_trgt);
// 		move_enemy(game, pos_trgt, cell_trgt, i);
// 		i++;
// 	}
// 	iterate_elements(game->map, game->enemies->index, game->enemies, spawn_enemy);
// }

void	move_all_enemies(t_game *game)
{
	t_llist	*start;
	t_pos	pos_trgt;
	t_pos	cell_trgt;

	start = game->enemies;
	while (game->enemies)
	{
		pos_trgt = game->enemies->pos;
		cell_trgt = game->enemies->cell;
		get_enemy_direction(game, &pos_trgt, &cell_trgt);
		move_enemy(game, pos_trgt, cell_trgt, game->enemies);
		game->enemies = game->enemies->next;
	}
	game->enemies = start;
	iterate_elements(game->map, game->enemies->index, game->enemies, spawn_enemy);
}
