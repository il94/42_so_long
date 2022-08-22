/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:08:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/22 18:56:47 by ilandols         ###   ########.fr       */
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
	get_images(game->mlx, game->sprites_mario, 'm', 44);
	game->sprites_mario[0].sprite_count = 2;
	game->sprites_mario[2].sprite_count = 2;
	game->sprites_mario[4].sprite_count = 2;
	game->sprites_mario[6].sprite_count = 2;
	game->sprites_mario[8].sprite_count = 2;
	game->sprites_mario[10].sprite_count = 2;
	game->sprites_mario[12].sprite_count = 2;
	game->sprites_mario[14].sprite_count = 2;
	game->sprites_mario[16].sprite_count = 1;
	game->sprites_mario[17].sprite_count = 1;
	game->sprites_mario[18].sprite_count = 1;
	game->sprites_mario[19].sprite_count = 1;
	game->sprites_mario[20].sprite_count = 3;
	game->sprites_mario[23].sprite_count = 3;
	game->sprites_mario[26].sprite_count = 3;
	game->sprites_mario[29].sprite_count = 3;
	game->sprites_mario[32].sprite_count = 3;
	game->sprites_mario[35].sprite_count = 3;
	game->sprites_mario[38].sprite_count = 3;
	game->sprites_mario[41].sprite_count = 3;
	game->bar.img = mlx_new_image(game->mlx,
			game->max.x * CELL, CELL);
	game->bar.width = game->max.x * CELL;
	game->bar.height = CELL;
	game->render.img = mlx_new_image(game->mlx,
			game->max.x * CELL, game->max.y * CELL);
}
