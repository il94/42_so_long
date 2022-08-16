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

int	get_drawing_position(t_pos index, t_pos trgt, t_sprite drawing_pos, char pos)
{
	if (drawing_pos == FULL)
	{
		if (pos == 'x')
			return (index.y + (CELL * trgt.x));
		else if (pos == 'y')
			return (index.x + (CELL * trgt.y));
	}
	else if (drawing_pos == BOT)
	{
		if (pos == 'x')
			return (index.y + trgt.x - (CELL / 2));
		else if (pos == 'y')
			return (index.x + trgt.y - CELL + (CELL / 6));
	}
	else if (drawing_pos == CENTER)
	{
		if (pos == 'x')
			return (index.y + trgt.x - (CELL / 2));
		else if (pos == 'y')
			return (index.x + trgt.y - (CELL / 2));
	}
	else if (drawing_pos == HAMMER_LEFT_1)
	{
		if (pos == 'x')
			return (index.y + trgt.x - (CELL / 3));
		else if (pos == 'y')
			return (index.x + trgt.y - (CELL + (CELL / 3)));
	}
	else if (drawing_pos == HAMMER_LEFT_2)
	{
		if (pos == 'x')
			return (index.y + trgt.x - CELL + (CELL / 6));
		else if (pos == 'y')
			return (index.x + trgt.y - CELL);
	}
	else if (drawing_pos == HAMMER_RIGHT_1)
	{
		if (pos == 'x')
			return (index.y + trgt.x - CELL);
		else if (pos == 'y')
			return (index.x + trgt.y - (CELL + (CELL / 3)));
	}
	else if (drawing_pos == HAMMER_RIGHT_2)
	{
		if (pos == 'x')
			return (index.y + trgt.x - CELL + (CELL - CELL / 6));
		else if (pos == 'y')
			return (index.x + trgt.y - CELL);
	}
	else if (drawing_pos == MENU)
	{
		if (pos == 'x')
			return (index.y + trgt.x);
		else if (pos == 'y')
			return (index.x + trgt.y - CELL);
	}
	else if (drawing_pos == TEST)
	{
		if (pos == 'x')
			return (index.y + trgt.x);
		else if (pos == 'y')
			return (index.x + trgt.y);
	}
}

int	draw_sprite(t_game *game, t_data *image, t_pos trgt, t_sprite drawing_pos)
{
	t_pos	index;
	char 	*dst;
	int		x;
	int		y;
	int		color;

	index.y = 0;
	while (index.y < image->width)
	{
		index.x = 0;
		while (index.x < image->height)
		{
			x = get_drawing_position(index, trgt, drawing_pos, 'x');
			y = get_drawing_position(index, trgt, drawing_pos, 'y');
			dst = game->screen.addr + y * game->screen.line + x * game->screen.bpp / 8;
			color = *(int *)(image->addr + index.x * image->line + index.y * 4);
			if (color >= -1 && y >= 0 && x >= 0)
				*(int *)dst = color;
			index.x++;
		}
		index.y++;
	}
	return (0);
}

int	draw_menu(t_game *game, t_data *image, t_pos trgt, t_sprite drawing_pos)
{
	t_pos	index;
	char 	*dst;
	int		x;
	int		y;
	int		color;

	index.y = 0;
	while (index.y < image->width)
	{
		index.x = 0;
		while (index.x < image->height)
		{
			x = get_drawing_position(index, trgt, drawing_pos, 'x');
			y = get_drawing_position(index, trgt, drawing_pos, 'y');
			dst = game->menu_full.addr + y * game->menu_full.line + x * game->menu_full.bpp / 8;
			color = *(int *)(image->addr + index.x * image->line + index.y * 4);
			if (color >= -1 && y >= 0 && x >= 0)
				*(int *)dst = color;
			index.x++;
		}
		index.y++;
	}
	return (0);
}

void	put_moves(t_game *game)
{
	char	*steps;
	int		size_number;
	int		i;
	t_pos	pos;

	steps = ft_itoa(game->player_steps);
	size_number = ft_strlen(steps);
	i = size_number;
	i--;
	pos.x = ((((game->max.x) * CELL)) + (size_number * CELL / 2) + (45 / 2)) / 2;
	pos.y = 20;
	if (pos.x < game->max.x * CELL - 1)
	{
		while (i >= 0)
		{
			draw_menu(game, &game->numbers[steps[i] - '0'], pos, TEST);
			if (pos.x - 25 >= 48)
				pos.x -= 25;
			else
				pos.x = 48;
			i--;
		}
		pos.x -= 45;
		if (pos.x < 0)
			pos.x = 0;
		if (game->player_steps < 2)
			draw_menu(game, &game->step, pos, TEST);
		else
			draw_menu(game, &game->steps, pos, TEST);
	}
	else
		game->max_player_steps = TRUE;
	free(steps);
}

