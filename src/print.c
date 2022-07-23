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
	if (101 % j <= 3)
		mlx_put_image_to_window(game->mlx, game->win, game->goomba.img, j * game->goomba.width, i * game->goomba.height);
	else if (101 % j > 3 && (101 % j <= 8))
		mlx_put_image_to_window(game->mlx, game->win, game->goomba_b.img, j * game->goomba_b.width, i * game->goomba_b.height);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->goomba_g.img, j * game->goomba_g.width, i * game->goomba_g.height);
}

void	print_walls(t_game *game, int i, int j, int y_map)
{
	if ((i == 0 && game->map[i + 1][j] != '1')
		|| (i == y_map - 1 && game->map[i - 1][j] != '1')
		|| (game->map[i + 1]
		&& game->map[i + 1][j] != '1' && game->map[i - 1][j] != '1'))
		mlx_put_image_to_window(game->mlx, game->win, game->wall_one.img, j * game->wall_one.width, i * game->wall_one.height);
	else if ((i == y_map - 1 && game->map[i - 1][j] == '1')
		|| (i != 0 && game->map[i + 1][j] != '1' && game->map[i - 1][j] == '1'))
		mlx_put_image_to_window(game->mlx, game->win, game->wall_bot.img, j * game->wall_bot.width, i * game->wall_bot.height);
	else if (i > 0 && game->map[i - 1][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_mid.img, j * game->wall_mid.width, i * game->wall_mid.height);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->wall_top.img, j * game->wall_top.width, i * game->wall_top.height);}

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
				mlx_put_image_to_window(game->mlx, game->win, game->floor.img, j * game->floor.width, i * game->floor.height);
			else if (game->map[i][j] == '1')
				print_walls(game, i, j, game->y_map);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->mushroom.img, j * game->mushroom.width, i * game->mushroom.height);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->star.img, j * game->star.width, i * game->star.height);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->mario.img, j * game->mario.width, i * game->mario.height);
			else if (game->map[i][j] == 'M')
				print_ennemies(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
