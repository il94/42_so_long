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

int	is_surrounded_by(t_game *game, t_axe pos, char c)
{
	return (game->map[pos.y + 1][pos.x] == c
			&& game->map[pos.y][pos.x + 1] == c
			&& game->map[pos.y - 1][pos.x] == c
			&& game->map[pos.y][pos.x - 1] == c);
}

int	is_ennemy(char c)
{
	int	i;

	i = 0;
	while (ENNEMY[i])
	{
		if (c == ENNEMY[i])
			return (ENNEMY[i]);
		i++;
	}
	return (0);
}

int	is_player(char c)
{
	int	i;

	i = 0;
	while (PLAYER[i])
	{
		if (c == PLAYER[i])
			return (PLAYER[i]);
		i++;
	}
	return (0);
}

int	is_lower_ennemy(char c)
{
	int	i;

	i = 0;
	while (LOWER_ENNEMY[i])
	{
		if (c == LOWER_ENNEMY[i])
			return (LOWER_ENNEMY[i]);
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

int	is_collectibles(char c)
{
	int	i;

	i = 0;
	while (COLLECTIBLES[i])
	{
		if (c == COLLECTIBLES[i])
			return (COLLECTIBLES[i]);
		i++;
	}
	return (0);
}

int	is_ennemy_obstacle(char c)
{
	int	i;

	i = 0;
	while (ENNEMY_OBSTACLE[i])
	{
		if (c == ENNEMY_OBSTACLE[i])
			return (ENNEMY_OBSTACLE[i]);
		i++;
	}
	return (0);
}
