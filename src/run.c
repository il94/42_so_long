/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:20:55 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/26 00:20:55 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_game *game, t_end condition)
{
	if (condition == WIN)
		ft_printf("End of Chapter !\n");
	else if (condition == LOOSE)
		ft_printf("Game Over\n");
	mlx_loop_end(game->mlx);
}

int	run_game(t_game *game)
{
	// usleep(4000);
	put_render(game);
	increment_element_states(game);
	move_player(game);
	move_all_enemies(game);
	if (game->enemies && check_hbox(game->player.cell, game->enemies, H_ENEMY))
		end_game(game, LOOSE);
	if (!game->star_appeared && !game->coins)
		appearing_star(game, game->star.pos);
	return (0);
}
