/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adresses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:50:15 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/01 18:56:14 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_adresses_environnement(t_game *game)
{
	game->grass.addr = mlx_get_data_addr(game->grass.img, 
            &game->grass.bpp, &game->grass.line, &game->grass.endian);
	game->wall_one.addr = mlx_get_data_addr(game->wall_one.img, 
            &game->wall_one.bpp, &game->wall_one.line, &game->wall_one.endian);
	game->wall_mid.addr = mlx_get_data_addr(game->wall_mid.img, 
            &game->wall_mid.bpp, &game->wall_mid.line, &game->wall_mid.endian);
	game->wall_top.addr = mlx_get_data_addr(game->wall_top.img, 
            &game->wall_top.bpp, &game->wall_top.line, &game->wall_top.endian);
	game->wall_bot.addr = mlx_get_data_addr(game->wall_bot.img, 
            &game->wall_bot.bpp, &game->wall_bot.line, &game->wall_bot.endian);
}

void	get_adresses_mobs(t_game *game)
{
	game->mario.addr = mlx_get_data_addr(game->mario.img, 
            &game->mario.bpp, &game->mario.line, &game->mario.endian);
	game->goomba.addr = mlx_get_data_addr(game->goomba.img, 
            &game->goomba.bpp, &game->goomba.line, &game->goomba.endian);
	game->goomba_b.addr = mlx_get_data_addr(game->goomba_b.img, 
            &game->goomba_b.bpp, &game->goomba_b.line, &game->goomba_b.endian);
	game->goomba_g.addr = mlx_get_data_addr(game->goomba_g.img, 
            &game->goomba_g.bpp, &game->goomba_g.line, &game->goomba_g.endian);
	game->goomba_r.addr = mlx_get_data_addr(game->goomba_r.img, 
            &game->goomba_r.bpp, &game->goomba_r.line, &game->goomba_r.endian);
}

void	get_adresses_collectibles(t_game *game)
{
	game->coin.addr = mlx_get_data_addr(game->coin.img, 
            &game->coin.bpp, &game->coin.line, &game->coin.endian);
	game->star.addr = mlx_get_data_addr(game->star.img, 
            &game->star.bpp, &game->star.line, &game->star.endian);
}

void	get_adresses(t_game *game)
{
	get_adresses_environnement(game);
	get_adresses_mobs(game);
	get_adresses_collectibles(game);
	game->screen.addr = mlx_get_data_addr(game->screen.img, 
            &game->screen.bpp, &game->screen.line, &game->screen.endian);
}
