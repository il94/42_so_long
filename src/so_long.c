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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:53:50 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/24 00:53:50 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	spawn_ennemy(t_game *game)
{
	t_axe	pos;

	pos.y = 1;
	while (pos.y < game->y_map - 1)
	{
		pos.x = 1;
		while (pos.x < game->x_map - 1)
		{
			if (is(LOWER_ENNEMY, game->map[pos.y][pos.x]))
				game->map[pos.y][pos.x] = ft_toupper(game->map[pos.y][pos.x]);
			pos.x++;
		}
		pos.y++;
	}
}

int	ennemy_proximity(t_game *game, t_axe pos)
{
	t_axe	target;

	target = pos;
	if (game->map[pos.y][pos.x] == 'D')
		target.y++;
	else if (game->map[pos.y][pos.x] == 'R')
		target.x++;
	else if (game->map[pos.y][pos.x] == 'U')
		target.y--;
	else if (game->map[pos.y][pos.x] == 'L')
		target.x--;
	if (game->player.x == target.x && game->player.y == target.y)
		return (1);
	if (is(ENNEMY_OBSTACLE, game->map[target.y][target.x]) && is_near_p(game, pos))
		return (2);
	return (0);
}

int	is_near(t_game *game, t_axe pos, char c)
{
	return (game->map[pos.y + 1][pos.x] == c
			|| game->map[pos.y][pos.x + 1] == c
			|| game->map[pos.y - 1][pos.x] == c
			|| game->map[pos.y][pos.x - 1] == c);
}

int	is_near_e(t_game *game, t_axe pos)
{
	return (is(ENNEMY, game->map[pos.y + 1][pos.x])
			|| is(ENNEMY, game->map[pos.y][pos.x + 1])
			|| is(ENNEMY, game->map[pos.y - 1][pos.x])
			|| is(ENNEMY, game->map[pos.y][pos.x - 1]));
}

int	is_near_p(t_game *game, t_axe pos)
{
	return (game->map[pos.y + 1][pos.x] == 'P'
			|| game->map[pos.y][pos.x + 1] == 'P'
			|| game->map[pos.y - 1][pos.x] == 'P'
			|| game->map[pos.y][pos.x - 1] == 'P');
}

void	kill_ennemies(t_game *game)
{
	t_axe	pos;

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
