/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:53:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/27 18:16:35 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	search_ennemy(t_game *game)
{
	t_axe	pos;

	pos.y = 1;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			if (is_ennemy(game->map[pos.y][pos.x]))
				get_direction(game, pos, &move_ennemy);
			pos.x++;
		}
		pos.y++;
	}
	spawn_ennemy(game);
	game->time_a = (unsigned int)time(NULL);
}

int	no_more_collectibles(t_game *game)
{
	t_axe	pos;

	pos.y = 1;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			if (game->map[pos.y][pos.x] == 'C')
				return (0);
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}

int	open_exit_door(t_game *game)
{
	t_axe	pos;

	pos.y = 1;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			if (game->map[pos.y][pos.x] == 'E')
			{
				ft_print_array(game->map);
				game->map[pos.y][pos.x] = 'e';
				ft_print_array(game->map);
				return (0);
			}
			pos.x++;
		}
		pos.y++;
	}
}

int	get_player_position(t_game *game)
{
	t_axe	pos;

	pos.y = 1;
	while (game->map[pos.y])
	{
		pos.x = 1;
		while (game->map[pos.y][pos.x])
		{
			if (game->map[pos.y][pos.x] == 'P')
			{
				game->x_pos = pos.x;
				game->y_pos = pos.y;
				return (0);
			}
			pos.x++;
		}
		pos.y++;
	}
}
