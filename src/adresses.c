/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adresses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:50:15 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/14 17:56:34 by ilandols         ###   ########.fr       */
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
	/* while */
}

void	get_adresses_collectibles(t_game *game)
{
	/* while */
}

void	get_adresses(t_game *game)
{
	get_adresses_environnement(game);
	get_adresses_mobs(game);
	get_adresses_collectibles(game);
	game->screen.addr = mlx_get_data_addr(game->screen.img, 
            &game->screen.bpp, &game->screen.line, &game->screen.endian);

	game->m_hammer_b_left_light.addr = mlx_get_data_addr(game->m_hammer_b_left_light.img, 
            &game->m_hammer_b_left_light.bpp, &game->m_hammer_b_left_light.line, &game->m_hammer_b_left_light.endian);
	game->m_hammer_b_left_light_2.addr = mlx_get_data_addr(game->m_hammer_b_left_light_2.img, 
            &game->m_hammer_b_left_light_2.bpp, &game->m_hammer_b_left_light_2.line, &game->m_hammer_b_left_light_2.endian);
	game->m_hammer_b_right.addr = mlx_get_data_addr(game->m_hammer_b_right.img, 
            &game->m_hammer_b_right.bpp, &game->m_hammer_b_right.line, &game->m_hammer_b_right.endian);
	game->m_hammer_b_right_2.addr = mlx_get_data_addr(game->m_hammer_b_right_2.img, 
            &game->m_hammer_b_right_2.bpp, &game->m_hammer_b_right_2.line, &game->m_hammer_b_right_2.endian);
	game->m_hammer_left_light.addr = mlx_get_data_addr(game->m_hammer_left_light.img, 
            &game->m_hammer_left_light.bpp, &game->m_hammer_left_light.line, &game->m_hammer_left_light.endian);
	game->m_hammer_left_light_2.addr = mlx_get_data_addr(game->m_hammer_left_light_2.img, 
            &game->m_hammer_left_light_2.bpp, &game->m_hammer_left_light_2.line, &game->m_hammer_left_light_2.endian);
	game->m_hammer_left_light_3.addr = mlx_get_data_addr(game->m_hammer_left_light_3.img, 
            &game->m_hammer_left_light_3.bpp, &game->m_hammer_left_light_3.line, &game->m_hammer_left_light_3.endian);
	game->m_hammer_right.addr = mlx_get_data_addr(game->m_hammer_right.img, 
            &game->m_hammer_right.bpp, &game->m_hammer_right.line, &game->m_hammer_right.endian);
	game->m_hammer_right_2.addr = mlx_get_data_addr(game->m_hammer_right_2.img, 
            &game->m_hammer_right_2.bpp, &game->m_hammer_right_2.line, &game->m_hammer_right_2.endian);
	game->m_hammer_right_3.addr = mlx_get_data_addr(game->m_hammer_right_3.img, 
            &game->m_hammer_right_3.bpp, &game->m_hammer_right_3.line, &game->m_hammer_right_3.endian);
	game->m_static_b_left_light.addr = mlx_get_data_addr(game->m_static_b_left_light.img, 
            &game->m_static_b_left_light.bpp, &game->m_static_b_left_light.line, &game->m_static_b_left_light.endian);
	game->m_static_b_right.addr = mlx_get_data_addr(game->m_static_b_right.img, 
            &game->m_static_b_right.bpp, &game->m_static_b_right.line, &game->m_static_b_right.endian);
	game->m_static_left_light.addr = mlx_get_data_addr(game->m_static_left_light.img, 
            &game->m_static_left_light.bpp, &game->m_static_left_light.line, &game->m_static_left_light.endian);
	game->m_static_right.addr = mlx_get_data_addr(game->m_static_right.img, 
            &game->m_static_right.bpp, &game->m_static_right.line, &game->m_static_right.endian);
	game->m_walk_b_left_light.addr = mlx_get_data_addr(game->m_walk_b_left_light.img, 
            &game->m_walk_b_left_light.bpp, &game->m_walk_b_left_light.line, &game->m_walk_b_left_light.endian);
	game->m_walk_b_left_light_2.addr = mlx_get_data_addr(game->m_walk_b_left_light_2.img, 
            &game->m_walk_b_left_light_2.bpp, &game->m_walk_b_left_light_2.line, &game->m_walk_b_left_light_2.endian);
	game->m_walk_b_left_light_3.addr = mlx_get_data_addr(game->m_walk_b_left_light_3.img, 
            &game->m_walk_b_left_light_3.bpp, &game->m_walk_b_left_light_3.line, &game->m_walk_b_left_light_3.endian);
	game->m_walk_b_right.addr = mlx_get_data_addr(game->m_walk_b_right.img, 
            &game->m_walk_b_right.bpp, &game->m_walk_b_right.line, &game->m_walk_b_right.endian);
	game->m_walk_b_right_2.addr = mlx_get_data_addr(game->m_walk_b_right_2.img, 
            &game->m_walk_b_right_2.bpp, &game->m_walk_b_right_2.line, &game->m_walk_b_right_2.endian);
	game->m_walk_b_right_3.addr = mlx_get_data_addr(game->m_walk_b_right_3.img, 
            &game->m_walk_b_right_3.bpp, &game->m_walk_b_right_3.line, &game->m_walk_b_right_3.endian);
	game->m_walk_left.addr = mlx_get_data_addr(game->m_walk_left.img, 
            &game->m_walk_left.bpp, &game->m_walk_left.line, &game->m_walk_left.endian);
	game->m_walk_left_2.addr = mlx_get_data_addr(game->m_walk_left_2.img, 
            &game->m_walk_left_2.bpp, &game->m_walk_left_2.line, &game->m_walk_left_2.endian);
	game->m_walk_left_3.addr = mlx_get_data_addr(game->m_walk_left_3.img, 
            &game->m_walk_left_3.bpp, &game->m_walk_left_3.line, &game->m_walk_left_3.endian);
	game->m_walk_right.addr = mlx_get_data_addr(game->m_walk_right.img, 
            &game->m_walk_right.bpp, &game->m_walk_right.line, &game->m_walk_right.endian);
	game->m_walk_right_2.addr = mlx_get_data_addr(game->m_walk_right_2.img, 
            &game->m_walk_right_2.bpp, &game->m_walk_right_2.line, &game->m_walk_right_2.endian);
	game->m_walk_right_3.addr = mlx_get_data_addr(game->m_walk_right_3.img, 
            &game->m_walk_right_3.bpp, &game->m_walk_right_3.line, &game->m_walk_right_3.endian);
	game->c.addr = mlx_get_data_addr(game->c.img, 
            &game->c.bpp, &game->c.line, &game->c.endian);
	game->c_2.addr = mlx_get_data_addr(game->c_2.img, 
            &game->c_2.bpp, &game->c_2.line, &game->c_2.endian);
	game->c_3.addr = mlx_get_data_addr(game->c_3.img, 
            &game->c_3.bpp, &game->c_3.line, &game->c_3.endian);
	game->c_4.addr = mlx_get_data_addr(game->c_4.img, 
            &game->c_4.bpp, &game->c_4.line, &game->c_4.endian);
	game->hammer.addr = mlx_get_data_addr(game->hammer.img, 
            &game->hammer.bpp, &game->hammer.line, &game->hammer.endian);
	game->s.addr = mlx_get_data_addr(game->s.img, 
            &game->s.bpp, &game->s.line, &game->s.endian);
	game->s_2.addr = mlx_get_data_addr(game->s_2.img, 
            &game->s_2.bpp, &game->s_2.line, &game->s_2.endian);
	game->s_3.addr = mlx_get_data_addr(game->s_3.img, 
            &game->s_3.bpp, &game->s_3.line, &game->s_3.endian);
	game->s_spawn.addr = mlx_get_data_addr(game->s_spawn.img, 
            &game->s_spawn.bpp, &game->s_spawn.line, &game->s_spawn.endian);
	game->s_spawn_2.addr = mlx_get_data_addr(game->s_spawn_2.img, 
            &game->s_spawn_2.bpp, &game->s_spawn_2.line, &game->s_spawn_2.endian);
	game->s_spawn_3.addr = mlx_get_data_addr(game->s_spawn_3.img, 
            &game->s_spawn_3.bpp, &game->s_spawn_3.line, &game->s_spawn_3.endian);
	game->s_spawn_4.addr = mlx_get_data_addr(game->s_spawn_4.img, 
            &game->s_spawn_4.bpp, &game->s_spawn_4.line, &game->s_spawn_4.endian);
	game->s_spawn_5.addr = mlx_get_data_addr(game->s_spawn_5.img, 
            &game->s_spawn_5.bpp, &game->s_spawn_5.line, &game->s_spawn_5.endian);
	game->s_spawn_6.addr = mlx_get_data_addr(game->s_spawn_6.img, 
            &game->s_spawn_6.bpp, &game->s_spawn_6.line, &game->s_spawn_6.endian);
	game->s_spawn_7.addr = mlx_get_data_addr(game->s_spawn_7.img, 
            &game->s_spawn_7.bpp, &game->s_spawn_7.line, &game->s_spawn_7.endian);
	game->s_spawn_8.addr = mlx_get_data_addr(game->s_spawn_8.img, 
            &game->s_spawn_8.bpp, &game->s_spawn_8.line, &game->s_spawn_8.endian);
	game->s_spawn_9.addr = mlx_get_data_addr(game->s_spawn_9.img, 
            &game->s_spawn_9.bpp, &game->s_spawn_9.line, &game->s_spawn_9.endian);
	game->s_spawn_10.addr = mlx_get_data_addr(game->s_spawn_10.img, 
            &game->s_spawn_10.bpp, &game->s_spawn_10.line, &game->s_spawn_10.endian);
	game->s_spawn_11.addr = mlx_get_data_addr(game->s_spawn_11.img, 
            &game->s_spawn_11.bpp, &game->s_spawn_11.line, &game->s_spawn_11.endian);
	game->s_spawn_12.addr = mlx_get_data_addr(game->s_spawn_12.img, 
            &game->s_spawn_12.bpp, &game->s_spawn_12.line, &game->s_spawn_12.endian);
	game->s_spawn_13.addr = mlx_get_data_addr(game->s_spawn_13.img, 
            &game->s_spawn_13.bpp, &game->s_spawn_13.line, &game->s_spawn_13.endian);
	game->s_spawn_14.addr = mlx_get_data_addr(game->s_spawn_14.img, 
            &game->s_spawn_14.bpp, &game->s_spawn_14.line, &game->s_spawn_14.endian);
	game->s_spawn_15.addr = mlx_get_data_addr(game->s_spawn_15.img, 
            &game->s_spawn_15.bpp, &game->s_spawn_15.line, &game->s_spawn_15.endian);
	game->s_spawn_16.addr = mlx_get_data_addr(game->s_spawn_16.img, 
            &game->s_spawn_16.bpp, &game->s_spawn_16.line, &game->s_spawn_16.endian);
	game->s_spawn_17.addr = mlx_get_data_addr(game->s_spawn_17.img, 
            &game->s_spawn_17.bpp, &game->s_spawn_17.line, &game->s_spawn_17.endian);
	game->s_spawn_18.addr = mlx_get_data_addr(game->s_spawn_18.img, 
            &game->s_spawn_18.bpp, &game->s_spawn_18.line, &game->s_spawn_18.endian);
	game->s_spawn_19.addr = mlx_get_data_addr(game->s_spawn_19.img, 
            &game->s_spawn_19.bpp, &game->s_spawn_19.line, &game->s_spawn_19.endian);
	game->s_spawn_20.addr = mlx_get_data_addr(game->s_spawn_20.img, 
            &game->s_spawn_20.bpp, &game->s_spawn_20.line, &game->s_spawn_20.endian);
	game->g.addr = mlx_get_data_addr(game->g.img, 
            &game->g.bpp, &game->g.line, &game->g.endian);
	game->g_2.addr = mlx_get_data_addr(game->g_2.img, 
            &game->g_2.bpp, &game->g_2.line, &game->g_2.endian);
	game->g_3.addr = mlx_get_data_addr(game->g_3.img, 
            &game->g_3.bpp, &game->g_3.line, &game->g_3.endian);
	game->g_death.addr = mlx_get_data_addr(game->g_death.img, 
            &game->g_death.bpp, &game->g_death.line, &game->g_death.endian);
	game->g_death_2.addr = mlx_get_data_addr(game->g_death_2.img, 
            &game->g_death_2.bpp, &game->g_death_2.line, &game->g_death_2.endian);
	game->gb.addr = mlx_get_data_addr(game->gb.img, 
            &game->gb.bpp, &game->gb.line, &game->gb.endian);
	game->gb_2.addr = mlx_get_data_addr(game->gb_2.img, 
            &game->gb_2.bpp, &game->gb_2.line, &game->gb_2.endian);
	game->gb_3.addr = mlx_get_data_addr(game->gb_3.img, 
            &game->gb_3.bpp, &game->gb_3.line, &game->gb_3.endian);
	game->gr.addr = mlx_get_data_addr(game->gr.img, 
            &game->gr.bpp, &game->gr.line, &game->gr.endian);
	game->gr_2.addr = mlx_get_data_addr(game->gr_2.img, 
            &game->gr_2.bpp, &game->gr_2.line, &game->gr_2.endian);
	game->gr_3.addr = mlx_get_data_addr(game->gr_3.img, 
            &game->gr_3.bpp, &game->gr_3.line, &game->gr_3.endian);
	game->grass_shadow.addr = mlx_get_data_addr(game->grass_shadow.img, 
            &game->grass_shadow.bpp, &game->grass_shadow.line, &game->grass_shadow.endian);
	game->wall_one_shadow.addr = mlx_get_data_addr(game->wall_one_shadow.img, 
            &game->wall_one_shadow.bpp, &game->wall_one_shadow.line, &game->wall_one_shadow.endian);
	game->wall_mid_shadow.addr = mlx_get_data_addr(game->wall_mid_shadow.img, 
            &game->wall_mid_shadow.bpp, &game->wall_mid_shadow.line, &game->wall_mid_shadow.endian);
	game->wall_top_shadow.addr = mlx_get_data_addr(game->wall_top_shadow.img, 
            &game->wall_top_shadow.bpp, &game->wall_top_shadow.line, &game->wall_top_shadow.endian);
	game->wall_bot_shadow.addr = mlx_get_data_addr(game->wall_bot_shadow.img, 
            &game->wall_bot_shadow.bpp, &game->wall_bot_shadow.line, &game->wall_bot_shadow.endian);
	game->m_hammer_b_left.addr = mlx_get_data_addr(game->m_hammer_b_left.img, 
            &game->m_hammer_b_left.bpp, &game->m_hammer_b_left.line, &game->m_hammer_b_left.endian);
	game->m_hammer_b_left_2.addr = mlx_get_data_addr(game->m_hammer_b_left_2.img, 
            &game->m_hammer_b_left_2.bpp, &game->m_hammer_b_left_2.line, &game->m_hammer_b_left_2.endian);
	game->m_hammer_b_right_light.addr = mlx_get_data_addr(game->m_hammer_b_right_light.img, 
            &game->m_hammer_b_right_light.bpp, &game->m_hammer_b_right_light.line, &game->m_hammer_b_right_light.endian);
	game->m_hammer_b_right_light_2.addr = mlx_get_data_addr(game->m_hammer_b_right_light_2.img, 
            &game->m_hammer_b_right_light_2.bpp, &game->m_hammer_b_right_light_2.line, &game->m_hammer_b_right_light_2.endian);
	game->m_hammer_left.addr = mlx_get_data_addr(game->m_hammer_left.img, 
            &game->m_hammer_left.bpp, &game->m_hammer_left.line, &game->m_hammer_left.endian);
	game->m_hammer_left_2.addr = mlx_get_data_addr(game->m_hammer_left_2.img, 
            &game->m_hammer_left_2.bpp, &game->m_hammer_left_2.line, &game->m_hammer_left_2.endian);
	game->m_hammer_left_3.addr = mlx_get_data_addr(game->m_hammer_left_3.img, 
            &game->m_hammer_left_3.bpp, &game->m_hammer_left_3.line, &game->m_hammer_left_3.endian);
	game->m_hammer_right_light.addr = mlx_get_data_addr(game->m_hammer_right_light.img, 
            &game->m_hammer_right_light.bpp, &game->m_hammer_right_light.line, &game->m_hammer_right_light.endian);
	game->m_hammer_right_light_2.addr = mlx_get_data_addr(game->m_hammer_right_light_2.img, 
            &game->m_hammer_right_light_2.bpp, &game->m_hammer_right_light_2.line, &game->m_hammer_right_light_2.endian);
	game->m_hammer_right_light_3.addr = mlx_get_data_addr(game->m_hammer_right_light_3.img, 
            &game->m_hammer_right_light_3.bpp, &game->m_hammer_right_light_3.line, &game->m_hammer_right_light_3.endian);
	game->m_static_b_left.addr = mlx_get_data_addr(game->m_static_b_left.img, 
            &game->m_static_b_left.bpp, &game->m_static_b_left.line, &game->m_static_b_left.endian);
	game->m_static_b_right_light.addr = mlx_get_data_addr(game->m_static_b_right_light.img, 
            &game->m_static_b_right_light.bpp, &game->m_static_b_right_light.line, &game->m_static_b_right_light.endian);
	game->m_static_left.addr = mlx_get_data_addr(game->m_static_left.img, 
            &game->m_static_left.bpp, &game->m_static_left.line, &game->m_static_left.endian);
	game->m_static_right_light.addr = mlx_get_data_addr(game->m_static_right_light.img, 
            &game->m_static_right_light.bpp, &game->m_static_right_light.line, &game->m_static_right_light.endian);
	game->m_walk_b_left.addr = mlx_get_data_addr(game->m_walk_b_left.img, 
            &game->m_walk_b_left.bpp, &game->m_walk_b_left.line, &game->m_walk_b_left.endian);
	game->m_walk_b_left_2.addr = mlx_get_data_addr(game->m_walk_b_left_2.img, 
            &game->m_walk_b_left_2.bpp, &game->m_walk_b_left_2.line, &game->m_walk_b_left_2.endian);
	game->m_walk_b_left_3.addr = mlx_get_data_addr(game->m_walk_b_left_3.img, 
            &game->m_walk_b_left_3.bpp, &game->m_walk_b_left_3.line, &game->m_walk_b_left_3.endian);
	game->m_walk_b_right_light.addr = mlx_get_data_addr(game->m_walk_b_right_light.img, 
            &game->m_walk_b_right_light.bpp, &game->m_walk_b_right_light.line, &game->m_walk_b_right_light.endian);
	game->m_walk_b_right_light_2.addr = mlx_get_data_addr(game->m_walk_b_right_light_2.img, 
            &game->m_walk_b_right_light_2.bpp, &game->m_walk_b_right_light_2.line, &game->m_walk_b_right_light_2.endian);
	game->m_walk_b_right_light_3.addr = mlx_get_data_addr(game->m_walk_b_right_light_3.img, 
            &game->m_walk_b_right_light_3.bpp, &game->m_walk_b_right_light_3.line, &game->m_walk_b_right_light_3.endian);
	game->m_walk_left_light.addr = mlx_get_data_addr(game->m_walk_left_light.img, 
            &game->m_walk_left_light.bpp, &game->m_walk_left_light.line, &game->m_walk_left_light.endian);
	game->m_walk_left_light_2.addr = mlx_get_data_addr(game->m_walk_left_light_2.img, 
            &game->m_walk_left_light_2.bpp, &game->m_walk_left_light_2.line, &game->m_walk_left_light_2.endian);
	game->m_walk_left_light_3.addr = mlx_get_data_addr(game->m_walk_left_light_3.img, 
            &game->m_walk_left_light_3.bpp, &game->m_walk_left_light_3.line, &game->m_walk_left_light_3.endian);
	game->m_walk_right_light.addr = mlx_get_data_addr(game->m_walk_right_light.img, 
            &game->m_walk_right_light.bpp, &game->m_walk_right_light.line, &game->m_walk_right_light.endian);
	game->m_walk_right_light_2.addr = mlx_get_data_addr(game->m_walk_right_light_2.img, 
            &game->m_walk_right_light_2.bpp, &game->m_walk_right_light_2.line, &game->m_walk_right_light_2.endian);
	game->m_walk_right_light_3.addr = mlx_get_data_addr(game->m_walk_right_light_3.img, 
            &game->m_walk_right_light_3.bpp, &game->m_walk_right_light_3.line, &game->m_walk_right_light_3.endian);


}
