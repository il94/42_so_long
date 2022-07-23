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

int	is_char_content(char c, int *cep)
{
	int	i;

	i = 0;
	while (CHAR_CONTENT[i])
	{
		if (c == CHAR_CONTENT[i])
		{
			if (c == 'C')
				cep[0]++;
			else if (c == 'E')
				cep[1]++;
			else if (c == 'P')
				cep[2]++;
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_valid_content(char **map)
{
	int	i;
	int	j;
	int	cep[3];

	i = 1;
	cep[0] = 0;
	cep[1] = 0;
	cep[2] = 0;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (!is_char_content(map[i][j], cep))
				return (0);
			j++;
		}	
		i++;
	}
	if (cep[0] > 0 && cep[1] > 0 && cep[2] == 1)
		return (1);
	else
		return (0);
}

int	is_valid_border(char **map, int x_map, int y_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j != x_map)
	{
		if (map[i][j] != '1' || map[y_map - 1][j] != '1')
			return (0);
		j++;
	}
	while (i != y_map)
	{
		if (map[i][0] != '1' || map[i][x_map - 1] != '1')
			return (0);
		i++;
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
