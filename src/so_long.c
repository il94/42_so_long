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

void	display_menu(t_game *game)
{
	if (!game->menu_opened)
	{
		system("cvlc sound/open_menu.wav &");
		game->menu_opened = TRUE;
	}
	else
	{
 		system("cvlc sound/close_menu.wav &");
		game->menu_opened = FALSE;
	}
}

int	ennemy_proximity(t_game *game, t_pos pos)
{
	t_pos	target;

	target = pos;
	if (game->map[pos.y][pos.x] == 'D')
		target.y++;
	else if (game->map[pos.y][pos.x] == 'R')
		target.x++;
	else if (game->map[pos.y][pos.x] == 'U')
		target.y--;
	else if (game->map[pos.y][pos.x] == 'L')
		target.x--;
	if (game->player_pos.x == target.x && game->player_pos.y == target.y)
		return (1);
	if (is(ENNEMY_OBSTACLE, game->map[target.y][target.x]) && is_near(game, pos, "P"))
		return (2);
	return (0);
}

int	is_near(t_game *game, t_pos pos, char *str)
{
	return (is(str, game->map[pos.y + 1][pos.x])
			|| is(str, game->map[pos.y][pos.x + 1])
			|| is(str, game->map[pos.y - 1][pos.x])
			|| is(str, game->map[pos.y][pos.x - 1]));
}

void	kill_ennemy(t_game *game, t_data *ennemy)
{
	system("cvlc sound/goomba.wav &");
	if (ennemy->pos.x != 0)
		game->map[ennemy->pos.y][ennemy->pos.x] = '0';
	ennemy->pos.x = 0;
	ennemy->pos.y = 1;
	ennemy->cell.x = 1;
	ennemy->cell.y = 1;
}
