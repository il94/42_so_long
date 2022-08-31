/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:22:59 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/31 17:22:59 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_D || keycode == KEY_S
		|| keycode == KEY_A)
		key_press_move(keycode, game);
	else if (keycode == KEY_ESC || keycode == KEY_SPACE || keycode == KEY_TAB)
		key_press_action(keycode, game);
	return (0);
}

int	key_press_move(int keycode, t_game *game)
{
	game->move_up = FALSE;
	game->move_right = FALSE;
	game->move_down = FALSE;
	game->move_left = FALSE;
	if (keycode == KEY_W)
		game->move_up = TRUE;
	else if (keycode == KEY_D)
		game->move_right = TRUE;
	else if (keycode == KEY_S)
		game->move_down = TRUE;
	else if (keycode == KEY_A)
		game->move_left = TRUE;
}

int	key_press_action(int keycode, t_game *game)
{
	int	end_delay;

	end_delay = (int)clock();
	if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx);
	if ((int)difftime(end_delay, game->start_delay) > DELAY_MIN)
	{
		if (keycode == KEY_SPACE)
		{
			if (game->move_down)
				jump(game);
			else if (game->get_hammer)
				hammer_hit(game);
		}
		else if (keycode == KEY_TAB)
			display_bar(game);
	}
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
