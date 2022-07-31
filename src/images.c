/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:08:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/31 01:16:05 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_images_environnement(t_game *game)
{
	game->grass.img = mlx_xpm_file_to_image(game->mlx, "xpm/grass.xpm",
			&game->grass.width, &game->grass.height);
	game->wall_one.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_one.xpm",
			&game->wall_one.width, &game->wall_one.height);
	game->wall_mid.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_mid.xpm",
			&game->wall_mid.width, &game->wall_mid.height);
	game->wall_top.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_top.xpm",
			&game->wall_top.width, &game->wall_top.height);
	game->wall_bot.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_bot.xpm",
			&game->wall_bot.width, &game->wall_bot.height);
}

void	get_images_mobs(t_game *game)
{
	game->mario.img = mlx_xpm_file_to_image(game->mlx, "xpm/mario.xpm",
			&game->mario.width, &game->mario.height);
	game->goomba.img = mlx_xpm_file_to_image(game->mlx, "xpm/goomba.xpm",
			&game->goomba.width, &game->goomba.height);
	game->goomba_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/goomba_b.xpm",
			&game->goomba_b.width, &game->goomba_b.height);
	game->goomba_g.img = mlx_xpm_file_to_image(game->mlx, "xpm/goomba_g.xpm",
			&game->goomba_g.width, &game->goomba_g.height);
	game->goomba_r.img = mlx_xpm_file_to_image(game->mlx, "xpm/goomba_r.xpm",
			&game->goomba_r.width, &game->goomba_r.height);
}

void	get_images_collectibles(t_game *game)
{
	game->coin.img = mlx_xpm_file_to_image(game->mlx, "xpm/coin.xpm",
			&game->coin.width, &game->coin.height);
	game->star.img = mlx_xpm_file_to_image(game->mlx, "xpm/star.xpm",
			&game->star.width, &game->star.height);
}

void	get_images(t_game *game)
{
	get_images_environnement(game);
	get_images_mobs(game);
	get_images_collectibles(game);
}
