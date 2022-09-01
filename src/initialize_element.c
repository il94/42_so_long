/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:01:16 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/31 18:01:16 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_player(t_game *game, t_list *player, t_info *i_player)
{
	get_position_entities(game->map, &player, PLAYER);
	player->cell.y += 16;
	player->dir = 'L';
	player->next = NULL;
	player->prev = NULL;
	i_player->state = 0;
	i_player->speed_animation = 24;
	game->player_steps = 0;
	game->hitting = FALSE;
	game->jumping = FALSE;
	game->move_up = FALSE;
	game->move_right = FALSE;
	game->move_down = FALSE;
	game->move_left = FALSE;
}

void	initialize_star(t_game *game, t_list *star, t_info *i_star)
{
	get_position_entities(game->map, &star, STAR);
	i_star->state = 0;
	i_star->speed_animation = 90;
	game->star_appeared = FALSE;
}

void	initialize_hammer(t_game *game, t_list *hammer)
{
	game->hammer.pos.x = 0;
	game->hammer.pos.y = 0;
	get_position_entities(game->map, &hammer, HAMMER);
	if (game->hammer.pos.x == 0 && game->hammer.pos.y == 0)
		game->map_contain_hammer = FALSE;
	else
		game->map_contain_hammer = TRUE;
	game->get_hammer = FALSE;
	game->land_displayed = FALSE;
}

void	initialize_bar(t_game *game, t_list *stepbar)
{
	stepbar->pos.x = 0;
	stepbar->pos.y = 0;
	stepbar->cell.x = 0;
	stepbar->cell.y = 0;
	game->bar_display = FALSE;
	game->max_player_steps = FALSE;
}
