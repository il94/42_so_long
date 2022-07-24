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

void	print_ennemies(t_game *game, int i, int j)
{
	if ((game->x_player == j + 1 && game->y_player == i) || (game->x_player == j - 1 && game->y_player == i) || (game->y_player == i + 1 && game->x_player == j) || (game->y_player == i - 1 && game->x_player == j))
		mlx_put_image_to_window(game->mlx, game->win, game->goomba_r.img, j * CELL, i * CELL);
	else if ((game->x_player == j + 2 && game->y_player == i) || (game->x_player == j - 2 && game->y_player == i) || (game->y_player == i + 2 && game->x_player == j) || (game->y_player == i - 2 && game->x_player == j) || (game->x_player == j + 1 && game->y_player == i + 1) || (game->x_player == j - 1 && game->y_player == i + 1) || (game->x_player == j + 1 && game->y_player == i - 1) || (game->x_player == j - 1 && game->y_player == i - 1))
		mlx_put_image_to_window(game->mlx, game->win, game->goomba_b.img, j * CELL, i * CELL);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->goomba.img, j * CELL, i * CELL);
}

void	print_walls(t_game *game, int i, int j, int y_map)
{
	if ((i == 0 && game->map[i + 1][j] != '1')
		|| (i == y_map - 1 && game->map[i - 1][j] != '1')
		|| (game->map[i + 1]
		&& game->map[i + 1][j] != '1' && game->map[i - 1][j] != '1'))
		mlx_put_image_to_window(game->mlx, game->win, game->wall_one.img, j * CELL, i * CELL);
	else if ((i == y_map - 1 && game->map[i - 1][j] == '1')
		|| (i != 0 && game->map[i + 1][j] != '1' && game->map[i - 1][j] == '1'))
		mlx_put_image_to_window(game->mlx, game->win, game->wall_bot.img, j * CELL, i * CELL);
	else if (i > 0 && game->map[i - 1][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_mid.img, j * CELL, i * CELL);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->wall_top.img, j *CELL, i * CELL);}

int	print_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->y_map)
	{
		j = 0;
		while (j < game->x_map)
		{
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor.img, j * CELL, i * CELL);
			else if (game->map[i][j] == '1')
				print_walls(game, i, j, game->y_map);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->mushroom.img, j * CELL, i * CELL);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->star.img, j * CELL, i * CELL);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->mario.img, j * CELL, i * CELL);
			else if (is_ennemies(game->map[i][j]))
				print_ennemies(game, i, j);
			j++;
		}
		i++;
	}

	if ((unsigned int)time(NULL) > game->time_a)
	{
		move_ennemies(game);
		game->time_a = (unsigned int)time(NULL);
	}
	return (0);
}
