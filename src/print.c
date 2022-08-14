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

int	get_drawing_position(t_pos cell, t_pos map, t_sprite drawing_pos, char pos)
{
	if (drawing_pos == FULL)
	{
		if (pos == 'x')
			return (cell.y + (CELL * map.x));
		else if (pos == 'y')
			return (cell.x + (CELL * map.y));
	}
	else if (drawing_pos == BOT)
	{
		if (pos == 'x')
			return (cell.y + map.x - (CELL / 2));
		else if (pos == 'y')
			return (cell.x + map.y - CELL + (CELL / 6));
	}
	else if (drawing_pos == CENTER)
	{
		if (pos == 'x')
			return (cell.y + map.x - (CELL / 2));
		else if (pos == 'y')
			return (cell.x + map.y - (CELL / 2));
	}
	else if (drawing_pos == HAMMER_LEFT_1)
	{
		if (pos == 'x')
			return (cell.y + map.x - (CELL / 3));
		else if (pos == 'y')
			return (cell.x + map.y - (CELL + (CELL / 3)));
	}
	else if (drawing_pos == HAMMER_LEFT_2)
	{
		if (pos == 'x')
			return (cell.y + map.x - CELL + (CELL / 6));
		else if (pos == 'y')
			return (cell.x + map.y - CELL);
	}
	else if (drawing_pos == HAMMER_RIGHT_1)
	{
		if (pos == 'x')
			return (cell.y + map.x - CELL);
		else if (pos == 'y')
			return (cell.x + map.y - (CELL + (CELL / 3)));
	}
	else if (drawing_pos == HAMMER_RIGHT_2)
	{
		if (pos == 'x')
			return (cell.y + map.x - CELL + (CELL - CELL / 6));
		else if (pos == 'y')
			return (cell.x + map.y - CELL);
	}
}

int	draw_sprite(t_game *game, t_data *image, t_pos pos, t_sprite drawing_pos)
{
	t_pos	cell;
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
			x = get_drawing_position(cell, pos, drawing_pos, 'x');
			y = get_drawing_position(cell, pos, drawing_pos, 'y');
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

void	put_hammer(t_game *game)
{
	int	frequency;
	static int	i;

	frequency = 3;
	if (!i)
		i = 0;
	if (!game->night)
	{
		if (game->player_direction == 'L')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_left_2, game->player_cell, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_left_3, game->player_cell, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'R')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_right_2, game->player_cell, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_right_3, game->player_cell, HAMMER_RIGHT_2);
			i++;
		}
		if (game->player_direction == 'l')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_b_left, game->player_cell, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_b_left_2, game->player_cell, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'r')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_b_right, game->player_cell, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_b_right_2, game->player_cell, HAMMER_RIGHT_2);
			i++;
		}
	}
	else
	{
		if (game->player_direction == 'L')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_left_light_2, game->player_cell, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_left_light_3, game->player_cell, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'R')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_right_light_2, game->player_cell, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_right_light_3, game->player_cell, HAMMER_RIGHT_2);
			i++;
		}
		if (game->player_direction == 'l')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_b_left_light, game->player_cell, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_b_left_light_2, game->player_cell, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'r')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_b_right_light, game->player_cell, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_b_right_light_2, game->player_cell, HAMMER_RIGHT_2);
			i++;
		}
	}
	if (i > frequency * 10)
	{
		game->is_hitting = FALSE;
		game->is_jumping = FALSE;
		i = 0;
	}
}

