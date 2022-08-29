/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:03:36 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/29 20:03:53 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	jump(t_game *game)
{
    system("cvlc sound/jump.wav &");
	game->jumping = TRUE;
	hbox_remove(game->map, game->player.cell, &game->enemies, H_JUMP);
}

void	hammer_hit(t_game *game)
{
    system("cvlc sound/hammer.wav &");
	game->hitting = TRUE;
	if (game->player.direction == 'l' || game->player.direction == 'r')
		hbox_remove(game->map, game->player.cell, &game->enemies, H_HIT_B);
	else if (game->player.direction == 'R')
		hbox_remove(game->map, game->player.cell, &game->enemies, H_HIT_RIGHT);
	else if (game->player.direction == 'L')
		hbox_remove(game->map, game->player.cell, &game->enemies, H_HIT_LEFT);
}
