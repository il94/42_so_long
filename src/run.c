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

// void	print_lists(t_list *lst)
// {
// 	printf("============PRINT LIST============\n");
// 	while (lst)
// 	{
// 		printf("pos.x = %d && pos.y = %d\n", lst->pos.x, lst->pos.y);
// 		lst = lst->next;
// 	}
// 	// printf("============PRINT LIST============\n");
// 	// while (lst)
// 	// {
// 	// 	lst = lst->prev;
// 	// 	printf("pos.x = %d && pos.y = %d\n", lst->pos.x, lst->pos.y);
// 	// }
// }

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
	// print_lists(game->enemies);
	// printf("========\n");
	// printf("pos.x = %d && pos.y = %d\n", game->player.pos.x, game->player.pos.y);
	// printf("========\n");
	// printf("enemies = %d, pos = x: %d y: %d\n", game->enemies->count, game->enemies[0].pos.x, game->enemies[0].pos.y);
	// printf("coins = %d, pos = x: %d y: %d\n", game->coins->count, game->coins[0].pos.x, game->coins[0].pos.y);
	// printf("count :%d xpos: %d ypos: %d xcell: %d ycell: %d\n", &game->star.count, &game->star.pos.x, &game->star.pos.y, &game->star.cell.x, &game->star.cell.y);
		// printf("pos.x = %d && pos.y = %d\n", src->pos.x, src->pos.y);
	// usleep(4000);
	put_render(game);
	// print_lists(game->enemies);
	if (game->i_coins.state++ >= game->i_coins.speed_animation)
		game->i_coins.state = 0;
	if (game->star.state++ >= game->star.speed_animation)
		game->star.state = 0;
	move_player(game);
	move_all_enemies(game);
	if (game->enemies && check_hbox(game->player.cell, game->enemies, H_ENEMY))
		end_game(game, LOOSE);
	if (!game->star_appeared && !game->coins)
		appearing_star(game, game->star.pos);
	return (0);
}

/* ne pas oublier de free lors des inits*/
void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit (0);
	game->win = mlx_new_window(game->mlx,
			game->max.x * CELL, game->max.y * CELL, "Paper mario");
	if (!game->win)
		exit (0);
	get_all_images(game);
	get_all_addresses(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0, mlx_loop_end, game->mlx);
	mlx_loop_hook(game->mlx, run_game, game);
	mlx_loop(game->mlx);
}

void	initialize_data_game(t_game *game, char *file)
{
	get_data_map(file, &game->map, &game->max);
	get_data_elements(game);
	system("cvlc sound/march_ahead.wav &");
}

