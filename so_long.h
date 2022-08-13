/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:53:28 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/13 21:49:19 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_ESC 65307
# define KEY_TAB 65289
# define KEY_SPACE 32

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
# define VALID_CHAR "01CEPMHJ"
# define COLLECTIBLES "CEeHJ"
# define ALL "01CEePMURDLurdlHJ"
# define ENNEMY "MURDL"
# define LOWER_ENNEMY "urdl"
# define ENNEMY_OBSTACLE "1CEMURDLHJ"

# include "mlx_linux/mlx.h"
# include "libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <time.h>

typedef enum	e_sprite {
	FULL,
	BOT,
	CENTER,
	RIGHT,
	TOP
}				t_sprite;

typedef enum	e_end {
	LOOSE,
	WIN
}				t_end;

typedef struct	s_axe {
	int	x;
	int	y;
}				t_axe;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
	int		width;
	int		height;
	char	direction;
	t_axe	pos;
	t_axe	cell;
}				t_data;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	char	**map;
	int		x_map;
	int		y_map;
	int		x_pos;
	int		y_pos;
	t_axe	player;
	t_axe	cell;
	char	direction;
	int		state;
	char	hit;
	int		speed_player;
	int		move_ennemy;
	int		moves;
	unsigned int	time_a;
	unsigned int	time_b;
	int		night;
	t_data	*ennemies;
	int	ennemy_count;
	int	i_ennemy;
	int	state_ennemy;
	int	speed_ennemy;
	int	all_coins;
	int	get_hammer;
	int	get_boots;
	int	keycode;
	int move_up;
	int move_right;
	int move_down;
	int move_left;
	t_data	screen;
	t_data	grass;
	t_data	wall_one;
	t_data	wall_mid;
	t_data	wall_top;
	t_data	wall_bot;
	t_data	mario;
	t_data	goomba;
	t_data	goomba_b;
	t_data	goomba_g;
	t_data	goomba_r;
	t_data	coin;
	t_data	star;
	t_data	m_hammer_b_left;
	t_data	m_hammer_b_left_2;
	t_data	m_hammer_b_right;
	t_data	m_hammer_b_right_2;
	t_data	m_hammer_left;
	t_data	m_hammer_left_2;
	t_data	m_hammer_left_3;
	t_data	m_hammer_right;
	t_data	m_hammer_right_2;
	t_data	m_hammer_right_3;
	t_data	m_static_b_left;
	t_data	m_static_b_right;
	t_data	m_static_left;
	t_data	m_static_right;
	t_data	m_walk_b_left;
	t_data	m_walk_b_left_2;
	t_data	m_walk_b_left_3;
	t_data	m_walk_b_right;
	t_data	m_walk_b_right_2;
	t_data	m_walk_b_right_3;
	t_data	m_walk_left;
	t_data	m_walk_left_2;
	t_data	m_walk_left_3;
	t_data	m_walk_right;
	t_data	m_walk_right_2;
	t_data	m_walk_right_3;
	t_data	c;
	t_data	c_2;
	t_data	c_3;
	t_data	c_4;
	t_data	hammer;
	t_data	s;
	t_data	s_2;
	t_data	s_3;
	t_data	s_spawn;
	t_data	s_spawn_2;
	t_data	s_spawn_3;
	t_data	s_spawn_4;
	t_data	s_spawn_5;
	t_data	s_spawn_6;
	t_data	s_spawn_7;
	t_data	s_spawn_8;
	t_data	s_spawn_9;
	t_data	s_spawn_10;
	t_data	s_spawn_11;
	t_data	s_spawn_12;
	t_data	s_spawn_13;
	t_data	s_spawn_14;
	t_data	s_spawn_15;
	t_data	s_spawn_16;
	t_data	s_spawn_17;
	t_data	s_spawn_18;
	t_data	s_spawn_19;
	t_data	s_spawn_20;
	t_data	g;
	t_data	g_2;
	t_data	g_3;
	t_data	g_death;
	t_data	g_death_2;
	t_data	gb;
	t_data	gb_2;
	t_data	gb_3;
	t_data	gr;
	t_data	gr_2;
	t_data	gr_3;
	t_data	grass_shadow;
	t_data	wall_one_shadow;
	t_data	wall_mid_shadow;
	t_data	wall_top_shadow;
	t_data	wall_bot_shadow;
	t_data	m_hammer_b_left_light;
	t_data	m_hammer_b_left_light_2;
	t_data	m_hammer_b_right_light;
	t_data	m_hammer_b_right_light_2;
	t_data	m_hammer_left_light;
	t_data	m_hammer_left_light_2;
	t_data	m_hammer_left_light_3;
	t_data	m_hammer_right_light;
	t_data	m_hammer_right_light_2;
	t_data	m_hammer_right_light_3;
	t_data	m_static_b_left_light;
	t_data	m_static_b_right_light;
	t_data	m_static_left_light;
	t_data	m_static_right_light;
	t_data	m_walk_b_left_light;
	t_data	m_walk_b_left_light_2;
	t_data	m_walk_b_left_light_3;
	t_data	m_walk_b_right_light;
	t_data	m_walk_b_right_light_2;
	t_data	m_walk_b_right_light_3;
	t_data	m_walk_left_light;
	t_data	m_walk_left_light_2;
	t_data	m_walk_left_light_3;
	t_data	m_walk_right_light;
	t_data	m_walk_right_light_2;
	t_data	m_walk_right_light_3;
}				t_game;

