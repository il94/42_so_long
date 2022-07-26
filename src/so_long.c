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

void	get_player_position(t_game *game)
{
	game->x_pos = 1;
	game->y_pos = 1;
	while (game->map[game->y_pos][game->x_pos]
		&& game->map[game->y_pos][game->x_pos] != 'P')
	{
		game->x_pos += 1;
		if (game->x_pos == game->x_map)
		{
			game->x_pos = 1;
			game->y_pos += 1;
		}
	}
}

int	player_is_in_danger(t_game *game, int y, int x)
{
	if (game->x_pos == x + 1 && game->y_pos == y && game->map[y][x] == 'R')
		return (1);
	else if (game->x_pos == x && game->y_pos == y + 1 && game->map[y][x] == 'D')
		return (1);
	else if (game->x_pos == x - 1 && game->y_pos == y && game->map[y][x] == 'L')
		return (1);
	else if (game->x_pos == x && game->y_pos == y - 1 && game->map[y][x] == 'U')
		return (1);
	return (0);
}
