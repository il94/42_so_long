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

int get_color(t_data *image, int x, int y)
{
	char *dst;

	dst = image->addr + y * image->line + x * 4;
	return (*(int *)dst);
}

void	put_color(t_game *game, t_data *image, t_axe pos, t_axe cell_pos)
{
	char *dst;

	int x;
	int y;
	int color;
	
	x = cell_pos.y + (CELL * pos.x);
	y = cell_pos.x + (CELL * pos.y);
	color = get_color(image, cell_pos.y, cell_pos.x);
	if (color >= -1)
	{
		dst = game->screen.addr + y * game->screen.line + x * game->screen.bpp / 8;
		*(int *)dst = color;
	}
}

int	draw_image(t_game *game, t_data *image, t_axe pos)
{
	t_axe	cell_pos;
	size_t	i;
	size_t	j;

	cell_pos.y = 0;
	while (cell_pos.y < CELL)
	{
		cell_pos.x = 0;
		while (cell_pos.x < CELL)
		{
			put_color(game, image, pos, cell_pos);
			cell_pos.x++;
		}
		cell_pos.y++;
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

void	print_player(t_game *game, t_axe pos, int keycode)
{
	static int	i;

	if (!i)
		i = 0;
	if (keycode == KEY_W)
	{
		if (i == 0)
			draw_image(game, &game->m_walk_b_left, pos);
		else if (i == 1)
			draw_image(game, &game->m_walk_b_left_2, pos);
		else if (i == 2)
			draw_image(game, &game->m_walk_b_left_3, pos);
	}
	else if (keycode == KEY_D)
	{
		if (i == 0)
			draw_image(game, &game->m_walk_right, pos);
		else if (i == 1)
			draw_image(game, &game->m_walk_right_2, pos);
		else if (i == 2)
			draw_image(game, &game->m_walk_right_3, pos);
	}
	else if (keycode == KEY_S)
	{
		if (i == 0)
			draw_image(game, &game->m_walk_right, pos);
		else if (i == 1)
			draw_image(game, &game->m_walk_right_2, pos);
		else if (i == 2)
			draw_image(game, &game->m_walk_right_3, pos);
	}
	else if (keycode == KEY_A)
	{
		if (i == 0)
			draw_image(game, &game->m_walk_left, pos);
		else if (i == 1)
			draw_image(game, &game->m_walk_left_2, pos);
		else if (i == 2)
			draw_image(game, &game->m_walk_left_3, pos);
	}
	else
		draw_image(game, &game->m_static_b_right, pos);
		i++;
	if (i > 2)
		i = 0;
}

void	print_mobs(t_game *game, t_axe pos)
{
	static int	i;

	if (!i)
		i = 0;
	if (is_player(game->map[pos.y][pos.x]))
		print_player(game, pos, 'P');
	else if (get_direction(game, pos, &ennemy_proximity) == 1)
	{
		if (i == 0)
			draw_image(game, &game->gr, pos);
		else if (i == 1)
			draw_image(game, &game->gr_2, pos);
		else if (i == 2)
			draw_image(game, &game->gr_3, pos);
	}
	else if (get_direction(game, pos, &ennemy_proximity) == 2)
	{
		if (i == 0)
			draw_image(game, &game->gb, pos);
		else if (i == 1)
			draw_image(game, &game->gb_2, pos);
		else if (i == 2)
			draw_image(game, &game->gb_3, pos);
	}
	else
	{
		if (i == 0)
			draw_image(game, &game->g, pos);
		else if (i == 1)
			draw_image(game, &game->g_2, pos);
		else if (i == 2)
			draw_image(game, &game->g_3, pos);
	}
	i++;
	if (i > 2)
		i = 0;
}

void	print_coins(t_game *game, t_axe pos)
{
	static int	i;

	if (!i)
		i = 0;
	if (i == 0)
		draw_image(game, &game->c, pos);
	else if (i == 1)
		draw_image(game, &game->c_2, pos);
	else if (i == 2)
		draw_image(game, &game->c_3, pos);
	else if (i == 3)
		draw_image(game, &game->c_4, pos);
	i++;
	if (i > 3)
		i = 0;
}

void	print_star(t_game *game, t_axe pos)
{
	static int	i;

	if (!i)
		i = 0;
	if (i == 0)
		draw_image(game, &game->s, pos);
	else if (i == 1)
		draw_image(game, &game->s_2, pos);
	else if (i == 2)
		draw_image(game, &game->s_3, pos);
	i++;
	if (i > 2)
		i = 0;
}

void	print_collectibles(t_game *game, t_axe pos)
{
	if (game->map[pos.y][pos.x] == 'C')
		print_coins(game, pos); /* verifier si spin des le debut */
	else if (game->map[pos.y][pos.x] == 'e')
		print_star(game, pos);
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
			else if (is_ennemy(target) || is_player(target))
				print_mobs(game, pos);
			pos.x++;
		}
		pos.y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
}
