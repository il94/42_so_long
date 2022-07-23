/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:53:28 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/24 01:10:56 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_ESC 65307
# define KEY_W 100
# define KEY_D 115
# define KEY_S 97
# define KEY_A 99
# define WIDTH 1920 / 2
# define HEIGHT 1080 / 2
# define CELL 48
# define CHAR_CONTENT "01CEPM"

# include "mlx_linux/mlx.h"
# include "libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	char	**map;
	int		x_map;
	int		y_map;
	t_data	floor;
	t_data	wall_one;
	t_data	wall_mid;
	t_data	wall_top;
	t_data	wall_bot;
	t_data	mario;
	t_data	goomba;
	t_data	goomba_b;
	t_data	goomba_g;
	t_data	mushroom;
	t_data	star;
}				t_game;

/* parsing.c */
char	*get_data_map(char *file);
int		is_char_content(char c, int *cep);
int		is_valid_content(char **map);
int		is_valid_border(char **map, int x_map, int y_map);
int		is_rectangular(char **map, int y_map);
int		is_valid_map(char ***map, char *file);

/* images.c */
void	get_images_environnement(t_game *game);
void	get_images_mobs(t_game *game);
void	get_images_collectibles(t_game *game);
void	get_images(t_game *game);

/* print.c */
void	print_ennemies(t_game *game, int i, int j);
void	print_walls(t_game *game, int i, int j, int y_map);
int		print_elements(t_game *game);

/* so_long.c */
int		close_win(int keycode, t_game *game);
void	initialize_mlx(t_game *game);
int		can_be_started(int ac, char **av, t_game *game);
void	destroy_elements(t_game *game);


#endif