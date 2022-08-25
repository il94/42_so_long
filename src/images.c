/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:08:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/25 17:10:23 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_images(void *mlx, t_data *data, char type, int number_sprite)
{
	char	file_name[17];
	char	sprite_index_ten;
	char	sprite_index_unit;
	int		i;

	ft_strlcpy(file_name, "sprites/x_00.xpm\0", 17);
	file_name[8] = type;
	sprite_index_ten = '0';
	sprite_index_unit = '0';
	i = 0;
	while (i < number_sprite)
	{
		data[i].img = mlx_xpm_file_to_image(mlx, file_name,
				&data[i].width, &data[i].height);
		sprite_index_unit++;
		if (sprite_index_unit > '9')
		{
			sprite_index_ten++;
			sprite_index_unit = '0';
		}
		file_name[10] = sprite_index_ten;
		file_name[11] = sprite_index_unit;
		i++;
	}
}

void	get_all_images(t_game *game)
{
	get_images(game->mlx, game->sprites_collectibles, 'c', 8);
	game->sprites_collectibles[0].sprite_count = 4;
	game->sprites_collectibles[4].sprite_count = 1;
	game->sprites_collectibles[5].sprite_count = 3;
	get_images(game->mlx, game->sprites_goombas, 'g', 9);
	game->sprites_goombas[0].sprite_count = 3;
	game->sprites_goombas[3].sprite_count = 3;
	game->sprites_goombas[6].sprite_count = 3;
	get_images(game->mlx, game->sprites_environnement, 'e', 10);
	get_images(game->mlx, game->sprites_bar, 'b', 15);
	get_images(game->mlx, game->sprites_mario, 'm', 52);
	game->sprites_mario[0].sprite_count = 1;
	game->sprites_mario[1].sprite_count = 1;
	game->sprites_mario[2].sprite_count = 1;
	game->sprites_mario[3].sprite_count = 1;
	game->sprites_mario[4].sprite_count = 3;
	game->sprites_mario[7].sprite_count = 3;
	game->sprites_mario[10].sprite_count = 3;
	game->sprites_mario[13].sprite_count = 3;
	game->sprites_mario[16].sprite_count = 1;
	game->sprites_mario[17].sprite_count = 1;
	game->sprites_mario[18].sprite_count = 2;
	game->sprites_mario[20].sprite_count = 2;
	game->sprites_mario[22].sprite_count = 2;
	game->sprites_mario[24].sprite_count = 2;
	game->sprites_mario[26].sprite_count = 1;
	game->sprites_mario[27].sprite_count = 1;
	game->sprites_mario[28].sprite_count = 1;
	game->sprites_mario[29].sprite_count = 1;
	game->sprites_mario[30].sprite_count = 3;
	game->sprites_mario[33].sprite_count = 3;
	game->sprites_mario[36].sprite_count = 3;
	game->sprites_mario[39].sprite_count = 3;
	game->sprites_mario[42].sprite_count = 1;
	game->sprites_mario[43].sprite_count = 1;
	game->sprites_mario[44].sprite_count = 2;
	game->sprites_mario[46].sprite_count = 2;
	game->sprites_mario[48].sprite_count = 2;
	game->sprites_mario[50].sprite_count = 2;
	game->scrolling_bar.img = mlx_new_image(game->mlx,
			game->max.x * CELL, CELL);
	game->scrolling_bar.width = game->max.x * CELL;
	game->scrolling_bar.height = CELL;
	game->render.img = mlx_new_image(game->mlx,
			game->max.x * CELL, game->max.y * CELL);
}
