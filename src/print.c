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

int	draw_image_s(t_game *game, t_data *image, t_axe pos, int z)
{
	t_axe	cell;
	char 	*dst;
	int		x;
	int		x2;
	int		y;
	int		y2;
	int		color;

	print(game, NOT_WALL, print_grass);
	cell.y = 0;
	cell.x = 0;
	while (cell.y < image->width)
	{
		cell.x = 0;
		while (cell.x < image->height)
		{
		/*  c = pos sur cell + pos sur map - decalage si sprite + grand */
			x = cell.y + (CELL * pos.x) - (image->width - CELL);
			y = cell.x + (CELL * pos.y) - (image->height - CELL) + z;
		/*  dst = ou ecrire sur map */
			dst = game->screen.addr + y * game->screen.line + x * game->screen.bpp / 8;
			color = *(int *)(image->addr + cell.x * image->line + cell.y * 4);
			if (color >= -1 && color)
				*(int *)dst = color;
			cell.x++;
		}
		cell.y++;
	}
	return (0);
}

void	print_player_up(t_game *game, t_axe pos)
{
	unsigned long long i = 0;

	// sleep(1);
	draw_image_s(game, &game->m_walk_b_left, pos, 32);
	// sleep(1);
	draw_image_s(game, &game->m_walk_b_left_2, pos, 16);
	// sleep(1);
	draw_image_s(game, &game->m_walk_b_left_3, pos, 0);
	// sleep(1);

}

int	draw_image(t_game *game, t_data *image, t_axe pos)
{
	t_axe	cell;
	char 	*dst;
	int		x;
	int		y;
	int		color;

	cell.y = 0;
	while (cell.y < image->width)
	{
		cell.x = 0;
		while (cell.x < image->height)
		{
			x = cell.y + (CELL * pos.x) - (image->width - CELL);
			y = cell.x + (CELL * pos.y) - (image->height - CELL);
			dst = game->screen.addr + y * game->screen.line + x * game->screen.bpp / 8;
			color = *(int *)(image->addr + cell.x * image->line + cell.y * 4);
			if (color >= -1)
				*(int *)dst = color;
			cell.x++;
		}
		cell.y++;
	}
	return (0);
}

