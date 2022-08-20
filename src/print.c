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
			dst = game->render.addr + y * game->render.line + x * game->render.bpp / 8;
			color = *(int *)(image->addr + index.x * image->line + index.y * 4);
			if (color >= -1 && y >= 0 && x >= 0)
				*(int *)dst = color;
			index.x++;
		}
		index.y++;
	}
	return (0);
}

int	draw_bar(t_game *game, t_data *image, t_pos trgt, t_sprite drawing_pos)
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
			dst = game->bar.addr + y * game->bar.line + x * game->bar.bpp / 8;
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
			draw_bar(game, &game->sprites_bar[steps[i] - '0'], pos, TEST);
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
			draw_bar(game, &game->sprites_bar[13], pos, TEST);
		else
			draw_bar(game, &game->sprites_bar[14], pos, TEST);
	}
	else
		game->max_player_steps = TRUE;
	free(steps);
}

void	put_bar(t_game *game)
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
	draw_bar(game, &game->sprites_bar[10], pos, FULL);
	pos.x++;
	while (i < game->max.x - 1)
	{
		draw_bar(game, &game->sprites_bar[11], pos, FULL);
		pos.x++;
		i++;
	}
	draw_bar(game, &game->sprites_bar[12], pos, FULL);
	put_moves(game);
	pos.x = 0;
	if (game->bar_displayed && scroll < frequency * 12)
		scroll++;
	else if (!game->bar_displayed && scroll >= 0)
		scroll--;
	if (scroll >= 0 && scroll <= frequency)
	{
		pos.y = 4;
		draw_sprite(game, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency && scroll <= frequency * 2)
	{
		pos.y = 8;
		draw_sprite(game, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 2 && scroll <= frequency * 3)
	{
		pos.y = 12;
		draw_sprite(game, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 3 && scroll <= frequency * 4)
	{
		pos.y = 16;
		draw_sprite(game, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 4 && scroll <= frequency * 5)
	{
		pos.y = 20;
		draw_sprite(game, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 5 && scroll <= frequency * 6)
	{
		pos.y = 24;
		draw_sprite(game, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 6 && scroll <= frequency * 7)
	{
		pos.y = 28;
		draw_sprite(game, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 7 && scroll <= frequency * 8)
	{
		pos.y = 32;
		draw_sprite(game, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 8 && scroll <= frequency * 9)
	{
		pos.y = 36;
		draw_sprite(game, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 9 && scroll <= frequency * 10)
	{
		pos.y = 40;
		draw_sprite(game, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 10 && scroll <= frequency * 11)
	{
		pos.y = 44;
		draw_sprite(game, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 11 && scroll <= frequency * 12)
	{
		pos.y = 48;
		draw_sprite(game, &game->bar, pos, MENU);
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
	if (!game->star_appeared)
	{
		if (game->player_direction == 'L' || game->player_direction == 'l')
		{
			if (i >= 0 && i <= frequency * 10)
				draw_sprite(game, &game->sprites_mario[16], trgt, BOT);
			i++;
		}
		else if (game->player_direction == 'R' || game->player_direction == 'r')
		{
			if (i >= 0 && i <= frequency * 10)
				draw_sprite(game, &game->sprites_mario[18], trgt, BOT);
			i++;
		}
	}
	else
	{
		if (game->player_direction == 'L')
		{
			if (i >= 0 && i <= frequency * 10)
				draw_sprite(game, &game->sprites_mario[17], trgt, BOT);
			i++;
		}
		else if (game->player_direction == 'R')
		{
			if (i >= 0 && i <= frequency * 10)
				draw_sprite(game, &game->sprites_mario[19], trgt, BOT);
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
	if (!game->star_appeared)
	{
		if (game->player_direction == 'L')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->sprites_mario[0], trgt, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->sprites_mario[1], trgt, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'R')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->sprites_mario[8], trgt, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->sprites_mario[9], trgt, HAMMER_RIGHT_2);
			i++;
		}
		else if (game->player_direction == 'l')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->sprites_mario[2], trgt, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->sprites_mario[3], trgt, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'r')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->sprites_mario[10], trgt, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->sprites_mario[11], trgt, HAMMER_RIGHT_2);
			i++;
		}
	}
	else
	{
		if (game->player_direction == 'L')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->sprites_mario[4], trgt, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->sprites_mario[5], trgt, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'R')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->sprites_mario[12], trgt, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->sprites_mario[13], trgt, HAMMER_RIGHT_2);
			i++;
		}
		else if (game->player_direction == 'l')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->sprites_mario[6], trgt, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->sprites_mario[7], trgt, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'r')
		{
			if (i >= 0 && i <= frequency)
				draw_sprite(game, &game->sprites_mario[14], trgt, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw_sprite(game, &game->sprites_mario[15], trgt, HAMMER_RIGHT_2);
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
	if (!game->star_appeared)
	{
		if (game->player_direction == 'l')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->sprites_mario[23], game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->sprites_mario[24], game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->sprites_mario[25], game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->sprites_mario[24], game->player_cell, BOT);
		}
		else if (game->player_direction == 'r')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->sprites_mario[35], game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->sprites_mario[36], game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->sprites_mario[37], game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->sprites_mario[36], game->player_cell, BOT);
		}
		else if (game->player_direction == 'L')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->sprites_mario[20], game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->sprites_mario[21], game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->sprites_mario[22], game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->sprites_mario[21], game->player_cell, BOT);
		}
		else if (game->player_direction == 'R')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->sprites_mario[32], game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->sprites_mario[33], game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->sprites_mario[34], game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->sprites_mario[33], game->player_cell, BOT);
		}
		// else if (game->player_direction == 'q')
		// 	draw_sprite(game, &game->m_static_left_b, game->player_cell, BOT);
		// else if (game->player_direction == 'Q')
		// 	draw_sprite(game, &game->m_static_left, game->player_cell, BOT);
		// else if (game->player_direction == 'p')
		// 	draw_sprite(game, &game->m_static_right_b, game->player_cell, BOT);
		// else if (game->player_direction == 'P')
		// 	draw_sprite(game, &game->sprites_mario[36], game->player_cell, BOT);
	}
	else
	{
		if (game->player_direction == 'l')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->sprites_mario[29], game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->sprites_mario[30], game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->sprites_mario[31], game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->sprites_mario[30], game->player_cell, BOT);
		}
		else if (game->player_direction == 'r')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->sprites_mario[41], game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->sprites_mario[42], game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->sprites_mario[43], game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->sprites_mario[42], game->player_cell, BOT);
		}
		else if (game->player_direction == 'L')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->sprites_mario[26], game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->sprites_mario[27], game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->sprites_mario[28], game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->sprites_mario[27], game->player_cell, BOT);
		}
		else if (game->player_direction == 'R')
		{
			if (game->player_state >= 0 && game->player_state <= frequency)
				draw_sprite(game, &game->sprites_mario[38], game->player_cell, BOT);
			else if (game->player_state >= frequency && game->player_state <= frequency * 2)
				draw_sprite(game, &game->sprites_mario[39], game->player_cell, BOT);
			else if (game->player_state >= frequency * 2 && game->player_state <= frequency * 3)
				draw_sprite(game, &game->sprites_mario[40], game->player_cell, BOT);
			else if (game->player_state >= frequency * 3 && game->player_state <= frequency * 4)
				draw_sprite(game, &game->sprites_mario[39], game->player_cell, BOT);
		}
		// else if (game->player_direction == 'q')
		// 	draw_sprite(game, &game->m_static_left_light_b, game->player_cell, BOT);
		// else if (game->player_direction == 'Q')
		// 	draw_sprite(game, &game->m_static_left_light, game->player_cell, BOT);
		// else if (game->player_direction == 'p')
		// 	draw_sprite(game, &game->m_static_right_light_b, game->player_cell, BOT);
		// else if (game->player_direction == 'P')
		// 	draw_sprite(game, &game->sprites_mario[36], game->player_cell, BOT);
	}
}

