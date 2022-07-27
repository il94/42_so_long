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

void	print_environnement(t_game *game, t_axe pos, int y_map)
{
	if (game->map[pos.y][pos.x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->grass.img,
			pos.x * CELL, pos.y * CELL);
	else
	{
		if (pos.y < y_map - 1 && pos.y > 0
			&& game->map[pos.y + 1][pos.x] == '1'
			&& game->map[pos.y - 1][pos.x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall_mid.img,
				pos.x * CELL, pos.y * CELL);
		else if (pos.y < y_map - 1 && game->map[pos.y + 1][pos.x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall_top.img,
				pos.x * CELL, pos.y * CELL);
		else if (pos.y > 0 && game->map[pos.y - 1][pos.x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall_bot.img,
				pos.x * CELL, pos.y * CELL);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->wall_one.img,
				pos.x * CELL, pos.y * CELL);
	}
}

void	print_mobs(t_game *game, t_axe pos)
{
	if (game->map[pos.y][pos.x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->mario.img,
			pos.x * CELL, pos.y * CELL);
	else if (get_direction(game, pos, &ennemy_proximity) == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->goomba_r.img,
			pos.x * CELL, pos.y * CELL);
	else if (get_direction(game, pos, &ennemy_proximity) == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->goomba_b.img,
			pos.x * CELL, pos.y * CELL);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->goomba.img,
			pos.x * CELL, pos.y * CELL);
}

void	print_collectibles(t_game *game, t_axe pos)
{
	if (game->map[pos.y][pos.x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->mushroom.img,
			pos.x * CELL, pos.y * CELL);
	else if (game->map[pos.y][pos.x] == 'e')
		mlx_put_image_to_window(game->mlx, game->win, game->star.img,
			pos.x * CELL, pos.y * CELL);
	else if (game->map[pos.y][pos.x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->grass.img,
			pos.x * CELL, pos.y * CELL);
}

void	print_elements(t_game *game)
{
	t_axe	pos;
	char	target;

	pos.y = 0;
	pos.x = 0;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			target = game->map[pos.y][pos.x];
			if (target == '0' || target == '1')
				print_environnement(game, pos, game->y_map);
			else if (target == 'C' || target == 'E' || target == 'e')
				print_collectibles(game, pos);
			else if (is_ennemy(target) || target == 'P')
				print_mobs(game, pos);
			pos.x++;
		}
		pos.y++;
	}
}
