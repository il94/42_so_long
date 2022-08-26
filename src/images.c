/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:08:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/26 17:56:36 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_images(void *mlx, t_img *data, char type, int number_sprite)
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
	get_images(game->mlx, game->s_items, 'c', 8);
	game->s_items[0].sprite_count = 4;
	game->s_items[4].sprite_count = 1;
	game->s_items[5].sprite_count = 3;
	get_images(game->mlx, game->s_goombas, 'g', 9);
	game->s_goombas[0].sprite_count = 3;
	game->s_goombas[3].sprite_count = 3;
	game->s_goombas[6].sprite_count = 3;
	get_images(game->mlx, game->s_land, 'e', 10);
	get_images(game->mlx, game->s_bar, 'b', 15);
	get_images(game->mlx, game->s_mario, 'm', 52);
	game->s_mario[0].sprite_count = 1;
	game->s_mario[1].sprite_count = 1;
	game->s_mario[2].sprite_count = 1;
	game->s_mario[3].sprite_count = 1;
	game->s_mario[4].sprite_count = 3;
	game->s_mario[7].sprite_count = 3;
	game->s_mario[10].sprite_count = 3;
	game->s_mario[13].sprite_count = 3;
	game->s_mario[16].sprite_count = 1;
	game->s_mario[17].sprite_count = 1;
	game->s_mario[18].sprite_count = 2;
	game->s_mario[20].sprite_count = 2;
	game->s_mario[22].sprite_count = 2;
	game->s_mario[24].sprite_count = 2;
	game->s_mario[26].sprite_count = 1;
	game->s_mario[27].sprite_count = 1;
	game->s_mario[28].sprite_count = 1;
	game->s_mario[29].sprite_count = 1;
	game->s_mario[30].sprite_count = 3;
	game->s_mario[33].sprite_count = 3;
	game->s_mario[36].sprite_count = 3;
	game->s_mario[39].sprite_count = 3;
	game->s_mario[42].sprite_count = 1;
	game->s_mario[43].sprite_count = 1;
	game->s_mario[44].sprite_count = 2;
	game->s_mario[46].sprite_count = 2;
	game->s_mario[48].sprite_count = 2;
	game->s_mario[50].sprite_count = 2;
	game->s_stepbar.img = mlx_new_image(game->mlx,
			game->max.x * CELL, CELL);
	game->s_stepbar.width = game->max.x * CELL;
	game->s_stepbar.height = CELL;
	game->s_render.img = mlx_new_image(game->mlx,
			game->max.x * CELL, game->max.y * CELL);
}
