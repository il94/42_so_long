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
	if (is(ENNEMY_OBSTACLE, game->map[target.y][target.x]) && is_near_p(game, pos))
		return (2);
	return (0);
}

int	is_near(t_game *game, t_pos pos, char c)
{
	return (game->map[pos.y + 1][pos.x] == c
			|| game->map[pos.y][pos.x + 1] == c
			|| game->map[pos.y - 1][pos.x] == c
			|| game->map[pos.y][pos.x - 1] == c);
}

int	is_near_e(t_game *game, t_pos pos)
{
	return (is(ENNEMY, game->map[pos.y + 1][pos.x])
			|| is(ENNEMY, game->map[pos.y][pos.x + 1])
			|| is(ENNEMY, game->map[pos.y - 1][pos.x])
			|| is(ENNEMY, game->map[pos.y][pos.x - 1]));
}

int	is_near_p(t_game *game, t_pos pos)
{
	return (game->map[pos.y + 1][pos.x] == 'P'
			|| game->map[pos.y][pos.x + 1] == 'P'
			|| game->map[pos.y - 1][pos.x] == 'P'
			|| game->map[pos.y][pos.x - 1] == 'P');
}

void	kill_ennemies(t_game *game)
{
	t_pos	pos;

	system("cvlc sound/goomba.wav &");
	pos.y = 1;
	while (game->map[pos.y])
	{
		pos.x = 1;
		while (game->map[pos.y][pos.x])
		{
			if (is(ENNEMY, game->map[pos.y][pos.x]))
				game->map[pos.y][pos.x] = '0';
			pos.x++;
		}
		pos.y++;
	}
}
