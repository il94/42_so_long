/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoubir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:09:21 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/25 22:09:21 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	collision_player_ennemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->ennemy_count)
	{
		if (game->ennemies[i].cell.x >= game->player_cell.x - 20 /* left */
			&& game->ennemies[i].cell.x <= game->player_cell.x + 20 /* right */
			&& game->ennemies[i].cell.y >= game->player_cell.y - 25 /* up */
			&& game->ennemies[i].cell.y <= game->player_cell.y + 25) /* down */
			return (1);
		i++;
	}
	return (0);
}

void	jump(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->ennemy_count)
	{
		if (game->player_direction == 'l' || game->player_direction == 'r')
		{
			if (game->ennemies[i].cell.x >= game->player_cell.x - 24 && game->ennemies[i].cell.x <= game->player_cell.x + 24 && game->ennemies[i].cell.y >= game->player_cell.y - 50 && game->ennemies[i].cell.y <= game->player_cell.y + 10)
			{
				game->map[game->player_pos.y - 1][game->player_pos.x] = '0';
				game->ennemies[i].cell.x = 1;
				game->ennemies[i].cell.y = 1;
				game->ennemies[i].pos.x = 1;
				game->ennemies[i].pos.y = 1;
			}
		}
		i++;
	}
	game->is_jumping = TRUE;
}

void	hammer_hit(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->ennemy_count)
	{
		if (game->player_direction == 'l' || game->player_direction == 'r')
		{
			if (game->ennemies[i].cell.x >= game->player_cell.x - 24 && game->ennemies[i].cell.x <= game->player_cell.x + 24 && game->ennemies[i].cell.y >= game->player_cell.y - 50 && game->ennemies[i].cell.y <= game->player_cell.y + 10)
			{
				game->map[game->player_pos.y - 1][game->player_pos.x] = '0';
				game->ennemies[i].cell.x = 1;
				game->ennemies[i].cell.y = 1;
				game->ennemies[i].pos.x = 1;
				game->ennemies[i].pos.y = 1;
			}
		}
		else if (game->player_direction == 'R')
		{
			if (game->ennemies[i].cell.x >= game->player_cell.x - 10 && game->ennemies[i].cell.x <= game->player_cell.x + 50 && game->ennemies[i].cell.y >= game->player_cell.y - 24 && game->ennemies[i].cell.y <= game->player_cell.y + 24)
			{
				game->map[game->player_pos.y][game->player_pos.x + 1] = '0';
				game->ennemies[i].cell.x = 1;
				game->ennemies[i].cell.y = 1;
				game->ennemies[i].pos.x = 1;
				game->ennemies[i].pos.y = 1;
			}
		}
		else if (game->player_direction == 'L')
		{
			if (game->ennemies[i].cell.x >= game->player_cell.x - 50 && game->ennemies[i].cell.x <= game->player_cell.x + 10 && game->ennemies[i].cell.y >= game->player_cell.y - 24 && game->ennemies[i].cell.y <= game->player_cell.y + 24)
			{
				game->map[game->player_pos.y][game->player_pos.x - 1] = '0';
				game->ennemies[i].cell.x = 1;
				game->ennemies[i].cell.y = 1;
				game->ennemies[i].pos.x = 1;
				game->ennemies[i].pos.y = 1;
			}
		}
		i++;
	}
	game->is_hitting = TRUE;
}

void	get_ennemies_data(t_game *game, t_pos pos)
{
	static int	i;

	if (!i)
		i = 0;
	game->ennemies[i].pos = pos;
	game->ennemies[i].cell.x = pos.x * CELL + CELL / 2;
	game->ennemies[i].cell.y = pos.y * CELL + CELL / 2;
	i++;
}

void	get_ennemies_count(t_game *game, t_pos pos)
{
	game->ennemy_count++;
}

int	is_surrounded_by(t_game *game, t_pos pos, char c)
{
	return (game->map[pos.y + 1][pos.x] == c
			&& game->map[pos.y][pos.x + 1] == c
			&& game->map[pos.y - 1][pos.x] == c
			&& game->map[pos.y][pos.x - 1] == c);
}

int	is_valid_char(char c, int *cep)
{
	int	i;

	i = 0;
	while (VALID_CHAR[i])
	{
		if (c == VALID_CHAR[i])
		{
			if (c == 'C')
				cep[0]++;
			else if (c == 'E')
				cep[1]++;
			else if (c == 'P')
				cep[2]++;
			return (VALID_CHAR[i]);
		}
		i++;
	}
	return (0);
}

int	is(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (str[i]);
		i++;
	}
	return (0);
}
