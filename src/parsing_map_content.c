/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:06:13 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/19 16:43:49 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_data_map(char *file, char ***map, t_pos *size_map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (!fd)
		exit (1);
	*map = ft_get_file_content(fd);
	close(fd);
	if (!(*map))
		exit (1);
	size_map->x = ft_strlen(*map[0]);
	size_map->y = ft_get_size_array(*map);
}

int	is_valid_content(char **map)
{
	t_pos	pos;
	int		cep[3];

	pos.y = 1;
	cep[0] = 0;
	cep[1] = 0;
	cep[2] = 0;
	while (map[pos.y])
	{
		pos.x = 1;
		while (map[pos.y][pos.x])
		{
			if (!is_valid_char(map[pos.y][pos.x++], cep))
				return (0);
		}	
		pos.y++;
	}
	if (cep[0] > 0 && cep[1] > 0 && cep[2] == 1)
		return (1);
	return (0);
}

int	is_valid_border(char **map, t_pos map_pos)
{
	t_pos	pos;

	pos.y = 0;
	pos.x = 0;
	while (pos.x != map_pos.x)
	{
		if (map[pos.y][pos.x] != '1' || map[map_pos.y - 1][pos.x] != '1')
			return (0);
		pos.x++;
	}
	while (pos.y != map_pos.y)
	{
		if (map[pos.y][0] != '1' || map[pos.y][map_pos.x - 1] != '1')
			return (0);
		pos.y++;
	}
	return (1);
}

int	is_rectangular(char **map, int y)
{
	int	size_line;
	int	i;

	size_line = ft_strlen(map[0]);
	i = 1;
	while (map[i] && size_line == ft_strlen(map[i]))
		i++;
	if (i != y)
		return (0);
	return (1);
}
