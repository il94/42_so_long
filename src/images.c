/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:08:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/20 11:16:07 by ilandols         ###   ########.fr       */
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
	get_images(game->mlx, game->sprites_goombas, 'g', 9);
	get_images(game->mlx, game->sprites_environnement, 'e', 10);
	get_images(game->mlx, game->sprites_bar, 'b', 15);
	get_images(game->mlx, game->sprites_mario, 'm', 44);
	game->bar.img = mlx_new_image(game->mlx,
			game->max.x * CELL, CELL);
	game->bar.width = game->max.x * CELL;
	game->bar.height = CELL;
	game->render.img = mlx_new_image(game->mlx,
			game->max.x * CELL, game->max.y * CELL);
}
