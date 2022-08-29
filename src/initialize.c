/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:56:49 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/21 15:09:24 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_elements(t_game *game)
{
	initialize_bar(game, &game->stepbar);
	// initialize_player(game, &game->player);
	initialize_player(game, &game->player, &game->i_player);
	initialize_enemies(game, &game->enemies, &game->i_enemies);
	initialize_coins(game, &game->coins, &game->i_coins);
	initialize_star(game, &game->star);
	game->hammer.pos = read_map_return_pos(game->map, HAMMER);
	if (game->hammer.pos.x == 0 && game->hammer.pos.y == 0)
		game->map_contain_hammer = FALSE;
	else
		game->map_contain_hammer = TRUE;
	game->get_hammer = FALSE;
	game->land_displayed = FALSE;

}
