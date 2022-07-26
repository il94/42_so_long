/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:06:00 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/26 01:06:00 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_e(t_game *game, int i, int j, char code)
{
	int	i_ennemy;
	int	j_ennemy;

	i_ennemy = i;
	j_ennemy = j;
	if (code == 'D')
		i_ennemy = i + 1;
	if (code == 'R')
		j_ennemy = j + 1;
	if (code == 'U')
		i_ennemy = i - 1;
	if (code == 'L')
		j_ennemy = j - 1;
	if (game->map[i_ennemy][j_ennemy] == '0' || game->map[i_ennemy][j_ennemy] == 'P')
	{
		if (game->map[i_ennemy][j_ennemy] == 'P')
			end_game(game, LOOSE);
		game->map[i][j] = '0';
		if (code == 'D')
			game->map[i_ennemy][j_ennemy] = 'd';
		if (code == 'R')
			game->map[i_ennemy][j_ennemy] = 'r';
		if (code == 'U')
			game->map[i_ennemy][j_ennemy] = 'u';
		if (code == 'L')
			game->map[i_ennemy][j_ennemy] = 'l';
	}
}

int	move_down_e(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'D' || game->map[i][j] == 'M')
	{
		if (game->map[i + 1][j] != '0' && game->map[i + 1][j] != 'P')
			return (0);
		if (game->map[i + 1][j] == 'P')
			end_game(game, LOOSE);
		game->map[i][j] = '0';
		game->map[i + 1][j] = 'd';
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
			end_game(game, LOOSE);
		game->map[i][j] = '0';
		game->map[i][j + 1] = 'r';
		return (1);
	}
	return (0);
}

int	move_up_e(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'D' || game->map[i][j] == 'R' || game->map[i][j] == 'U' || game->map[i][j] == 'M')
	{
		if (game->map[i - 1][j] != '0' && game->map[i - 1][j] != 'P')
			return (0);
		if (game->map[i - 1][j] == 'P')
			end_game(game, LOOSE);
		game->map[i][j] = '0';
		game->map[i - 1][j] = 'u';
		return (1);
	}
	return (0);
}

int	move_left_e(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'D' || game->map[i][j] == 'R' || game->map[i][j] == 'U' || game->map[i][j] == 'L' || game->map[i][j] == 'M')
	{
		if (game->map[i][j - 1] != '0' && game->map[i][j - 1] != 'P')
			return (0);
		if (game->map[i][j - 1] == 'P')
			end_game(game, LOOSE);
		game->map[i][j] = '0';
		game->map[i][j - 1] = 'l';
		return (1);
	}
	return (0);
}

int	get_new_direction(t_game *game, int i, int j)
{
	if (game->map[i + 1][j] == '0' || game->map[i + 1][j] == 'P')
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
	else if (game->map[i][j - 1] == '0' || game->map[i][j - 1] == 'P')
	{
		game->map[i][j] = '0';
		game->map[i][j - 1] = 'l';
	}
}

int	get_direction(t_game *game, int i, int j)
{
	ft_print_array(game->map);
	printf("\n=====\n");

	// if (game->map[i][j] == 'D')
	// 	move_e(game, i, j, 'D');
	// else if (game->map[i][j] == 'R')
	// 	move_e(game, i, j, 'R');
	// else if (game->map[i][j] == 'U')
	// 	move_e(game, i, j, 'U');
	// else if (game->map[i][j] == 'L')
	// 	move_e(game, i, j, 'L');
	// else
	// 	get_new_direction(game, i, j);
	// return (0);

	if (move_down_e(game, i, j))
		return (0);
	else if (move_right_e(game, i, j))
		return (0);
	else if (move_up_e(game, i, j))
		return (0);
	else if (move_left_e(game, i, j))
		return (0);
	else
		get_new_direction(game, i, j);
	return (0);
}

int	move_ennemies(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	if ((unsigned int)time(NULL) > game->time_a)
	{
		while (i < game->y_map - 1)
		{
			j = 0;
			while (j < game->x_map - 1)
			{
				if (game->map[i][j] && is_ennemies(game->map[i][j]))
					get_direction(game, i, j);
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
	game->time_a = (unsigned int)time(NULL);
	}
}

void	move_player(t_game *game, int y, int x)
{
	if (is_ennemies(game->map[y][x]))
		end_game(game, LOOSE);
	else if (game->map[y][x] != '1')
	{
		game->map[game->y_pos][game->x_pos] = '0';
		game->x_pos = x;
		game->y_pos = y;
		game->map[game->y_pos][game->x_pos] = 'P';
		ft_printf("Moves = %d\n", game->moves += 1);
	}
}
