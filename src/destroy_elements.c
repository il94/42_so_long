/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:14:44 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/25 22:14:44 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_data_environnement(t_game *game)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		mlx_destroy_image(game->mlx, game->environnement[i].img);
		i++;
	}
}

void	destroy_data_mobs(t_game *game)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		mlx_destroy_image(game->mlx, game->goombas[i].img);
		i++;
	}
	i = 0;
	while (i < 44)
	{
		mlx_destroy_image(game->mlx, game->mario[i].img);
		i++;
	}
}

void	destroy_data_collectibles(t_game *game)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, game->coin[i].img);
		i++;
	}
}

int	destroy_elements(t_game *game)
{
	destroy_data_environnement(game);
	destroy_data_mobs(game);
	destroy_data_collectibles(game);
	
/*============================================================================*/

	mlx_destroy_image(game->mlx, game->hammer.img);

/*============================================================================*/

	mlx_destroy_image(game->mlx, game->s.img);
	mlx_destroy_image(game->mlx, game->s_2.img);
	mlx_destroy_image(game->mlx, game->s_3.img);
	mlx_destroy_image(game->mlx, game->s_4.img);
	mlx_destroy_image(game->mlx, game->s_5.img);

/*============================================================================*/

	mlx_destroy_image(game->mlx, game->menu.img);
	mlx_destroy_image(game->mlx, game->menu_2.img);
	mlx_destroy_image(game->mlx, game->menu_3.img);
	mlx_destroy_image(game->mlx, game->step.img);
	mlx_destroy_image(game->mlx, game->steps.img);
	mlx_destroy_image(game->mlx, game->numbers[0].img);
	mlx_destroy_image(game->mlx, game->numbers[1].img);
	mlx_destroy_image(game->mlx, game->numbers[2].img);
	mlx_destroy_image(game->mlx, game->numbers[3].img);
	mlx_destroy_image(game->mlx, game->numbers[4].img);
	mlx_destroy_image(game->mlx, game->numbers[5].img);
	mlx_destroy_image(game->mlx, game->numbers[6].img);
	mlx_destroy_image(game->mlx, game->numbers[7].img);
	mlx_destroy_image(game->mlx, game->numbers[8].img);
	mlx_destroy_image(game->mlx, game->numbers[9].img);

/*============================================================================*/

	mlx_destroy_image(game->mlx, game->screen.img);
	mlx_destroy_image(game->mlx, game->menu_full.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free_array(game->map);
	free(game->ennemies);
	free(game->mlx);
	system("pkill vlc");
}
