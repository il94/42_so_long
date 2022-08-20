/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:53:28 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/20 19:53:02 by ilandols         ###   ########.fr       */
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
# define ENEMY "MURDL"
# define LOWER_ENEMY "urdl"
# define ENEMY_OBSTACLE "1CEMURDLH"

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
	t_data	render;
	t_data	bar;
	
	/* data game */
	t_pos	star_pos;
	t_bool	star_appeared;
	t_bool	get_hammer;
	t_bool	bar_displayed;
	int		keycode;
	int		coin_count;

	/* data map */
	char	**map;
	t_pos	max;

	/* data mario */
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

	/* data enemies */
	t_data	*enemies;
	int		enemy_count;
	int		enemy_index;
	int		state_enemy;
	int		speed_animation_enemy;
	
	/* images */

	t_data		sprites_collectibles[8];
	// [0]		c;
	// [1]		c_2;
	// [2]		c_3;
	// [3]		c_4;
	// [4]		hammer;
	// [5]		s;
	// [6]		s_2;
	// [7]		s_3;
	t_data		sprites_goombas[9];
	// [0]		g;
	// [1]		g_2;
	// [2]		g_3;
	// [3]		gb;
	// [4]		gb_2;
	// [5]		gb_3;
	// [6]		gr;
	// [7]		gr_2;
	// [8]		gr_3;
	t_data		sprites_environnement[10];
	// [0]		e_grass;
	// [1]		e_grass_shadow;
	// [2]		e_wall_bot;
	// [3]		e_wall_bot_shadow;
	// [4]		e_wall_mid;
	// [5]		e_wall_mid_shadow;
	// [6]		e_wall_top;
	// [7]		e_wall_top_shadow;
	// [8]		e_wall_one;
	// [9]		e_wall_one_shadow;
	t_data		sprites_bar[15];
	// [10]		sprites_bar;
	// [11]		bar_2;
	// [12]		bar_3;
	// [13]		step;
	// [14]		steps;
	t_data		sprites_mario[44];
	// [0]		p_hammer_left;
	// [1]		p_hammer_left_2;
	// [2]		p_hammer_left_b;
	// [3]		p_hammer_left_b_2;
	// [4]		p_hammer_left_light;
	// [5]		p_hammer_left_light_2;
	// [6]		p_hammer_left_light_b;
	// [7]		p_hammer_left_light_b_2;
	// [8]		p_hammer_right;
	// [9]		p_hammer_right_2;
	// [10]		p_hammer_right_b;
	// [11]		p_hammer_right_b_2;
	// [12]		p_hammer_right_light;
	// [13]		p_hammer_right_light_2;
	// [14]		p_hammer_right_light_b;
	// [15]		p_hammer_right_light_b_2;
	// [16]		p_jump_left;
	// [17]		p_jump_left_light;
	// [18]		p_jump_right;
	// [19]		p_jump_right_light;
	// [20]		p_walk_left;
	// [21]		p_walk_left_2;
	// [22]		p_walk_left_3;
	// [23]		p_walk_left_b;
	// [24]		p_walk_left_b_2;
	// [25]		p_walk_left_b_3;
	// [26]		p_walk_left_light;
	// [27]		p_walk_left_light_2;
	// [28]		p_walk_left_light_3;
	// [29]		p_walk_left_light_b;
	// [30]		p_walk_left_light_b_2;
	// [31]		p_walk_left_light_b_3;
	// [32]		p_walk_right;
	// [33]		p_walk_right_2;
	// [34]		p_walk_right_3;
	// [35]		p_walk_right_b;
	// [36]		p_walk_right_b_2;
	// [37]		p_walk_right_b_3;
	// [38]		p_walk_right_light;
	// [39]		p_walk_right_light_2;
	// [40]		p_walk_right_light_3;
	// [41]		p_walk_right_light_b;
	// [42]		p_walk_right_light_b_2;
	// [43]		p_walk_right_light_b_3;
	}				t_game;

