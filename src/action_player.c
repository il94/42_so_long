/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:03:36 by ilandols          #+#    #+#             */
/*   Updated: 2022/09/06 21:07:08 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	jump(t_game *game)
{
	system("cvlc sounds/jump.wav &");
	game->jumping = TRUE;
	hbox_remove(game->map, game->player.cell, &game->enemies, H_JUMP);
	game->start_delay = (int)clock();
}

void	hammer_hit(t_game *game)
{
	system("cvlc sounds/hammer.wav &");
	game->hitting = TRUE;
	if (game->player.dir == 'l' || game->player.dir == 'r')
		hbox_remove(game->map, game->player.cell, &game->enemies, H_HIT_B);
	else if (game->player.dir == 'R')
		hbox_remove(game->map, game->player.cell, &game->enemies, H_HIT_RIGHT);
	else if (game->player.dir == 'L')
		hbox_remove(game->map, game->player.cell, &game->enemies, H_HIT_LEFT);
	game->start_delay = (int)clock();
}

void	display_bar(t_game *game)
{
	if (!game->bar_display)
	{
		system("cvlc sounds/open_bar.wav &");
		game->bar_display = TRUE;
	}
	else
	{
		system("cvlc sounds/close_bar.wav &");
		game->bar_display = FALSE;
	}
	game->start_delay = (int)clock();
}
