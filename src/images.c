/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:08:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/24 00:55:57 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_images_environnement(t_game *game)
{
	game->floor.img = mlx_xpm_file_to_image(game->mlx, "sprites/grass.xpm", &game->floor.width, &game->floor.height);
	game->floor.addr = mlx_get_data_addr(game->floor.img, &game->floor.bits_per_pixel, &game->floor.line_length, &game->floor.endian);
	game->wall_one.img = mlx_xpm_file_to_image(game->mlx, "sprites/wall_one.xpm", &game->wall_one.width, &game->wall_one.height);
	game->wall_one.addr = mlx_get_data_addr(game->wall_one.img, &game->wall_one.bits_per_pixel, &game->wall_one.line_length, &game->wall_one.endian);
	game->wall_mid.img = mlx_xpm_file_to_image(game->mlx, "sprites/wall_mid.xpm", &game->wall_mid.width, &game->wall_mid.height);
	game->wall_mid.addr = mlx_get_data_addr(game->wall_mid.img, &game->wall_mid.bits_per_pixel, &game->wall_mid.line_length, &game->wall_mid.endian);
	game->wall_top.img = mlx_xpm_file_to_image(game->mlx, "sprites/wall_top.xpm", &game->wall_top.width, &game->wall_top.height);
	game->wall_top.addr = mlx_get_data_addr(game->wall_top.img, &game->wall_top.bits_per_pixel, &game->wall_top.line_length, &game->wall_top.endian);
	game->wall_bot.img = mlx_xpm_file_to_image(game->mlx, "sprites/wall_bot.xpm", &game->wall_bot.width, &game->wall_bot.height);
	game->wall_bot.addr = mlx_get_data_addr(game->wall_bot.img, &game->wall_bot.bits_per_pixel, &game->wall_bot.line_length, &game->wall_bot.endian);
}

void	get_images_mobs(t_game *game)
{
	game->mario.img = mlx_xpm_file_to_image(game->mlx, "sprites/mario.xpm", &game->mario.width, &game->mario.height);
	game->mario.addr = mlx_get_data_addr(game->mario.img, &game->mario.bits_per_pixel, &game->mario.line_length, &game->mario.endian);
	game->goomba.img = mlx_xpm_file_to_image(game->mlx, "sprites/goomba.xpm", &game->goomba.width, &game->goomba.height);
	game->goomba.addr = mlx_get_data_addr(game->goomba.img, &game->goomba.bits_per_pixel, &game->goomba.line_length, &game->goomba.endian);
	game->goomba_b.img = mlx_xpm_file_to_image(game->mlx, "sprites/goomba_b.xpm", &game->goomba_b.width, &game->goomba_b.height);
	game->goomba_b.addr = mlx_get_data_addr(game->goomba_b.img, &game->goomba_b.bits_per_pixel, &game->goomba_b.line_length, &game->goomba_b.endian);
	game->goomba_g.img = mlx_xpm_file_to_image(game->mlx, "sprites/goomba_g.xpm", &game->goomba_g.width, &game->goomba_g.height);
	game->goomba_g.addr = mlx_get_data_addr(game->goomba_g.img, &game->goomba_g.bits_per_pixel, &game->goomba_g.line_length, &game->goomba_g.endian);
}

void	get_images_collectibles(t_game *game)
{
	game->mushroom.img = mlx_xpm_file_to_image(game->mlx, "sprites/mushroom.xpm", &game->mushroom.width, &game->mushroom.height);
	game->mushroom.addr = mlx_get_data_addr(game->mushroom.img, &game->mushroom.bits_per_pixel, &game->mushroom.line_length, &game->mushroom.endian);
	game->star.img = mlx_xpm_file_to_image(game->mlx, "sprites/star.xpm", &game->star.width, &game->star.height);
	game->star.addr = mlx_get_data_addr(game->star.img, &game->star.bits_per_pixel, &game->star.line_length, &game->star.endian);
}

void	get_images(t_game *game)
{
	get_images_environnement(game);
	get_images_mobs(game);
	get_images_collectibles(game);
}
