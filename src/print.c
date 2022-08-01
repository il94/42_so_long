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

void	put_color(t_data *image, int x, int y, unsigned int color)
{
		char *dst;

		if (color != 0)
		{
			dst = image->addr + y * image->line + x * image->bpp / 8;
			*(unsigned int *)dst = color;
		}
}

unsigned int get_color(t_data *image, int x, int y)
{
	char *dst;

	dst = image->addr + y * image->line + x * 4;
	return (*(unsigned int *)dst);
}

int	draw_image(t_game *game, t_data *image, t_axe pos)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < CELL)
	{
		j = 0;
		while (j < CELL)
		{
			put_color(&game->screen, j + (CELL * pos.x), i + (CELL * pos.y), get_color(image, j, i));
			j++;
		}
		i++;
	}
	return (0);
}

void	print_wall(t_game *game, t_axe pos)
{
	if (pos.y < game->y_map - 1 && pos.y > 0
		&& game->map[pos.y + 1][pos.x] == '1'
		&& game->map[pos.y - 1][pos.x] == '1')
		draw_image(game, &game->wall_mid, pos);
	else if (pos.y < game->y_map - 1 && game->map[pos.y + 1][pos.x] == '1')
		draw_image(game, &game->wall_top, pos);
	else if (pos.y > 0 && game->map[pos.y - 1][pos.x] == '1')
		draw_image(game, &game->wall_bot, pos);
	else
		draw_image(game, &game->wall_one, pos);
}

void	print_environnement(t_game *game)
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
			if (game->map[pos.y][pos.x] == '1')
				print_wall(game, pos);
			else
				draw_image(game, &game->grass, pos);
			pos.x++;
		}
		pos.y++;
	}
}

void	print_mobs(t_game *game, t_axe pos)
{
	if (game->map[pos.y][pos.x] == 'P')
		draw_image(game, &game->mario, pos);
	else if (get_direction(game, pos, &ennemy_proximity) == 1)
		draw_image(game, &game->goomba_r, pos);
	else if (get_direction(game, pos, &ennemy_proximity) == 2)
		draw_image(game, &game->goomba_b, pos);
	else
		draw_image(game, &game->goomba, pos);
}

void	print_collectibles(t_game *game, t_axe pos)
{
	if (game->map[pos.y][pos.x] == 'C')
		draw_image(game, &game->coin, pos);
	else if (game->map[pos.y][pos.x] == 'e')
		draw_image(game, &game->star, pos);
	else if (game->map[pos.y][pos.x] == 'E')
		draw_image(game, &game->grass, pos);
}

void	print_elements(t_game *game)
{
	t_axe	pos;
	char	target;

	pos.y = 0;
	pos.x = 0;
	print_environnement(game);
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			target = game->map[pos.y][pos.x];
			if (target == 'C' || target == 'E' || target == 'e')
				print_collectibles(game, pos);
			else if (is_ennemy(target) || target == 'P')
				print_mobs(game, pos);
			pos.x++;
		}
		pos.y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
}
