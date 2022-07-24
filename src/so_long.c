/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 00:53:50 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/24 00:53:50 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *game)
{
	if (is_ennemies(game->map[game->y_player - 1][game->x_player]))
	{
		ft_printf("Game Over\n");
		mlx_loop_end(game->mlx);
	}
	else if (game->map[game->y_player - 1][game->x_player] != '1')
	{
		game->map[game->y_player][game->x_player] = '0';
		game->y_player -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		// if (game->moves % 2 != 0)
		// 	move_ennemies(game);
		ft_printf("Moves = %d\n", game->moves += 1);
	}
}

void	move_right(t_game *game)
{
	if (is_ennemies(game->map[game->y_player][game->x_player + 1]))
	{
		ft_printf("Game Over\n");
		mlx_loop_end(game->mlx);
	}
	else if (game->map[game->y_player][game->x_player + 1] != '1')
	{
		game->map[game->y_player][game->x_player] = '0';
		game->x_player += 1;
		game->map[game->y_player][game->x_player] = 'P';
		// if (game->moves % 2 != 0)
		// 	move_ennemies(game);
		ft_printf("Moves = %d\n", game->moves += 1);
	}
}

void	move_down(t_game *game)
{
	if (is_ennemies(game->map[game->y_player + 1][game->x_player]))
	{
		ft_printf("Game Over\n");
		mlx_loop_end(game->mlx);
	}
	else if (game->map[game->y_player + 1][game->x_player] != '1')
	{
		game->map[game->y_player][game->x_player] = '0';
		game->y_player += 1;
		game->map[game->y_player][game->x_player] = 'P';
		// if (game->moves % 2 != 0)
		// 	move_ennemies(game);
		ft_printf("Moves = %d\n", game->moves += 1);
	}
}

void	move_left(t_game *game)
{
	if (is_ennemies(game->map[game->y_player][game->x_player - 1]))
	{
		ft_printf("Game Over\n");
		mlx_loop_end(game->mlx);
	}
	else if (game->map[game->y_player][game->x_player - 1] != '1')
	{
		game->map[game->y_player][game->x_player] = '0';
		game->x_player -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		// if (game->moves % 2 != 0)
		// 	move_ennemies(game);
		ft_printf("Moves = %d\n", game->moves += 1);
	}
}

int	close_win(int keycode, t_game *game)
{
	// if (keycode == 1)
	// 	mlx_loop_end(game->mlx);
	printf("key = %d\n", keycode);
}

int	get_input_keyboard(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx);
	return (0);
}

void	get_player_position(t_game *game)
{
	game->x_player = 1;
	game->y_player = 0;
	while (game->map[game->y_player][game->x_player] != 'P')
	{
		game->y_player += 1;
		game->x_player = 1;
		while(game->map[game->y_player][game->x_player] && game->map[game->y_player][game->x_player] != 'P')
			game->x_player += 1;
	}
}

int	move_up_e(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'D' || game->map[i][j] == 'R' || game->map[i][j] == 'U' || game->map[i][j] == 'M')
	{
		if (game->map[i - 1][j] != '0' && game->map[i - 1][j] != 'P')
			return (0);
		if (game->map[i - 1][j] == 'P')
		{
			ft_printf("Game Over\n");
			mlx_loop_end(game->mlx);
		}
		game->map[i][j] = '0';
		game->map[i - 1][j] = 'u';
		return (1);
	}
	return (0);
}

int	move_right_e(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'D' || game->map[i][j] == 'R' || game->map[i][j] == 'M')
	{
		if (game->map[i][j + 1] != '0' && game->map[i][j + 1] != 'P')
			return (0);
		if (game->map[i][j + 1] == 'P')
		{
			ft_printf("Game Over\n");
			mlx_loop_end(game->mlx);
		}
		game->map[i][j] = '0';
		game->map[i][j + 1] = 'r';
		return (1);
	}
	return (0);
}

int	move_down_e(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'D' || game->map[i][j] == 'M')
	{
		if (game->map[i + 1][j] != '0' && game->map[i + 1][j] != 'P')
			return (0);
		if (game->map[i + 1][j] == 'P')
		{
			ft_printf("Game Over\n");
			mlx_loop_end(game->mlx);
		}
		game->map[i][j] = '0';
		game->map[i + 1][j] = 'd';
		return (1);
	}
	return (0);
}

