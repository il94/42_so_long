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
	if (!is_valid_map(&game->map, av[1]))
	{
		ft_printf("Invalid map\n");
		exit (1);
	}
	return (1);
}

int	get_input_keyboard(int keycode, t_game *game)
{
	int	i;

	i = 0;
	if (keycode == KEY_W)
		move_player(game, game->player.y - 1, game->player.x);
	else if (keycode == KEY_D)
		move_player(game, game->player.y, game->player.x + 1);
	else if (keycode == KEY_S)
		move_player(game, game->player.y + 1, game->player.x);
	else if (keycode == KEY_A)
		move_player(game, game->player.y, game->player.x - 1);
	else if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx);
	return (0);
}

int	run_game(t_game *game)
{
	print_elements(game);
	if ((unsigned int)time(NULL) > game->time_a)
		search_ennemy(game);
	if (no_more_collectibles(game))
		open_exit_door(game);
	return (0);
}

/* ne pas oublier de free lors des inits*/
void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit (0);
	game->x_map = ft_strlen(game->map[0]);
	game->y_map = ft_get_size_array(game->map);
	game->time_a = (unsigned int)time(NULL);
	get_player_position(game);
	game->moves = 0;
	game->win = mlx_new_window(game->mlx,
			game->x_map * CELL, game->y_map * CELL, "Paper Mario");
	if (!game->win)
		exit (0);
	get_images(game);
	// mlx_hook(game->win, 2, 1L << 0, get_input_keyboard, game);
	mlx_key_hook(game->win, get_input_keyboard, game);
	mlx_loop_hook(game->mlx, run_game, game);
	// mlx_hook(game->win, 17, 0, mlx_loop_end, game->mlx);
	system("cvlc sound/march_ahead.wav &");
	mlx_loop(game->mlx);
}
