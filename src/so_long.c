/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:53:50 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/24 00:53:50 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	spawn_ennemy(t_game *game)
{
	t_axe	pos;

	pos.y = 1;
	while (pos.y < game->y_map - 1)
	{
		pos.x = 1;
		while (pos.x < game->x_map - 1)
		{
			if (is_lower_ennemy(game->map[pos.y][pos.x]))
				game->map[pos.y][pos.x] = ft_toupper(game->map[pos.y][pos.x]);
			pos.x++;
		}
		pos.y++;
	}
}

int	ennemy_proximity(t_game *game, t_axe pos, int y_bot, int x_bot)
{
	if (game->player.x == x_bot && game->player.y == y_bot)
		return (1);
	if (is_ennemy_obstacle(game->map[y_bot][x_bot]) && is_near_p(game, pos))
		return (2);
	return (0);
}

int	is_near(t_game *game, t_axe pos, char c)
{
	return (game->map[pos.y + 1][pos.x] == c
			|| game->map[pos.y][pos.x + 1] == c
			|| game->map[pos.y - 1][pos.x] == c
			|| game->map[pos.y][pos.x - 1] == c);
}

int	is_near_e(t_game *game, t_axe pos)
{
	return (is_ennemy(game->map[pos.y + 1][pos.x])
			|| is_ennemy(game->map[pos.y][pos.x + 1])
			|| is_ennemy(game->map[pos.y - 1][pos.x])
			|| is_ennemy(game->map[pos.y][pos.x - 1]));
}

int	is_near_p(t_game *game, t_axe pos)
{
	return (is_player(game->map[pos.y + 1][pos.x])
			|| is_player(game->map[pos.y][pos.x + 1])
			|| is_player(game->map[pos.y - 1][pos.x])
			|| is_player(game->map[pos.y][pos.x - 1]));
}

void	kill_ennemies(t_game *game)
{
	t_axe	pos;

	system("cvlc sound/goomba.wav &");
	pos.y = 1;
	while (game->map[pos.y])
	{
		pos.x = 1;
		while (game->map[pos.y][pos.x])
		{
			if (is_ennemy(game->map[pos.y][pos.x]))
				game->map[pos.y][pos.x] = '0';
			pos.x++;
		}
		pos.y++;
	}
}
