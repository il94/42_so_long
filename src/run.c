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
	if (keycode == KEY_W)
	{
		if (game->map[game->player.y - 1][game->player.x - 1] == '1')
		{
			if (game->cell.x < game->player.x * CELL + (CELL / 3))
				printf("BBBBBBBBBBBBBBBBBBBB\n");
		}
		// if (game->map[game->player.y - 1][game->player.x + 1] == '1')
		// {
		// 	if (game->cell.x < game->player.x * CELL + (CELL / 3))
		// 		printf("AAAAAAAAAAAAAAAAAAAAA\n");
		// }
		if (game->map[game->player.y - 1][game->player.x] != '1')
			game->cell.y -= 8;
		else if (game->player.y * CELL < game->cell.y)
			game->cell.y -= 8;
		if (game->cell.y / CELL < game->player.y)
		{
			if (is(PLAYER, game->map[game->player.y][game->player.x]) == 'a'
				|| is(PLAYER, game->map[game->player.y][game->player.x]) == 'A')
				move_player(game, game->player.y - 1, game->player.x, 'a');
			else
				move_player(game, game->player.y - 1, game->player.x, 'b');
		}
	}
	else if (keycode == KEY_D)
	{
		if (game->map[game->player.y][game->player.x + 1] != '1')
			game->cell.x += 8;
		else if (game->player.x * CELL >= game->cell.x - CELL / 2)
			game->cell.x += 8;
		if (game->cell.x > game->player.x * CELL - (CELL / 3) + CELL)
		// if ((double)game->cell.x / CELL > (double)game->player.x + 1.4)
			move_player(game, game->player.y, game->player.x + 1, 'B');
	}
	else if (keycode == KEY_S)
	{
		if (game->map[game->player.y + 1][game->player.x] != '1')
			game->cell.y += 8;
		else if (game->player.y * CELL > game->cell.y - CELL)
			game->cell.y += 8;
		if (game->cell.y / CELL > game->player.y)
		{
			if (game->map[game->player.y][game->player.x] == 'a'
				|| game->map[game->player.y][game->player.x] == 'A')
				move_player(game, game->player.y + 1, game->player.x, 'A');
			else
				move_player(game, game->player.y + 1, game->player.x, 'B');
		}
	}
	else if (keycode == KEY_A)
	{
		if (game->map[game->player.y][game->player.x - 1] != '1')
			game->cell.x -= 8;
		else if (game->player.x * CELL <= game->cell.x - CELL / 2)
			game->cell.x -= 8;
		if (game->cell.x < game->player.x * CELL + (CELL / 3))
		// if ((double)game->cell.x / CELL < (double)game->player.x - 0.4)
			move_player(game, game->player.y, game->player.x - 1, 'A');
	}
	// else if (keycode == KEY_SPACE)
	// 	reboot_game(game);
	// else if (keycode == KEY_TAB)
	// 	reboot_game(game);
	else if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx);
	ft_print_array(game->map);
	printf("CELL x = %d, y = %d\n", game->cell.x, game->cell.y);
	printf("PLAYER x = %d, y = %d\n", game->player.x, game->player.y);
	return (0);
}

		// if (game->cell.x > game->player.x * CELL - (CELL / 3) + CELL)
		// if (game->cell.x < game->player.x * CELL + (CELL / 3))


int	run_game(t_game *game)
{
	static char	brk;

	print_elements(game);
	if ((unsigned int)time(NULL) > game->time_a)
		search_ennemy(game);
	if (!read_map(game, 'C', &more_collectibles) && !brk)
	{
		brk = '1';
		read_map(game, 'E', &open_exit_door);
		kill_ennemies(game);
	}
	// print_player(game);
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
	read_map(game, 'P', &get_player_position);
	game->cell.x = (game->player.x * CELL) + (CELL / 2);
	game->cell.y = (game->player.y * CELL) + CELL - (CELL / 6);
	game->direction = 'P';
	game->moves = 0;
	game->delay = 0;
	game->win = mlx_new_window(game->mlx,
			game->x_map * CELL, game->y_map * CELL, "Paper Mario");
	if (!game->win)
		exit (0);
	get_images(game);
	get_adresses(game);
	mlx_hook(game->win, 2, 1L << 0, get_input_keyboard, game);
	// mlx_key_hook(game->win, get_input_keyboard, game);
	mlx_loop_hook(game->mlx, run_game, game);
	mlx_hook(game->win, 17, 0, mlx_loop_end, game->mlx);
	system("cvlc sound/march_ahead.wav &");
	mlx_loop(game->mlx);
}