void	put_menu(t_game *game)
{
	t_pos	pos;
	int	i;
	static int	scroll;
	int	frequency;
	if (!scroll)
		scroll = 0;
	frequency = 3;
	pos.x = 0;
	pos.y = 0;
	i = 1;
	draw_menu(game, &game->menu, pos, FULL);
	pos.x++;
	while (i < game->max.x - 1)
	{
		draw_menu(game, &game->menu_2, pos, FULL);
		pos.x++;
		i++;
	}
	draw_menu(game, &game->menu_3, pos, FULL);
	put_moves(game);
	pos.x = 0;
	if (game->menu_opened && scroll < frequency * 12)
		scroll++;
	else if (!game->menu_opened && scroll >= 0)
		scroll--;
	if (scroll >= 0 && scroll <= frequency)
	{
		pos.y = 4;
		draw_sprite(game, &game->menu_full, pos, MENU);
	}
	else if (scroll >= frequency && scroll <= frequency * 2)
	{
		pos.y = 8;
		draw_sprite(game, &game->menu_full, pos, MENU);
	}
	else if (scroll >= frequency * 2 && scroll <= frequency * 3)
	{
		pos.y = 12;
		draw_sprite(game, &game->menu_full, pos, MENU);
	}
	else if (scroll >= frequency * 3 && scroll <= frequency * 4)
	{
		pos.y = 16;
		draw_sprite(game, &game->menu_full, pos, MENU);
	}
	else if (scroll >= frequency * 4 && scroll <= frequency * 5)
	{
		pos.y = 20;
		draw_sprite(game, &game->menu_full, pos, MENU);
	}
	else if (scroll >= frequency * 5 && scroll <= frequency * 6)
	{
		pos.y = 24;
		draw_sprite(game, &game->menu_full, pos, MENU);
	}
	else if (scroll >= frequency * 6 && scroll <= frequency * 7)
	{
		pos.y = 28;
		draw_sprite(game, &game->menu_full, pos, MENU);
	}
	else if (scroll >= frequency * 7 && scroll <= frequency * 8)
	{
		pos.y = 32;
		draw_sprite(game, &game->menu_full, pos, MENU);
	}
	else if (scroll >= frequency * 8 && scroll <= frequency * 9)
	{
		pos.y = 36;
		draw_sprite(game, &game->menu_full, pos, MENU);
	}
	else if (scroll >= frequency * 9 && scroll <= frequency * 10)
	{
		pos.y = 40;
		draw_sprite(game, &game->menu_full, pos, MENU);
	}
	else if (scroll >= frequency * 10 && scroll <= frequency * 11)
	{
		pos.y = 44;
		draw_sprite(game, &game->menu_full, pos, MENU);
	}
	else if (scroll >= frequency * 11 && scroll <= frequency * 12)
	{
		pos.y = 48;
		draw_sprite(game, &game->menu_full, pos, MENU);
	}
}

void	put_jump(t_game *game)
{
	t_pos		trgt;
	int			frequency;
	static int	i;

	trgt = game->player_cell;
	if (game->player_cell.y < 64)
		trgt.y += 64 - trgt.y;
	frequency = 3;
	if (!i)
		i = 0;
	if (!game->night)
	{
		if (game->player_direction == 'L' || game->player_direction == 'l')
		{
			if (i >= 0 && i <= frequency * 10)
				draw_sprite(game, &game->m_jump_left, trgt, BOT);
			i++;
		}
		else if (game->player_direction == 'R' || game->player_direction == 'r')
		{
			if (i >= 0 && i <= frequency * 10)
				draw_sprite(game, &game->m_jump_right, trgt, BOT);
			i++;
		}
	}
	else
	{
		if (game->player_direction == 'L')
		{
			if (i >= 0 && i <= frequency * 10)
				draw_sprite(game, &game->m_jump_left_light, trgt, BOT);
			i++;
		}
		else if (game->player_direction == 'R')
		{
			if (i >= 0 && i <= frequency * 10)
				draw_sprite(game, &game->m_jump_right_light, trgt, BOT);
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


void	put_hammer(t_game *game)
{
	t_pos		trgt;
	int			frequency;
	static int	i;

	trgt = game->player_cell;
	if (game->player_cell.y < 64)
		trgt.y += 64 - trgt.y;
	frequency = 3;
	if (!i)
		i = 0;
	if (!game->night)
	{
		if (game->player_direction == 'L')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_left, trgt, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_left_2, trgt, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'R')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_right, trgt, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_right_2, trgt, HAMMER_RIGHT_2);
			i++;
		}
		else if (game->player_direction == 'l')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_left_b, trgt, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_left_b_2, trgt, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'r')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_right_b, trgt, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_right_b_2, trgt, HAMMER_RIGHT_2);
			i++;
		}
	}
	else
	{
		if (game->player_direction == 'L')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_left_light, trgt, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_left_light_2, trgt, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'R')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_right_light, trgt, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_right_light_2, trgt, HAMMER_RIGHT_2);
			i++;
		}
		else if (game->player_direction == 'l')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_left_light_b, trgt, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_left_light_b_2, trgt, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'r')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->m_hammer_right_light_b, trgt, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->m_hammer_right_light_b_2, trgt, HAMMER_RIGHT_2);
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
				draw_sprite(game, &game->m_walk_left_b, game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->m_walk_left_b_2, game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->m_walk_left_b_3, game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->m_walk_left_b_2, game->player_cell, BOT);
		}
		else if (game->player_direction == 'r')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->m_walk_right_b, game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->m_walk_right_b_2, game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->m_walk_right_b_3, game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->m_walk_right_b_2, game->player_cell, BOT);
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
			draw_sprite(game, &game->m_static_left_b, game->player_cell, BOT);
		else if (game->player_direction == 'Q')
			draw_sprite(game, &game->m_static_left, game->player_cell, BOT);
		else if (game->player_direction == 'p')
			draw_sprite(game, &game->m_static_right_b, game->player_cell, BOT);
		else if (game->player_direction == 'P')
			draw_sprite(game, &game->m_static_right, game->player_cell, BOT);
	}
	else
	{
		if (game->player_direction == 'l')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->m_walk_left_light_b, game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->m_walk_left_light_b_2, game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->m_walk_left_light_b_3, game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->m_walk_left_light_b_2, game->player_cell, BOT);
		}
		else if (game->player_direction == 'r')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->m_walk_right_light_b, game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->m_walk_right_light_b_2, game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->m_walk_right_light_b_3, game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->m_walk_right_light_b_2, game->player_cell, BOT);
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
			draw_sprite(game, &game->m_static_left_light_b, game->player_cell, BOT);
		else if (game->player_direction == 'Q')
			draw_sprite(game, &game->m_static_left_light, game->player_cell, BOT);
		else if (game->player_direction == 'p')
			draw_sprite(game, &game->m_static_right_light_b, game->player_cell, BOT);
		else if (game->player_direction == 'P')
			draw_sprite(game, &game->m_static_right_light, game->player_cell, BOT);
	}
}

