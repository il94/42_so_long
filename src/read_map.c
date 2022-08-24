/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:53:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/24 18:49:35 by ilandols         ###   ########.fr       */
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

void	read_map_and_array(char **map, t_data *element, char *target, void (*f)(t_data *, t_pos))
{
	int		index_element;
	t_pos	pos;

	index_element = 0;
	pos.y = 1;
	while (map[pos.y])
	{
		pos.x = 1;
		while (map[pos.y][pos.x])
		{
			if (is(target, map[pos.y][pos.x]))
			{
				((*f)(&element[index_element], pos));
				index_element++;
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	read_map(char **map, t_data *element, char *target, void (*f)(t_data *, t_pos))
{
	t_pos	pos;

	pos.y = 1;
	while (map[pos.y])
	{
		pos.x = 1;
		while (map[pos.y][pos.x])
		{
			if (is(target, map[pos.y][pos.x]))
				((*f)(element, pos));
			pos.x++;
		}
		pos.y++;
	}
}

void	read_map_with_struct(t_game *game, char *target, void (*f)(t_game *, t_pos))
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

t_pos	read_map_return_pos(char **map, char *target)
{
	t_pos	pos;

	pos.y = 1;
	while (map[pos.y])
	{
		pos.x = 1;
		while (map[pos.y][pos.x])
		{
			if (is(target, map[pos.y][pos.x]))
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	pos.x = 0;
	pos.y = 0;
	return (pos);
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
