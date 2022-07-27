/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osef.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:52:40 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/24 00:52:40 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	print_sprites(t_game *game)
{
	char	*line;
	int		fd;

	fd = open("src/map.ber", O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = ft_get_next_line(fd);
	printf("line = %s\n", line);
	return (0);
}

int	get_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
