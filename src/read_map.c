/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:53:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/20 19:28:55 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	spawn_enemy(char **map, t_data *enemy)
{
	t_pos	pos;
	
	pos = enemy->pos;
	map[pos.y][pos.x] = ft_toupper(map[pos.y][pos.x]);
}

int	more_element(t_game *game, t_pos pos)
{
	return (1);
}

int	read_map(t_game *game, char *target, int (*f)(t_game *, t_pos))
{
	t_pos	pos;

	pos.y = 1;
	while (game->map[pos.y])
	{
		pos.x = 1;
		while (game->map[pos.y][pos.x])
		{
			if (is(target, game->map[pos.y][pos.x]))
				return ((*f)(game, pos));
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

void	read_all_map(t_game *game, char *target, void (*f)(t_game *, t_pos))
{
	t_pos	pos;

	pos.y = 0;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			if (is(target, game->map[pos.y][pos.x]))
				((*f)(game, pos));
			pos.x++;
		}
		pos.y++;
	}
}

void	iterate_elements(char **map, int element_count, t_data *elements, void (*f)(char **, t_data *))
{
	int	i;

	i = 0;
	while (i < element_count)
	{
		(*f)(map, &elements[i]);
		i++;
	}
}
