/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:32:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/13 20:45:08 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_player_sprite_direction(t_game *game)
{
	if (game->move_up)
	{
		if (game->direction == 'a' || game->direction == 'A')
			game->direction = 'a';
		else
			game->direction = 'b';
	}
	else if (game->move_right)
		game->direction = 'B';
	else if (game->move_down)
	{
		if (game->direction == 'a' || game->direction == 'A')
			game->direction = 'A';
		else
			game->direction = 'B';
	}
	else if (game->move_left)
		game->direction = 'A';
}

int	player_sprite_can_move(t_game *game, t_axe pos_trgt)
{
	if (game->move_up && (!is("1E", game->map[pos_trgt.y][pos_trgt.x])
		|| game->player.y * CELL < game->cell.y))
		return (1);
	else if (game->move_right && (!is("1E", game->map[pos_trgt.y][pos_trgt.x])
		|| game->player.x * CELL >= game->cell.x - CELL / 2))
		return (1);
	else if (game->move_down && (!is("1E", game->map[pos_trgt.y][pos_trgt.x])
		|| game->player.y * CELL > game->cell.y - CELL))
		return (1);
	else if (game->move_left && (!is("1E", game->map[pos_trgt.y][pos_trgt.x])
		|| game->player.x * CELL <= game->cell.x - CELL / 2))
		return (1);
	else
		return (0);
}

void	move_player_sprite(t_game *game, t_axe cell_trgt)
{
	game->cell = cell_trgt;
	if (game->state++ >= game->speed_player)
		game->state = 0;
    // ft_printf("Steps : %d\n", ++game->moves);
}

int	player_position_can_move(t_game *game, t_axe pos_trgt)
{
	if (game->move_up && !is("1E", game->map[pos_trgt.y][pos_trgt.x])
        && game->cell.y / CELL < game->player.y)
		return (1);
	else if (game->move_right && !is("1E", game->map[pos_trgt.y][pos_trgt.x])
            && game->cell.x > game->player.x * CELL + CELL + 8)
		return (1);
	else if (game->move_down && !is("1E", game->map[pos_trgt.y][pos_trgt.x])
            && game->cell.y / CELL > game->player.y)
		return (1);
	else if (game->move_left && !is("1E", game->map[pos_trgt.y][pos_trgt.x])
            && game->cell.x < game->player.x * CELL - 8)
		return (1);
	return (0);
}

void	move_player_position(t_game *game, t_axe pos_trgt)
{
	if (game->map[pos_trgt.y][pos_trgt.x] == 'e')
		end_game(game, WIN);
	else if (game->map[pos_trgt.y][pos_trgt.x] == 'H')
		game->get_hammer = 1;
	else if (game->map[pos_trgt.y][pos_trgt.x] == 'J')
		game->get_boots = 1;
	else if (game->map[pos_trgt.y][pos_trgt.x] == 'C')
        system("cvlc sound/coin.wav &");
	if (!is(ENNEMY, game->map[game->player.y][game->player.x]))
   		game->map[game->player.y][game->player.x] = '0';
    game->player.x = pos_trgt.x;
    game->player.y = pos_trgt.y;
    game->map[game->player.y][game->player.x] = 'P';
}

void	move_player(t_game *game, t_axe cell_trgt, t_axe pos_trgt)
{
	if (player_sprite_can_move(game, pos_trgt))
		move_player_sprite(game, cell_trgt);
	if (loose_condition_p(game))
		end_game(game, LOOSE);
	if (player_position_can_move(game, pos_trgt))
		move_player_position(game, pos_trgt);
	get_player_sprite_direction(game);
}
