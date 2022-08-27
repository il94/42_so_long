/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:19:22 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/22 18:19:22 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	enemy_sprite_can_move(t_game *game, t_pos pos_trgt, char code, int i)
// {
// 	int	is_obstacle;

// 	is_obstacle = is(ENEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x]);
// 	if ((game->enemies[i].pos.y * CELL < game->enemies[i].cell.y - CELL / 2
// 			|| !is_obstacle) && code == 'U')
// 		return (1);
// 	else if ((game->enemies[i].pos.x * CELL > game->enemies[i].cell.x - CELL / 2
// 			|| !is_obstacle) && code == 'R')
// 		return (1);
// 	else if ((game->enemies[i].pos.y * CELL > game->enemies[i].cell.y - CELL / 2
// 			|| !is_obstacle) && code == 'D')
// 		return (1);
// 	else if ((game->enemies[i].pos.x * CELL < game->enemies[i].cell.x - CELL / 2
// 			|| !is_obstacle) && code == 'L')
// 		return (1);
// 	return (0);
// }

// void	move_enemy_sprite(t_game *game, t_pos cell_trgt, int i)
// {
// 	game->enemies[i].cell = cell_trgt;
// 	if (game->enemies[i].state++ >= game->enemies[i].speed_animation)
// 		game->enemies[i].state = 0;
// }

// int	enemy_position_can_move(t_game *game, t_pos pos_trgt, char code, int i)
// {
// 	if (!is(ENEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x]))
// 	{
// 		if (code == 'U' && game->enemies[i].cell.y / CELL
// 			< game->enemies[i].pos.y)
// 			return (1);
// 		else if (code == 'R' && game->enemies[i].cell.x
// 			> game->enemies[i].pos.x * CELL - (CELL / 3) + CELL)
// 			return (1);
// 		else if (code == 'D' && game->enemies[i].cell.y / CELL
// 			> game->enemies[i].pos.y)
// 			return (1);
// 		else if (code == 'L' && game->enemies[i].cell.x
// 			< game->enemies[i].pos.x * CELL + (CELL / 3))
// 			return (1);
// 	}
// 	return (0);
// }

// void	move_enemy_position(t_game *game, t_pos trgt, char code, int i)
// {
// 	game->map[game->enemies[i].pos.y][game->enemies[i].pos.x] = '0';
// 	game->enemies[i].pos = trgt;
// 	game->map[trgt.y][trgt.x] = ft_tolower(code);
// }

// void	move_enemy(t_game *game, t_pos pos_trgt, t_pos cell_trgt, int i)
// {
// 	char	code;

// 	code = game->map[game->enemies[i].pos.y][game->enemies[i].pos.x];
// 	if (enemy_sprite_can_move(game, pos_trgt, code, i))
// 	{
// 		move_enemy_sprite(game, cell_trgt, i);
// 		if (enemy_position_can_move(game, pos_trgt, code, i))
// 			move_enemy_position(game, pos_trgt, code, i);
// 	}
// 	else
// 		change_enemy_direction(game, code, i);
// }

int	enemy_sprite_can_move(t_game *game, t_pos pos_trgt, char code, t_llist *enemy)
{
	int	is_obstacle;

	is_obstacle = is(ENEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x]);
	if ((enemy->pos.y * CELL < enemy->cell.y - CELL / 2
			|| !is_obstacle) && code == 'U')
		return (1);
	else if ((enemy->pos.x * CELL > enemy->cell.x - CELL / 2
			|| !is_obstacle) && code == 'R')
		return (1);
	else if ((enemy->pos.y * CELL > enemy->cell.y - CELL / 2
			|| !is_obstacle) && code == 'D')
		return (1);
	else if ((enemy->pos.x * CELL < enemy->cell.x - CELL / 2
			|| !is_obstacle) && code == 'L')
		return (1);
	return (0);
}

void	move_enemy_sprite(t_game *game, t_pos cell_trgt, t_llist *enemy)
{
	enemy->cell = cell_trgt;
	if (enemy->state++ >= enemy->speed_animation)
		enemy->state = 0;
}

int	enemy_position_can_move(t_game *game, t_pos pos_trgt, char code, t_llist *enemy)
{
	if (!is(ENEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x]))
	{
		if (code == 'U' && enemy->cell.y / CELL
			< enemy->pos.y)
			return (1);
		else if (code == 'R' && enemy->cell.x
			> enemy->pos.x * CELL - (CELL / 3) + CELL)
			return (1);
		else if (code == 'D' && enemy->cell.y / CELL
			> enemy->pos.y)
			return (1);
		else if (code == 'L' && enemy->cell.x
			< enemy->pos.x * CELL + (CELL / 3))
			return (1);
	}
	return (0);
}

void	move_enemy_position(t_game *game, t_pos trgt, char code, t_llist *enemy)
{
	game->map[enemy->pos.y][enemy->pos.x] = '0';
	enemy->pos = trgt;
	game->map[trgt.y][trgt.x] = ft_tolower(code);
}

void	move_enemy(t_game *game, t_pos cell_trgt, t_pos pos_trgt, t_llist *enemy)
{
	char	code;

	code = game->map[enemy->pos.y][enemy->pos.x];
	if (enemy_sprite_can_move(game, pos_trgt, code, enemy))
	{
		move_enemy_sprite(game, cell_trgt, enemy);
		if (enemy_position_can_move(game, pos_trgt, code, enemy))
			move_enemy_position(game, pos_trgt, code, enemy);
	}
	else
		change_enemy_direction(game, code, enemy);
}
