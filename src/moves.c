/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:06:00 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/26 01:06:00 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	change_direction(t_game *game, t_axe pos)
{
	if (game->map[pos.y][pos.x] == 'D')
	{
		game->map[pos.y][pos.x] = 'R';
		move_ennemy(game, pos, pos.y, pos.x + 1);
	}
	else if (game->map[pos.y][pos.x] == 'R')
	{
		game->map[pos.y][pos.x] = 'U';
		move_ennemy(game, pos, pos.y - 1, pos.x);
	}
	else if (game->map[pos.y][pos.x] == 'U')
	{
		game->map[pos.y][pos.x] = 'L';
		move_ennemy(game, pos, pos.y, pos.x - 1);
	}
	else if (game->map[pos.y][pos.x] == 'L')
	{
		game->map[pos.y][pos.x] = 'D';
		move_ennemy(game, pos, pos.y + 1, pos.x);
	}
}

int	move_ennemy(t_game *game, t_axe pos, int y_bot, int x_bot)
{
	if (game->map[y_bot][x_bot] == 'P')
		end_game(game, LOOSE);
	else if (game->map[y_bot][x_bot] == '0')
	{
		game->map[y_bot][x_bot] = ft_tolower(game->map[pos.y][pos.x]);
		game->map[pos.y][pos.x] = '0';
	}
	else if (is_near(game, pos, '0') || is_near_p(game, pos))
		change_direction(game, pos);
	return (0);
}

int	get_direction(t_game *game, t_axe pos, int (*f)(t_game *, t_axe, int, int))
{
	if (game->map[pos.y][pos.x] == 'M')
		game->map[pos.y][pos.x] = 'D';
	if (game->map[pos.y][pos.x] == 'D')
		return ((*f)(game, pos, pos.y + 1, pos.x));
	else if (game->map[pos.y][pos.x] == 'R')
		return ((*f)(game, pos, pos.y, pos.x + 1));
	else if (game->map[pos.y][pos.x] == 'U')
		return ((*f)(game, pos, pos.y - 1, pos.x));
	else if (game->map[pos.y][pos.x] == 'L')
		return ((*f)(game, pos, pos.y, pos.x - 1));
}

void	get_direction_2(t_game *game, int keycode)
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

void	move_player_22(t_game *game, t_axe player, int keycode)
{
	if (is(ENNEMY, game->map[player.y][player.x]))
		end_game(game, LOOSE);
	else if (game->map[player.y][player.x] == 'e')
		end_game(game, WIN);
	else if (game->map[player.y][player.x] != '1' && game->map[player.y][player.x] != 'E')
	{
		if (game->map[player.y][player.x] == 'C')
			system("cvlc sound/coin.wav &");
		game->map[game->player.y][game->player.x] = '0';
		game->player.x = player.x;
		game->player.y = player.y;
		game->map[game->player.y][game->player.x] = 'P';
		ft_printf("Moves = %d\n", game->moves += 1);
	}
}

int	move_player_12(t_game *game, t_axe cell, t_axe player, int keycode)
{
	if (keycode == KEY_W && (game->map[player.y][player.x] != '1'
		|| game->player.y * CELL < game->cell.y))
		return (1);
	else if (keycode == KEY_D && (game->map[player.y][player.x] != '1'
		|| game->player.x * CELL >= game->cell.x - CELL / 2))
		return (1);
	else if (keycode == KEY_S && (game->map[player.y][player.x] != '1'
		|| game->player.y * CELL > game->cell.y - CELL))
		return (1);
	else if (keycode == KEY_A && (game->map[player.y][player.x] != '1'
		|| game->player.x * CELL <= game->cell.x - CELL / 2))
		return (1);
	else
		return (0);

}

int	move_player_11(t_game *game, t_axe cell, t_axe player, int keycode)
{
	if (keycode == KEY_W && game->cell.y / CELL < game->player.y)
		return (1);
	else if (keycode == KEY_D && game->cell.x > game->player.x * CELL - (CELL / 3) + CELL)
		return (1);
	else if (keycode == KEY_S && game->cell.y / CELL > game->player.y)
		return (1);
	else if (keycode == KEY_A && game->cell.x < game->player.x * CELL + (CELL / 3))
		return (1);
	return (0);
}

void	move_player(t_game *game, t_axe cell, t_axe player, int keycode)
{
	if (move_player_12(game, cell, player, keycode))
	{
		game->cell.y = cell.y;
		game->cell.x = cell.x;
	}
	if (move_player_11(game, cell, player, keycode))
		move_player_22(game, player, keycode);
	get_direction_2(game, keycode);
}