void	put_e_grass(t_game *game, t_pos pos)
{
	if (!game->star_appeared)
		draw_sprite(game, &game->sprites_environnement[0], pos, FULL);
	else
		draw_sprite(game, &game->sprites_environnement[1], pos, FULL);
}

void	put_e_wall(t_game *game, t_pos pos)
{
	if (!game->star_appeared)
	{
		if (pos.y < game->max.y - 1 && pos.y > 0
			&& game->map[pos.y + 1][pos.x] == '1'
			&& game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->sprites_environnement[4], pos, FULL);
		else if (pos.y < game->max.y - 1 && game->map[pos.y + 1][pos.x] == '1')
			draw_sprite(game, &game->sprites_environnement[6], pos, FULL);
		else if (pos.y > 0 && game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->sprites_environnement[2], pos, FULL);
		else
			draw_sprite(game, &game->sprites_environnement[8], pos, FULL);
	}
	else
	{
		if (pos.y < game->max.y - 1 && pos.y > 0
			&& game->map[pos.y + 1][pos.x] == '1'
			&& game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->sprites_environnement[5], pos, FULL);
		else if (pos.y < game->max.y - 1 && game->map[pos.y + 1][pos.x] == '1')
			draw_sprite(game, &game->sprites_environnement[7], pos, FULL);
		else if (pos.y > 0 && game->map[pos.y - 1][pos.x] == '1')
			draw_sprite(game, &game->sprites_environnement[3], pos, FULL);
		else
			draw_sprite(game, &game->sprites_environnement[9], pos, FULL);
	}
}

