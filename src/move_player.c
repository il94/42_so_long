/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:32:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/11 23:42:22 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_player_sprite_direction(t_game *game, int keycode)
{
	if (keycode == KEY_W)
	{
		if (game->direction == 'a' || game->direction == 'A')
			game->direction = 'a';
		else
			game->direction = 'b';
	}
	else if (keycode == KEY_D)
		game->direction = 'B';
	else if (keycode == KEY_S)
	{
		if (game->direction == 'a' || game->direction == 'A')
			game->direction = 'A';
		else
			game->direction = 'B';
	}
	else if (keycode == KEY_A)
		game->direction = 'A';
}

int	player_sprite_can_move(t_game *game, t_axe pos_trgt, int keycode)
{
	if (keycode == KEY_W && (!is("1E", game->map[pos_trgt.y][pos_trgt.x])
		|| game->player.y * CELL < game->cell.y))
		return (1);
	else if (keycode == KEY_D && (!is("1E", game->map[pos_trgt.y][pos_trgt.x])
		|| game->player.x * CELL >= game->cell.x - CELL / 2))
		return (1);
	else if (keycode == KEY_S && (!is("1E", game->map[pos_trgt.y][pos_trgt.x])
		|| game->player.y * CELL > game->cell.y - CELL))
		return (1);
	else if (keycode == KEY_A && (!is("1E", game->map[pos_trgt.y][pos_trgt.x])
		|| game->player.x * CELL <= game->cell.x - CELL / 2))
		return (1);
	else
		return (0);
}

void	move_player_sprite(t_game *game, t_axe cell_trgt)
{
	game->cell.y = cell_trgt.y;
	game->cell.x = cell_trgt.x;
	if (game->state++ >= 3)
		game->state = 0;
    ft_printf("Steps : %d\n", ++game->moves);
}

int	player_position_can_move(t_game *game, t_axe pos_trgt, int keycode)
{
	if (keycode == KEY_W && !is("1E", game->map[pos_trgt.y][pos_trgt.x])
        && game->cell.y / CELL < game->player.y)
		return (1);
	else if (keycode == KEY_D && !is("1E", game->map[pos_trgt.y][pos_trgt.x])
            && game->cell.x > game->player.x * CELL - (CELL / 3) + CELL)
		return (1);
	else if (keycode == KEY_S && !is("1E", game->map[pos_trgt.y][pos_trgt.x])
            && game->cell.y / CELL > game->player.y)
		return (1);
	else if (keycode == KEY_A && !is("1E", game->map[pos_trgt.y][pos_trgt.x])
            && game->cell.x < game->player.x * CELL + (CELL / 3))
		return (1);
	return (0);
}

void	move_player_position(t_game *game, t_axe pos_trgt, int keycode)
{
	if (is(ENNEMY, game->map[pos_trgt.y][pos_trgt.x]))
		end_game(game, LOOSE);
	else if (game->map[pos_trgt.y][pos_trgt.x] == 'e')
		end_game(game, WIN);
	else if (game->map[pos_trgt.y][pos_trgt.x] == 'H')
		game->get_hammer = 1;
	else if (game->map[pos_trgt.y][pos_trgt.x] == 'C')
        system("cvlc sound/coin.wav &");
    game->map[game->player.y][game->player.x] = '0';
    game->player.x = pos_trgt.x;
    game->player.y = pos_trgt.y;
    game->map[game->player.y][game->player.x] = 'P';
}

void	move_player(t_game *game, t_axe cell_trgt, t_axe pos_trgt, int keycode)
{
	if (player_sprite_can_move(game, pos_trgt, keycode))
		move_player_sprite(game, cell_trgt);
	if (player_position_can_move(game, pos_trgt, keycode))
		move_player_position(game, pos_trgt, keycode);
	get_player_sprite_direction(game, keycode);
}

/* trgt = target */
