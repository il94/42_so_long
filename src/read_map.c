/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:53:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/31 23:17:11 by ilandols         ###   ########.fr       */
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

int	more_collectibles(t_game *game, t_axe pos)
{
	return (1);
}

int	open_exit_door(t_game *game, t_axe pos)
{
	game->map[pos.y][pos.x] = 'e';
	system("pkill vlc");
	system("cvlc sound/star_spawn.wav &");
	sleep(13);
	system("cvlc sound/star_way.wav &");
	return (1);
}

int	get_player_position(t_game *game, t_axe pos)
{
	game->player.x = pos.x;
	game->player.y = pos.y;
	return (1);
}

int	read_map(t_game *game, char target, int (*f)(t_game *, t_axe))
{
	t_axe	pos;

	pos.y = 1;
	while (game->map[pos.y])
	{
		pos.x = 1;
		while (game->map[pos.y][pos.x])
		{
			if (game->map[pos.y][pos.x] == target)
				return ((*f)(game, pos));
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
