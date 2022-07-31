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
	mlx_destroy_image(game->mlx, game->grass.img);
	mlx_destroy_image(game->mlx, game->wall_one.img);
	mlx_destroy_image(game->mlx, game->wall_mid.img);
	mlx_destroy_image(game->mlx, game->wall_top.img);
	mlx_destroy_image(game->mlx, game->wall_bot.img);
}

void	destroy_data_mobs(t_game *game)
{
	mlx_destroy_image(game->mlx, game->mario.img);
	mlx_destroy_image(game->mlx, game->goomba.img);
	mlx_destroy_image(game->mlx, game->goomba_b.img);
	mlx_destroy_image(game->mlx, game->goomba_g.img);
	mlx_destroy_image(game->mlx, game->goomba_r.img);
}

void	destroy_data_collectibles(t_game *game)
{
	mlx_destroy_image(game->mlx, game->coin.img);
	mlx_destroy_image(game->mlx, game->star.img);
}

int	destroy_elements(t_game *game)
{
	destroy_data_environnement(game);
	destroy_data_mobs(game);
	destroy_data_collectibles(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free_array(game->map);
	free(game->mlx);
	system("pkill vlc");
}
