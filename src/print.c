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

void	put_render(t_game *game)
{
	put_all_land(game);
	if (game->map_contain_hammer && !game->get_hammer)
		draw(&game->s_render, &game->s_items[4], game->hammer.pos, FULL);
	if (game->star_appeared)
		put_element(&game->s_render, &game->star, &game->s_items[5], CENTER);
	if (game->enemies->count > 0)
		put_enemies(game, &game->s_render, game->enemies, game->s_goombas);
	if (game->coins->count > 0)
		put_all_element(&game->s_render, game->coins, game->s_items, CENTER);
	put_player(game, &game->s_render, &game->player, game->s_mario);
	put_wall_to_player(game);
	put_stepbar(game);
	mlx_put_image_to_window(game->mlx, game->win, game->s_render.img, 0, 0);
}
