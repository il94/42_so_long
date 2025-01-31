/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_addresses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:14:55 by ilandols          #+#    #+#             */
/*   Updated: 2022/09/01 19:53:04 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_addresses(t_game *game, t_img *data, int number_sprite)
{
	int	i;

	i = 0;
	while (i < number_sprite)
	{
		data[i].addr = mlx_get_data_addr(data[i].img,
				&data[i].bpp, &data[i].line, &data[i].end);
		verify_alloc(game, data[i].addr);
		i++;
	}
}

void	get_all_addresses(t_game *game)
{
	get_addresses(game, game->s_items, 8);
	get_addresses(game, game->s_goombas, 9);
	get_addresses(game, game->s_land, 10);
	get_addresses(game, game->s_bar, 15);
	get_addresses(game, game->s_mario, 52);
	game->s_stepbar.addr = mlx_get_data_addr(game->s_stepbar.img,
			&game->s_stepbar.bpp, &game->s_stepbar.line, &game->s_stepbar.end);
	verify_alloc(game, game->s_stepbar.addr);
	game->s_render.addr = mlx_get_data_addr(game->s_render.img,
			&game->s_render.bpp, &game->s_render.line, &game->s_render.end);
	verify_alloc(game, game->s_render.addr);
}
