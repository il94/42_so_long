/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:08:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/09/02 16:29:35 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_images(t_game *game, t_img *data, char type, int number_sprite)
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
		data[i].img = mlx_xpm_file_to_image(game->mlx, file_name,
				&data[i].width, &data[i].height);
		verify_alloc(game, data[i].img);
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

void	get_sprites_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i <= 25)
	{
		game->s_mario[i].sprite_count = j;
		game->s_mario[i + 26].sprite_count = j;
		if (i == 5)
			j++;
		if (i == 13)
			j++;
		i++;
	}
	game->s_items[0].sprite_count = 4;
	game->s_items[4].sprite_count = 1;
	game->s_items[5].sprite_count = 3;
	game->s_goombas[0].sprite_count = 3;
	game->s_goombas[3].sprite_count = 3;
	game->s_goombas[6].sprite_count = 3;
}

void	get_all_images(t_game *game)
{
	get_images(game, game->s_items, 'c', 8);
	get_images(game, game->s_goombas, 'g', 9);
	get_images(game, game->s_land, 'e', 10);
	get_images(game, game->s_bar, 'b', 15);
	get_images(game, game->s_mario, 'm', 52);
	game->s_stepbar.img = mlx_new_image(game->mlx,
			game->max.x * CELL, CELL);
	verify_alloc(game, game->s_stepbar.img);
	game->s_stepbar.width = game->max.x * CELL;
	game->s_stepbar.height = CELL;
	game->s_render.img = mlx_new_image(game->mlx,
			game->max.x * CELL, game->max.y * CELL);
	verify_alloc(game, game->s_render.img);
	get_sprites_count(game);
}
