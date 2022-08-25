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
	put_all_environnement(game);
	if (game->map_contain_hammer && !game->get_hammer)
		draw(&game->render, &game->sprites_collectibles[4], game->hammer.pos, FULL);
	if (game->star_appeared)
		put_element(&game->render, game->star, &game->sprites_collectibles[5], CENTER);
	if (game->enemies->count > 0)
		put_enemies(game, &game->render, game->enemies, game->sprites_goombas);
	if (game->coins->count > 0)
		put_all_elements(&game->render, game->coins, game->sprites_collectibles, CENTER);
	put_player(game, &game->render, &game->player, game->sprites_mario);
	put_wall_to_player(game);
	put_scrolling_bar(game);
	mlx_put_image_to_window(game->mlx, game->win, game->render.img, 0, 0);
}
