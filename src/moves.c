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
	if (is(PLAYER, game->map[y_bot][x_bot]))
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

void	move_player(t_game *game, int y, int x, char code)
{
	if (is(ENNEMY, game->map[y][x]))
		end_game(game, LOOSE);
	else if (game->map[y][x] == 'e')
		end_game(game, WIN);
	else if (game->map[y][x] != '1' && game->map[y][x] != 'E')
	{
		if (game->map[y][x] == 'C')
			system("cvlc sound/coin.wav &");
		game->map[game->player.y][game->player.x] = '0';
		game->player.x = x;
		game->player.y = y;
		game->map[game->player.y][game->player.x] = code;
		ft_printf("Moves = %d\n", game->moves += 1);
	}
}
