/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:53:28 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/29 20:37:29 by ilandols         ###   ########.fr       */
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
# define FPS 60
# define VALID_CHAR "01CEPMH"
# define items "CEeH"
# define ALL "01CEePMURDLurdlH"
# define GRASS "0"
# define WALL "1"
# define COIN "C"
# define STAR "Ee"
# define PLAYER "P"
# define HAMMER "H"
# define ENEMY "MURDL"
# define LOWER_ENEMY "urdl"
# define ENEMY_OBSTACLE "1CEMURDLH"

# include "mlx_linux/mlx.h"
# include "libft/libft.h"

# include <stdlib.h>
# include <fcntl.h>

typedef enum	e_shift {
	FULL,
	BOT,
	CENTER,
	RIGHT,
	HAMMER_LEFT_1,
	HAMMER_LEFT_2,
	HAMMER_RIGHT_1,
	HAMMER_RIGHT_2,
	MENU,
	MOVE_COUNTER
}				t_shift;

typedef struct	s_hbox {
	int	left;
	int	right;
	int	down;
	int	up;
}				t_hbox;

typedef enum	e_range {
	H_COIN,
	H_ENEMY,
	H_JUMP,
	H_HIT_B,
	H_HIT_RIGHT,
	H_HIT_LEFT
}				t_range;

typedef enum	e_end {
	LOOSE,
	WIN
}				t_end;

typedef struct	s_info {
	int		state;
	int		speed_animation;
}				t_info;

typedef struct	s_data {
	t_pos	pos;
	t_pos	cell;
	int		count;
	int		index;
	int		state;
	int		speed_animation;
	char	direction;
}				t_data;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		end;
	int		width;
	int		height;
	int		sprite_count;
}				t_img;

typedef struct	s_game {
	/* data mlx */
	void	*mlx;
	void	*win;
	int		keycode;

	/* data map */
	char	**map;
	t_pos	max;

	/* data render */
	t_data	render;
	t_data	stepbar;
	t_bool	bar_display;
	t_bool	land_displayed;
	t_bool	max_player_steps;

	/* data mario */
	// t_data	player;
	t_list	player;
	t_info	i_player;
	int		player_steps;
	t_bool	hitting;
	t_bool	jumping;
	t_bool	move_up;
	t_bool	move_right;
	t_bool	move_down;
	t_bool	move_left;

	/* data enemies */
	t_list	*enemies;
	t_info	i_enemies;
	
	/* data coins */
	t_list	*coins;
	t_info	i_coins;

	/* data star */
	t_data	star;
	t_bool	star_appeared;

	/* data hammer */
	t_data	hammer;
	t_bool	map_contain_hammer;
	t_bool	get_hammer;

	/* images */
	t_img		s_render;
	t_img		s_land[10];
	t_img		s_stepbar;
	t_img		s_bar[15];
	t_img		s_mario[52];
	t_img		s_goombas[9];
	t_img		s_items[8];
	}				t_game;


/* zoubir.c */
int		player_is_moving(t_game *game);
void	get_player_position(t_data *entity, t_pos pos_trgt);
void	get_position_entities(t_data *entities, t_pos pos_trgt);
void	lget_position_entities(t_list *entities, t_pos pos_trgt);
int		count_entity(char **map, char *target);
int		player_get_coin(t_game *game);
int		is_valid_char(char c, int *cep);
int		is(char *str, char c);
void	print_lists(t_list *lst);

/* so_long.c */
int		appearing_star(t_game *game, t_pos pos);
void	display_bar(t_game *game);
int		enemy_proximity(char **map, t_pos player, t_pos pos);
int		is_near(char **map, t_pos pos, char *str);

/* run.c */
void	end_game(t_game *game, t_end condition);
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
int		run_game(t_game *game);
void	initialize_mlx(t_game *game);
void	initialize_data_game(t_game *game, char *file);

/* read_map.c */
void	spawn_enemy(char **map, t_list *enemy);
int		more_element(t_game *game, t_pos pos);
void	read_map_and_array(char **map, t_data *element, char *target, void (*f)(t_data *, t_pos));
void	read_map_and_list(char **map, t_list **element, char *target, void (*f)(t_list *, t_pos));
void	read_map(char **map, t_data *element, char *target, void (*f)(t_data *, t_pos));
void	read_map_with_struct(t_game *game, char *target, void (*f)(t_game *, t_pos));
t_pos	read_map_return_pos(char **map, char *target);
void	iterate_elements(char **map, t_list *elements, void (*f)(char **, t_list *));

