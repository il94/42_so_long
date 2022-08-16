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

int	can_be_started(int ac, char **av, t_game *game)
{
	if (ac != 2)
	{
		ft_printf("Bad input\n");
		exit (1);
	}
	if (!is_valid_map(game, av[1]))
	{
		ft_printf("Invalid map\n");
		exit (1);
	}
	return (1);
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
		display_menu(game);
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
	// printf("cell player : x = %d | y = %d\n", game->player_cell.x, game->player_cell.y);
	ft_print_array(game->map);
	printf("=========\n");
	put_elements(game);
	move_player(game);
	move_all_ennemies(game);
	if (!game->all_coins && !read_map(game, "C", &more_collectibles))
	{
		game->all_coins = TRUE;
		read_map(game, "E", open_exit_door);
		iterate_ennemies(game, kill_ennemy);
	}
	return (0);
}

/* ne pas oublier de free lors des inits*/
void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit (0);
	game->max.x = ft_strlen(game->map[0]);
	game->max.y = ft_get_size_array(game->map);
	game->win = mlx_new_window(game->mlx,
			game->max.x * CELL, game->max.y * CELL, "Paper Mario");
	game->night = FALSE;
	game->all_coins = FALSE;
	game->get_hammer = FALSE;
	game->menu_opened = FALSE;
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
	game->ennemy_count = 0;
	read_all_map(game, "M", get_ennemies_count);
	game->ennemies = malloc(game->ennemy_count * sizeof(t_data));
	// if (!game->ennemies)
		/* free */
	read_all_map(game, "M", &get_ennemies_data);
	game->state_ennemy = 0;
	game->speed_animation_ennemy = 200;
	if (!game->win)
		exit (0);
	get_images(game);
	get_adresses(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx, run_game, game);
	mlx_hook(game->win, 17, 0, mlx_loop_end, game->mlx);
	system("cvlc sound/march_ahead.wav &");
	mlx_loop(game->mlx);
}
