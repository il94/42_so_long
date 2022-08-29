/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:19:22 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/22 18:19:22 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	e_cell_can_move(char **map, t_pos pos_trgt, char dir, t_list *enemy)
{
	int	is_obstacle;

	is_obstacle = is(ENEMY_OBSTACLE, map[pos_trgt.y][pos_trgt.x]);
	if ((enemy->pos.y * CELL < enemy->cell.y - CELL / 2
			|| !is_obstacle) && dir == 'U')
		return (1);
	else if ((enemy->pos.x * CELL > enemy->cell.x - CELL / 2
			|| !is_obstacle) && dir == 'R')
		return (1);
	else if ((enemy->pos.y * CELL > enemy->cell.y - CELL / 2
			|| !is_obstacle) && dir == 'D')
		return (1);
	else if ((enemy->pos.x * CELL < enemy->cell.x - CELL / 2
			|| !is_obstacle) && dir == 'L')
		return (1);
	return (0);
}

void	e_move_cell(t_pos cell_trgt, t_list *enemy, t_info *i_enemies)
{
	enemy->cell = cell_trgt;
	if (i_enemies->state++ >= i_enemies->speed_animation)
		i_enemies->state = 0;
}

int	e_pos_can_move(char **map, t_pos pos_trgt, char dir, t_list *enemy)
{
	if (!is(ENEMY_OBSTACLE, map[pos_trgt.y][pos_trgt.x]))
	{
		if (dir == 'U' && enemy->cell.y / CELL
			< enemy->pos.y)
			return (1);
		else if (dir == 'R' && enemy->cell.x
			> enemy->pos.x * CELL - (CELL / 3) + CELL)
			return (1);
		else if (dir == 'D' && enemy->cell.y / CELL
			> enemy->pos.y)
			return (1);
		else if (dir == 'L' && enemy->cell.x
			< enemy->pos.x * CELL + (CELL / 3))
			return (1);
	}
	return (0);
}

void	e_move_pos(char **map, t_pos trgt, char dir, t_list *enemy)
{
	map[enemy->pos.y][enemy->pos.x] = '0';
	enemy->pos = trgt;
	map[trgt.y][trgt.x] = ft_tolower(dir);
}

void	e_move(t_game *game, t_pos cell_trgt, t_pos pos_trgt, t_list *enemy)
{
	enemy->dir = game->map[enemy->pos.y][enemy->pos.x];
	if (e_cell_can_move(game->map, pos_trgt, enemy->dir, enemy))
	{
		e_move_cell(cell_trgt, enemy, &game->i_enemies);
		if (e_pos_can_move(game->map, pos_trgt, enemy->dir, enemy))
			e_move_pos(game->map, pos_trgt, enemy->dir, enemy);
	}
	else
		change_enemy_direction(game->map, enemy->dir, enemy);
}
