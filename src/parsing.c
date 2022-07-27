/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:06:13 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/23 17:06:13 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_data_map(char *file)
{
	int		fd;
	char	*line;
	char	*result;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (0);
	line = "";
	result = NULL;
	while (line)
	{
		line = ft_get_next_line(fd);
		if (line)
			result = ft_strjoin_gnl(result, line);
		free(line);
	}
	return (result);
}

int	is_valid_content(char **map)
{
	t_axe	pos;
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

int	is_valid_border(char **map, int x_map, int y_map)
{
	t_axe	pos;

	pos.y = 0;
	pos.x = 0;
	while (pos.x != x_map)
	{
		if (map[pos.y][pos.x] != '1' || map[y_map - 1][pos.x] != '1')
			return (0);
		pos.x++;
	}
	while (pos.y != y_map)
	{
		if (map[pos.y][0] != '1' || map[pos.y][x_map - 1] != '1')
			return (0);
		pos.y++;
	}
	return (1);
}

int	is_rectangular(char **map, int y_map)
{
	int	size_line;
	int	i;

	size_line = ft_strlen(map[0]);
	i = 1;
	while (map[i] && size_line == ft_strlen(map[i]))
		i++;
	if (i != y_map)
		return (0);
	return (1);
}

int	is_valid_map(char ***map, char *file)
{
	int		size_line;
	int		count_line;
	char	*str;
	int		x_map;
	int		y_map;

	str = get_data_map(file);
	*map = ft_split(str, '\n');
	x_map = ft_strlen(*map[0]);
	y_map = ft_get_size_array(*map);
	free(str);
	if (y_map < 3 || !is_rectangular(*map, y_map)
		|| !is_valid_border(*map, x_map, y_map) || !is_valid_content(*map))
	{
		ft_free_array(*map);
		return (0);
	}
	return (1);
}