void	put_enemy(t_game *game)
{
	int	i;
	int	frequency;

	i = 0;
	frequency = game->speed_animation_enemy / 4;
	while (i < game->enemy_index)
	{
		if (enemy_proximity(game, game->enemies[i].pos) == 1 && is(ENEMY, game->map[game->enemies[i].pos.y][ game->enemies[i].pos.x]))
		{
			if (game->state_enemy >= 0 && game->state_enemy <= frequency)
				draw_sprite(game, &game->sprites_goombas[7], game->enemies[i].cell, CENTER);
			else if (game->state_enemy >= frequency && game->state_enemy <= frequency * 2)
				draw_sprite(game, &game->sprites_goombas[6], game->enemies[i].cell, CENTER);
			else if (game->state_enemy >= frequency * 2 && game->state_enemy <= frequency * 3)
				draw_sprite(game, &game->sprites_goombas[8], game->enemies[i].cell, CENTER);
			else if (game->state_enemy >= frequency * 3 && game->state_enemy <= frequency * 4)
				draw_sprite(game, &game->sprites_goombas[6], game->enemies[i].cell, CENTER);
		}
		else if (enemy_proximity(game, game->enemies[i].pos) == 2 && is(ENEMY, game->map[game->enemies[i].pos.y][ game->enemies[i].pos.x]))
		{
			if (game->state_enemy >= 0 && game->state_enemy <= frequency)
				draw_sprite(game, &game->sprites_goombas[4], game->enemies[i].cell, CENTER);
			else if (game->state_enemy >= frequency && game->state_enemy <= frequency * 2)
				draw_sprite(game, &game->sprites_goombas[3], game->enemies[i].cell, CENTER);
			else if (game->state_enemy >= frequency * 2 && game->state_enemy <= frequency * 3)
				draw_sprite(game, &game->sprites_goombas[5], game->enemies[i].cell, CENTER);
			else if (game->state_enemy >= frequency * 3 && game->state_enemy <= frequency * 4)
				draw_sprite(game, &game->sprites_goombas[3], game->enemies[i].cell, CENTER);
		}
		else if (is(ENEMY, game->map[game->enemies[i].pos.y][ game->enemies[i].pos.x]))
		{
			if (game->state_enemy >= 0 && game->state_enemy <= frequency)
				draw_sprite(game, &game->sprites_goombas[1], game->enemies[i].cell, CENTER);
			else if (game->state_enemy >= frequency && game->state_enemy <= frequency * 2)
				draw_sprite(game, &game->sprites_goombas[0], game->enemies[i].cell, CENTER);
			else if (game->state_enemy >= frequency * 2 && game->state_enemy <= frequency * 3)
				draw_sprite(game, &game->sprites_goombas[2], game->enemies[i].cell, CENTER);
			else if (game->state_enemy >= frequency * 3 && game->state_enemy <= frequency * 4)
				draw_sprite(game, &game->sprites_goombas[0], game->enemies[i].cell, CENTER);
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
		draw_sprite(game, &game->sprites_collectibles[5], pos, FULL);
	else if (i >= frequency * 3 && i <= frequency * 4)
		draw_sprite(game, &game->sprites_collectibles[6], pos, FULL);
	else if (i >= frequency * 4 && i <= frequency * 7)
		draw_sprite(game, &game->sprites_collectibles[7], pos, FULL);
	else if (i >= frequency * 7 && i <= frequency * 8)
		draw_sprite(game, &game->sprites_collectibles[6], pos, FULL);
	i++;
	if (i > frequency * 8)
		i = 0;
}

void	put_collectibless(t_game *game, t_pos pos)
{
	static int	i;
	int			frequency;
	
	frequency = 75;
	if (!i)
		i = 0;
	if (i >= 0 && i <= frequency)
		draw_sprite(game, &game->sprites_collectibles[0], pos, FULL);
	else if (i >= frequency && i <= frequency * 2)
		draw_sprite(game, &game->sprites_collectibles[1], pos, FULL);
	else if (i >= frequency * 2 && i <= frequency * 3)
		draw_sprite(game, &game->sprites_collectibles[2], pos, FULL);
	else if (i >= frequency * 3 && i <= frequency * 4)
		draw_sprite(game, &game->sprites_collectibles[3], pos, FULL);
	i++;
	if (i > frequency * 4)
		i = 0;
}

void	put_collectibles(t_game *game, t_pos pos)
{
	if (game->map[pos.y][pos.x] == 'C')
		put_collectibless(game, pos);
	else if (game->map[pos.y][pos.x] == 'e')
		put_star(game, pos);
	else if (game->map[pos.y][pos.x] == 'H')
		draw_sprite(game, &game->sprites_collectibles[4], pos, FULL);
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
	put_enemy(game);
	if (game->is_jumping)
		put_jump(game);
	else if (game->is_hitting)
		put_hammer(game);
	else
		put_player(game);
	put_bar(game);
	put_e_wall_to_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->render.img, 0, 0);
}
