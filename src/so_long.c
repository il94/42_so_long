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

int	close_win(int keycode, t_game *game)
{
	// if (keycode == KEY_W)
	// 	move_w();
	// else if (keycode == KEY_D)
	// 	move_d();
	// else if (keycode == KEY_S)
	// 	move_s();
	// else if (keycode == KEY_A)
	// 	move_a();
	if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx);
	return (0);
}

void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx) //ne pas oublier de free
		exit (0);
	game->x_map = ft_strlen(game->map[0]);
	game->y_map = ft_get_size_array(game->map);
	game->win = mlx_new_window(game->mlx, game->x_map * CELL, game->y_map * CELL, "Paper Mario");
	if (!game->win) //ne pas oublier de free
		exit (0);
	get_images(game);
	// mlx_hook(game->win, 2, 17, close_win, game);
	mlx_loop_hook(game->mlx, print_elements, game);
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
	mlx_destroy_image(game->mlx, game->mushroom.img);
	mlx_destroy_image(game->mlx, game->star.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free_array(game->map);
	free(game->mlx);
}
