/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addresses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:14:55 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/20 11:15:29 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_addresses(t_data *data, int number_sprite)
{
	int	i;

	i = 0;
	while (i < number_sprite)
	{
		data[i].addr = mlx_get_data_addr(data[i].img,
				&data[i].bpp, &data[i].line, &data[i].endian);
		i++;
	}
}

void	get_all_addresses(t_game *game)
{
	get_addresses(game->sprites_collectibles, 8);
	get_addresses(game->sprites_goombas, 9);
	get_addresses(game->sprites_environnement, 10);
	get_addresses(game->sprites_bar, 15);
	get_addresses(game->sprites_mario, 44);
	game->bar.addr = mlx_get_data_addr(game->bar.img,
			&game->bar.bpp, &game->bar.line, &game->bar.endian);
	game->render.addr = mlx_get_data_addr(game->render.img,
			&game->render.bpp, &game->render.line, &game->render.endian);
}
