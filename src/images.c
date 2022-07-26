/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:08:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/25 22:30:51 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_images_environnement(t_game *game)
{
	game->floor.img = mlx_xpm_file_to_image(game->mlx, "xpm/grass.xpm",
			&game->floor.width, &game->floor.height);
	game->floor.addr = mlx_get_data_addr(game->floor.img,
			&game->floor.bpp, &game->floor.line, &game->floor.endian);
	game->wall_one.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_one.xpm",
			&game->wall_one.width, &game->wall_one.height);
	game->wall_one.addr = mlx_get_data_addr(game->wall_one.img,
			&game->wall_one.bpp, &game->wall_one.line, &game->wall_one.endian);
	game->wall_mid.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_mid.xpm",
			&game->wall_mid.width, &game->wall_mid.height);
	game->wall_mid.addr = mlx_get_data_addr(game->wall_mid.img,
			&game->wall_mid.bpp, &game->wall_mid.line, &game->wall_mid.endian);
	game->wall_top.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_top.xpm",
			&game->wall_top.width, &game->wall_top.height);
	game->wall_top.addr = mlx_get_data_addr(game->wall_top.img,
			&game->wall_top.bpp, &game->wall_top.line, &game->wall_top.endian);
	game->wall_bot.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_bot.xpm",
			&game->wall_bot.width, &game->wall_bot.height);
	game->wall_bot.addr = mlx_get_data_addr(game->wall_bot.img,
			&game->wall_bot.bpp, &game->wall_bot.line, &game->wall_bot.endian);
}

void	get_images_mobs(t_game *game)
{
	game->mario.img = mlx_xpm_file_to_image(game->mlx, "xpm/mario.xpm",
			&game->mario.width, &game->mario.height);
	game->mario.addr = mlx_get_data_addr(game->mario.img,
			&game->mario.bpp, &game->mario.line, &game->mario.endian);
	game->goomba.img = mlx_xpm_file_to_image(game->mlx, "xpm/goomba.xpm",
			&game->goomba.width, &game->goomba.height);
	game->goomba.addr = mlx_get_data_addr(game->goomba.img,
			&game->goomba.bpp, &game->goomba.line, &game->goomba.endian);
	game->goomba_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/goomba_b.xpm",
			&game->goomba_b.width, &game->goomba_b.height);
	game->goomba_b.addr = mlx_get_data_addr(game->goomba_b.img,
			&game->goomba_b.bpp, &game->goomba_b.line, &game->goomba_b.endian);
	game->goomba_g.img = mlx_xpm_file_to_image(game->mlx, "xpm/goomba_g.xpm",
			&game->goomba_g.width, &game->goomba_g.height);
	game->goomba_g.addr = mlx_get_data_addr(game->goomba_g.img,
			&game->goomba_g.bpp, &game->goomba_g.line, &game->goomba_g.endian);
	game->goomba_r.img = mlx_xpm_file_to_image(game->mlx, "xpm/goomba_r.xpm",
			&game->goomba_r.width, &game->goomba_r.height);
	game->goomba_r.addr = mlx_get_data_addr(game->goomba_r.img,
			&game->goomba_r.bpp, &game->goomba_r.line, &game->goomba_r.endian);
}

void	get_images_collectibles(t_game *game)
{
	game->mushroom.img = mlx_xpm_file_to_image(game->mlx, "xpm/mushroom.xpm",
			&game->mushroom.width, &game->mushroom.height);
	game->mushroom.addr = mlx_get_data_addr(game->mushroom.img,
			&game->mushroom.bpp, &game->mushroom.line, &game->mushroom.endian);
	game->star.img = mlx_xpm_file_to_image(game->mlx, "xpm/star.xpm",
			&game->star.width, &game->star.height);
	game->star.addr = mlx_get_data_addr(game->star.img,
			&game->star.bpp, &game->star.line, &game->star.endian);
}

void	get_images(t_game *game)
{
	get_images_environnement(game);
	get_images_mobs(game);
	get_images_collectibles(game);
}
