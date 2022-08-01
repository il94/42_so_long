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

void	put_color(t_data *image, int x, int y, unsigned int color)
{
		char *dst;

		dst = image->addr + y * image->line + x * image->bpp / 8;
		*(unsigned int *)dst = color;
}

unsigned int get_color(t_data *image, int x, int y)
{
	char *dst;

	dst = image->addr + y * image->line + x * 4;
	return (*(unsigned int *)dst);
}

void	draw_sprite(t_data *image, t_data *sprite, int x, int y)
{
	size_t i;
	size_t j;
	unsigned int color;
	double	ratio;

	ratio = (double)sprite->width / (double)CELL;
	i = 0 ;
	while (i < CELL)
	{
		j = 0;
		while (j < CELL)
		{
			color = get_color(sprite, (double)j * ratio, (double)i * ratio);
			if (color != 0x0)
				put_color(image, x + j, y + i, color);
			j++;
		}
		i++;
	}
}


void	print_elements(t_game *game)
{
	t_axe	pos;
	char	target;

	pos.y = 0;
	pos.x = 0;
	game->background.img = mlx_new_image(game->mlx,
			game->x_map * CELL, game->y_map * CELL);
	game->background.addr = mlx_get_data_addr(game->background.img, &game->background.bpp, &game->background.line, &game->background.endian);
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			target = game->map[pos.y][pos.x];
			if (target == '0')
				draw_sprite(game->background.img, game->grass.img, pos.x, pos.y);
			else if (target == '1')
				draw_sprite(game->background.img, game->wall_one.img, pos.x, pos.y);
			pos.x++;
		}
		pos.y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->background.img, 0, 0);
	// pos.y = 0;
	// pos.x = 0;
	// while (game->map[pos.y])
	// {
	// 	pos.x = 0;
	// 	while (game->map[pos.y][pos.x])
	// 	{
	// 		target = game->map[pos.y][pos.x];
	// 		if (target == 'C' || target == 'E' || target == 'e')
	// 			print_collectibles(game, pos);
	// 		else if (is_ennemy(target) || target == 'P')
	// 			print_mobs(game, pos);
	// 		pos.x++;
	// 	}
	// 	pos.y++;
	// }
}

void	get_images_environnement(t_game *game)
{
	game->grass.img = mlx_xpm_file_to_image(game->mlx, "xpm/grass.xpm",
			&game->grass.width, &game->grass.height);
	game->wall_one.img = mlx_xpm_file_to_image(game->mlx, "xpm/wall_one.xpm",
			&game->wall_one.width, &game->wall_one.height);
	game->mario.img = mlx_xpm_file_to_image(game->mlx, "xpm/mario_tr.xpm",
			&game->mario.width, &game->mario.height);
}

void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			1920, 1080, "Testent");
	get_images_environnement(game);
	print_elements(game);
	mlx_loop(game->mlx);
}

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

int	main(int ac, char **av)
{
	t_game	game;
	char *str;

	game.map = ft_split(get_data_map(av[1]), '\n');
	initialize_mlx(&game);
	destroy_elements(&game);
}
