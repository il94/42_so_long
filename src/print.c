/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:50:53 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/24 00:50:53 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_environnement(t_game *game, int y, int x, int y_map)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor.img,
			x * CELL, y * CELL);
	else
	{
		if (y < y_map - 1 && y > 0
			&& game->map[y + 1][x] == '1' && game->map[y - 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall_mid.img,
				x * CELL, y * CELL);
		else if (y < y_map - 1 && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall_top.img,
				x * CELL, y * CELL);
		else if (y > 0 && game->map[y - 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall_bot.img,
				x * CELL, y * CELL);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->wall_one.img,
				x * CELL, y * CELL);
	}
}

void	print_mobs(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->mario.img,
			x * CELL, y * CELL);
	else if (player_is_in_danger(game, y, x))
		mlx_put_image_to_window(game->mlx, game->win, game->goomba_r.img,
			x * CELL, y * CELL);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->goomba.img,
			x * CELL, y * CELL);
}

void	print_collectibles(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->mushroom.img,
			x * CELL, y * CELL);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->star.img,
			x * CELL, y * CELL);
}

int	print_elements(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->y_map)
	{
		x = 0;
		while (x < game->x_map)
		{
			if (game->map[y][x] == '0' || game->map[y][x] == '1')
				print_environnement(game, y, x, game->y_map);
			else if (game->map[y][x] == 'C' || game->map[y][x] == 'E')
				print_collectibles(game, y, x);
			else if (is_ennemies(game->map[y][x]) || game->map[y][x] == 'P')
				print_mobs(game, y, x);
			x++;
		}
		y++;
	}
	move_ennemies(game);
	return (0);
}
