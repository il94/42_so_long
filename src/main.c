/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:32:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/22 19:08:35 by ilandols         ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->back.height)
	{
		j = 0;
		while (j < game->back.width)
		{
			my_mlx_pixel_put(&game->screen, j, i, get_color(&game->back, j, i));
			j++;
		}
		i++;
	}
	return (0);
}

int	print_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < HEIGHT / game->back.height)
	{
		j = 0;
		while (j < WIDTH / game->back.width)
		{
			if (i == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->back.img, j * game->back.width, i * game->back.height);
			j++;
		}
		i++;
	}
	return (0);
}



int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	if (!game.mlx)
		exit (0);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "So Longuent");
	game.screen.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	get_xpm(game);
	game.back.img = mlx_xpm_file_to_image(game.mlx, "src/floor.xpm", &game.back.width, &game.back.height);
	
/*============================================================================*/
	
	game.screen.addr = mlx_get_data_addr(game.screen.img, &game.screen.bits_per_pixel, &game.screen.line_length, &game.screen.endian);
	game.back.addr = mlx_get_data_addr(game.back.img, &game.back.bits_per_pixel, &game.back.line_length, &game.back.endian);
/*============================================================================*/
	mlx_hook(game.win, 2, 17, close_win, &game);
	mlx_loop_hook(game.mlx, print_background, &game);
	
/*============================================================================*/

	mlx_loop(game.mlx);

	
	mlx_destroy_image(game.mlx, game.screen.img);
	mlx_destroy_image(game.mlx, game.back.img);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
