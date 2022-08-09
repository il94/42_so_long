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

int	draw_player(t_game *game, t_data *image, t_axe pos)
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
			x = cell.y + pos.x - (image->width - CELL) - (CELL / 2);
			y = cell.x + pos.y - (image->height - CELL) - CELL + (CELL / 6);
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

int	draw_ennemy(t_game *game, t_data *image, t_axe pos)
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

int	draw_sprite(t_game *game, t_data *image, t_axe pos)
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

void	put_player(t_game *game)
{
	if (game->night == 0)
	{
		if (game->direction == 'a')
		{
			if (game->state == 0)
				draw_player(game, &game->m_walk_b_left, game->cell);
			else if (game->state == 1)
				draw_player(game, &game->m_walk_b_left_2, game->cell);
			else if (game->state == 2)
				draw_player(game, &game->m_walk_b_left_3, game->cell);
			else if (game->state == 3)
				draw_player(game, &game->m_walk_b_left_2, game->cell);
		}
		else if (game->direction == 'b')
		{
			if (game->state == 0)
				draw_player(game, &game->m_walk_b_right, game->cell);
			else if (game->state == 1)
				draw_player(game, &game->m_walk_b_right_2, game->cell);
			else if (game->state == 2)
				draw_player(game, &game->m_walk_b_right_3, game->cell);
			else if (game->state == 3)
				draw_player(game, &game->m_walk_b_right_2, game->cell);
		}
		else if (game->direction == 'A')
		{
			if (game->state == 0)
				draw_player(game, &game->m_walk_left, game->cell);
			else if (game->state == 1)
				draw_player(game, &game->m_walk_left_2, game->cell);
			else if (game->state == 2)
				draw_player(game, &game->m_walk_left_3, game->cell);
			else if (game->state == 3)
				draw_player(game, &game->m_walk_left_2, game->cell);
		}
		else if (game->direction == 'B')
		{
			if (game->state == 0)
				draw_player(game, &game->m_walk_right, game->cell);
			else if (game->state == 1)
				draw_player(game, &game->m_walk_right_2, game->cell);
			else if (game->state == 2)
				draw_player(game, &game->m_walk_right_3, game->cell);
			else if (game->state == 3)
				draw_player(game, &game->m_walk_right_2, game->cell);
		}
		else if (game->direction == 'q')
			draw_player(game, &game->m_static_b_left, game->cell);
		else if (game->direction == 'Q')
			draw_player(game, &game->m_static_left, game->cell);
		else if (game->direction == 'p')
			draw_player(game, &game->m_static_b_right, game->cell);
		else if (game->direction == 'P')
			draw_player(game, &game->m_static_right, game->cell);
	}
	else
	{
		if (game->direction == 'a')
		{
			if (game->state == 0)
				draw_player(game, &game->m_walk_b_left_light, game->cell);
			else if (game->state == 1)
				draw_player(game, &game->m_walk_b_left_light_2, game->cell);
			else if (game->state == 2)
				draw_player(game, &game->m_walk_b_left_light_3, game->cell);
			else if (game->state == 3)
				draw_player(game, &game->m_walk_b_left_light_2, game->cell);
		}
		else if (game->direction == 'b')
		{
			if (game->state == 0)
				draw_player(game, &game->m_walk_b_right_light, game->cell);
			else if (game->state == 1)
				draw_player(game, &game->m_walk_b_right_light_2, game->cell);
			else if (game->state == 2)
				draw_player(game, &game->m_walk_b_right_light_3, game->cell);
			else if (game->state == 3)
				draw_player(game, &game->m_walk_b_right_light_2, game->cell);
		}
		else if (game->direction == 'A')
		{
			if (game->state == 0)
				draw_player(game, &game->m_walk_left_light, game->cell);
			else if (game->state == 1)
				draw_player(game, &game->m_walk_left_light_2, game->cell);
			else if (game->state == 2)
				draw_player(game, &game->m_walk_left_light_3, game->cell);
			else if (game->state == 3)
				draw_player(game, &game->m_walk_left_light_2, game->cell);
		}
		else if (game->direction == 'B')
		{
			if (game->state == 0)
				draw_player(game, &game->m_walk_right_light, game->cell);
			else if (game->state == 1)
				draw_player(game, &game->m_walk_right_light_2, game->cell);
			else if (game->state == 2)
				draw_player(game, &game->m_walk_right_light_3, game->cell);
			else if (game->state == 3)
				draw_player(game, &game->m_walk_right_light_2, game->cell);
		}
		else if (game->direction == 'q')
			draw_player(game, &game->m_static_b_left_light, game->cell);
		else if (game->direction == 'Q')
			draw_player(game, &game->m_static_left_light, game->cell);
		else if (game->direction == 'p')
			draw_player(game, &game->m_static_b_right_light, game->cell);
		else if (game->direction == 'P')
			draw_player(game, &game->m_static_right_light, game->cell);
	}
	// game->map[game->player.y][game->player.x] = 'P';
}

