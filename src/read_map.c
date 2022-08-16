/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:53:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/16 18:23:12 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	spawn_ennemy(t_game *game, t_pos pos)
{
	game->map[pos.y][pos.x] = ft_toupper(game->map[pos.y][pos.x]);
}

int	more_collectibles(t_game *game, t_pos pos)
{
	return (1);
}

int	open_exit_door(t_game *game, t_pos pos)
{
	game->map[pos.y][pos.x] = 'e';
	system("pkill vlc");
	system("cvlc sound/star_spawn.wav &");
	sleep(3);
	game->night = TRUE;
	system("cvlc sound/star_way.wav &");
	return (1);
}

int	get_player_position(t_game *game, t_pos pos)
{
	game->player_pos = pos;
	game->player_cell.x = (game->player_pos.x * CELL) + (CELL / 2);
	game->player_cell.y = (game->player_pos.y * CELL) + CELL - (CELL / 6);
	return (1);
}

int	read_map(t_game *game, char *target, int (*f)(t_game *, t_pos))
{
	t_pos	pos;

	pos.y = 1;
	while (game->map[pos.y])
	{
		pos.x = 1;
		while (game->map[pos.y][pos.x])
		{
			if (is(target, game->map[pos.y][pos.x]))
				return ((*f)(game, pos));
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

void	read_all_map(t_game *game, char *target, void (*f)(t_game *, t_pos))
{
	t_pos	pos;

	pos.y = 0;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			if (is(target, game->map[pos.y][pos.x]))
				((*f)(game, pos));
			pos.x++;
		}
		pos.y++;
	}
}

void	iterate_ennemies(t_game *game, void (*f)(t_game *, t_data *))
{
	int	i;

	i = 0;
	while (i < game->ennemy_count)
	{
		(*f)(game, &game->ennemies[i]);
		i++;
	}
}