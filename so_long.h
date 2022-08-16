/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:53:28 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/16 18:21:58 by ilandols         ###   ########.fr       */
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

# define CELL 48
# define VALID_CHAR "01CEPMH"
# define COLLECTIBLES "CEeH"
# define ALL "01CEePMURDLurdlH"
# define ENNEMY "MURDL"
# define LOWER_ENNEMY "urdl"
# define ENNEMY_OBSTACLE "1CEMURDLH"

# include "mlx_linux/mlx.h"
# include "libft/libft.h"

# include <stdlib.h>
# include <fcntl.h>

typedef enum	e_sprite {
	FULL,
	BOT,
	CENTER,
	RIGHT,
	HAMMER_LEFT_1,
	HAMMER_LEFT_2,
	HAMMER_RIGHT_1,
	HAMMER_RIGHT_2,
	MENU,
	TEST
}				t_sprite;

typedef enum	e_bool {
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_end {
	LOOSE,
	WIN
}				t_end;

typedef struct	s_pos {
	int	x;
	int	y;
}				t_pos;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
	int		width;
	int		height;
	char	player_direction;
	t_pos	pos;
	t_pos	cell;
}				t_data;

typedef struct	s_game {
	/* data mlx */
	void	*mlx;
	void	*win;
	t_data	screen;
	t_data	menu_full;
	
	/* data game */
	t_bool	night;
	t_bool	all_coins;
	t_bool	get_hammer;
	t_bool	menu_opened;
	int		keycode;

	/* data map */
	char	**map;
	t_pos	max;

	/* data player */
	t_pos	player_pos;
	t_pos	player_cell;
	char	player_direction;
	int		player_state;
	int		player_steps;
	t_bool	max_player_steps;
	int		player_animation_speed;
	t_bool	is_hitting;
	t_bool	is_jumping;
	t_bool	move_up;
	t_bool	move_right;
	t_bool	move_down;
	t_bool	move_left;

	/* data ennemies */
	t_data	*ennemies;
	int		ennemy_count;
	int		state_ennemy;
	int		speed_animation_ennemy;
	
	/* images environnement */
	t_data		e_grass;
	t_data		e_wall_one;
	t_data		e_wall_mid;
	t_data		e_wall_top;
	t_data		e_wall_bot;
	t_data		e_grass_shadow;
	t_data		e_wall_one_shadow;
	t_data		e_wall_mid_shadow;
	t_data		e_wall_top_shadow;
	t_data		e_wall_bot_shadow;

	/* images player */

	t_data		m_jump_left;
	t_data		m_jump_right;
	t_data		m_hammer_left;
	t_data		m_hammer_left_2;
	t_data		m_hammer_right;
	t_data		m_hammer_right_2;
	t_data		m_jump_left_light;
	t_data		m_jump_right_light;
	t_data		m_hammer_left_light;
	t_data		m_hammer_left_light_2;
	t_data		m_hammer_right_light;
	t_data		m_hammer_right_light_2;

	t_data		m_hammer_left_b;
	t_data		m_hammer_left_b_2;
	t_data		m_hammer_right_b;
	t_data		m_hammer_right_b_2;
	t_data		m_hammer_left_light_b;
	t_data		m_hammer_left_light_b_2;
	t_data		m_hammer_right_light_b;
	t_data		m_hammer_right_light_b_2;
/*============================================================================*/
	t_data		m_static_left;
	t_data		m_static_right;
	t_data		m_static_left_light;
	t_data		m_static_right_light;
	
	t_data		m_static_left_b;
	t_data		m_static_right_b;
	t_data		m_static_left_light_b;
	t_data		m_static_right_light_b;
/*============================================================================*/
	t_data		m_walk_left;
	t_data		m_walk_left_2;
	t_data		m_walk_left_3;
	t_data		m_walk_right;
	t_data		m_walk_right_2;
	t_data		m_walk_right_3;
	t_data		m_walk_left_light;
	t_data		m_walk_left_light_2;
	t_data		m_walk_left_light_3;
	t_data		m_walk_right_light;
	t_data		m_walk_right_light_2;
	t_data		m_walk_right_light_3;

	t_data		m_walk_left_b;
	t_data		m_walk_left_b_2;
	t_data		m_walk_left_b_3;
	t_data		m_walk_right_b;
	t_data		m_walk_right_b_2;
	t_data		m_walk_right_b_3;
	t_data		m_walk_left_light_b;
	t_data		m_walk_left_light_b_2;
	t_data		m_walk_left_light_b_3;
	t_data		m_walk_right_light_b;
	t_data		m_walk_right_light_b_2;
	t_data		m_walk_right_light_b_3;
/*============================================================================*/
	/* images ennemies */
	t_data		g;
	t_data		g_2;
	t_data		g_3;
	t_data		g_death;
	t_data		g_death_2;
	t_data		gb;
	t_data		gb_2;
	t_data		gb_3;
	t_data		gr;
	t_data		gr_2;
	t_data		gr_3;

	/* images collectibles */
	t_data		c;
	t_data		c_2;
	t_data		c_3;
	t_data		c_4;
	t_data		hammer;
	t_data		s;
	t_data		s_2;
	t_data		s_3;
	t_data		s_4;
	t_data		s_5;
	t_data		s_spawn;
	t_data		s_spawn_2;
	t_data		s_spawn_3;
	t_data		s_spawn_4;
	t_data		s_spawn_5;
	t_data		s_spawn_6;
	t_data		s_spawn_7;
	t_data		s_spawn_8;
	t_data		s_spawn_9;
	t_data		s_spawn_10;
	t_data		s_spawn_11;
	t_data		s_spawn_12;
	t_data		s_spawn_13;
	t_data		s_spawn_14;
	t_data		s_spawn_15;
	t_data		s_spawn_16;
	t_data		s_spawn_17;
	t_data		s_spawn_18;
	t_data		s_spawn_19;
	t_data		s_spawn_20;

	/* images menu */
	t_data		menu;
	t_data		menu_2;
	t_data		menu_3;
	t_data		step;
	t_data		steps;
	t_data		numbers[10];
	}				t_game;

