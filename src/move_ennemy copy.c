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
	t_axe	trgt;

	trgt = pos;
	if (game->map[pos.y][pos.x] == 'D')
	{
		game->map[pos.y][pos.x] = 'R';
		trgt.x++;
	}
	else if (game->map[pos.y][pos.x] == 'R')
	{
		game->map[pos.y][pos.x] = 'U';
		trgt.y--;
	}
	else if (game->map[pos.y][pos.x] == 'U')
	{
		game->map[pos.y][pos.x] = 'L';
		trgt.x--;
	}
	else if (game->map[pos.y][pos.x] == 'L')
	{
		game->map[pos.y][pos.x] = 'D';
		trgt.y++;
	}
	move_ennemy(game, pos, trgt);
}

int	move_ennemy(t_game *game, t_axe pos, t_axe trgt)
{
	if (game->map[trgt.y][trgt.x] == 'P')
		end_game(game, LOOSE);
	else if (game->map[trgt.y][trgt.x] == '0')
	{
		game->map[trgt.y][trgt.x] = ft_tolower(game->map[pos.y][pos.x]);
		game->map[pos.y][pos.x] = '0';
	}
	else if (is_near(game, pos, '0') || is_near_p(game, pos))
		change_direction(game, pos);
	return (0);
}

int	get_direction(t_game *game, t_axe pos, int (*f)(t_game *, t_axe, t_axe))
{
	t_axe	trgt;

	trgt = pos;
	if (game->map[pos.y][pos.x] == 'M')
		game->map[pos.y][pos.x] = 'D';
	if (game->map[pos.y][pos.x] == 'D')
		trgt.y++;
	else if (game->map[pos.y][pos.x] == 'R')
		trgt.x++;
	else if (game->map[pos.y][pos.x] == 'U')
		trgt.y--;
	else if (game->map[pos.y][pos.x] == 'L')
		trgt.x--;
	return ((*f)(game, pos, trgt));
}
