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
	/* while */
}

void	destroy_data_mobs(t_game *game)
{
	/* while */
}

void	destroy_data_collectibles(t_game *game)
{
	/* while */
}

int	destroy_elements(t_game *game)
{
	destroy_data_environnement(game);
	destroy_data_mobs(game);
	destroy_data_collectibles(game);
	
/*============================================================================*/

	mlx_destroy_image(game->mlx, game->e_grass.img);
	mlx_destroy_image(game->mlx, game->e_wall_one.img);
	mlx_destroy_image(game->mlx, game->e_wall_mid.img);
	mlx_destroy_image(game->mlx, game->e_wall_top.img);
	mlx_destroy_image(game->mlx, game->e_wall_bot.img);
	mlx_destroy_image(game->mlx, game->e_grass_shadow.img);
	mlx_destroy_image(game->mlx, game->e_wall_one_shadow.img);
	mlx_destroy_image(game->mlx, game->e_wall_mid_shadow.img);
	mlx_destroy_image(game->mlx, game->e_wall_top_shadow.img);
	mlx_destroy_image(game->mlx, game->e_wall_bot_shadow.img);

/*============================================================================*/

	mlx_destroy_image(game->mlx, game->m_jump_left.img);
	mlx_destroy_image(game->mlx, game->m_jump_right.img);
	mlx_destroy_image(game->mlx, game->m_hammer_left.img);
	mlx_destroy_image(game->mlx, game->m_hammer_left_2.img);
	mlx_destroy_image(game->mlx, game->m_hammer_right.img);
	mlx_destroy_image(game->mlx, game->m_hammer_right_2.img);
	mlx_destroy_image(game->mlx, game->m_jump_left_light.img);
	mlx_destroy_image(game->mlx, game->m_jump_right_light.img);
	mlx_destroy_image(game->mlx, game->m_hammer_left_light.img);
	mlx_destroy_image(game->mlx, game->m_hammer_left_light_2.img);
	mlx_destroy_image(game->mlx, game->m_hammer_right_light.img);
	mlx_destroy_image(game->mlx, game->m_hammer_right_light_2.img);

	mlx_destroy_image(game->mlx, game->m_hammer_left_b.img);
	mlx_destroy_image(game->mlx, game->m_hammer_left_b_2.img);
	mlx_destroy_image(game->mlx, game->m_hammer_right_b.img);
	mlx_destroy_image(game->mlx, game->m_hammer_right_b_2.img);
	mlx_destroy_image(game->mlx, game->m_hammer_left_light_b.img);
	mlx_destroy_image(game->mlx, game->m_hammer_left_light_b_2.img);
	mlx_destroy_image(game->mlx, game->m_hammer_right_light_b.img);
	mlx_destroy_image(game->mlx, game->m_hammer_right_light_b_2.img);

/*============================================================================*/

	mlx_destroy_image(game->mlx, game->m_static_left.img);
	mlx_destroy_image(game->mlx, game->m_static_right.img);
	mlx_destroy_image(game->mlx, game->m_static_left_light.img);
	mlx_destroy_image(game->mlx, game->m_static_right_light.img);

	mlx_destroy_image(game->mlx, game->m_static_left_b.img);
	mlx_destroy_image(game->mlx, game->m_static_right_b.img);
	mlx_destroy_image(game->mlx, game->m_static_left_light_b.img);
	mlx_destroy_image(game->mlx, game->m_static_right_light_b.img);

/*============================================================================*/

	mlx_destroy_image(game->mlx, game->m_walk_left.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_3.img);
	mlx_destroy_image(game->mlx, game->m_walk_right.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_3.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_light.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_light_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_light_3.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_light.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_light_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_light_3.img);


	mlx_destroy_image(game->mlx, game->m_walk_left_b.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_b_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_b_3.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_b.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_b_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_b_3.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_light_b.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_light_b_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_left_light_b_3.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_light_b.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_light_b_2.img);
	mlx_destroy_image(game->mlx, game->m_walk_right_light_b_3.img);

/*============================================================================*/

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

/*============================================================================*/

	mlx_destroy_image(game->mlx, game->c.img);
	mlx_destroy_image(game->mlx, game->c_2.img);
	mlx_destroy_image(game->mlx, game->c_3.img);
	mlx_destroy_image(game->mlx, game->c_4.img);

/*============================================================================*/

	mlx_destroy_image(game->mlx, game->hammer.img);

/*============================================================================*/

	mlx_destroy_image(game->mlx, game->s.img);
	mlx_destroy_image(game->mlx, game->s_2.img);
	mlx_destroy_image(game->mlx, game->s_3.img);
	mlx_destroy_image(game->mlx, game->s_4.img);
	mlx_destroy_image(game->mlx, game->s_5.img);
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
