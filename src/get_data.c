/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:56:49 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/20 19:53:10 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_player_position(t_game *game, t_pos pos)
{
	game->player_pos = pos;
	game->player_cell.x = (game->player_pos.x * CELL) + (CELL / 2);
	game->player_cell.y = (game->player_pos.y * CELL) + CELL - (CELL / 6);
	return (1);
}

void	get_elements_count(t_game *game, t_pos pos)
{
	if (is(ENEMY, game->map[pos.y][pos.x]))
		game->enemy_count++;
	else if (is("C", game->map[pos.y][pos.x]))
		game->coin_count++;
	else if (is("E", game->map[pos.y][pos.x]))
		game->star_pos = pos;
}

void	get_enemies_data(t_game *game, t_pos pos)
{
	static int	i;

	if (!i)
		i = 0;
	game->enemies[i].pos = pos;
	game->enemies[i].cell.x = pos.x * CELL + CELL / 2;
	game->enemies[i].cell.y = pos.y * CELL + CELL / 2;
	i++;
}

