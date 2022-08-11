/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoubir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:09:21 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/25 22:09:21 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	hammer_hit(t_game *game)
{
	if (game->direction == 'a' || game->direction == 'b')
	{
		if (is(ENNEMY, game->map[game->player.y - 1][game->player.x]))
		{
			game->map[game->player.y - 1][game->player.x] = '0';
		}
	}
}

void	get_ennemies_data(t_game *game, t_axe pos)
{
	static int	i;

	if (!i)
		i = 0;
	game->ennemies[i].pos = pos;
	game->ennemies[i].cell.x = pos.x * CELL + CELL / 2;
	game->ennemies[i].cell.y = pos.y * CELL + CELL / 2;
	// game->ennemies[i].cell.x = pos.y * CELL;
	// game->ennemies[i].cell.y = pos.x * CELL;
	i++;
}

void	get_ennemies_count(t_game *game, t_axe pos)
{
	game->ennemy_count++;
}

int	is_surrounded_by(t_game *game, t_axe pos, char c)
{
	return (game->map[pos.y + 1][pos.x] == c
			&& game->map[pos.y][pos.x + 1] == c
			&& game->map[pos.y - 1][pos.x] == c
			&& game->map[pos.y][pos.x - 1] == c);
}

int	is(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (str[i]);
		i++;
	}
	return (0);
}

int	is_valid_char(char c, int *cep)
{
	int	i;

	i = 0;
	while (VALID_CHAR[i])
	{
		if (c == VALID_CHAR[i])
		{
			if (c == 'C')
				cep[0]++;
			else if (c == 'E')
				cep[1]++;
			else if (c == 'P')
				cep[2]++;
			return (VALID_CHAR[i]);
		}
		i++;
	}
	return (0);
}