int	move_left_e(t_game *game, int i, int j)
{
	// if (game->map[i][j - 1] != '0' && game->map[i][j - 1] != 'P')
	// {
	// 	game->map[i][j] = 'd';
	// 	return (0);
	// }
	if (game->map[i][j - 1] == 'P')
	{
		ft_printf("Game Over\n");
		mlx_loop_end(game->mlx);
	}
	if (game->map[i][j - 1] == '0' || game->map[i][j - 1] == 'P')
	{
		game->map[i][j] = '0';
		game->map[i][j - 1] = 'l';
	}
	else if (game->map[i + 1][j] == '0' || game->map[i + 1][j - 1] == 'P')
	{
		game->map[i][j] = '0';
		game->map[i + 1][j] = 'd';
	}
	else if (game->map[i][j + 1] == '0' || game->map[i][j + 1] == 'P')
	{
		game->map[i][j] = '0';
		game->map[i][j + 1] = 'r';
	}
	else if (game->map[i - 1][j] == '0' || game->map[i - 1][j] == 'P')
	{
		game->map[i][j] = '0';
		game->map[i - 1][j] = 'u';
	}
	return (1);	
}

int	move_ennemies(t_game *game)
{
	int	i;
	int	j;

	i = 1;
				ft_print_array(game->map);
				printf("\n=======\n");

	while (i < game->y_map - 1)
	{
		j = 0;
		while (j < game->x_map - 1)
		{
			if (game->map[i][j] && is_ennemies(game->map[i][j]))
			{
				if (!move_down_e(game, i, j))
				{
					if (!move_right_e(game, i, j))
					{
						if (!move_up_e(game, i, j))
						{
							if (!move_left_e(game, i, j))
								move_down_e(game, i, j);
						}
					}
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < game->y_map - 1)
	{
		j = 0;
		while (j < game->x_map - 1)
		{
			if (game->map[i][j] && is_ennemies_m(game->map[i][j]))
				game->map[i][j] = ft_toupper(game->map[i][j]);
			j++;
		}
		i++;
	}
}

void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx) //ne pas oublier de free
		exit (0);
	game->x_map = ft_strlen(game->map[0]);
	game->y_map = ft_get_size_array(game->map);
	game->time_a = (unsigned int)time(NULL);
	get_player_position(game);
	game->moves = 0;
	game->win = mlx_new_window(game->mlx, game->x_map * CELL, game->y_map * CELL, "PM");
	if (!game->win) //ne pas oublier de free
		exit (0);
	get_images(game);
	// mlx_hook(game->win, 2, 17, get_input_keyboard, game);
	mlx_loop_hook(game->mlx, print_elements, game);
	// mlx_loop_hook(game->mlx, move_ennemies, game);
	mlx_mouse_hook(game->win, close_win, game);
	mlx_key_hook(game->win, get_input_keyboard, game);
}

int	can_be_started(int ac, char **av, t_game *game)
{
	if (ac != 2)
	{
		ft_printf("Bad input\n");
		return (0);
	}
	if (!is_valid_map(&game->map, av[1]))
	{
		ft_printf("Invalid map\n");
		exit (0);
	}
	return (1);
}

void	destroy_elements(t_game *game)
{
	mlx_destroy_image(game->mlx, game->floor.img);
	mlx_destroy_image(game->mlx, game->wall_one.img);
	mlx_destroy_image(game->mlx, game->wall_mid.img);
	mlx_destroy_image(game->mlx, game->wall_top.img);
	mlx_destroy_image(game->mlx, game->wall_bot.img);
	mlx_destroy_image(game->mlx, game->mario.img);
	mlx_destroy_image(game->mlx, game->goomba.img);
	mlx_destroy_image(game->mlx, game->goomba_b.img);
	mlx_destroy_image(game->mlx, game->goomba_g.img);
	mlx_destroy_image(game->mlx, game->goomba_r.img);
	mlx_destroy_image(game->mlx, game->mushroom.img);
	mlx_destroy_image(game->mlx, game->star.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free_array(game->map);
	free(game->mlx);
}
