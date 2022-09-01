/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:56:49 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/21 15:09:24 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit (0);
	game->win = mlx_new_window(game->mlx,
			game->max.x * CELL, game->max.y * CELL, "So Long");
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
	initialize_all_elements(game);
	game->start_delay = (int)clock();
	// system("cvlc sound/march_ahead.wav &");
}

void	initialize_all_elements(t_game *game)
{
	initialize_player(game, &game->player, &game->i_player);
	initialize_star(game, &game->star, &game->i_star);
	initialize_hammer(game, &game->hammer);
	initialize_bar(game, &game->stepbar);
	initialize_coins(game, &game->coins, &game->i_coins);
	initialize_enemies(game, &game->enemies, &game->i_enemies);
}

int	count_entity(char **map, char *target)
{
	int		result;
	t_pos	pos;

	result = 0;
	pos.y = 1;
	while (map[pos.y])
	{
		pos.x = 1;
		while (map[pos.y][pos.x])
		{
			if (is(target, map[pos.y][pos.x]))
				result++;
			pos.x++;
		}
		pos.y++;
	}
	return (result);
}

void	get_position_entities(char **map, t_list **element, char *target)
{
	t_list	*start;
	t_pos	pos;

	start = *element;
	pos.y = 1;
	while (map[pos.y])
	{
		pos.x = 1;
		while (map[pos.y][pos.x])
		{
			if (is(target, map[pos.y][pos.x]))
			{
				(*element)->pos = pos;
				(*element)->cell.x = pos.x * CELL + CELL / 2;
				(*element)->cell.y = pos.y * CELL + CELL / 2;
				*element = (*element)->next;
			}
			pos.x++;
		}
		pos.y++;
	}
	*element = start;
}
