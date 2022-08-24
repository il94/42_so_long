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

void	put_all_elements(t_data *dst, t_data *src, t_data *sprites, t_shift drawing_pos)
{
	int	frequency;
	int	frequency_count;
	int	index_sprite;
	int	i;

	i = 0;
	frequency = src->speed_animation / sprites->sprite_count;
	while (i < src->index)
	{
		index_sprite = 0;
		frequency_count = 0;
		while (index_sprite < sprites->sprite_count)
		{
			if (src->state >= frequency_count && src->state <= frequency_count + frequency)
				draw(dst, &sprites[index_sprite], src[i].cell, drawing_pos);
			index_sprite++;
			frequency_count += frequency;
		}
		i++;
	}
}

void	put_element(t_data *dst, t_data *src, t_data *sprites, t_shift drawing_pos)
{
	int	frequency_count;
	int	frequency;
	int	index_sprite;

	index_sprite = 0;
	frequency_count = 0;
	frequency = src->speed_animation / sprites->sprite_count;
	while (index_sprite < sprites->sprite_count)
	{
		if (src->state >= frequency_count && src->state <= frequency_count + frequency)
			draw(dst, &sprites[index_sprite], src->cell, drawing_pos);
		frequency_count += frequency;
		index_sprite++;
	}
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

void	put_enemies(t_game *game, t_data *dst, t_data *src, t_data *sprites)
{
	int	i;

	i = 0;
	while (i < src->index)
	{
		if (enemy_proximity(game->map, game->player.pos, src[i].pos) == 1)
			put_element(dst, &src[i], &sprites[6], CENTER);
		else if (enemy_proximity(game->map, game->player.pos, src[i].pos) == 2)
			put_element(dst, &src[i], &sprites[3], CENTER);
		else
			put_element(dst, &src[i], &sprites[0], CENTER);
		i++;
	}
}

void	put_player_hit(t_data *dst, t_data *src, t_data *sprites, t_bool *is_hitting)
{
	static int	state;

	if (src->direction == 'L' && state < 3)
		draw(dst, &sprites[0], src->cell, HAMMER_LEFT_1);
	else if (src->direction == 'L')
		draw(dst, &sprites[1], src->cell, HAMMER_LEFT_2);
	if (src->direction == 'l' && state < 3)
		draw(dst, &sprites[2], src->cell, HAMMER_LEFT_1);
	else if (src->direction == 'l')
		draw(dst, &sprites[3], src->cell, HAMMER_LEFT_2);
	if (src->direction == 'R' && state < 3)
		draw(dst, &sprites[4], src->cell, HAMMER_RIGHT_1);
	else if (src->direction == 'R')
		draw(dst, &sprites[5], src->cell, HAMMER_RIGHT_2);
	if (src->direction == 'r' && state < 3)
		draw(dst, &sprites[6], src->cell, HAMMER_RIGHT_1);
	else if (src->direction == 'r')
		draw(dst, &sprites[7], src->cell, HAMMER_RIGHT_2);
	state++;
	if (state > 30)
	{
		*is_hitting = FALSE;
		state = 0;
	}
}

void	put_player_static(t_data *dst, t_data *src, t_data *sprites)
{
	if (src->direction == 'L')
		draw(dst, &sprites[0], src->cell, BOT);
	if (src->direction == 'l')
		draw(dst, &sprites[1], src->cell, BOT);
	if (src->direction == 'R')
		draw(dst, &sprites[2], src->cell, BOT);
	if (src->direction == 'r')
		draw(dst, &sprites[3], src->cell, BOT);
}

void	put_player_walk(t_data *dst, t_data *src, t_data *sprites)
{
	int	frequency;
	int	frequency_count;
	int	number_sprite;

	frequency = src->speed_animation / sprites->sprite_count;
	number_sprite = 0;
	frequency_count = 0;
	while (number_sprite < sprites->sprite_count)
	{
		if (src->state >= frequency_count && src->state <= frequency_count + frequency)
		{
			if (src->direction == 'L')
				draw(dst, &sprites[number_sprite], src->cell, BOT);
			if (src->direction == 'l')
				draw(dst, &sprites[number_sprite + 3], src->cell, BOT);
			if (src->direction == 'R')
				draw(dst, &sprites[number_sprite + 6], src->cell, BOT);
			if (src->direction == 'r')
				draw(dst, &sprites[number_sprite + 9], src->cell, BOT);
		}
		number_sprite++;
		frequency_count += frequency;
	}
}

void	put_player_jump(t_data *dst, t_data *src, t_data *sprites, t_bool *is_jumping)
{
	static int	state;
	int			frequency_jump;

	frequency_jump = 30;
	if (state < frequency_jump)
	{
		if (src->direction == 'L')
			draw(dst, &sprites[0], src->cell, BOT);
		if (src->direction == 'R')
			draw(dst, &sprites[1], src->cell, BOT);
		state++;
	}
	else
	{
		*is_jumping = FALSE;
		state = 0;
	}
}

void	put_player(t_game *game, t_data *dst, t_data *src, t_data *sprites)
{
	int	i;

	i = 0;
	if (game->star_appeared)
		i += 26;
	if (game->is_hitting)
		put_player_hit(dst, src, &game->sprites_mario[i + 18], &game->is_hitting);
	else if (game->is_jumping)
		put_player_jump(dst, src, &game->sprites_mario[i + 16], &game->is_jumping);
	else if (player_is_moving(game))
		put_player_walk(dst, src, &game->sprites_mario[i + 4]);
	else
		put_player_static(dst, src, &game->sprites_mario[i]);
}

void	put_wall_to_player(t_game *game)
{
	t_pos	pos_trgt;
	int	i;

	i = 0;
	if (game->star_appeared)
		i += 5;
	pos_trgt.x = game->player.pos.x - 1;
	pos_trgt.y = game->player.pos.y + 1;
	while (pos_trgt.x <= game->player.pos.x + 1)
	{
		if (is(WALL, game->map[pos_trgt.y][pos_trgt.x]))
			put_wall(game, &game->render, &game->sprites_environnement[i], pos_trgt);
		pos_trgt.x++;
	}
}

void	put_wall(t_game *game, t_data *dst, t_data *sprites, t_pos pos)
{
	int	i;

	i = 0;
	if (pos.y < game->max.y - 1 && pos.y > 0
		&& is(WALL, game->map[pos.y + 1][pos.x])
		&& is(WALL, game->map[pos.y - 1][pos.x]))
		i += 2;
	else if (pos.y < game->max.y - 1 && is(WALL, game->map[pos.y + 1][pos.x]))
		i += 3;
	else if (pos.y > 0 && is(WALL, game->map[pos.y - 1][pos.x]))
		i += 1;
	else
		i += 4;
	draw(dst, &sprites[i], pos, FULL);
}

void	put_environnement(t_game *game, t_pos pos_trgt)
{
	int	i;

	i = 0;
	if (game->star_appeared)
		i += 5;
	draw(&game->render, &game->sprites_environnement[i], pos_trgt, FULL);
	if (is(WALL, game->map[pos_trgt.y][pos_trgt.x]))
		put_wall(game, &game->render, &game->sprites_environnement[i], pos_trgt);
}

void	put_around_player(t_game *game, t_pos pos)
{
	t_pos	pos_trgt;

	pos_trgt = pos;
	pos_trgt.y -= 2;
	if (pos_trgt.y < 0)
		pos_trgt.y = 0;
	while (pos_trgt.y <= pos.y + 1)
	{
		pos_trgt.x = pos.x - 1;
		if (pos_trgt.x < 0)
			pos_trgt.x = 0;
		while (pos_trgt.x <= pos.x + 1)
		{
			put_environnement(game, pos_trgt);
			pos_trgt.x++;
		}
		pos_trgt.y++;
	}
}

void	put_around_enemy(t_game *game, t_pos pos)
{
	t_pos	pos_trgt;

	pos_trgt = pos;
	pos_trgt.y--;
	while (pos_trgt.y <= pos.y + 1)
	{
		put_environnement(game, pos_trgt);
		pos_trgt.y++;
	}
	pos_trgt.y = pos.y;
	pos_trgt.x--;
	while (pos_trgt.x <= pos.x + 1)
	{
		put_environnement(game, pos_trgt);
		pos_trgt.x++;
	}
}

void	put_all_environnement(t_game *game)
{
	if (!game->environnement_displayed)
	{
		read_map_with_struct(game, ALL, put_environnement);
		game->environnement_displayed = TRUE;
	}
}

void	put_environnement_around_entity(t_game *game)
{
	int	i;

	put_around_player(game, game->player.pos);
	i = 0;
	while (i < game->enemies->count)
	{
		put_around_enemy(game, game->enemies[i].pos);
		i++;
	}
}

void	put_render(t_game *game)
{
	put_all_environnement(game);
	put_environnement_around_entity(game);
	if (game->map_contain_hammer && !game->get_hammer)
		draw(&game->render, &game->sprites_collectibles[4], game->hammer.pos, FULL);
	if (game->star_appeared)
		put_all_elements(&game->render, game->star, &game->sprites_collectibles[5], CENTER);
	if (game->enemies->count > 0)
		put_enemies(game, &game->render, game->enemies, game->sprites_goombas);
	if (game->coins->count > 0)
		put_all_elements(&game->render, game->coins, game->sprites_collectibles, CENTER);
	put_player(game, &game->render, &game->player, game->sprites_mario);
	put_bar(game);
	put_wall_to_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->render.img, 0, 0);
}

