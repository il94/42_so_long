/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:08:03 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/16 15:34:51 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_images_environnement(t_game *game)
{
	/* while */
}

void	get_images_mobs(t_game *game)
{
	/* while */
}

void	get_images_collectibles(t_game *game)
{
	/* while */
}

void	get_images(t_game *game)
{
	get_images_environnement(game);
	get_images_mobs(game);
	get_images_collectibles(game);
	
/*============================================================================*/

	game->e_grass.img = mlx_xpm_file_to_image(game->mlx, "xpm/e_grass.xpm",
			&game->e_grass.width, &game->e_grass.height);
	game->e_wall_one.img = mlx_xpm_file_to_image(game->mlx, "xpm/e_wall_one.xpm",
			&game->e_wall_one.width, &game->e_wall_one.height);
	game->e_wall_mid.img = mlx_xpm_file_to_image(game->mlx, "xpm/e_wall_mid.xpm",
			&game->e_wall_mid.width, &game->e_wall_mid.height);
	game->e_wall_top.img = mlx_xpm_file_to_image(game->mlx, "xpm/e_wall_top.xpm",
			&game->e_wall_top.width, &game->e_wall_top.height);
	game->e_wall_bot.img = mlx_xpm_file_to_image(game->mlx, "xpm/e_wall_bot.xpm",
			&game->e_wall_bot.width, &game->e_wall_bot.height);
	game->e_grass_shadow.img = mlx_xpm_file_to_image(game->mlx, "xpm/e_grass_shadow.xpm",
			&game->e_grass_shadow.width, &game->e_grass_shadow.height);
	game->e_wall_one_shadow.img = mlx_xpm_file_to_image(game->mlx, "xpm/e_wall_one_shadow.xpm",
			&game->e_wall_one_shadow.width, &game->e_wall_one_shadow.height);
	game->e_wall_mid_shadow.img = mlx_xpm_file_to_image(game->mlx, "xpm/e_wall_mid_shadow.xpm",
			&game->e_wall_mid_shadow.width, &game->e_wall_mid_shadow.height);
	game->e_wall_top_shadow.img = mlx_xpm_file_to_image(game->mlx, "xpm/e_wall_top_shadow.xpm",
			&game->e_wall_top_shadow.width, &game->e_wall_top_shadow.height);
	game->e_wall_bot_shadow.img = mlx_xpm_file_to_image(game->mlx, "xpm/e_wall_bot_shadow.xpm",
			&game->e_wall_bot_shadow.width, &game->e_wall_bot_shadow.height);

/*============================================================================*/

	game->m_jump_left.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_jump_left.xpm",
			&game->m_jump_left.width, &game->m_jump_left.height);
	game->m_jump_right.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_jump_right.xpm",
			&game->m_jump_right.width, &game->m_jump_right.height);
	game->m_hammer_left.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left.xpm",
			&game->m_hammer_left.width, &game->m_hammer_left.height);
	game->m_hammer_left_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left_2.xpm",
			&game->m_hammer_left_2.width, &game->m_hammer_left_2.height);
	game->m_hammer_right.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right.xpm",
			&game->m_hammer_right.width, &game->m_hammer_right.height);
	game->m_hammer_right_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right_2.xpm",
			&game->m_hammer_right_2.width, &game->m_hammer_right_2.height);
	game->m_jump_left_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_jump_left_light.xpm",
			&game->m_jump_left_light.width, &game->m_jump_left_light.height);
	game->m_jump_right_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_jump_right_light.xpm",
			&game->m_jump_right_light.width, &game->m_jump_right_light.height);
	game->m_hammer_left_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left_light.xpm",
			&game->m_hammer_left_light.width, &game->m_hammer_left_light.height);
	game->m_hammer_left_light_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left_light_2.xpm",
			&game->m_hammer_left_light_2.width, &game->m_hammer_left_light_2.height);
	game->m_hammer_right_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right_light.xpm",
			&game->m_hammer_right_light.width, &game->m_hammer_right_light.height);
	game->m_hammer_right_light_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right_light_2.xpm",
			&game->m_hammer_right_light_2.width, &game->m_hammer_right_light_2.height);



	game->m_hammer_left_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left_b.xpm",
			&game->m_hammer_left_b.width, &game->m_hammer_left_b.height);
	game->m_hammer_left_b_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left_b_2.xpm",
			&game->m_hammer_left_b_2.width, &game->m_hammer_left_b_2.height);
	game->m_hammer_right_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right_b.xpm",
			&game->m_hammer_right_b.width, &game->m_hammer_right_b.height);
	game->m_hammer_right_b_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right_b_2.xpm",
			&game->m_hammer_right_b_2.width, &game->m_hammer_right_b_2.height);
	game->m_hammer_left_light_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left_light_b.xpm",
			&game->m_hammer_left_light_b.width, &game->m_hammer_left_light_b.height);
	game->m_hammer_left_light_b_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_left_light_b_2.xpm",
			&game->m_hammer_left_light_b_2.width, &game->m_hammer_left_light_b_2.height);
	game->m_hammer_right_light_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right_light_b.xpm",
			&game->m_hammer_right_light_b.width, &game->m_hammer_right_light_b.height);
	game->m_hammer_right_light_b_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_hammer_right_light_b_2.xpm",
			&game->m_hammer_right_light_b_2.width, &game->m_hammer_right_light_b_2.height);

