/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:08:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/19 18:58:41 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_images_environnement(t_game *game)
{
	char	file_name[13];
	char	sprite_index_ten;
	char	sprite_index_unit;
	int		i;

	ft_strlcpy(file_name, "xpm/e_00.xpm\0", 13);
	sprite_index_ten = '0';
	sprite_index_unit = '0';
	i = 0;
	while (sprite_index_ten != '1' || sprite_index_unit != '0')
	{
		game->environnement[i].img = mlx_xpm_file_to_image(game->mlx, file_name,
			&game->environnement[i].width, &game->environnement[i].height);
		sprite_index_unit++;
		if (sprite_index_unit > '9')
		{
			sprite_index_ten++;
			sprite_index_unit = '0';
		}
		file_name[6] = sprite_index_ten;
		file_name[7] = sprite_index_unit;
		i++;
	}
}

void	get_images_mobs(t_game *game)
{
	char	file_name[13];
	char	file_name2[13];
	char	sprite_index_ten;
	char	sprite_index_unit;
	int		i;

	ft_strlcpy(file_name, "xpm/g_00.xpm\0", 13);
	sprite_index_ten = '0';
	sprite_index_unit = '0';
	i = 0;
	while (sprite_index_ten != '0' || sprite_index_unit != '9')
	{
		game->goombas[i].img = mlx_xpm_file_to_image(game->mlx, file_name,
			&game->goombas[i].width, &game->goombas[i].height);
		sprite_index_unit++;
		if (sprite_index_unit > '9')
		{
			sprite_index_ten++;
			sprite_index_unit = '0';
		}
		file_name[6] = sprite_index_ten;
		file_name[7] = sprite_index_unit;
		i++;
	}
	ft_strlcpy(file_name2, "xpm/m_00.xpm\0", 13);
	sprite_index_ten = '0';
	sprite_index_unit = '0';
	i = 0;
	while (sprite_index_ten != '4' || sprite_index_unit != '4')
	{
		game->mario[i].img = mlx_xpm_file_to_image(game->mlx, file_name2,
			&game->mario[i].width, &game->mario[i].height);
			printf("%s\n", file_name2);
			printf("%d\n", i);
		sprite_index_unit++;
		if (sprite_index_unit > '9')
		{
			sprite_index_ten++;
			sprite_index_unit = '0';
		}
		file_name2[6] = sprite_index_ten;
		file_name2[7] = sprite_index_unit;
		i++;
	}
}

void	get_images_collectibles(t_game *game)
{
	char	file_name[13];
	char	sprite_index_ten;
	char	sprite_index_unit;
	int		i;

	ft_strlcpy(file_name, "xpm/c_00.xpm\0", 13);
	sprite_index_ten = '0';
	sprite_index_unit = '0';
	i = 0;
	while (sprite_index_ten != '0' || sprite_index_unit != '4')
	{
		game->coin[i].img = mlx_xpm_file_to_image(game->mlx, file_name,
			&game->coin[i].width, &game->coin[i].height);
		sprite_index_unit++;
		if (sprite_index_unit > '9')
		{
			sprite_index_ten++;
			sprite_index_unit = '0';
		}
		file_name[6] = sprite_index_ten;
		file_name[7] = sprite_index_unit;
		i++;
	}
}

void	get_images(t_game *game)
{
	get_images_environnement(game);
	get_images_mobs(game);
	get_images_collectibles(game);

/*============================================================================*/

	game->hammer.img = mlx_xpm_file_to_image(game->mlx, "xpm/hammer.xpm",
			&game->hammer.width, &game->hammer.height);

/*============================================================================*/

	game->s.img = mlx_xpm_file_to_image(game->mlx, "xpm/s.xpm",
			&game->s.width, &game->s.height);
	game->s_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_2.xpm",
			&game->s_2.width, &game->s_2.height);
	game->s_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_3.xpm",
			&game->s_3.width, &game->s_3.height);
	game->s_4.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_4.xpm",
			&game->s_4.width, &game->s_4.height);
	game->s_5.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_5.xpm",
			&game->s_5.width, &game->s_5.height);

/*============================================================================*/

	game->menu.img = mlx_xpm_file_to_image(game->mlx, "xpm/menu.xpm",
			&game->menu.width, &game->menu.height);
	game->menu_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/menu_2.xpm",
			&game->menu_2.width, &game->menu_2.height);
	game->menu_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/menu_3.xpm",
			&game->menu_3.width, &game->menu_3.height);
	game->step.img = mlx_xpm_file_to_image(game->mlx, "xpm/step.xpm",
			&game->step.width, &game->step.height);
	game->steps.img = mlx_xpm_file_to_image(game->mlx, "xpm/steps.xpm",
			&game->steps.width, &game->steps.height);
	game->numbers[0].img = mlx_xpm_file_to_image(game->mlx, "xpm/_0.xpm",
			&game->numbers[0].width, &game->numbers[0].height);
	game->numbers[1].img = mlx_xpm_file_to_image(game->mlx, "xpm/_1.xpm",
			&game->numbers[1].width, &game->numbers[1].height);
	game->numbers[2].img = mlx_xpm_file_to_image(game->mlx, "xpm/_2.xpm",
			&game->numbers[2].width, &game->numbers[2].height);
	game->numbers[3].img = mlx_xpm_file_to_image(game->mlx, "xpm/_3.xpm",
			&game->numbers[3].width, &game->numbers[3].height);
	game->numbers[4].img = mlx_xpm_file_to_image(game->mlx, "xpm/_4.xpm",
			&game->numbers[4].width, &game->numbers[4].height);
	game->numbers[5].img = mlx_xpm_file_to_image(game->mlx, "xpm/_5.xpm",
			&game->numbers[5].width, &game->numbers[5].height);
	game->numbers[6].img = mlx_xpm_file_to_image(game->mlx, "xpm/_6.xpm",
			&game->numbers[6].width, &game->numbers[6].height);
	game->numbers[7].img = mlx_xpm_file_to_image(game->mlx, "xpm/_7.xpm",
			&game->numbers[7].width, &game->numbers[7].height);
	game->numbers[8].img = mlx_xpm_file_to_image(game->mlx, "xpm/_8.xpm",
			&game->numbers[8].width, &game->numbers[8].height);
	game->numbers[9].img = mlx_xpm_file_to_image(game->mlx, "xpm/_9.xpm",
			&game->numbers[9].width, &game->numbers[9].height);

/*============================================================================*/

	game->screen.img = mlx_new_image(game->mlx,
			game->max.x * CELL, game->max.y * CELL);
	game->menu_full.img = mlx_new_image(game->mlx,
			game->max.x * CELL, CELL);
	game->menu_full.width = game->max.x * CELL;
	game->menu_full.height = CELL;

}
