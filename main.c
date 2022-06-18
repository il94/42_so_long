/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:32:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/18 16:35:56 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	test_pixel_put(void *mlx, void *mlx_win, t_data img)
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
	// while (x < 100 && y < 100)
	// {
	// 	my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 	x += 1;
	// 	y += 2;
	// }
	// my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

void	test_img(void *mlx, void *mlx_win)
{
	// void	*mlx;
	void	*img;
	char	*relative_path = "./mystic_woods_free_v0.2/sprites/characters.png";
	int		img_width;
	int		img_height;

	// mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Zoubir");
	// img.img = mlx_new_image(mlx, 101, 101);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// test_pixel_put(mlx, mlx_win, img);
	test_img(mlx, mlx_win);

	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
	// img.img = mlx_xpm_file_to_image(mlx, "./mystic_woods_free_v0.2/sprites/characters", &img.bits_per_pixel, &img.line_length);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
}