void	print_grass(t_game *game, t_axe pos)
{
	if (!(game->delay = 1 && game->player.x == pos.x && game->player.y == pos.y))
		draw_image(game, &game->grass, pos);

	// t_axe	cell;
	// char 	*dst;
	// int		x;
	// int		x2;
	// int		y;
	// int		y2;
	// int		color;

	// cell.y = 0;
	// cell.x = 0;
	// while (cell.y < game->grass.width)
	// {
	// 	cell.x = 0;
	// 	while (cell.x < game->grass.height)
	// 	{
	// 	/*  c = pos sur cell + pos sur map - decalage si sprite + grand */
	// 		x = cell.y + (CELL * pos.x) - (game->grass.width - CELL);
	// 		y = cell.x + (CELL * pos.y) - (game->grass.height - CELL);
	// 	/*  dst = ou ecrire sur map */
	// 		dst = game->screen.addr + y * game->screen.line + x * game->screen.bpp / 8;
	// 		color = *(int *)(game->grass.addr + cell.x * game->grass.line + cell.y * 4);
	// 		if (color >= -1 && color != *(int *)(game->m_walk_b_left.addr + cell.x * game->m_walk_b_left.line + cell.y * 4))
	// 			*(int *)dst = color;
	// 		cell.x++;
	// 	}
	// 	cell.y++;
	// }
	// return (0);

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

void	print_player(t_game *game, t_axe pos)
{
	static int	i;
	char		code;
	int			frequency;
	
	frequency = 10;
	code = game->map[pos.y][pos.x];
	if (!i)
		i = 0;
	if (code == 'a')
	{
		// print_player_up(game, pos);

		// if (i >= 0 && i <= frequency)
		// 	draw_image(game, &game->m_walk_b_left, pos);
		// else if (i >= frequency && i <= frequency * 2)
		// 	draw_image(game, &game->m_walk_b_left_2, pos);
		// else if (i >= frequency * 2 && i <= frequency * 3)
		// 	draw_image(game, &game->m_walk_b_left_3, pos);
		// else if (i >= frequency * 3 && i <= frequency * 4)
		// 	draw_image(game, &game->m_walk_b_left_2, pos);
	}
	else if (code == 'b')
	{
		if (i >= 0 && i <= frequency)
			draw_image(game, &game->m_walk_b_right, pos);
		else if (i >= frequency && i <= frequency * 2)
			draw_image(game, &game->m_walk_b_right_2, pos);
		else if (i >= frequency * 2 && i <= frequency * 3)
			draw_image(game, &game->m_walk_b_right_3, pos);
		else if (i >= frequency * 3 && i <= frequency * 4)
			draw_image(game, &game->m_walk_b_right_2, pos);
	}
	else if (code == 'A')
	{
		if (i >= 0 && i <= frequency)
			draw_image(game, &game->m_walk_left, pos);
		else if (i >= frequency && i <= frequency * 2)
			draw_image(game, &game->m_walk_left_2, pos);
		else if (i >= frequency * 2 && i <= frequency * 3)
			draw_image(game, &game->m_walk_left_3, pos);
		else if (i >= frequency * 3 && i <= frequency * 4)
			draw_image(game, &game->m_walk_left_2, pos);
	}
	else if (code == 'B')
	{
		if (i >= 0 && i <= frequency)
			draw_image(game, &game->m_walk_right, pos);
		else if (i >= frequency && i <= frequency * 2)
			draw_image(game, &game->m_walk_right_2, pos);
		else if (i >= frequency * 2 && i <= frequency * 3)
			draw_image(game, &game->m_walk_right_3, pos);
		else if (i >= frequency * 3 && i <= frequency * 4)
			draw_image(game, &game->m_walk_right_2, pos);
	}
	else if (code == 'q')
		draw_image(game, &game->m_static_b_left, pos);
	else if (code == 'Q')
		draw_image(game, &game->m_static_left, pos);
	else if (code == 'p')
		draw_image(game, &game->m_static_b_right, pos);
	else if (code == 'P')
		draw_image(game, &game->m_static_right, pos);
		i++;
	if (i > frequency * 4)
		i = 0;
	// game->map[pos.y][pos.x] = 'P';
}

void	print_ennemy(t_game *game, t_axe pos)
{
	static int	i;
	int			frequency;
	
	frequency = 100;
	if (!i)
		i = 0;
	if (get_direction(game, pos, &ennemy_proximity) == 1)
	{
		if (i >= 0 && i <= frequency)
				draw_image(game, &game->gr, pos);
		else if (i >= frequency && i <= frequency * 2)
				draw_image(game, &game->gr_2, pos);
		else if (i >= frequency * 2 && i <= frequency * 3)
				draw_image(game, &game->gr_3, pos);
	}
	else if (get_direction(game, pos, &ennemy_proximity) == 2)
	{
		if (i >= 0 && i <= frequency)
				draw_image(game, &game->gb, pos);
		else if (i >= frequency && i <= frequency * 2)
				draw_image(game, &game->gb_2, pos);
		else if (i >= frequency * 2 && i <= frequency * 3)
				draw_image(game, &game->gb_3, pos);
	}
	else
	{
		if (i >= 0 && i <= frequency)
				draw_image(game, &game->g, pos);
		else if (i >= frequency && i <= frequency * 2)
				draw_image(game, &game->g_2, pos);
		else if (i >= frequency * 2 && i <= frequency * 3)
				draw_image(game, &game->g_3, pos);
	}
	i++;
	if (i > frequency * 3)
		i = 0;
}

void	print_star(t_game *game, t_axe pos)
{
	static int	i;
	int			frequency;
	
	frequency = 100;
	if (!i)
		i = 0;
	if (i >= 0 && i <= frequency)
		draw_image(game, &game->s, pos);
	else if (i >= frequency && i <= frequency * 2)
		draw_image(game, &game->s_2, pos);
	else if (i >= frequency * 2 && i <= frequency * 3)
		draw_image(game, &game->s_3, pos);
	else if (i >= frequency * 3 && i <= frequency * 4)
		draw_image(game, &game->s_2, pos);
	i++;
	if (i > frequency * 4)
		i = 0;
}

void	print_coins(t_game *game, t_axe pos)
{
	static int	i;
	int			frequency;
	
	frequency = 200;
	if (!i)
		i = 0;
	if (i >= 0 && i <= frequency)
		draw_image(game, &game->c, pos);
	else if (i >= frequency && i <= frequency * 2)
		draw_image(game, &game->c_2, pos);
	else if (i >= frequency * 2 && i <= frequency * 3)
		draw_image(game, &game->c_3, pos);
	else if (i >= frequency * 3 && i <= frequency * 4)
		draw_image(game, &game->c_4, pos);
	i++;
	if (i > frequency * 4)
		i = 0;
}

void	print_collectibles(t_game *game, t_axe pos)
{
	if (game->map[pos.y][pos.x] == 'C')
		print_coins(game, pos);
	else if (game->map[pos.y][pos.x] == 'e')
		print_star(game, pos);
}

void	print_elements(t_game *game)
{
	print(game, NOT_WALL, print_grass);
	print(game, "1", print_wall);
	print(game, PLAYER, print_player);
	print(game, ENNEMY, print_ennemy);
	print(game, COLLECTIBLES, print_collectibles);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
}
