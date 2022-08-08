/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:08:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/08 15:45:12 by ilandols         ###   ########.fr       */
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

	game->m_hammer_b_left_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_b_left_light.xpm",
			&game->m_hammer_b_left_light.width, &game->m_hammer_b_left_light.height);
	game->m_hammer_b_left_light_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_b_left_light_2.xpm",
			&game->m_hammer_b_left_light_2.width, &game->m_hammer_b_left_light_2.height);
	game->m_hammer_b_right.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_b_right.xpm",
			&game->m_hammer_b_right.width, &game->m_hammer_b_right.height);
	game->m_hammer_b_right_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_b_right_2.xpm",
			&game->m_hammer_b_right_2.width, &game->m_hammer_b_right_2.height);
	game->m_hammer_left_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left_light.xpm",
			&game->m_hammer_left_light.width, &game->m_hammer_left_light.height);
	game->m_hammer_left_light_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left_light_2.xpm",
			&game->m_hammer_left_light_2.width, &game->m_hammer_left_light_2.height);
	game->m_hammer_left_light_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left_light_3.xpm",
			&game->m_hammer_left_light_3.width, &game->m_hammer_left_light_3.height);
	game->m_hammer_right.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right.xpm",
			&game->m_hammer_right.width, &game->m_hammer_right.height);
	game->m_hammer_right_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right_2.xpm",
			&game->m_hammer_right_2.width, &game->m_hammer_right_2.height);
	game->m_hammer_right_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right_3.xpm",
			&game->m_hammer_right_3.width, &game->m_hammer_right_3.height);
	game->m_static_b_left_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_b_left_light.xpm",
			&game->m_static_b_left_light.width, &game->m_static_b_left_light.height);
	game->m_static_b_right.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_b_right.xpm",
			&game->m_static_b_right.width, &game->m_static_b_right.height);
	game->m_static_left_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_left_light.xpm",
			&game->m_static_left_light.width, &game->m_static_left_light.height);
	game->m_static_right.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_right.xpm",
			&game->m_static_right.width, &game->m_static_right.height);
	game->m_walk_b_left_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_b_left_light.xpm",
			&game->m_walk_b_left_light.width, &game->m_walk_b_left_light.height);
	game->m_walk_b_left_light_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_b_left_light_2.xpm",
			&game->m_walk_b_left_light_2.width, &game->m_walk_b_left_light_2.height);
	game->m_walk_b_left_light_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_b_left_light_3.xpm",
			&game->m_walk_b_left_light_3.width, &game->m_walk_b_left_light_3.height);
	game->m_walk_b_right.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_b_right.xpm",
			&game->m_walk_b_right.width, &game->m_walk_b_right.height);
	game->m_walk_b_right_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_b_right_2.xpm",
			&game->m_walk_b_right_2.width, &game->m_walk_b_right_2.height);
	game->m_walk_b_right_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_b_right_3.xpm",
			&game->m_walk_b_right_3.width, &game->m_walk_b_right_3.height);
	game->m_walk_left.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_left.xpm",
			&game->m_walk_left.width, &game->m_walk_left.height);
	game->m_walk_left_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_left_2.xpm",
			&game->m_walk_left_2.width, &game->m_walk_left_2.height);
	game->m_walk_left_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_left_3.xpm",
			&game->m_walk_left_3.width, &game->m_walk_left_3.height);
	game->m_walk_right.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_right.xpm",
			&game->m_walk_right.width, &game->m_walk_right.height);
	game->m_walk_right_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_right_2.xpm",
			&game->m_walk_right_2.width, &game->m_walk_right_2.height);
	game->m_walk_right_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_right_3.xpm",
			&game->m_walk_right_3.width, &game->m_walk_right_3.height);
	game->c.img = mlx_xpm_file_to_image(game->mlx, "xpm/c.xpm",
			&game->c.width, &game->c.height);
	game->c_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/c_2.xpm",
			&game->c_2.width, &game->c_2.height);
	game->c_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/c_3.xpm",
			&game->c_3.width, &game->c_3.height);
	game->c_4.img = mlx_xpm_file_to_image(game->mlx, "xpm/c_4.xpm",
			&game->c_4.width, &game->c_4.height);
	game->hammer.img = mlx_xpm_file_to_image(game->mlx, "xpm/hammer.xpm",
			&game->hammer.width, &game->hammer.height);
	game->s.img = mlx_xpm_file_to_image(game->mlx, "xpm/s.xpm",
			&game->s.width, &game->s.height);
	game->s_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_2.xpm",
			&game->s_2.width, &game->s_2.height);
	game->s_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_3.xpm",
			&game->s_3.width, &game->s_3.height);
	game->s_spawn.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn.xpm",
			&game->s_spawn.width, &game->s_spawn.height);
	game->s_spawn_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_2.xpm",
			&game->s_spawn_2.width, &game->s_spawn_2.height);
	game->s_spawn_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_3.xpm",
			&game->s_spawn_3.width, &game->s_spawn_3.height);
	game->s_spawn_4.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_4.xpm",
			&game->s_spawn_4.width, &game->s_spawn_4.height);
	game->s_spawn_5.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_5.xpm",
			&game->s_spawn_5.width, &game->s_spawn_5.height);
	game->s_spawn_6.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_6.xpm",
			&game->s_spawn_6.width, &game->s_spawn_6.height);
	game->s_spawn_7.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_7.xpm",
			&game->s_spawn_7.width, &game->s_spawn_7.height);
	game->s_spawn_8.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_8.xpm",
			&game->s_spawn_8.width, &game->s_spawn_8.height);
	game->s_spawn_9.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_9.xpm",
			&game->s_spawn_9.width, &game->s_spawn_9.height);
	game->s_spawn_10.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_10.xpm",
			&game->s_spawn_10.width, &game->s_spawn_10.height);
	game->s_spawn_11.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_11.xpm",
			&game->s_spawn_11.width, &game->s_spawn_11.height);
	game->s_spawn_12.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_12.xpm",
			&game->s_spawn_12.width, &game->s_spawn_12.height);
	game->s_spawn_13.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_13.xpm",
			&game->s_spawn_13.width, &game->s_spawn_13.height);
	game->s_spawn_14.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_14.xpm",
			&game->s_spawn_14.width, &game->s_spawn_14.height);
	game->s_spawn_15.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_15.xpm",
			&game->s_spawn_15.width, &game->s_spawn_15.height);
	game->s_spawn_16.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_16.xpm",
			&game->s_spawn_16.width, &game->s_spawn_16.height);
	game->s_spawn_17.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_17.xpm",
			&game->s_spawn_17.width, &game->s_spawn_17.height);
	game->s_spawn_18.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_18.xpm",
			&game->s_spawn_18.width, &game->s_spawn_18.height);
	game->s_spawn_19.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_19.xpm",
			&game->s_spawn_19.width, &game->s_spawn_19.height);
	game->s_spawn_20.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_spawn_20.xpm",
			&game->s_spawn_20.width, &game->s_spawn_20.height);
	game->g.img = mlx_xpm_file_to_image(game->mlx, "xpm/g.xpm",
			&game->g.width, &game->g.height);
	game->g_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/g_2.xpm",
			&game->g_2.width, &game->g_2.height);
	game->g_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/g_3.xpm",
			&game->g_3.width, &game->g_3.height);
	game->g_death.img = mlx_xpm_file_to_image(game->mlx, "xpm/g_death.xpm",
			&game->g_death.width, &game->g_death.height);
	game->g_death_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/g_death_2.xpm",
			&game->g_death_2.width, &game->g_death_2.height);
	game->gb.img = mlx_xpm_file_to_image(game->mlx, "xpm/gb.xpm",
			&game->gb.width, &game->gb.height);
	game->gb_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/gb_2.xpm",
			&game->gb_2.width, &game->gb_2.height);
	game->gb_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/gb_3.xpm",
			&game->gb_3.width, &game->gb_3.height);
	game->gr.img = mlx_xpm_file_to_image(game->mlx, "xpm/gr.xpm",
			&game->gr.width, &game->gr.height);
	game->gr_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/gr_2.xpm",
			&game->gr_2.width, &game->gr_2.height);
	game->gr_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/gr_3.xpm",
			&game->gr_3.width, &game->gr_3.height);
	game->grass_shadow.img = mlx_xpm_file_to_image(game->mlx, "xpm/grass_shadow.xpm",
			&game->grass_shadow.width, &game->grass_shadow.height);
	game->wall_one_shadow.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_one_shadow.xpm",
			&game->wall_one_shadow.width, &game->wall_one_shadow.height);
	game->wall_mid_shadow.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_mid_shadow.xpm",
			&game->wall_mid_shadow.width, &game->wall_mid_shadow.height);
	game->wall_top_shadow.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_top_shadow.xpm",
			&game->wall_top_shadow.width, &game->wall_top_shadow.height);
	game->wall_bot_shadow.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_bot_shadow.xpm",
			&game->wall_bot_shadow.width, &game->wall_bot_shadow.height);
	game->m_hammer_b_left.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_b_left.xpm",
			&game->m_hammer_b_left.width, &game->m_hammer_b_left.height);
	game->m_hammer_b_left_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_b_left_2.xpm",
			&game->m_hammer_b_left_2.width, &game->m_hammer_b_left_2.height);
	game->m_hammer_b_right_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_b_right_light.xpm",
			&game->m_hammer_b_right_light.width, &game->m_hammer_b_right_light.height);
	game->m_hammer_b_right_light_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_b_right_light_2.xpm",
			&game->m_hammer_b_right_light_2.width, &game->m_hammer_b_right_light_2.height);
	game->m_hammer_left.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left.xpm",
			&game->m_hammer_left.width, &game->m_hammer_left.height);
	game->m_hammer_left_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left_2.xpm",
			&game->m_hammer_left_2.width, &game->m_hammer_left_2.height);
	game->m_hammer_left_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left_3.xpm",
			&game->m_hammer_left_3.width, &game->m_hammer_left_3.height);
	game->m_hammer_right_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right_light.xpm",
			&game->m_hammer_right_light.width, &game->m_hammer_right_light.height);
	game->m_hammer_right_light_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right_light_2.xpm",
			&game->m_hammer_right_light_2.width, &game->m_hammer_right_light_2.height);
	game->m_hammer_right_light_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right_light_3.xpm",
			&game->m_hammer_right_light_3.width, &game->m_hammer_right_light_3.height);
	game->m_static_b_left.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_b_left.xpm",
			&game->m_static_b_left.width, &game->m_static_b_left.height);
	game->m_static_b_right_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_b_right_light.xpm",
			&game->m_static_b_right_light.width, &game->m_static_b_right_light.height);
	game->m_static_left.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_left.xpm",
			&game->m_static_left.width, &game->m_static_left.height);
	game->m_static_right_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_right_light.xpm",
			&game->m_static_right_light.width, &game->m_static_right_light.height);
	game->m_walk_b_left.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_b_left.xpm",
			&game->m_walk_b_left.width, &game->m_walk_b_left.height);
	game->m_walk_b_left_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_b_left_2.xpm",
			&game->m_walk_b_left_2.width, &game->m_walk_b_left_2.height);
	game->m_walk_b_left_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_b_left_3.xpm",
			&game->m_walk_b_left_3.width, &game->m_walk_b_left_3.height);
	game->m_walk_b_right_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_b_right_light.xpm",
			&game->m_walk_b_right_light.width, &game->m_walk_b_right_light.height);
	game->m_walk_b_right_light_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_b_right_light_2.xpm",
			&game->m_walk_b_right_light_2.width, &game->m_walk_b_right_light_2.height);
	game->m_walk_b_right_light_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_b_right_light_3.xpm",
			&game->m_walk_b_right_light_3.width, &game->m_walk_b_right_light_3.height);
	game->m_walk_left_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_left_light.xpm",
			&game->m_walk_left_light.width, &game->m_walk_left_light.height);
	game->m_walk_left_light_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_left_light_2.xpm",
			&game->m_walk_left_light_2.width, &game->m_walk_left_light_2.height);
	game->m_walk_left_light_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_left_light_3.xpm",
			&game->m_walk_left_light_3.width, &game->m_walk_left_light_3.height);
	game->m_walk_right_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_right_light.xpm",
			&game->m_walk_right_light.width, &game->m_walk_right_light.height);
	game->m_walk_right_light_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_right_light_2.xpm",
			&game->m_walk_right_light_2.width, &game->m_walk_right_light_2.height);
	game->m_walk_right_light_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_right_light_3.xpm",
			&game->m_walk_right_light_3.width, &game->m_walk_right_light_3.height);



	game->screen.img = mlx_new_image(game->mlx,
			game->x_map * CELL, game->y_map * CELL);
}
