/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:56:49 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/21 15:09:24 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_data_elements(t_game *game)
{
	initialize_enemies(game, game->enemies);
	initialize_coins(game, game->coins);
	initialize_player(game, &game->player);
	game->star_pos = read_map_return_pos(game->map, STAR);
	game->star_appeared = FALSE;
	game->get_hammer = FALSE;
}
