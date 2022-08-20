/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:20:55 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/26 00:20:55 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_game *game, t_end condition)
{
	if (condition == WIN)
		ft_printf("GG\n");
	else if (condition == LOOSE)
		ft_printf("Game Over\n");
	mlx_loop_end(game->mlx);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->move_up = TRUE;
		game->move_right = FALSE;
		game->move_down = FALSE;
		game->move_left = FALSE;
	}
	else if (keycode == KEY_D)
	{
		game->move_right = TRUE;
		game->move_up = FALSE;
		game->move_down = FALSE;
		game->move_left = FALSE;
	}
	else if (keycode == KEY_S)
	{
		game->move_down = TRUE;
		game->move_up = FALSE;
		game->move_right = FALSE;
		game->move_left = FALSE;
	}
	else if (keycode == KEY_A)
	{
		game->move_left = TRUE;
		game->move_up = FALSE;
		game->move_right = FALSE;
		game->move_down = FALSE;
	}
	else if (keycode == KEY_SPACE)
	{
		if (game->move_down)
			jump(game);
		else if (game->get_hammer)
			hammer_hit(game);
	}
	else if (keycode == KEY_TAB)
		display_bar(game);
	else if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx);
	game->keycode = keycode;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->move_up = FALSE;
	else if (keycode == KEY_D)
		game->move_right = FALSE;
	else if (keycode == KEY_S)
		game->move_down = FALSE;
	else if (keycode == KEY_A)
		game->move_left = FALSE;
	return (0);
}

int	run_game(t_game *game)
{
	// ft_print_array(game->map);
	// printf("========\n");
	printf("ennemies = %d\n", game->enemy_count);
	if (game->enemy_count == 0)
		game->enemy_index = 0;
	put_elements(game);
	move_player(game);
	move_all_enemies(game);
	if (collision_player_enemy(game))
		end_game(game, LOOSE);
	if (!game->star_appeared && game->coin_count == 0)
		appearing_star(game, game->star_pos);
	return (0);
}

/* ne pas oublier de free lors des inits*/
void	initialize_mlx(t_game *game, char *file)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit (0);
	get_data_map(file, &game->map, &game->max);
	game->win = mlx_new_window(game->mlx,
			game->max.x * CELL, game->max.y * CELL, "Paper mario");
	game->star_appeared = FALSE;
	game->get_hammer = FALSE;
	game->bar_displayed = FALSE;
	game->enemy_count = 0;
	game->coin_count = 0;
	read_all_map(game, "CEM", get_elements_count);
	game->enemy_index = game->enemy_count;
	read_map(game, "P", &get_player_position);
	game->player_direction = 'P';
	game->player_state = 0;
	game->player_steps = 0;
	game->max_player_steps = FALSE;
	game->player_animation_speed = 12;
	game->is_hitting = FALSE;
	game->is_jumping = FALSE;
	game->move_up = FALSE;
	game->move_right = FALSE;
	game->move_down = FALSE;
	game->move_left = FALSE;
	game->enemies = malloc(game->enemy_count * sizeof(t_data));
	read_all_map(game, "M", &get_enemies_data);
	game->state_enemy = 0;
	game->speed_animation_enemy = 200;
	if (!game->win)
		exit (0);

	// game->sprites_collectibles[5].pos = 
	get_all_images(game);
	get_all_addresses(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx, run_game, game);
	mlx_hook(game->win, 17, 0, mlx_loop_end, game->mlx);
	system("cvlc sound/march_ahead.wav &");
	mlx_loop(game->mlx);
}
