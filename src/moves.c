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

void	change_direction(t_game *game, t_coordinates pos, int y_bot, int x_bot)
{
	if (game->map[pos.y][pos.x] == 'D')
	{
		game->map[pos.y][pos.x] = 'R';
		move_ennemies(game, pos, pos.y, pos.x + 1);
	}
	else if (game->map[pos.y][pos.x] == 'R')
	{
		game->map[pos.y][pos.x] = 'U';
		move_ennemies(game, pos, pos.y - 1, pos.x);
	}
	else if (game->map[pos.y][pos.x] == 'U')
	{
		game->map[pos.y][pos.x] = 'L';
		move_ennemies(game, pos, pos.y, pos.x - 1);
	}
	else if (game->map[pos.y][pos.x] == 'L')
	{
		game->map[pos.y][pos.x] = 'D';
		move_ennemies(game, pos, pos.y + 1, pos.x);
	}
}

void	move_ennemies(t_game *game, t_coordinates pos, int y_bot, int x_bot)
{
	if (game->map[y_bot][x_bot] == 'P')
		end_game(game, LOOSE);
	if (game->map[y_bot][x_bot] == '0')
	{
		game->map[y_bot][x_bot] = ft_tolower(game->map[pos.y][pos.x]);
		game->map[pos.y][pos.x] = '0';
	}
	else
		change_direction(game, pos, pos.y, pos.x);
}

int	get_direction(t_game *game, t_coordinates pos)
{
	ft_print_array(game->map);
	printf("\n=====\n");

	if (game->map[pos.y][pos.x] == 'M')
		game->map[pos.y][pos.x] = 'D';
	if (game->map[pos.y][pos.x] == 'D')
		move_ennemies(game, pos, pos.y + 1, pos.x);
	else if (game->map[pos.y][pos.x] == 'R')
		move_ennemies(game, pos, pos.y, pos.x + 1);
	else if (game->map[pos.y][pos.x] == 'U')
		move_ennemies(game, pos, pos.y - 1, pos.x);
	else if (game->map[pos.y][pos.x] == 'L')
		move_ennemies(game, pos, pos.y, pos.x - 1);
	return (0);
}

int	search_ennemies(t_game *game)
{
	t_coordinates	pos;

	pos.y = 1;
	while (pos.y < game->y_map - 1)
	{
		pos.x = 0;
		while (pos.x < game->x_map - 1)
		{
			if (game->map[pos.y][pos.x] && is_ennemies(game->map[pos.y][pos.x]))
				get_direction(game, pos);
			pos.x += 1;
		}
		pos.y += 1;
	}
	pos.y = 1;
	while (pos.y < game->y_map - 1)
	{
		pos.x = 1;
		while (pos.x < game->x_map - 1)
		{
			if (is_ennemies_m(game->map[pos.y][pos.x]))
				game->map[pos.y][pos.x] = ft_toupper(game->map[pos.y][pos.x]);
			pos.x += 1;
		}
		pos.y += 1;
	}
	game->time_a = (unsigned int)time(NULL);
}

void	move_player(t_game *game, int y, int x)
{
	if (is_ennemies(game->map[y][x]))
		end_game(game, LOOSE);
	else if (game->map[y][x] != '1')
	{
		game->map[game->y_pos][game->x_pos] = '0';
		game->x_pos = x;
		game->y_pos = y;
		game->map[game->y_pos][game->x_pos] = 'P';
		ft_printf("Moves = %d\n", game->moves += 1);
	}
}
