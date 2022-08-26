/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:02:52 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/11 23:02:52 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	appearing_star(t_game *game, t_pos pos)
{
	game->map[pos.y][pos.x] = 'e';
	game->star_appeared = TRUE;
	game->land_displayed = FALSE;
	system("pkill vlc");
	system("cvlc sound/star_appeared.wav &");
	sleep(3);
	iterate_elements(game->map, game->enemies->index, game->enemies, kill_enemy);
	game->enemies->count = 0;
	system("cvlc sound/star_way.wav &");
	return (1);
}

void	display_bar(t_game *game)
{
	if (!game->bar_display)
	{
		system("cvlc sound/open_bar.wav &");
		game->bar_display = TRUE;
	}
	else
	{
 		system("cvlc sound/close_bar.wav &");
		game->bar_display = FALSE;
	}
}

int	enemy_proximity(char **map, t_pos player, t_pos pos)
{
	t_pos	target;

	target = pos;
	if (map[pos.y][pos.x] == 'D')
		target.y++;
	else if (map[pos.y][pos.x] == 'R')
		target.x++;
	else if (map[pos.y][pos.x] == 'U')
		target.y--;
	else if (map[pos.y][pos.x] == 'L')
		target.x--;
	if (player.x == target.x && player.y == target.y)
		return (1);
	if (is(ENEMY_OBSTACLE, map[target.y][target.x]) && is_near(map, pos, PLAYER))
		return (2);
	return (0);
}

int	is_near(char **map, t_pos pos, char *str)
{
	return (is(str, map[pos.y + 1][pos.x])
			|| is(str, map[pos.y][pos.x + 1])
			|| is(str, map[pos.y - 1][pos.x])
			|| is(str, map[pos.y][pos.x - 1]));
}