int	get_input_keyboard2(int keycode, t_game *game);
void	get_player_direction(t_game *game);

/* zoubir.c */
void	put_hammer(t_game *game);
int		loose_condition_p(t_game *game);
void	jump(t_game *game);
void	hammer_hit(t_game *game);
void	get_ennemies_data(t_game *game, t_axe pos);
void	get_ennemies_count(t_game *game, t_axe pos);
int		is_surrounded_by(t_game *game, t_axe pos, char c);
int		is_valid_char(char c, int *cep);
int		is(char *str, char c);

/* so_long.c */
void	spawn_ennemy(t_game *game);
int		ennemy_proximity(t_game *game, t_axe pos);
int		is_near(t_game *game, t_axe pos, char c);
int		is_near_e(t_game *game, t_axe pos);
int		is_near_p(t_game *game, t_axe pos);
void	kill_ennemies(t_game *game);

/* run.c */
void	end_game(t_game *game, t_end condition);
int		can_be_started(int ac, char **av, t_game *game);
int		get_input_keyboard(int keycode, t_game *game);
int		run_game(t_game *game);
void	initialize_mlx(t_game *game);

/* move_ennemy.c */
int		ennemy_sprite_can_move(t_game *game, t_axe pos_trgt, char code);
void	move_ennemy_sprite(t_game *game, t_axe cell_trgt);
int		ennemy_position_can_move(t_game *game, t_axe pos_trgt, char code);
void	move_ennemy_position(t_game *game, t_axe trgt, char code);
int		move_ennemy(t_game *game, t_axe cell_trgt, t_axe pos_trgt);
void	change_direction(t_game *game, t_axe cell_trgt, t_axe pos_trgt, char code);
int		get_ennemy_direction(t_game *game, t_axe pos, t_axe cell);

/* move_player.c */
void	get_player_sprite_direction(t_game *game);
int		player_sprite_can_move(t_game *game, t_axe pos_trgt);
void	move_player_sprite(t_game *game, t_axe cell_trgt);
int		player_position_can_move(t_game *game, t_axe pos_trgt);
void	move_player_position(t_game *game, t_axe pos_trgt);
void	move_player(t_game *game, t_axe cell_trgt, t_axe pos_trgt);

/* parsing.c */
char	*get_data_map(char *file);
int		is_valid_content(char **map);
int		is_valid_border(char **map, int x_map, int y_map);
int		is_rectangular(char **map, int y_map);
int		is_valid_map(char ***map, char *file);

/* read_map.c */
int		more_collectibles(t_game *game, t_axe pos);
int		open_exit_door(t_game *game, t_axe pos);
int		get_player_position(t_game *game, t_axe pos);
int		read_map(t_game *game, char target,  int (*f)(t_game *, t_axe));
void	read_all_map(t_game *game, char target, void (*f)(t_game *, t_axe));
void	put_to_screen(t_game *game, char *target, void (*f)(t_game *, t_axe));

/* print.c */
int		get_drawing_position(t_axe cell, t_axe map, t_sprite drawing_pos, char axe);
int		draw_sprite(t_game *game, t_data *image, t_axe pos, t_sprite drawing_pos);
void	put_player(t_game *game);
void	put_grass(t_game *game, t_axe pos);
void	put_wall(t_game *game, t_axe pos);
void	put_ennemy(t_game *game);
void	put_star(t_game *game, t_axe pos);
void	put_coins(t_game *game, t_axe pos);
void	put_collectibles(t_game *game, t_axe pos);
void	put_wall_to_player(t_game *game);
void	put_elements(t_game *game);

/* adresses.c */
void	get_adresses_environnement(t_game *game);
void	get_adresses_mobs(t_game *game);
void	get_adresses_collectibles(t_game *game);
void	get_adresses(t_game *game);

/* images.c */
void	get_images_environnement(t_game *game);
void	get_images_mobs(t_game *game);
void	get_images_collectibles(t_game *game);
void	get_images(t_game *game);

/* destroy_elements.c */
void	destroy_data_environnement(t_game *game);
void	destroy_data_mobs(t_game *game);
void	destroy_data_collectibles(t_game *game);
int		destroy_elements(t_game *game);

#endif