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


int	get_shift_drawing_x(t_pos index, t_pos trgt, t_shift drawing_pos)
{
	if (drawing_pos == FULL)
		return (index.y + (CELL * trgt.x));
	else if (drawing_pos == BOT || drawing_pos == CENTER)
		return (index.y + trgt.x - (CELL / 2));
	else if (drawing_pos == HAMMER_LEFT_1)
		return (index.y + trgt.x - (CELL / 3));
	else if (drawing_pos == HAMMER_LEFT_2)
		return (index.y + trgt.x - CELL + (CELL / 6));
	else if (drawing_pos == HAMMER_RIGHT_1)
		return (index.y + trgt.x - CELL);
	else if (drawing_pos == HAMMER_RIGHT_2)
		return (index.y + trgt.x - (CELL / 6));
	else if (drawing_pos == MENU || drawing_pos == TEST)
		return (index.y + trgt.x);
}

int	get_shift_drawing_y(t_pos index, t_pos trgt, t_shift drawing_pos)
{
	if (drawing_pos == FULL)
		return (index.x + (CELL * trgt.y));
	else if (drawing_pos == BOT)
		return (index.x + trgt.y - CELL + (CELL / 6));
	else if (drawing_pos == CENTER)
		return (index.x + trgt.y - (CELL / 2));
	else if (drawing_pos == HAMMER_LEFT_1)
		return (index.x + trgt.y - (CELL + (CELL / 3)));
	else if (drawing_pos == HAMMER_LEFT_2)
		return (index.x + trgt.y - CELL);
	else if (drawing_pos == HAMMER_RIGHT_1)
		return (index.x + trgt.y - (CELL + (CELL / 3)));
	else if (drawing_pos == HAMMER_RIGHT_2 || drawing_pos == MENU)
		return (index.x + trgt.y - CELL);
	else if (drawing_pos == TEST)
		return (index.x + trgt.y);
}

