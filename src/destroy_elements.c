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

	mlx_destroy_image(game->mlx, game->m_hammer_b_left.img);
	mlx_destroy_image(game->mlx, game->m_hammer_b_left_2.img);
	mlx_destroy_image(game->mlx, game->m_hammer_b_right.img);
	mlx_destroy_image(game->mlx, game->m_hammer_b_right_2.img);
	mlx_destroy_image(game->mlx, game->m_hammer_left.img);
	mlx_destroy_image(game->mlx, game->m_hammer_left_2.img);
	mlx_destroy_image(game->mlx, game->m_hammer_left_3.img);
	mlx_destroy_image(game->mlx, game->m_hammer_right.img);
	mlx_destroy_image(game->mlx, game->m_hammer_right_2.img);
	mlx_destroy_image(game->mlx, game->m_hammer_right_3.img);
	mlx_destroy_image(game->mlx, game->m_static_b_left.img);
	mlx_destroy_image(game->mlx, game->m_static_b_right.img);
	mlx_destroy_image(game->mlx, game->m_static_left.img);
	mlx_destroy_image(game->mlx, game->m_static_right.img);
	mlx_destroy_image(game->mlx, game->m_walk_b_left.img);
	mlx_destroy_image(game->mlx, game->m_walk_b_left_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_b_left_3.img);
	mlx_destroy_image(game->mlx, game->m_walk_b_right.img);
	mlx_destroy_image(game->mlx, game->m_walk_b_right_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_b_right_3.img);
	mlx_destroy_image(game->mlx, game->m_walk_left.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_3.img);
	mlx_destroy_image(game->mlx, game->m_walk_right.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_3.img);
	mlx_destroy_image(game->mlx, game->c.img);
	mlx_destroy_image(game->mlx, game->c_2.img);
	mlx_destroy_image(game->mlx, game->c_3.img);
	mlx_destroy_image(game->mlx, game->c_4.img);
	mlx_destroy_image(game->mlx, game->hammer.img);
	mlx_destroy_image(game->mlx, game->s.img);
	mlx_destroy_image(game->mlx, game->s_2.img);
	mlx_destroy_image(game->mlx, game->s_3.img);
	mlx_destroy_image(game->mlx, game->s_spawn.img);
	mlx_destroy_image(game->mlx, game->s_spawn_2.img);
	mlx_destroy_image(game->mlx, game->s_spawn_3.img);
	mlx_destroy_image(game->mlx, game->s_spawn_4.img);
	mlx_destroy_image(game->mlx, game->s_spawn_5.img);
	mlx_destroy_image(game->mlx, game->s_spawn_6.img);
	mlx_destroy_image(game->mlx, game->s_spawn_7.img);
	mlx_destroy_image(game->mlx, game->s_spawn_8.img);
	mlx_destroy_image(game->mlx, game->s_spawn_9.img);
	mlx_destroy_image(game->mlx, game->s_spawn_10.img);
	mlx_destroy_image(game->mlx, game->s_spawn_11.img);
	mlx_destroy_image(game->mlx, game->s_spawn_12.img);
	mlx_destroy_image(game->mlx, game->s_spawn_13.img);
	mlx_destroy_image(game->mlx, game->s_spawn_14.img);
	mlx_destroy_image(game->mlx, game->s_spawn_15.img);
	mlx_destroy_image(game->mlx, game->s_spawn_16.img);
	mlx_destroy_image(game->mlx, game->s_spawn_17.img);
	mlx_destroy_image(game->mlx, game->s_spawn_18.img);
	mlx_destroy_image(game->mlx, game->s_spawn_19.img);
	mlx_destroy_image(game->mlx, game->s_spawn_20.img);
	mlx_destroy_image(game->mlx, game->g.img);
	mlx_destroy_image(game->mlx, game->g_2.img);
	mlx_destroy_image(game->mlx, game->g_3.img);
	mlx_destroy_image(game->mlx, game->g_death.img);
	mlx_destroy_image(game->mlx, game->g_death_2.img);
	mlx_destroy_image(game->mlx, game->gb.img);
	mlx_destroy_image(game->mlx, game->gb_2.img);
	mlx_destroy_image(game->mlx, game->gb_3.img);
	mlx_destroy_image(game->mlx, game->gr.img);
	mlx_destroy_image(game->mlx, game->gr_2.img);
	mlx_destroy_image(game->mlx, game->gr_3.img);
	mlx_destroy_image(game->mlx, game->grass_shadow.img);
	mlx_destroy_image(game->mlx, game->wall_one_shadow.img);
	mlx_destroy_image(game->mlx, game->wall_mid_shadow.img);
	mlx_destroy_image(game->mlx, game->wall_top_shadow.img);
	mlx_destroy_image(game->mlx, game->wall_bot_shadow.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_light.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_light_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_light_3.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_light.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_light_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_light_3.img);




	mlx_destroy_image(game->mlx, game->screen.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free_array(game->map);
	free(game->mlx);
	system("pkill vlc");
}