void	put_player(t_game *game)
{
	int	frequency;

	frequency = game->player_animation_speed / 4;
	if (!game->night)
	{
		if (game->player_direction == 'l')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->m_walk_b_left, game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->m_walk_b_left_2, game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->m_walk_b_left_3, game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->m_walk_b_left_2, game->player_cell, BOT);
		}
		else if (game->player_direction == 'r')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->m_walk_b_right, game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->m_walk_b_right_2, game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->m_walk_b_right_3, game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->m_walk_b_right_2, game->player_cell, BOT);
		}
		else if (game->player_direction == 'L')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->m_walk_left, game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->m_walk_left_2, game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->m_walk_left_3, game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->m_walk_left_2, game->player_cell, BOT);
		}
		else if (game->player_direction == 'R')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->m_walk_right, game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->m_walk_right_2, game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->m_walk_right_3, game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->m_walk_right_2, game->player_cell, BOT);
		}
		else if (game->player_direction == 'q')
			draw_sprite(game, &game->m_static_b_left, game->player_cell, BOT);
		else if (game->player_direction == 'Q')
			draw_sprite(game, &game->m_static_left, game->player_cell, BOT);
		else if (game->player_direction == 'p')
			draw_sprite(game, &game->m_static_b_right, game->player_cell, BOT);
		else if (game->player_direction == 'P')
			draw_sprite(game, &game->m_static_right, game->player_cell, BOT);
	}
	else
	{
		if (game->player_direction == 'l')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->m_walk_b_left_light, game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->m_walk_b_left_light_2, game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->m_walk_b_left_light_3, game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->m_walk_b_left_light_2, game->player_cell, BOT);
		}
		else if (game->player_direction == 'r')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->m_walk_b_right_light, game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->m_walk_b_right_light_2, game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->m_walk_b_right_light_3, game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->m_walk_b_right_light_2, game->player_cell, BOT);
		}
		else if (game->player_direction == 'L')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->m_walk_left_light, game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->m_walk_left_light_2, game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->m_walk_left_light_3, game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->m_walk_left_light_2, game->player_cell, BOT);
		}
		else if (game->player_direction == 'R')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->m_walk_right_light, game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->m_walk_right_light_2, game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->m_walk_right_light_3, game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->m_walk_right_light_2, game->player_cell, BOT);
		}
		else if (game->player_direction == 'q')
			draw_sprite(game, &game->m_static_b_left_light, game->player_cell, BOT);
		else if (game->player_direction == 'Q')
			draw_sprite(game, &game->m_static_left_light, game->player_cell, BOT);
		else if (game->player_direction == 'p')
			draw_sprite(game, &game->m_static_b_right_light, game->player_cell, BOT);
		else if (game->player_direction == 'P')
			draw_sprite(game, &game->m_static_right_light, game->player_cell, BOT);
	}
}

void	put_grass(t_game *game, t_pos pos)
{
	if (!game->night)
		draw_sprite(game, &game->grass, pos, FULL);
	else
		draw_sprite(game, &game->grass_shadow, pos, FULL);
}

void	put_wall(t_game *game, t_pos pos)
{
	if (!game->night)
	{
		if (pos.y < game->max.y - 1 && pos.y > 0
			&& game->map[pos.y + 1][pos.x] == '1'
			&& game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->wall_mid, pos, FULL);
		else if (pos.y < game->max.y - 1 && game->map[pos.y + 1][pos.x] == '1')
			draw_sprite(game, &game->wall_top, pos, FULL);
		else if (pos.y > 0 && game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->wall_bot, pos, FULL);
		else
			draw_sprite(game, &game->wall_one, pos, FULL);
	}
	else
	{
		if (pos.y < game->max.y - 1 && pos.y > 0
			&& game->map[pos.y + 1][pos.x] == '1'
			&& game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->wall_mid_shadow, pos, FULL);
		else if (pos.y < game->max.y - 1 && game->map[pos.y + 1][pos.x] == '1')
			draw_sprite(game, &game->wall_top_shadow, pos, FULL);
		else if (pos.y > 0 && game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->wall_bot_shadow, pos, FULL);
		else
			draw_sprite(game, &game->wall_one_shadow, pos, FULL);
	}
}

