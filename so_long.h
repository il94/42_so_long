/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:53:28 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/26 17:56:11 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_ESC 65307

/* for QWERTY */
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97

/* for AZERTY */
// # define KEY_W 122
// # define KEY_D 100
// # define KEY_S 115
// # define KEY_A 113

# define WIDTH 1920 / 2
# define HEIGHT 1080 / 2
# define CELL 48
# define COLLECTIBLES "CE"
# define CHAR_CONTENT "01CEPM"
# define ENNEMIES "MURDL"
# define ENNEMIES_M "urdl"

# include "mlx_linux/mlx.h"
# include "libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <time.h>

typedef enum	e_end {
	LOOSE,
	WIN
}				t_end;

typedef struct	s_coordinates {
	int	x;
	int	y;
}				t_coordinates;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
	int		width;
	int		height;
	char	direction;
}				t_data;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	char	**map;
	int		x_map;
	int		y_map;
	int		x_pos;
	int		y_pos;
	int		moves;
	t_data	floor;
	t_data	wall_one;
	t_data	wall_mid;
	t_data	wall_top;
	t_data	wall_bot;
	t_data	mario;
	t_data	goomba;
	t_data	goomba_b;
	t_data	goomba_g;
	t_data	goomba_r;
	t_data	mushroom;
	t_data	star;
	unsigned int	time_a;
	unsigned int	time_b;
}				t_game;


/* so_long.c */
void	get_player_position(t_game *game);
int		player_is_in_danger(t_game *game, int y, int x);

/* run.c */
int		close_win(int keycode, t_game *game);
void	end_game(t_game *game, t_end condition);
int		can_be_started(int ac, char **av, t_game *game);
int		get_input_keyboard(int keycode, t_game *game);
void	initialize_mlx(t_game *game);

/* zoubir.c */
int		is_ennemies(char c);
int		is_ennemies_m(char c);
int		is_char_content(char c, int *cep);
int		is_collectibles(char c);

/* moves.c */
void	change_direction(t_game *game, t_coordinates pos, int y_bot, int x_bot);
void	move_ennemies(t_game *game, t_coordinates pos, int y_bot, int x_bot);
int		get_direction(t_game *game, t_coordinates pos);
int		search_ennemies(t_game *game);
void	spawn_ennemies(t_game *game);
void	move_player(t_game *game, int y, int x);

/* parsing.c */
char	*get_data_map(char *file);
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
void	print_environnement(t_game *game, int i, int j, int y_map);
void	print_mobs(t_game *game, int i, int j);
void	print_collectibles(t_game *game, int i, int j);
int		print_elements(t_game *game);

/* destroy_elements.c */
void	destroy_data_environnement(t_game *game);
void	destroy_data_mobs(t_game *game);
void	destroy_data_collectibles(t_game *game);
void	destroy_elements(t_game *game);

#endif