void	put_grass(t_game *game, t_axe pos)
{
	if (game->night == 0)
		draw_sprite(game, &game->grass, pos);
	else
		draw_sprite(game, &game->grass_shadow, pos);
}

void	put_wall(t_game *game, t_axe pos)
{
	if (game->night == 0)
	{
		if (pos.y < game->y_map - 1 && pos.y > 0
			&& game->map[pos.y + 1][pos.x] == '1'
			&& game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->wall_mid, pos);
		else if (pos.y < game->y_map - 1 && game->map[pos.y + 1][pos.x] == '1')
			draw_sprite(game, &game->wall_top, pos);
		else if (pos.y > 0 && game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->wall_bot, pos);
		else
			draw_sprite(game, &game->wall_one, pos);
	}
	else
	{
		if (pos.y < game->y_map - 1 && pos.y > 0
			&& game->map[pos.y + 1][pos.x] == '1'
			&& game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->wall_mid_shadow, pos);
		else if (pos.y < game->y_map - 1 && game->map[pos.y + 1][pos.x] == '1')
			draw_sprite(game, &game->wall_top_shadow, pos);
		else if (pos.y > 0 && game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->wall_bot_shadow, pos);
		else
			draw_sprite(game, &game->wall_one_shadow, pos);
	}
}

void	put_ennemy(t_game *game, t_axe pos)
{
	static int	i;
	int			frequency;
	
	frequency = 100;
	if (!i)
		i = 0;
	if (get_direction(game, pos, &ennemy_proximity) == 1)
	{
		if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->gr, pos);
		else if (i >= frequency && i <= frequency * 2)
				draw_sprite(game, &game->gr_2, pos);
		else if (i >= frequency * 2 && i <= frequency * 3)
				draw_sprite(game, &game->gr_3, pos);
	}
	else if (get_direction(game, pos, &ennemy_proximity) == 2)
	{
		if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->gb, pos);
		else if (i >= frequency && i <= frequency * 2)
				draw_sprite(game, &game->gb_2, pos);
		else if (i >= frequency * 2 && i <= frequency * 3)
				draw_sprite(game, &game->gb_3, pos);
	}
	else
	{
		if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->g, pos);
		else if (i >= frequency && i <= frequency * 2)
				draw_sprite(game, &game->g_2, pos);
		else if (i >= frequency * 2 && i <= frequency * 3)
				draw_sprite(game, &game->g_3, pos);
	}
	i++;
	if (i > frequency * 3)
		i = 0;
}

void	put_star(t_game *game, t_axe pos)
{
	static int	i;
	int			frequency;
	
	frequency = 100;
	if (!i)
		i = 0;
	if (i >= 0 && i <= frequency)
		draw_sprite(game, &game->s, pos);
	else if (i >= frequency && i <= frequency * 2)
		draw_sprite(game, &game->s_2, pos);
	else if (i >= frequency * 2 && i <= frequency * 3)
		draw_sprite(game, &game->s_3, pos);
	else if (i >= frequency * 3 && i <= frequency * 4)
		draw_sprite(game, &game->s_2, pos);
	i++;
	if (i > frequency * 4)
		i = 0;
}

void	put_coins(t_game *game, t_axe pos)
{
	static int	i;
	int			frequency;
	
	frequency = 175;
	if (!i)
		i = 0;
	if (i >= 0 && i <= frequency)
		draw_sprite(game, &game->c, pos);
	else if (i >= frequency && i <= frequency * 2)
		draw_sprite(game, &game->c_2, pos);
	else if (i >= frequency * 2 && i <= frequency * 3)
		draw_sprite(game, &game->c_3, pos);
	else if (i >= frequency * 3 && i <= frequency * 4)
		draw_sprite(game, &game->c_4, pos);
	i++;
	if (i > frequency * 4)
		i = 0;
}

void	put_collectibles(t_game *game, t_axe pos)
{
	if (game->map[pos.y][pos.x] == 'C')
		put_coins(game, pos);
	else if (game->map[pos.y][pos.x] == 'e')
		put_star(game, pos);
}

void	put_wall_to_player(t_game *game)
{
	t_axe	target;

	target = game->player;
	target.y++;
	target.x--;
	if (game->map[game->player.y + 1][game->player.x - 1] == '1')
		put_wall(game, target);
	target.x++;
	if (game->map[game->player.y + 1][game->player.x] == '1')
		put_wall(game, target);
	target.x++;
	if (game->map[game->player.y + 1][game->player.x + 1] == '1')
		put_wall(game, target);
}

void	put_elements(t_game *game)
{
	put_to_screen(game, ALL, put_grass);
	put_to_screen(game, "1", put_wall);
	put_to_screen(game, ENNEMY, put_ennemy);
	put_to_screen(game, COLLECTIBLES, put_collectibles);
	put_player(game);
	put_wall_to_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
}
