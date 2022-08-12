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
	t_axe	cell_trgt;
	t_axe	pos_trgt;

	cell_trgt = game->cell;
	pos_trgt = game->player;
	if (keycode == KEY_W)
	{
		cell_trgt.y -= 8;
		pos_trgt.y -= 1;
	}
	else if (keycode == KEY_D)
	{
		cell_trgt.x += 8;
		pos_trgt.x += 1;
	}
	else if (keycode == KEY_S)
	{
		cell_trgt.y += 8;
		pos_trgt.y += 1;
	}
	else if (keycode == KEY_A)
	{
		cell_trgt.x -= 8;
		pos_trgt.x -= 1;
	}
	else if (keycode == KEY_SPACE && game->get_hammer == 1)
		hammer_hit(game);
	// else if (keycode == KEY_TAB)
	// 	reboot_game(game);
	else if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx);
	move_player(game, cell_trgt, pos_trgt, keycode);
	return (0);
}

int	run_game(t_game *game)
{
	put_elements(game);
	while (game->i_ennemy < game->ennemy_count)
	{
		get_ennemy_direction(game, game->ennemies[game->i_ennemy].pos, game->ennemies[game->i_ennemy].cell);
		game->i_ennemy++;
	}
	game->i_ennemy = 0;
	spawn_ennemy(game);
	if (game->all_coins == 0 && !read_map(game, 'C', &more_collectibles))
	{
		game->all_coins = 1;
		read_map(game, 'E', &open_exit_door);
		kill_ennemies(game);
	}
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
	game->ennemy_count = 0;
	read_all_map(game, 'M', &get_ennemies_count);
	game->ennemies = malloc(game->ennemy_count * sizeof(t_data));
	if (!game->ennemies)
		/* free */
	game->ennemies = NULL;
	read_all_map(game, 'M', &get_ennemies_data);
	game->i_ennemy = 0;
	game->cell.x = (game->player.x * CELL) + (CELL / 2);
	game->cell.y = (game->player.y * CELL) + CELL - (CELL / 6);
	game->direction = 'P';
	game->state = 0;
	game->state_ennemy = 0;
	game->speed_ennemy = 200;
	game->moves = 0;
	game->move_ennemy = 0;
	game->all_coins = 0;
	game->get_hammer = 0;
	game->get_boots = 0;
	game->delay = 0;
	game->night = 0;
	game->win = mlx_new_window(game->mlx,
			game->x_map * CELL, game->y_map * CELL, "Paper Mario");
	if (!game->win)
		exit (0);
	get_images(game);
	get_adresses(game);
	mlx_hook(game->win, 2, 1L << 0, get_input_keyboard, game);
	mlx_loop_hook(game->mlx, run_game, game);
	mlx_hook(game->win, 17, 0, mlx_loop_end, game->mlx);
	system("cvlc sound/march_ahead.wav &");
	mlx_loop(game->mlx);
}