/* zoubir.c */
int		collision_player_ennemy(t_game *game);
void	jump(t_game *game);
void	hammer_hit(t_game *game);
void	jump(t_game *game);
void	get_ennemies_data(t_game *game, t_pos pos);
void	get_ennemies_count(t_game *game, t_pos pos);
int		is_valid_char(char c, int *cep);
int		is(char *str, char c);

/* so_long.c */
void	display_menu(t_game *game);
int		ennemy_proximity(t_game *game, t_pos pos);
int		is_near(t_game *game, t_pos pos, char *str);
void	kill_ennemy(t_game *game, t_data *ennemy);

/* run.c */
void	end_game(t_game *game, t_end condition);
int		can_be_started(int ac, char **av, t_game *game);
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
int		run_game(t_game *game);
void	initialize_mlx(t_game *game);

/* move_ennemy.c */
void	change_direction(t_game *game, char code, int i);
int		ennemy_sprite_can_move(t_game *game, t_pos pos_trgt, char code, int i);
void	move_ennemy_sprite(t_game *game, t_pos cell_trgt, int i);
int		ennemy_position_can_move(t_game *game, t_pos pos_trgt, char code, int i);
void	move_ennemy_position(t_game *game, t_pos trgt, char code, int i);
void	move_ennemy(t_game *game, t_pos cell_trgt, t_pos pos_trgt, int i);
void	get_ennemy_direction(t_game *game, t_pos *pos, t_pos *cell);
void	move_all_ennemies(t_game *game);

/* move_player.c */
void	get_player_sprite_direction(t_game *game);
int		player_sprite_can_move(t_game *game, t_pos pos_trgt);
void	move_player_sprite(t_game *game, t_pos cell_trgt);
int		player_position_can_move(t_game *game, t_pos pos_trgt);
void	move_player_position(t_game *game, t_pos pos_trgt);
void	get_player_direction(t_game *game, t_pos *pos_trgt, t_pos *cell_trgt);
void	move_player(t_game *game);

/* read_map.c */
void	spawn_ennemy(t_game *game, t_pos pos);
int		more_collectibles(t_game *game, t_pos pos);
int		open_exit_door(t_game *game, t_pos pos);
int		get_player_position(t_game *game, t_pos pos);
int		read_map(t_game *game, char *target,  int (*f)(t_game *, t_pos));
void	read_all_map(t_game *game, char *target, void (*f)(t_game *, t_pos));
void	iterate_ennemies(t_game *game, void (*f)(t_game *, t_data *));

/* print.c */
int		get_drawing_position(t_pos cell, t_pos map, t_sprite drawing_pos, char pos);
int		draw_sprite(t_game *game, t_data *image, t_pos pos, t_sprite drawing_pos);
int		draw_menu(t_game *game, t_data *image, t_pos trgt, t_sprite drawing_pos);
void	put_moves(t_game *game);
void	put_menu(t_game *game);
void	put_jump(t_game *game);
void	put_hammer(t_game *game);
void	put_player(t_game *game);
void	put_e_grass(t_game *game, t_pos pos);
void	put_e_wall(t_game *game, t_pos pos);
void	put_ennemy(t_game *game);
void	put_star(t_game *game, t_pos pos);
void	put_coins(t_game *game, t_pos pos);
void	put_collectibles(t_game *game, t_pos pos);
void	put_e_wall_to_player(t_game *game);
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

/* parsing.c */
char	*get_data_map(char *file);
int		is_valid_content(char **map);
int		is_valid_border(char **map, t_pos map_pos);
int		is_rectangular(char **map, int y);
int		is_valid_map(t_game *game, char *file);

#endif