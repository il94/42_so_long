/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:32:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/23 01:52:17 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_color(t_data *data, int x, int y)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
	
}

int	close_win(int keycode, t_game *game)
{
	// if (keycode == KEY_W)
	// 	move_w();
	// else if (keycode == KEY_D)
	// 	move_d();
	// else if (keycode == KEY_S)
	// 	move_s();
	// else if (keycode == KEY_A)
	// 	move_a();
	if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx);
	return (0);
}

int	print_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= HEIGHT / game->floor.height)
	{
		j = 0;
		while (j < WIDTH / game->floor.width)
		{
			// if (i == 0 || j == 0 || i + 1 == HEIGHT / game->floor.height || j + 1 == WIDTH / game->floor.width)
			// 	mlx_put_image_to_window(game->mlx, game->win, game->wall.img, j * game->wall.width, i * game->wall.height);
			// else
				mlx_put_image_to_window(game->mlx, game->win, game->floor.img, j * game->floor.width, i * game->floor.height);
			j++;
		}
		i++;
	}
	return (0);
}

int	print_sprites(t_game *game)
{
	char	*line;
	int		fd;

	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (NULL); //penser a tout free
	line = ft_get_next_line(fd);
	printf("line = %s\n", line);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	if (!game.mlx)
		exit (0);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "So Longuent");
	game.floor.img = mlx_xpm_file_to_image(game.mlx, "sprites/floor2.xpm", &game.floor.width, &game.floor.height);
	game.wall.img = mlx_xpm_file_to_image(game.mlx, "sprites/wall2.xpm", &game.wall.width, &game.wall.height);
	game.floor.addr = mlx_get_data_addr(game.floor.img, &game.floor.bits_per_pixel, &game.floor.line_length, &game.floor.endian);
	game.wall.addr = mlx_get_data_addr(game.wall.img, &game.wall.bits_per_pixel, &game.wall.line_length, &game.wall.endian);
	// mlx_hook(game.win, 2, 17, close_win, &game);
	mlx_loop_hook(game.mlx, print_background, &game);
	
	// mlx_loop_hook(game.mlx, print_sprites, &game);
	mlx_loop(game.mlx);
	mlx_destroy_image(game.mlx, game.floor.img);
	mlx_destroy_image(game.mlx, game.wall.img);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