/* collisions.c */
t_hbox	get_hbox_range(t_range range);
void	hbox_remove(char **map, t_pos player, t_list **element, t_range range);
int		check_hbox(t_pos player_cell, t_list *element, t_range range);
void	remove_element(char **map, t_list *enemy, t_list **start);

/* action_player.c */
void	jump(t_game *game);
void	hammer_hit(t_game *game);
/* move.c */
void	get_player_sprite_direction(t_game *game);
void	get_player_direction(t_game *game, t_pos *pos_trgt, t_pos *cell_trgt);
void	change_enemy_direction(char **map, char direction, t_list *enemy);
void	get_enemy_direction(char **map, t_pos *pos, t_pos *cell);
void	move_all_enemies(t_game *game);
/* move_player.c */
int		player_sprite_can_move(t_game *game, t_pos pos_trgt);
void	move_player_sprite(t_game *game, t_pos cell_trgt);
int		player_pos_can_move(t_game *game, t_pos pos_trgt);
void	move_player_pos(t_game *game, t_pos pos_trgt);
void	move_player(t_game *game);
/* move_enemy.c */
int		e_cell_can_move(char **map, t_pos pos_trgt, char dir, t_list *enemy);
void	e_move_cell(t_pos cell_trgt, t_list *enemy, t_info *i_enemies);
int		e_pos_can_move(char **map, t_pos pos_trgt, char dir, t_list *enemy);
void	e_move_pos(char **map, t_pos trgt, char dir, t_list *enemy);
void	e_move(t_game *game, t_pos cell_trgt, t_pos pos_trgt, t_list *enemy);

/* print.c */
void	put_render(t_game *game);
/* print_elements.c */
void	put_land(t_game *game, t_pos pos_trgt);
void	put_wall(t_game *game, t_img *dst, t_img *sprites, t_pos pos);
void	put_enemies(t_game *game, t_img *dst, t_list *src, t_img *sprites);
void	put_player(t_game *game, t_img *dst, t_data *src, t_img *sprites);
void	put_stepbar(t_game *game);
/* print_player.c */
void	put_player_hit(t_img *dst, t_data *src, t_img *sprite, t_bool *hit);
void	put_player_jump(t_img *dst, t_data *src, t_img *sprite, t_bool *jump);
void	put_player_walk(t_img *dst, t_data *src, t_img *sprites);
void	put_player_static(t_img *dst, t_data *src, t_img *sprites);
/* print_stepbar.c */
void	put_bar(t_img *dst, t_img *sprites, int size_bar);
void	put_move_count(t_game *game, t_img *dst, t_img *sprites);
void	put_step(t_img *dst, t_img *sprites, t_pos pos_trgt, int player_steps);
void	scroll_bar(t_img *dst, t_data *src, t_img *sprite, t_bool bar_display);
/* print_utils.c */
int		get_shift_drawing_x(t_pos index, t_pos trgt, t_shift shift);
int		get_shift_drawing_y(t_pos index, t_pos trgt, t_shift shift);
int		draw(t_img *dst_img, t_img *src_img, t_pos trgt, t_shift shift);
void	put_all_element(t_img *dst, t_data *src, t_img *sprite, t_shift shift);
void	put_all_lelement(t_img *dst, t_list *src, t_img *sprites, t_info i_coins);
void	put_element(t_img *dst, t_data *src, t_img *sprite);
void	put_lelement(t_img *dst, t_list *src, t_img *sprites, t_info i_enemies);
/* print_utils2.c */
void	put_all_land(t_game *game);
void	put_wall_to_player(t_game *game);
void	put_around_player(t_game *game, t_pos pos_player);
void	put_around_enemy(t_game *game, t_pos pos_enemy);
void	put_around_bar(t_game *game, t_pos pos_stepbar);

/* mlx_addresses.c */
void	get_addresses(t_img *data, int number_sprite);
void	get_all_addresses(t_game *game);
/* mlx_images.c */
void	get_images(void *mlx, t_img *data, char type, int number_sprite);
void	get_all_images(t_game *game);
/* mlx_destroy.c */
void	destroy_elements(void *mlx, t_img *data, int number_sprite);
int		destroy_all_elements(t_game *game);

/* initialize.c */
void	initialize_elements(t_game *game);
/* initialize_elements.c */
void	initialize_enemies(t_game *game, t_list **enemies, t_info *i_enemies);
void	initialize_coins(t_game *game, t_list **coins, t_info *i_coins);
void	initialize_star(t_game *game, t_data *star);
void	initialize_bar(t_game *game, t_data *stepbar);
// void	initialize_player(t_game *game, t_data *player);
void	initialize_player(t_game *game, t_list **player, t_info *i_player);

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

/* main.c */
int		main(int ac, char **av);

#endif