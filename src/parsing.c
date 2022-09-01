/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:57:25 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/18 21:57:25 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_valid_parameter(int ac, char *file)
{
	int		fd;
	char	buffer[1];

	fd = open(file, O_RDONLY);
	if (!is_only_one_parameter(ac) || !file_exist(fd)
		|| !is_ber_file(file) || !is_not_empty(fd, buffer))
	{
		close(fd);
		exit (1);
	}
	close(fd);
	return (1);
}

int	is_valid_map(char *file)
{
	char	**map;
	t_pos	size_map;

	get_data_map(file, &map, &size_map);
	if (!is_rectangular(map, size_map.y) || !is_valid_border(map, size_map)
		|| !is_valid_content(map))
	{
		ft_printf("Error\nInvalid map\n");
		ft_free_array(map);
		return (0);
	}
	ft_free_array(map);
	return (1);
}
