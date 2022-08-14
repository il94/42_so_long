/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.41.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1011/07/16 01:06:00 by ilandols          #+#    #+#             */
/*   Updated: 1011/07/16 01:06:00 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	change_direction(t_game *game, char code, int i)
{
	if (code == 'D')
		game->map[game->ennemies[i].pos.y][game->ennemies[i].pos.x] = 'R';
	else if (code == 'R')
		game->map[game->ennemies[i].pos.y][game->ennemies[i].pos.x] = 'U';
	else if (code == 'U')
		game->map[game->ennemies[i].pos.y][game->ennemies[i].pos.x] = 'L';
	else if (code == 'L')
		game->map[game->ennemies[i].pos.y][game->ennemies[i].pos.x] = 'D';
}

int	ennemy_sprite_can_move(t_game *game, t_pos pos_trgt, char code, int i)
{
	if (code == 'U' && (!is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
		|| game->ennemies[i].pos.y * CELL < game->ennemies[i].cell.y - CELL / 2))
		return (1);
	else if (code == 'R' && (!is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
		|| game->ennemies[i].pos.x * CELL >= game->ennemies[i].cell.x - CELL / 2))
		return (1);
	else if (code == 'D' && (!is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
		|| game->ennemies[i].pos.y * CELL > game->ennemies[i].cell.y - CELL / 2))
		return (1);
	else if (code == 'L' && (!is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
		|| game->ennemies[i].pos.x * CELL <= game->ennemies[i].cell.x - CELL / 2))
		return (1);
	return (0);
}

void	move_ennemy_sprite(t_game *game, t_pos cell_trgt, int i)
{
	game->ennemies[i].cell = cell_trgt;
	if (game->state_ennemy++ >= game->speed_animation_ennemy)
		game->state_ennemy = 0;
}

int	ennemy_position_can_move(t_game *game, t_pos pos_trgt, char code, int i)
{
	if (code == 'U' && !is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
        && game->ennemies[i].cell.y / CELL < game->ennemies[i].pos.y)
		return (1);
	else if (code == 'R' && !is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
            && game->ennemies[i].cell.x > game->ennemies[i].pos.x * CELL - (CELL / 3) + CELL)
		return (1);
	else if (code == 'D' && !is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
            && game->ennemies[i].cell.y / CELL > game->ennemies[i].pos.y)
		return (1);
	else if (code == 'L' && !is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
            && game->ennemies[i].cell.x < game->ennemies[i].pos.x * CELL + (CELL / 3))
		return (1);
	return (0);
}

void	move_ennemy_position(t_game *game, t_pos trgt, char code, int i)
{
	game->map[game->ennemies[i].pos.y][game->ennemies[i].pos.x] = '0';
	game->ennemies[i].pos.x = trgt.x;
	game->ennemies[i].pos.y = trgt.y;
	game->map[trgt.y][trgt.x] = ft_tolower(code);
}

void	move_ennemy(t_game *game, t_pos pos_trgt, t_pos cell_trgt, int i)
{
	char	code;

	code = game->map[game->ennemies[i].pos.y][game->ennemies[i].pos.x];
	if (ennemy_sprite_can_move(game, pos_trgt, code, i))
	{
		move_ennemy_sprite(game, cell_trgt, i);
		if (ennemy_position_can_move(game, pos_trgt, code, i))
			move_ennemy_position(game, pos_trgt, code, i);
	}
	else
		change_direction(game, code, i);
}

void	get_ennemy_direction(t_game *game, t_pos *pos, t_pos *cell)
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

void	move_all_ennemies(t_game *game)
{
	int		i;
	t_pos	pos;
	t_pos	cell;

	i = 0;
	while (i < game->ennemy_count)
	{
		pos = game->ennemies[i].pos;
		cell = game->ennemies[i].cell;
		get_ennemy_direction(game, &pos, &cell);
		move_ennemy(game, pos, cell, i);
		i++;
	}
	read_all_map(game, LOWER_ENNEMY, spawn_ennemy);
}
