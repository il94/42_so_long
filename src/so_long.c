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
	if (game->x_pos == x_bot && game->y_pos == y_bot)
		return (1);
	if (is_ennemy_obstacle(game->map[y_bot][x_bot]) && is_near(game, pos, 'P'))
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
