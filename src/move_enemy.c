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

int	enemy_sprite_can_move(char **map, t_pos pos_trgt, char code, t_list *enemy)
{
	int	is_obstacle;

	is_obstacle = is(ENEMY_OBSTACLE, map[pos_trgt.y][pos_trgt.x]);
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

void	move_enemy_sprite(t_pos cell_trgt, t_list *enemy, t_info *i_enemies)
{
	enemy->cell = cell_trgt;
	if (i_enemies->state++ >= i_enemies->speed_animation)
		i_enemies->state = 0;
}

int	enemy_position_can_move(char **map, t_pos pos_trgt, char code, t_list *enemy)
{
	if (!is(ENEMY_OBSTACLE, map[pos_trgt.y][pos_trgt.x]))
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

void	move_enemy_position(char **map, t_pos trgt, char code, t_list *enemy)
{
	map[enemy->pos.y][enemy->pos.x] = '0';
	enemy->pos = trgt;
	map[trgt.y][trgt.x] = ft_tolower(code);
}

void	move_enemy(t_game *game, t_pos cell_trgt, t_pos pos_trgt, t_list *enemy)
{
	char	code;

	code = game->map[enemy->pos.y][enemy->pos.x];
	if (enemy_sprite_can_move(game->map, pos_trgt, code, enemy))
	{
		move_enemy_sprite(cell_trgt, enemy, &game->i_enemies);
		if (enemy_position_can_move(game->map, pos_trgt, code, enemy))
			move_enemy_position(game->map, pos_trgt, code, enemy);
	}
	else
		change_enemy_direction(game->map, code, enemy);
}