/* print.c */
int		get_drawing_position(t_pos cell, t_pos map, t_sprite drawing_pos, char pos);
int		draw_sprite(t_game *game, t_data *image, t_pos pos, t_sprite drawing_pos);
int		draw_bar(t_game *game, t_data *image, t_pos trgt, t_sprite drawing_pos);
void	put_moves(t_game *game);
void	put_bar(t_game *game);
void	put_jump(t_game *game);
void	put_hammer(t_game *game);
void	put_player(t_game *game);
void	put_e_grass(t_game *game, t_pos pos);
void	put_e_wall(t_game *game, t_pos pos);
void	put_enemy(t_game *game);
void	put_star(t_game *game, t_pos pos);
void	put_collectibless(t_game *game, t_pos pos);
void	put_collectibles(t_game *game, t_pos pos);
void	put_e_wall_to_player(t_game *game);
void	put_elements(t_game *game);

/* zoubir.c */
int		player_get_coin(int coin_count);
int		is_valid_char(char c, int *cep);
int		is(char *str, char c);

/* so_long.c */
int		appearing_star(t_game *game, t_pos pos);
void	display_bar(t_game *game);
int		enemy_proximity(t_game *game, t_pos pos);
int		is_near(t_game *game, t_pos pos, char *str);

/* run.c */
void	end_game(t_game *game, t_end condition);
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
int		run_game(t_game *game);
void	initialize_mlx(t_game *game, char *file);

/* read_map.c */
void	spawn_enemy(char **map, t_data *enemy);
int		more_element(t_game *game, t_pos pos);
int		read_map(t_game *game, char *target,  int (*f)(t_game *, t_pos));
void	read_all_map(t_game *game, char *target, void (*f)(t_game *, t_pos));
void	iterate_elements(char **map, int element_count, t_data *elements, void (*f)(char **, t_data *));

/* entity.c */
void	kill_enemy(char **map, t_data *enemy);
int		collision_player_enemy(t_game *game);
void	hammer_hit(t_game *game);
void	jump(t_game *game);

/* get_data.c */
int		get_player_position(t_game *game, t_pos pos);
void	get_enemies_data(t_game *game, t_pos pos);
void	get_elements_count(t_game *game, t_pos pos);




/* move_enemy.c */
int		enemy_sprite_can_move(t_game *game, t_pos pos_trgt, char code, int i);
void	move_enemy_sprite(t_game *game, t_pos cell_trgt, int i);
int		enemy_position_can_move(t_game *game, t_pos pos_trgt, char code, int i);
void	move_enemy_position(t_game *game, t_pos trgt, char code, int i);
void	move_enemy(t_game *game, t_pos cell_trgt, t_pos pos_trgt, int i);

/* move_player.c */
int		player_sprite_can_move(t_game *game, t_pos pos_trgt);
void	move_player_sprite(t_game *game, t_pos cell_trgt);
int		player_position_can_move(t_game *game, t_pos pos_trgt);
void	move_player_position(t_game *game, t_pos pos_trgt);
void	move_player(t_game *game);

/* move.c */
void	get_player_sprite_direction(t_game *game);
void	get_player_direction(t_game *game, t_pos *pos_trgt, t_pos *cell_trgt);
void	change_enemy_direction(t_game *game, char code, int i);
void	get_enemy_direction(t_game *game, t_pos *pos, t_pos *cell);
void	move_all_enemies(t_game *game);

/* parsing.c */
int		is_valid_parameter(int ac, char *file);
int		is_valid_map(t_game *game, char *file);

/* parsing_map_file.c */
int		is_only_one_parameter(int ac);
int		file_exist(char *file, int fd);
int		is_ber_file(char *file);
int		is_not_empty(char *file, int fd, char *buffer);

/* parsing_map_content.c */
void	get_data_map(char *file, char ***map, t_pos *size_map);
int		is_valid_content(char **map);
int		is_valid_border(char **map, t_pos map_pos);
int		is_rectangular(char **map, int y);

/* addresses.c */
void	get_addresses(t_data *data, int number_sprite);
void	get_all_addresses(t_game *game);

/* images.c */
void	get_images(void *mlx, t_data *data, char type, int number_sprite);
void	get_all_images(t_game *game);

/* destroy.c */
void	destroy_elements(void *mlx, t_data *data, int number_sprite);
int		destroy_all_elements(t_game *game);

/* main.c */
int		main(int ac, char **av);

#endif