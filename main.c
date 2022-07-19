/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:32:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/04 13:55:36 by ilandols         ###   ########.fr       */
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

void	test_pixel_put(void *mlx, void *mlx_win)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 100;
	z = 0;
	
	while (x < 50 && y > 0)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x00FFFA4C);
		mlx_pixel_put(mlx, mlx_win, z, 100, 0x00FFFA4C);
		x += 1;
		y -= 2;
		z += 1;
	}
	while (x < 100 && y < 100)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x00FFFA4C);
		mlx_pixel_put(mlx, mlx_win, z, 100, 0x00FFFA4C);
		x += 1;
		y += 2;
		z += 1;
	}
	x = 25;
	y = 50;
	z = 25;
	while (x < 50 && y < 100)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x00FFFA4C);
		mlx_pixel_put(mlx, mlx_win, z, 50, 0x00FFFA4C);
		x += 1;
		y += 2;
		z += 1;
	}
	while (x < 75 && y > 50)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x00FFFA4C);
		mlx_pixel_put(mlx, mlx_win, z, 50, 0x00FFFA4C);
		x += 1;
		y -= 2;
		z += 1;
	}
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
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


typedef struct	s_mlx {
	void	*mlx;
	void	*win;
}				t_mlx;

int	ft_close(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}


int	main(void)
{
	t_mlx	mlx;
	// void	*mlx;
	void	*mlx_win;
	t_data	img;

	perror("test");
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 101, 101, "Zoubir");
	// mlx_pixel_put(mlx, mlx_win, 900, 900, 0x00FFFA4C);
	// img.img = mlx_new_image(mlx, 101, 101);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	mlx_hook(mlx.win, 2, 1L<<0, ft_close, &mlx);
	// mlx_hook(mlx.win, 2, 1L<<0, ft_close, &mlx);
	test_pixel_put(mlx.mlx, mlx.win);
	// test_img(mlx, mlx_win);

	// mlx_loop(mlx.mlx);
}

/*
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

void build_image()
{
	// parcourir map de i=0 ; j=0 a i=max ; j=max
	// pour chaque case

	build_square(texture xpm)
	{
		// boucle sur la case
	}
}

void render_next_frame()
{
	build_image();
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	void	*tex;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	tex = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_loop_hook(mlx, render_next_frame, YourStruct);
	mlx_loop(mlx);
}*/