int	draw(t_data *dst_img, t_data *src_img, t_pos trgt, t_shift drawing_pos)
{
	t_pos	px;
	char 	*dst;
	int		x;
	int		y;
	int		color;

	px.y = 0;
	while (px.y < src_img->width)
	{
		px.x = 0;
		while (px.x < src_img->height)
		{
			x = get_shift_drawing_x(px, trgt, drawing_pos);
			y = get_shift_drawing_y(px, trgt, drawing_pos);
			dst = dst_img->addr + y * dst_img->line + x * dst_img->bpp / 8;
			color = *(int *)(src_img->addr + px.x * src_img->line + px.y * 4);
			if (color >= -1 && y >= 0 && x >= 0 && color != *(int *)dst)
				*(int *)dst = color;
			px.x++;
		}
		px.y++;
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
			draw(&game->bar, &game->sprites_bar[steps[i] - '0'], pos, TEST);
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
			draw(&game->bar, &game->sprites_bar[13], pos, TEST);
		else
			draw(&game->bar, &game->sprites_bar[14], pos, TEST);
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
	draw(&game->bar, &game->sprites_bar[10], pos, FULL);
	pos.x++;
	while (i < game->max.x - 1)
	{
		draw(&game->bar, &game->sprites_bar[11], pos, FULL);
		pos.x++;
		i++;
	}
	draw(&game->bar, &game->sprites_bar[12], pos, FULL);
	put_moves(game);
	pos.x = 0;
	if (game->bar_displayed && scroll < frequency * 12)
		scroll++;
	else if (!game->bar_displayed && scroll >= 0)
		scroll--;
	if (scroll >= 0 && scroll <= frequency)
	{
		pos.y = 4;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency && scroll <= frequency * 2)
	{
		pos.y = 8;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 2 && scroll <= frequency * 3)
	{
		pos.y = 12;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 3 && scroll <= frequency * 4)
	{
		pos.y = 16;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 4 && scroll <= frequency * 5)
	{
		pos.y = 20;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 5 && scroll <= frequency * 6)
	{
		pos.y = 24;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 6 && scroll <= frequency * 7)
	{
		pos.y = 28;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 7 && scroll <= frequency * 8)
	{
		pos.y = 32;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 8 && scroll <= frequency * 9)
	{
		pos.y = 36;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 9 && scroll <= frequency * 10)
	{
		pos.y = 40;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 10 && scroll <= frequency * 11)
	{
		pos.y = 44;
		draw(&game->render, &game->bar, pos, MENU);
	}
	else if (scroll >= frequency * 11 && scroll <= frequency * 12)
	{
		pos.y = 48;
		draw(&game->render, &game->bar, pos, MENU);
	}
}

void	put_jump(t_game *game)
{
	t_pos		trgt;
	int			frequency;
	static int	i;

	trgt = game->player.cell;
	if (game->player.cell.y < 64)
		trgt.y += 64 - trgt.y;
	frequency = 3;
	if (!i)
		i = 0;
	if (!game->star_appeared)
	{
		if (game->player_direction == 'L' || game->player_direction == 'l')
		{
			if (i >= 0 && i <= frequency * 10)
				draw(&game->render, &game->sprites_mario[16], trgt, BOT);
			i++;
		}
		else if (game->player_direction == 'R' || game->player_direction == 'r')
		{
			if (i >= 0 && i <= frequency * 10)
				draw(&game->render, &game->sprites_mario[18], trgt, BOT);
			i++;
		}
	}
	else
	{
		if (game->player_direction == 'L')
		{
			if (i >= 0 && i <= frequency * 10)
				draw(&game->render, &game->sprites_mario[17], trgt, BOT);
			i++;
		}
		else if (game->player_direction == 'R')
		{
			if (i >= 0 && i <= frequency * 10)
				draw(&game->render, &game->sprites_mario[19], trgt, BOT);
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


void	put_hammer_hit(t_game *game)
{
	t_pos		trgt;
	int			frequency;
	static int	i;

	trgt = game->player.cell;
	if (game->player.cell.y < 64)
		trgt.y += 64 - trgt.y;
	frequency = 3;
	if (!i)
		i = 0;
	if (!game->star_appeared)
	{
		if (game->player_direction == 'L')
		{
			if (i >= 0 && i <= frequency)
				draw(&game->render, &game->sprites_mario[0], trgt, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw(&game->render, &game->sprites_mario[1], trgt, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'R')
		{
			if (i >= 0 && i <= frequency)
				draw(&game->render, &game->sprites_mario[8], trgt, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw(&game->render, &game->sprites_mario[9], trgt, HAMMER_RIGHT_2);
			i++;
		}
		else if (game->player_direction == 'l')
		{
			if (i >= 0 && i <= frequency)
				draw(&game->render, &game->sprites_mario[2], trgt, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw(&game->render, &game->sprites_mario[3], trgt, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'r')
		{
			if (i >= 0 && i <= frequency)
				draw(&game->render, &game->sprites_mario[10], trgt, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw(&game->render, &game->sprites_mario[11], trgt, HAMMER_RIGHT_2);
			i++;
		}
	}
	else
	{
		if (game->player_direction == 'L')
		{
			if (i >= 0 && i <= frequency)
				draw(&game->render, &game->sprites_mario[4], trgt, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw(&game->render, &game->sprites_mario[5], trgt, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'R')
		{
			if (i >= 0 && i <= frequency)
				draw(&game->render, &game->sprites_mario[12], trgt, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw(&game->render, &game->sprites_mario[13], trgt, HAMMER_RIGHT_2);
			i++;
		}
		else if (game->player_direction == 'l')
		{
			if (i >= 0 && i <= frequency)
				draw(&game->render, &game->sprites_mario[6], trgt, HAMMER_LEFT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw(&game->render, &game->sprites_mario[7], trgt, HAMMER_LEFT_2);
			i++;
		}
		else if (game->player_direction == 'r')
		{
			if (i >= 0 && i <= frequency)
				draw(&game->render, &game->sprites_mario[14], trgt, HAMMER_RIGHT_1);
			else if (i >= frequency && i <= frequency * 10)
				draw(&game->render, &game->sprites_mario[15], trgt, HAMMER_RIGHT_2);
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

void	put_player_base(t_game *game)
{
	int	frequency;

	frequency = game->player.speed_animation / 4;
	if (!game->star_appeared)
	{
		if (game->player_direction == 'l')
		{
			if (game->player.state >= 0 && game->player.state <= frequency)
				draw(&game->render, &game->sprites_mario[23], game->player.cell, BOT);
			else if (game->player.state >= frequency && game->player.state <= frequency * 2)
				draw(&game->render, &game->sprites_mario[24], game->player.cell, BOT);
			else if (game->player.state >= frequency * 2 && game->player.state <= frequency * 3)
				draw(&game->render, &game->sprites_mario[25], game->player.cell, BOT);
			else if (game->player.state >= frequency * 3 && game->player.state <= frequency * 4)
				draw(&game->render, &game->sprites_mario[24], game->player.cell, BOT);
		}
		else if (game->player_direction == 'r')
		{
			if (game->player.state >= 0 && game->player.state <= frequency)
				draw(&game->render, &game->sprites_mario[35], game->player.cell, BOT);
			else if (game->player.state >= frequency && game->player.state <= frequency * 2)
				draw(&game->render, &game->sprites_mario[36], game->player.cell, BOT);
			else if (game->player.state >= frequency * 2 && game->player.state <= frequency * 3)
				draw(&game->render, &game->sprites_mario[37], game->player.cell, BOT);
			else if (game->player.state >= frequency * 3 && game->player.state <= frequency * 4)
				draw(&game->render, &game->sprites_mario[36], game->player.cell, BOT);
		}
		else if (game->player_direction == 'L')
		{
			if (game->player.state >= 0 && game->player.state <= frequency)
				draw(&game->render, &game->sprites_mario[20], game->player.cell, BOT);
			else if (game->player.state >= frequency && game->player.state <= frequency * 2)
				draw(&game->render, &game->sprites_mario[21], game->player.cell, BOT);
			else if (game->player.state >= frequency * 2 && game->player.state <= frequency * 3)
				draw(&game->render, &game->sprites_mario[22], game->player.cell, BOT);
			else if (game->player.state >= frequency * 3 && game->player.state <= frequency * 4)
				draw(&game->render, &game->sprites_mario[21], game->player.cell, BOT);
		}
		else if (game->player_direction == 'R')
		{
			if (game->player.state >= 0 && game->player.state <= frequency)
				draw(&game->render, &game->sprites_mario[32], game->player.cell, BOT);
			else if (game->player.state >= frequency && game->player.state <= frequency * 2)
				draw(&game->render, &game->sprites_mario[33], game->player.cell, BOT);
			else if (game->player.state >= frequency * 2 && game->player.state <= frequency * 3)
				draw(&game->render, &game->sprites_mario[34], game->player.cell, BOT);
			else if (game->player.state >= frequency * 3 && game->player.state <= frequency * 4)
				draw(&game->render, &game->sprites_mario[33], game->player.cell, BOT);
		}
		else if (game->player_direction == 'P')
			draw(&game->render, &game->sprites_mario[34], game->player.cell, BOT);
	}
	else
	{
		if (game->player_direction == 'l')
		{
			if (game->player.state >= 0 && game->player.state <= frequency)
				draw(&game->render, &game->sprites_mario[29], game->player.cell, BOT);
			else if (game->player.state >= frequency && game->player.state <= frequency * 2)
				draw(&game->render, &game->sprites_mario[30], game->player.cell, BOT);
			else if (game->player.state >= frequency * 2 && game->player.state <= frequency * 3)
				draw(&game->render, &game->sprites_mario[31], game->player.cell, BOT);
			else if (game->player.state >= frequency * 3 && game->player.state <= frequency * 4)
				draw(&game->render, &game->sprites_mario[30], game->player.cell, BOT);
		}
		else if (game->player_direction == 'r')
		{
			if (game->player.state >= 0 && game->player.state <= frequency)
				draw(&game->render, &game->sprites_mario[41], game->player.cell, BOT);
			else if (game->player.state >= frequency && game->player.state <= frequency * 2)
				draw(&game->render, &game->sprites_mario[42], game->player.cell, BOT);
			else if (game->player.state >= frequency * 2 && game->player.state <= frequency * 3)
				draw(&game->render, &game->sprites_mario[43], game->player.cell, BOT);
			else if (game->player.state >= frequency * 3 && game->player.state <= frequency * 4)
				draw(&game->render, &game->sprites_mario[42], game->player.cell, BOT);
		}
		else if (game->player_direction == 'L')
		{
			if (game->player.state >= 0 && game->player.state <= frequency)
				draw(&game->render, &game->sprites_mario[26], game->player.cell, BOT);
			else if (game->player.state >= frequency && game->player.state <= frequency * 2)
				draw(&game->render, &game->sprites_mario[27], game->player.cell, BOT);
			else if (game->player.state >= frequency * 2 && game->player.state <= frequency * 3)
				draw(&game->render, &game->sprites_mario[28], game->player.cell, BOT);
			else if (game->player.state >= frequency * 3 && game->player.state <= frequency * 4)
				draw(&game->render, &game->sprites_mario[27], game->player.cell, BOT);
		}
		else if (game->player_direction == 'R')
		{
			if (game->player.state >= 0 && game->player.state <= frequency)
				draw(&game->render, &game->sprites_mario[38], game->player.cell, BOT);
			else if (game->player.state >= frequency && game->player.state <= frequency * 2)
				draw(&game->render, &game->sprites_mario[39], game->player.cell, BOT);
			else if (game->player.state >= frequency * 2 && game->player.state <= frequency * 3)
				draw(&game->render, &game->sprites_mario[40], game->player.cell, BOT);
			else if (game->player.state >= frequency * 3 && game->player.state <= frequency * 4)
				draw(&game->render, &game->sprites_mario[39], game->player.cell, BOT);
		}
	}
}

void	put_grass(t_game *game, t_pos pos)
{
	if (!game->star_appeared)
		draw(&game->render, &game->sprites_environnement[0], pos, FULL);
	else
		draw(&game->render, &game->sprites_environnement[1], pos, FULL);
}

void	put_wall(t_game *game, t_pos pos)
{
	if (!game->star_appeared)
	{
		if (pos.y < game->max.y - 1 && pos.y > 0
			&& game->map[pos.y + 1][pos.x] == '1'
			&& game->map[pos.y - 1][pos.x] == '1')
			draw(&game->render, &game->sprites_environnement[4], pos, FULL);
		else if (pos.y < game->max.y - 1 && game->map[pos.y + 1][pos.x] == '1')
			draw(&game->render, &game->sprites_environnement[6], pos, FULL);
		else if (pos.y > 0 && game->map[pos.y - 1][pos.x] == '1')
			draw(&game->render, &game->sprites_environnement[2], pos, FULL);
		else
			draw(&game->render, &game->sprites_environnement[8], pos, FULL);
	}
	else
	{
		if (pos.y < game->max.y - 1 && pos.y > 0
			&& game->map[pos.y + 1][pos.x] == '1'
			&& game->map[pos.y - 1][pos.x] == '1')
			draw(&game->render, &game->sprites_environnement[5], pos, FULL);
		else if (pos.y < game->max.y - 1 && game->map[pos.y + 1][pos.x] == '1')
			draw(&game->render, &game->sprites_environnement[7], pos, FULL);
		else if (pos.y > 0 && game->map[pos.y - 1][pos.x] == '1')
			draw(&game->render, &game->sprites_environnement[3], pos, FULL);
		else
			draw(&game->render, &game->sprites_environnement[9], pos, FULL);
	}
}



void	put_element(t_data *dst, t_data *src, t_data *sprites, t_shift drawing_pos)
{
	int	index_elements;
	int	frequency;
	int	frequency_count;
	int	number_sprite;

	index_elements = 0;
	frequency = src->speed_animation / sprites->sprite_count;
	while (index_elements < src->index)
	{
		number_sprite = 0;
		frequency_count = 0;
		while (number_sprite < sprites->sprite_count)
		{
			if (src->state >= frequency_count && src->state <= frequency_count + frequency)
				draw(dst, &sprites[number_sprite], src[index_elements].cell, drawing_pos);
			number_sprite++;
			frequency_count += frequency;
		}
		index_elements++;
	}
}

void	put_enemies(t_game *game, t_data *dst, t_data *src, t_data *sprites, t_shift drawing_pos)
{
	int	index_elements;
	int	frequency;
	int	frequency_count;
	int	number_sprite;

	index_elements = 0;
	frequency = src->speed_animation / sprites->sprite_count;
	while (index_elements < src->index)
	{
		number_sprite = 0;
		frequency_count = 0;
		while (number_sprite < sprites->sprite_count)
		{
			if (src->state >= frequency_count && src->state <= frequency_count + frequency)
			{
				if (enemy_proximity(game, src[index_elements].pos) == 1 && is(ENEMY, game->map[src[index_elements].pos.y][src[index_elements].pos.x]))
					draw(&game->render, &game->sprites_goombas[number_sprite + 6], src[index_elements].cell, CENTER);
				else if (enemy_proximity(game, src[index_elements].pos) == 2 && is(ENEMY, game->map[src[index_elements].pos.y][src[index_elements].pos.x]))
					draw(&game->render, &game->sprites_goombas[number_sprite + 3], src[index_elements].cell, CENTER);
				else if (is(ENEMY, game->map[src[index_elements].pos.y][ src[index_elements].pos.x]))
					draw(dst, &sprites[number_sprite], src[index_elements].cell, drawing_pos);
			}
			number_sprite++;
			frequency_count += frequency;
		}
		index_elements++;
	}
}

void	put_wall_to_player(t_game *game)
{
	t_pos	target;

	target.y = game->player.pos.y + 1;
	target.x = game->player.pos.x - 1;
	while (target.x <= game->player.pos.x + 1)
	{
		if (game->map[target.y][target.x] == '1')
			put_wall(game, target);
		target.x++;
	}
}

void	put_player(t_game *game, t_data *dst, t_data *src, t_data *sprites, t_shift drawing_pos)
{
	int	index_elements;
	int	frequency;
	int	frequency_count;
	int	number_sprite;

	index_elements = 0;
	frequency = src->speed_animation / sprites->sprite_count;
	while (index_elements < src->count)
	{
		number_sprite = 0;
		frequency_count = 0;
		while (number_sprite < sprites->sprite_count)
		{
			printf("number_sprite = %d\n", number_sprite);
			if (game->player_direction == 'P')
				draw(dst, &sprites[number_sprite + 20], src[index_elements].cell, drawing_pos);
			if (game->player_direction == 'L')
				draw(dst, &sprites[number_sprite + 20], src[index_elements].cell, drawing_pos);
			if (game->player_direction == 'l')
				draw(dst, &sprites[number_sprite + 23], src[index_elements].cell, drawing_pos);
			if (game->player_direction == 'R')
				draw(dst, &sprites[number_sprite + 32], src[index_elements].cell, drawing_pos);
			if (game->player_direction == 'r')
				draw(dst, &sprites[number_sprite + 35], src[index_elements].cell, drawing_pos);
			number_sprite++;
			frequency_count += frequency;
		}
		index_elements++;
	}
}

void	put_elements(t_game *game)
{
	read_all_map(game, ALL, put_grass);
	read_all_map(game, "1", put_wall);
	if (game->map_contain_hammer && !game->get_hammer)
		draw(&game->render, &game->sprites_collectibles[4], game->hammer.pos, FULL);
	if (game->star_appeared)
		put_element(&game->render, game->star, &game->sprites_collectibles[5], CENTER);
	if (game->enemies->count > 0)
		put_enemies(game, &game->render, game->enemies, game->sprites_goombas, CENTER);
	if (game->coins->count > 0)
		put_element(&game->render, game->coins, game->sprites_collectibles, CENTER);
	if (game->is_jumping)
		put_jump(game);
	else if (game->is_hitting)
		put_hammer_hit(game);
	else
		put_player_base(game);
		// put_player(game, &game->render, &game->player, game->sprites_mario, BOT);
	put_bar(game);
	put_wall_to_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->render.img, 0, 0);
}