/*============================================================================*/

	game->m_static_left.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_left.xpm",
			&game->m_static_left.width, &game->m_static_left.height);
	game->m_static_right.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_right.xpm",
			&game->m_static_right.width, &game->m_static_right.height);
	game->m_static_left_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_left_light.xpm",
			&game->m_static_left_light.width, &game->m_static_left_light.height);
	game->m_static_right_light.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_right_light.xpm",
			&game->m_static_right_light.width, &game->m_static_right_light.height);



	game->m_static_left_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_left_b.xpm",
			&game->m_static_left_b.width, &game->m_static_left_b.height);
	game->m_static_right_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_right_b.xpm",
			&game->m_static_right_b.width, &game->m_static_right_b.height);
	game->m_static_left_light_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_left_light_b.xpm",
			&game->m_static_left_light_b.width, &game->m_static_left_light_b.height);
	game->m_static_right_light_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_static_right_light_b.xpm",
			&game->m_static_right_light_b.width, &game->m_static_right_light_b.height);

/*============================================================================*/

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



	game->m_walk_left_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_left_b.xpm",
			&game->m_walk_left_b.width, &game->m_walk_left_b.height);
	game->m_walk_left_b_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_left_b_2.xpm",
			&game->m_walk_left_b_2.width, &game->m_walk_left_b_2.height);
	game->m_walk_left_b_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_left_b_3.xpm",
			&game->m_walk_left_b_3.width, &game->m_walk_left_b_3.height);
	game->m_walk_right_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_right_b.xpm",
			&game->m_walk_right_b.width, &game->m_walk_right_b.height);
	game->m_walk_right_b_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_right_b_2.xpm",
			&game->m_walk_right_b_2.width, &game->m_walk_right_b_2.height);
	game->m_walk_right_b_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_right_b_3.xpm",
			&game->m_walk_right_b_3.width, &game->m_walk_right_b_3.height);
	game->m_walk_left_light_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_left_light_b.xpm",
			&game->m_walk_left_light_b.width, &game->m_walk_left_light_b.height);
	game->m_walk_left_light_b_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_left_light_b_2.xpm",
			&game->m_walk_left_light_b_2.width, &game->m_walk_left_light_b_2.height);
	game->m_walk_left_light_b_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_left_light_b_3.xpm",
			&game->m_walk_left_light_b_3.width, &game->m_walk_left_light_b_3.height);
	game->m_walk_right_light_b.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_right_light_b.xpm",
			&game->m_walk_right_light_b.width, &game->m_walk_right_light_b.height);
	game->m_walk_right_light_b_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_right_light_b_2.xpm",
			&game->m_walk_right_light_b_2.width, &game->m_walk_right_light_b_2.height);
	game->m_walk_right_light_b_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/m_walk_right_light_b_3.xpm",
			&game->m_walk_right_light_b_3.width, &game->m_walk_right_light_b_3.height);
			
