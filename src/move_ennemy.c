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

int	ennemy_sprite_can_move(t_game *game, t_axe pos_trgt, char code)
{
	if (code == 'U' && (!is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
		|| game->ennemies[game->i_ennemy].pos.y * CELL < game->ennemies[game->i_ennemy].cell.y - CELL / 2))
		return (1);
	else if (code == 'R' && (!is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
		|| game->ennemies[game->i_ennemy].pos.x * CELL >= game->ennemies[game->i_ennemy].cell.x - CELL / 2))
		return (1);
	else if (code == 'D' && (!is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
		|| game->ennemies[game->i_ennemy].pos.y * CELL > game->ennemies[game->i_ennemy].cell.y - CELL / 2))
		return (1);
	else if (code == 'L' && (!is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
		|| game->ennemies[game->i_ennemy].pos.x * CELL <= game->ennemies[game->i_ennemy].cell.x - CELL / 2))
		return (1);
	return (0);
}

void	move_ennemy_sprite(t_game *game, t_axe cell_trgt)
{
	game->ennemies[game->i_ennemy].cell = cell_trgt;
	if (game->state_ennemy++ >= 3)
		game->state_ennemy = 0;
}

int	ennemy_position_can_move(t_game *game, t_axe pos_trgt, char code)
{
	if (code == 'U' && !is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
        && game->ennemies[game->i_ennemy].cell.y / CELL < game->ennemies[game->i_ennemy].pos.y)
		return (1);
	else if (code == 'R' && !is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
            && game->ennemies[game->i_ennemy].cell.x > game->ennemies[game->i_ennemy].pos.x * CELL - (CELL / 3) + CELL)
		return (1);
	else if (code == 'D' && !is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
            && game->ennemies[game->i_ennemy].cell.y / CELL > game->ennemies[game->i_ennemy].pos.y)
		return (1);
	else if (code == 'L' && !is(ENNEMY_OBSTACLE, game->map[pos_trgt.y][pos_trgt.x])
            && game->ennemies[game->i_ennemy].cell.x < game->ennemies[game->i_ennemy].pos.x * CELL + (CELL / 3))
		return (1);
	return (0);
}

void	change_direction(t_game *game, t_axe cell_trgt, t_axe pos_trgt, char code)
{
	if (code == 'D')
		game->map[game->ennemies[game->i_ennemy].pos.y][game->ennemies[game->i_ennemy].pos.x] = 'R';
	else if (code == 'R')
		game->map[game->ennemies[game->i_ennemy].pos.y][game->ennemies[game->i_ennemy].pos.x] = 'U';
	else if (code == 'U')
		game->map[game->ennemies[game->i_ennemy].pos.y][game->ennemies[game->i_ennemy].pos.x] = 'L';
	else if (code == 'L')
		game->map[game->ennemies[game->i_ennemy].pos.y][game->ennemies[game->i_ennemy].pos.x] = 'D';
}

void	move_ennemy_position(t_game *game, t_axe trgt, char code)
{
	if (game->map[trgt.y][trgt.x] == 'P')
		end_game(game, LOOSE);
	else if (game->map[trgt.y][trgt.x] == '0')
	{
		game->map[game->ennemies[game->i_ennemy].pos.y][game->ennemies[game->i_ennemy].pos.x] = '0';
		game->ennemies[game->i_ennemy].pos.x = trgt.x;
		game->ennemies[game->i_ennemy].pos.y = trgt.y;
		game->map[trgt.y][trgt.x] = ft_tolower(code);
	}
}

int	move_ennemy(t_game *game, t_axe cell_trgt, t_axe pos_trgt)
{
	char	code;

	code = game->map[game->ennemies[game->i_ennemy].pos.y][game->ennemies[game->i_ennemy].pos.x];
	if (ennemy_sprite_can_move(game, pos_trgt, code))
	{
		move_ennemy_sprite(game, cell_trgt);
		if (ennemy_position_can_move(game, pos_trgt, code))
			move_ennemy_position(game, pos_trgt, code);
	}
	else
		change_direction(game, game->ennemies[game->i_ennemy].cell, game->ennemies[game->i_ennemy].pos, code);
	return (0);
}

int	get_ennemy_direction(t_game *game, t_axe pos, t_axe cell)
{
	if (game->map[pos.y][pos.x] == 'M')
		game->map[pos.y][pos.x] = 'D';
	if (game->map[pos.y][pos.x] == 'D')
	{
		cell.y += 1;
		pos.y += 1;
	}
	else if (game->map[pos.y][pos.x] == 'R')
	{
		cell.x += 1;
		pos.x += 1;
	}
	else if (game->map[pos.y][pos.x] == 'U')
	{
		cell.y -= 1;
		pos.y -= 1;
	}
	else if (game->map[pos.y][pos.x] == 'L')
	{
		cell.x -= 1;
		pos.x -= 1;
	}
	move_ennemy(game, cell, pos);
}
