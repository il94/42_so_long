/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:32:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/14 21:55:11 by ilandols         ###   ########.fr       */
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

int	player_sprite_can_move(t_game *game, t_pos pos_trgt)
{
	if (game->move_up && (!is("1E", game->map[pos_trgt.y][pos_trgt.x])
		|| game->player_pos.y * CELL < game->player_cell.y))
		return (1);
	else if (game->move_right && (!is("1E", game->map[pos_trgt.y][pos_trgt.x])
		|| game->player_pos.x * CELL >= game->player_cell.x - CELL / 2))
		return (1);
	else if (game->move_down && (!is("1E", game->map[pos_trgt.y][pos_trgt.x])
		|| game->player_pos.y * CELL > game->player_cell.y - CELL))
		return (1);
	else if (game->move_left && (!is("1E", game->map[pos_trgt.y][pos_trgt.x])
		|| game->player_pos.x * CELL <= game->player_cell.x - CELL / 2))
		return (1);
	else
		return (0);
}

void	move_player_sprite(t_game *game, t_pos cell_trgt)
{
	game->player_cell = cell_trgt;
	if (game->player_state++ >= game->player_animation_speed)
		game->player_state = 0;
    ft_printf("Steps : %d\n", ++game->player_steps);
}

int	player_position_can_move(t_game *game, t_pos pos_trgt)
{
	if (game->move_up && !is("1E", game->map[pos_trgt.y][pos_trgt.x])
        && game->player_cell.y / CELL < game->player_pos.y)
		return (1);
	else if (game->move_right && !is("1E", game->map[pos_trgt.y][pos_trgt.x])
            && game->player_cell.x > game->player_pos.x * CELL + CELL + 8)
		return (1);
	else if (game->move_down && !is("1E", game->map[pos_trgt.y][pos_trgt.x])
            && game->player_cell.y / CELL > game->player_pos.y)
		return (1);
	else if (game->move_left && !is("1E", game->map[pos_trgt.y][pos_trgt.x])
            && game->player_cell.x < game->player_pos.x * CELL - 8)
		return (1);
	return (0);
}

void	move_player_position(t_game *game, t_pos pos_trgt)
{
	if (game->map[pos_trgt.y][pos_trgt.x] == 'e')
		end_game(game, WIN);
	else if (game->map[pos_trgt.y][pos_trgt.x] == 'H')
		game->get_hammer = TRUE;
	else if (game->map[pos_trgt.y][pos_trgt.x] == 'B')
		game->get_boots = TRUE;
	else if (game->map[pos_trgt.y][pos_trgt.x] == 'C')
        system("cvlc sound/coin.wav &");
	if (!is(ENNEMY, game->map[game->player_pos.y][game->player_pos.x]))
   		game->map[game->player_pos.y][game->player_pos.x] = '0';
    game->player_pos.x = pos_trgt.x;
    game->player_pos.y = pos_trgt.y;
    game->map[game->player_pos.y][game->player_pos.x] = 'P';
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

void	move_player(t_game *game)
{
	t_pos	pos_trgt;
	t_pos	cell_trgt;

	pos_trgt = game->player_pos;
	cell_trgt = game->player_cell;
	get_player_direction(game, &pos_trgt, &cell_trgt);
	if (player_sprite_can_move(game, pos_trgt))
		move_player_sprite(game, cell_trgt);
	if (collision_player_ennemy(game))
		end_game(game, LOOSE);
	if (player_position_can_move(game, pos_trgt))
		move_player_position(game, pos_trgt);
	get_player_sprite_direction(game);
}