void	put_e_grass(t_game *game, t_pos pos)
{
	if (!game->night)
		draw_sprite(game, &game->e_grass, pos, FULL);
	else
		draw_sprite(game, &game->e_grass_shadow, pos, FULL);
}

void	put_e_wall(t_game *game, t_pos pos)
{
	if (!game->night)
	{
		if (pos.y < game->max.y - 1 && pos.y > 0
			&& game->map[pos.y + 1][pos.x] == '1'
			&& game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->e_wall_mid, pos, FULL);
		else if (pos.y < game->max.y - 1 && game->map[pos.y + 1][pos.x] == '1')
			draw_sprite(game, &game->e_wall_top, pos, FULL);
		else if (pos.y > 0 && game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->e_wall_bot, pos, FULL);
		else
			draw_sprite(game, &game->e_wall_one, pos, FULL);
	}
	else
	{
		if (pos.y < game->max.y - 1 && pos.y > 0
			&& game->map[pos.y + 1][pos.x] == '1'
			&& game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->e_wall_mid_shadow, pos, FULL);
		else if (pos.y < game->max.y - 1 && game->map[pos.y + 1][pos.x] == '1')
			draw_sprite(game, &game->e_wall_top_shadow, pos, FULL);
		else if (pos.y > 0 && game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->e_wall_bot_shadow, pos, FULL);
		else
			draw_sprite(game, &game->e_wall_one_shadow, pos, FULL);
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
	
	frequency = 5;
	if (!i)
		i = 0;
	if (i >= 0 && i <= frequency * 3)
		draw_sprite(game, &game->s, pos, FULL);
	else if (i >= frequency * 3 && i <= frequency * 4)
		draw_sprite(game, &game->s_2, pos, FULL);
	else if (i >= frequency * 4 && i <= frequency * 7)
		draw_sprite(game, &game->s_3, pos, FULL);
	else if (i >= frequency * 7 && i <= frequency * 8)
		draw_sprite(game, &game->s_2, pos, FULL);
	i++;
	if (i > frequency * 8)
		i = 0;
}

void	put_coins(t_game *game, t_pos pos)
{
	static int	i;
	int			frequency;
	
	frequency = 75;
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
}

void	put_e_wall_to_player(t_game *game)
{
	t_pos	target;

	target = game->player_pos;
	target.y++;
	target.x--;
	if (game->map[game->player_pos.y + 1][game->player_pos.x - 1] == '1')
		put_e_wall(game, target);
	target.x++;
	if (game->map[game->player_pos.y + 1][game->player_pos.x] == '1')
		put_e_wall(game, target);
	target.x++;
	if (game->map[game->player_pos.y + 1][game->player_pos.x + 1] == '1')
		put_e_wall(game, target);
}

void	put_elements(t_game *game)
{
	read_all_map(game, ALL, put_e_grass);
	read_all_map(game, "1", put_e_wall);
	read_all_map(game, COLLECTIBLES, put_collectibles);
	put_ennemy(game);
	if (game->is_jumping)
		put_jump(game);
	else if (game->is_hitting)
		put_hammer(game);
	else
		put_player(game);
	put_menu(game);
	put_e_wall_to_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
}