void	put_ennemy(t_game *game)
{
	int	i;
	int	frequency;

	i = 0;
	frequency = game->speed_animation_ennemy / 4;
	while (i < game->ennemy_count)
	{
		if (ennemy_proximity(game, game->ennemies[i].pos) == 1 && is(ENNEMY, game->map[game->ennemies[i].pos.y][ game->ennemies[i].pos.x]))
		{
			if (game->state_ennemy >= 0 && game->state_ennemy <= frequency)
				draw_sprite(game, &game->gr_2, game->ennemies[i].cell, CENTER);
			else if (game->state_ennemy >= frequency && game->state_ennemy <= frequency * 2)
				draw_sprite(game, &game->gr, game->ennemies[i].cell, CENTER);
			else if (game->state_ennemy >= frequency * 2 && game->state_ennemy <= frequency * 3)
				draw_sprite(game, &game->gr_3, game->ennemies[i].cell, CENTER);
			else if (game->state_ennemy >= frequency * 3 && game->state_ennemy <= frequency * 4)
				draw_sprite(game, &game->gr, game->ennemies[i].cell, CENTER);
		}
		else if (ennemy_proximity(game, game->ennemies[i].pos) == 2 && is(ENNEMY, game->map[game->ennemies[i].pos.y][ game->ennemies[i].pos.x]))
		{
			if (game->state_ennemy >= 0 && game->state_ennemy <= frequency)
				draw_sprite(game, &game->gb_2, game->ennemies[i].cell, CENTER);
			else if (game->state_ennemy >= frequency && game->state_ennemy <= frequency * 2)
				draw_sprite(game, &game->gb, game->ennemies[i].cell, CENTER);
			else if (game->state_ennemy >= frequency * 2 && game->state_ennemy <= frequency * 3)
				draw_sprite(game, &game->gb_3, game->ennemies[i].cell, CENTER);
			else if (game->state_ennemy >= frequency * 3 && game->state_ennemy <= frequency * 4)
				draw_sprite(game, &game->gb, game->ennemies[i].cell, CENTER);
		}
		else if (is(ENNEMY, game->map[game->ennemies[i].pos.y][ game->ennemies[i].pos.x]))
		{
			if (game->state_ennemy >= 0 && game->state_ennemy <= frequency)
				draw_sprite(game, &game->g_2, game->ennemies[i].cell, CENTER);
			else if (game->state_ennemy >= frequency && game->state_ennemy <= frequency * 2)
				draw_sprite(game, &game->g, game->ennemies[i].cell, CENTER);
			else if (game->state_ennemy >= frequency * 2 && game->state_ennemy <= frequency * 3)
				draw_sprite(game, &game->g_3, game->ennemies[i].cell, CENTER);
			else if (game->state_ennemy >= frequency * 3 && game->state_ennemy <= frequency * 4)
				draw_sprite(game, &game->g, game->ennemies[i].cell, CENTER);
		}
		i++;
	}
}

void	put_star(t_game *game, t_pos pos)
{
	static int	i;
	int			frequency;
	
	frequency = 100;
	if (!i)
		i = 0;
	if (i >= 0 && i <= frequency)
		draw_sprite(game, &game->s, pos, FULL);
	else if (i >= frequency && i <= frequency * 2)
		draw_sprite(game, &game->s_2, pos, FULL);
	else if (i >= frequency * 2 && i <= frequency * 3)
		draw_sprite(game, &game->s_3, pos, FULL);
	else if (i >= frequency * 3 && i <= frequency * 4)
		draw_sprite(game, &game->s_2, pos, FULL);
	i++;
	if (i > frequency * 4)
		i = 0;
}

void	put_coins(t_game *game, t_pos pos)
{
	static int	i;
	int			frequency;
	
	frequency = 175;
	if (!i)
		i = 0;
	if (i >= 0 && i <= frequency)
		draw_sprite(game, &game->c, pos, FULL);
	else if (i >= frequency && i <= frequency * 2)
		draw_sprite(game, &game->c_2, pos, FULL);
	else if (i >= frequency * 2 && i <= frequency * 3)
		draw_sprite(game, &game->c_3, pos, FULL);
	else if (i >= frequency * 3 && i <= frequency * 4)
		draw_sprite(game, &game->c_4, pos, FULL);
	i++;
	if (i > frequency * 4)
		i = 0;
}

void	put_collectibles(t_game *game, t_pos pos)
{
	if (game->map[pos.y][pos.x] == 'C')
		put_coins(game, pos);
	else if (game->map[pos.y][pos.x] == 'e')
		put_star(game, pos);
	else if (game->map[pos.y][pos.x] == 'H')
		draw_sprite(game, &game->hammer, pos, FULL);
	else if (game->map[pos.y][pos.x] == 'B')
		draw_sprite(game, &game->s_spawn_10, pos, FULL);
}

void	put_wall_to_player(t_game *game)
{
	t_pos	target;

	target = game->player_pos;
	target.y++;
	target.x--;
	if (game->map[game->player_pos.y + 1][game->player_pos.x - 1] == '1')
		put_wall(game, target);
	target.x++;
	if (game->map[game->player_pos.y + 1][game->player_pos.x] == '1')
		put_wall(game, target);
	target.x++;
	if (game->map[game->player_pos.y + 1][game->player_pos.x + 1] == '1')
		put_wall(game, target);
}

void	put_elements(t_game *game)
{
	read_all_map(game, ALL, put_grass);
	read_all_map(game, "1", put_wall);
	read_all_map(game, COLLECTIBLES, put_collectibles);
	put_ennemy(game);
	if (game->is_hitting)
		put_hammer(game);
	else
		put_player(game);
	put_wall_to_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
}
