/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:15:47 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/20 11:15:47 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_elements(void *mlx, t_data *data, int number_sprite)
{
	int	i;

	i = 0;
	while (i < number_sprite)
	{
		mlx_destroy_image(mlx, data[i].img);
		i++;
	}
}

int	destroy_all_elements(t_game *game)
{
	destroy_elements(game->mlx, game->sprites_collectibles, 8);
	destroy_elements(game->mlx, game->sprites_goombas, 9);
	destroy_elements(game->mlx, game->sprites_environnement, 10);
	destroy_elements(game->mlx, game->sprites_bar, 15);
	destroy_elements(game->mlx, game->sprites_mario, 44);
	mlx_destroy_image(game->mlx, game->bar.img);
	mlx_destroy_image(game->mlx, game->render.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free_array(game->map);
	free(game->enemies);
	free(game->coins);
	free(game->mlx);
	system("pkill vlc");
}
