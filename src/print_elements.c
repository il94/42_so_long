/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:54:53 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/25 18:55:06 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	put_scrolling_bar(t_game *game)
{
	put_bar(&game->scrolling_bar, game->sprites_bar, game->max.x - 1);
	put_move_count(game);
	scroll_bar(&game->render, &game->scrolling_bar, game->bar_displayed);
}
