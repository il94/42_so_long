/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:32:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/23 23:01:14 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_sprite_can_move(t_game *game, t_pos pos_trgt)
{
	int	is_obstacle;

	is_obstacle = is("1E", game->map[pos_trgt.y][pos_trgt.x]);
	if (game->move_up && (!is_obstacle
			|| game->player.pos.y * CELL < game->player.cell.y))
		return (1);
	else if (game->move_right && (!is_obstacle
			|| game->player.pos.x * CELL >= game->player.cell.x - CELL / 2))
		return (1);
	else if (game->move_down && (!is_obstacle
			|| game->player.pos.y * CELL > game->player.cell.y - CELL))
		return (1);
	else if (game->move_left && (!is_obstacle
			|| game->player.pos.x * CELL <= game->player.cell.x - CELL / 2))
		return (1);
	else
		return (0);
}

void	move_player_sprite(t_game *game, t_pos cell_trgt)
{
	game->player.cell = cell_trgt;
	if (game->player.state++ >= game->player.speed_animation)
		game->player.state = 0;
	if (!game->max_player_steps)
		game->player_steps++;
	else
	{
		game->player_steps = 0;
		game->max_player_steps = FALSE;
	}
}

int	player_position_can_move(t_game *game, t_pos pos_trgt)
{
	if (!is("1E", game->map[pos_trgt.y][pos_trgt.x]))
	{
		if (game->player.cell.y / CELL < game->player.pos.y
			&& game->move_up)
			return (1);
		else if (game->player.cell.x > game->player.pos.x * CELL + CELL + 8
			&& game->move_right)
			return (1);
		else if (game->player.cell.y / CELL > game->player.pos.y
			&& game->move_down)
			return (1);
		else if (game->player.cell.x < game->player.pos.x * CELL - 8
			&& game->move_left)
			return (1);
	}
	return (0);
}

void	move_player_position(t_game *game, t_pos pos_trgt)
{
	if (game->map[pos_trgt.y][pos_trgt.x] == 'e')
		end_game(game, WIN);
	else if (game->map[pos_trgt.y][pos_trgt.x] == 'H')
		game->get_hammer = TRUE;
	if (!is(ENEMY, game->map[game->player.pos.y][game->player.pos.x]))
		game->map[game->player.pos.y][game->player.pos.x] = '0';
	game->player.pos = pos_trgt;
	game->map[game->player.pos.y][game->player.pos.x] = 'P';
}

void	move_player(t_game *game)
{
	t_pos	pos_trgt;
	t_pos	cell_trgt;

	pos_trgt = game->player.pos;
	cell_trgt = game->player.cell;
	get_player_direction(game, &pos_trgt, &cell_trgt);
	if (player_sprite_can_move(game, pos_trgt))
		move_player_sprite(game, cell_trgt);
	if (player_position_can_move(game, pos_trgt))
		move_player_position(game, pos_trgt);
	get_player_sprite_direction(game);
}