/*============================================================================*/

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

/*============================================================================*/

	game->c.img = mlx_xpm_file_to_image(game->mlx, "xpm/c.xpm",
			&game->c.width, &game->c.height);
	game->c_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/c_2.xpm",
			&game->c_2.width, &game->c_2.height);
	game->c_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/c_3.xpm",
			&game->c_3.width, &game->c_3.height);
	game->c_4.img = mlx_xpm_file_to_image(game->mlx, "xpm/c_4.xpm",
			&game->c_4.width, &game->c_4.height);

/*============================================================================*/

	game->hammer.img = mlx_xpm_file_to_image(game->mlx, "xpm/hammer.xpm",
			&game->hammer.width, &game->hammer.height);

/*============================================================================*/

	game->s.img = mlx_xpm_file_to_image(game->mlx, "xpm/s.xpm",
			&game->s.width, &game->s.height);
	game->s_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_2.xpm",
			&game->s_2.width, &game->s_2.height);
	game->s_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_3.xpm",
			&game->s_3.width, &game->s_3.height);
	game->s_4.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_4.xpm",
			&game->s_4.width, &game->s_4.height);
	game->s_5.img = mlx_xpm_file_to_image(game->mlx, "xpm/s_5.xpm",
			&game->s_5.width, &game->s_5.height);
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

/*============================================================================*/

	game->menu.img = mlx_xpm_file_to_image(game->mlx, "xpm/menu.xpm",
			&game->menu.width, &game->menu.height);
	game->menu_2.img = mlx_xpm_file_to_image(game->mlx, "xpm/menu_2.xpm",
			&game->menu_2.width, &game->menu_2.height);
	game->menu_3.img = mlx_xpm_file_to_image(game->mlx, "xpm/menu_3.xpm",
			&game->menu_3.width, &game->menu_3.height);
	game->step.img = mlx_xpm_file_to_image(game->mlx, "xpm/step.xpm",
			&game->step.width, &game->step.height);
	game->steps.img = mlx_xpm_file_to_image(game->mlx, "xpm/steps.xpm",
			&game->steps.width, &game->steps.height);
	game->numbers[0].img = mlx_xpm_file_to_image(game->mlx, "xpm/_0.xpm",
			&game->numbers[0].width, &game->numbers[0].height);
	game->numbers[1].img = mlx_xpm_file_to_image(game->mlx, "xpm/_1.xpm",
			&game->numbers[1].width, &game->numbers[1].height);
	game->numbers[2].img = mlx_xpm_file_to_image(game->mlx, "xpm/_2.xpm",
			&game->numbers[2].width, &game->numbers[2].height);
	game->numbers[3].img = mlx_xpm_file_to_image(game->mlx, "xpm/_3.xpm",
			&game->numbers[3].width, &game->numbers[3].height);
	game->numbers[4].img = mlx_xpm_file_to_image(game->mlx, "xpm/_4.xpm",
			&game->numbers[4].width, &game->numbers[4].height);
	game->numbers[5].img = mlx_xpm_file_to_image(game->mlx, "xpm/_5.xpm",
			&game->numbers[5].width, &game->numbers[5].height);
	game->numbers[6].img = mlx_xpm_file_to_image(game->mlx, "xpm/_6.xpm",
			&game->numbers[6].width, &game->numbers[6].height);
	game->numbers[7].img = mlx_xpm_file_to_image(game->mlx, "xpm/_7.xpm",
			&game->numbers[7].width, &game->numbers[7].height);
	game->numbers[8].img = mlx_xpm_file_to_image(game->mlx, "xpm/_8.xpm",
			&game->numbers[8].width, &game->numbers[8].height);
	game->numbers[9].img = mlx_xpm_file_to_image(game->mlx, "xpm/_9.xpm",
			&game->numbers[9].width, &game->numbers[9].height);

/*============================================================================*/

	game->screen.img = mlx_new_image(game->mlx,
			game->max.x * CELL, game->max.y * CELL);
	game->menu_full.img = mlx_new_image(game->mlx,
			game->max.x * CELL, CELL);
	game->menu_full.width = game->max.x * CELL;
	game->menu_full.height = CELL;
}
