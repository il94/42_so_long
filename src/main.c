/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:32:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/21 17:59:01 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_color(t_data *data, int x, int y)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
	
}

void	test_pixel_put(void *mlx, t_data img)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 100;
	z = 0;
	
	while (x < 50 && y > 0)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FFFA4C);
		my_mlx_pixel_put(&img, z, 100, 0x00FFFA4C);
		x += 1;
		y -= 2;
		z += 1;
	}
	while (x < 100 && y < 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FFFA4C);
		my_mlx_pixel_put(&img, z, 100, 0x00FFFA4C);
		x += 1;
		y += 2;
		z += 1;
	}
	x = 25;
	y = 50;
	z = 25;
	while (x < 50 && y < 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FFFA4C);
		my_mlx_pixel_put(&img, z, 50, 0x00FFFA4C);
		x += 1;
		y += 2;
		z += 1;
	}
	while (x < 75 && y > 50)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FFFA4C);
		my_mlx_pixel_put(&img, z, 50, 0x00FFFA4C);
		x += 1;
		y -= 2;
		z += 1;
	}
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

int	print_image(t_game *game)
{
	int	back_x;
	int	back_y;
	int	i;
	int	j;

	back_x = 0;
	back_y = 0;
	i = 0;
	j = 0;
	while (back_y < HEIGHT / 4)
	{
		back_x = 0;
		while (back_x < WIDTH / 4)
		{
			i = 0;
			while (i < game->img.height)
			{
				j = 0;
				while (j < game->img.width)
				{
					my_mlx_pixel_put(&game->img, j, i, get_color(&game->img, j, i));
					j++;
				}
				i++;
			}
			back_x++;
		}
		back_y++;
	}

	// test_pixel_put(game->mlx, game->img);
	// game->img.img = mlx_xpm_file_to_image(game->mlx, "./grass.xpm", &game->img.width, &game->img.height);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	if (!game.mlx)
		exit (0);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "So Longuent");
	// game.img.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	game.img.img = mlx_xpm_file_to_image(game.mlx, "src/grass.xpm", &game.img.width, &game.img.height);
	
/*============================================================================*/
	
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);
/*============================================================================*/
	mlx_hook(game.win, 2, 1L<<0, close_win, &game);
	mlx_loop_hook(game.mlx, print_image, &game);
	
/*============================================================================*/

	mlx_loop(game.mlx);

	
	mlx_destroy_image(game.mlx, game.img.img);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
