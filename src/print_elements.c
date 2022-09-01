/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:54:53 by ilandols          #+#    #+#             */
/*   Updated: 2022/09/01 16:23:02 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_land(t_game *game, t_pos pos_trgt)
{
	int	i;

	i = 0;
	if (game->star_appeared)
		i += 5;
	draw(&game->s_render, &game->s_land[i], pos_trgt, FULL);
	if (is(WALL, game->map[pos_trgt.y][pos_trgt.x]))
		put_wall(game, &game->s_render, &game->s_land[i], pos_trgt);
}

void	put_wall(t_game *game, t_img *dst, t_img *sprites, t_pos pos)
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

void	put_enemies(t_game *game, t_img *dst, t_list *src, t_img *sprites)
{
	while (src)
	{
		if (enemy_proximity(game->map, game->player.pos, src->pos) == 1)
			put_element(dst, src, &sprites[6], game->i_enemies);
		else if (enemy_proximity(game->map, game->player.pos, src->pos) == 2)
			put_element(dst, src, &sprites[3], game->i_enemies);
		else
			put_element(dst, src, &sprites[0], game->i_enemies);
		src = src->next;
	}
}

void	put_player(t_game *game, t_img *dst, t_list *src, t_img *sprites)
{
	int	i;

	i = 0;
	if (game->star_appeared)
		i += 26;
	if (game->hitting)
		put_player_hit(dst, src, &sprites[i + 6], &game->hitting);
	else if (game->jumping)
		put_player_jump(dst, src, &sprites[i + 4], &game->jumping);
	else if (player_is_moving(game))
		put_player_walk(dst, src, &sprites[i + 14], game->i_player);
	else
		put_player_static(dst, src, &sprites[i]);
}

void	put_stepbar(t_game *game)
{
	put_bar(&game->s_stepbar, game->s_bar, game->max.x - 1);
	put_move_count(game, &game->s_stepbar, game->s_bar);
	scroll_bar(&game->s_render, &game->stepbar,
		&game->s_stepbar, game->bar_display);
}
