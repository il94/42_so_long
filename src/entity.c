/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:58:45 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/20 19:53:10 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	kill_enemy(char **map, t_data *enemy)
{
	system("cvlc sound/goomba.wav &");
	if (enemy->pos.x != 0)
		map[enemy->pos.y][enemy->pos.x] = '0';
	enemy->pos.x = 0;
	enemy->pos.y = 1;
	enemy->cell.x = 1;
	enemy->cell.y = 1;
}

int	collision_player_enemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_index)
	{
		if (game->enemies[i].cell.x >= game->player_cell.x - 20 /* left */
			&& game->enemies[i].cell.x <= game->player_cell.x + 20 /* right */
			&& game->enemies[i].cell.y >= game->player_cell.y - 25 /* up */
			&& game->enemies[i].cell.y <= game->player_cell.y + 25) /* down */
			return (1);
		i++;
	}
	return (0);
}

void	jump(t_game *game)
{
	int	i;

	i = 0;
	game->is_jumping = TRUE;
    system("cvlc sound/jump.wav &");
	while (i < game->enemy_index)
	{
		if (game->enemies[i].cell.x >= game->player_cell.x - 24 && game->enemies[i].cell.x <= game->player_cell.x + 24 && game->enemies[i].cell.y >= game->player_cell.y - 10 && game->enemies[i].cell.y <= game->player_cell.y + 50)
		{
			game->map[game->player_pos.y + 1][game->player_pos.x] = '0';
			game->enemies[i].cell.x = 1;
			game->enemies[i].cell.y = 1;
			game->enemies[i].pos.x = 1;
			game->enemies[i].pos.y = 1;
			game->enemy_count--;
		}
		i++;
	}
}

void	hammer_hit(t_game *game)
{
	int	i;
	t_pos	trgt;

	i = 0;
	trgt = game->player_pos;
    system("cvlc sound/hammer.wav &");
	while (i < game->enemy_index)
	{
		if (game->player_direction == 'l' || game->player_direction == 'r')
		{
			if (game->enemies[i].cell.x >= game->player_cell.x - 24 && game->enemies[i].cell.x <= game->player_cell.x + 24 && game->enemies[i].cell.y >= game->player_cell.y - 50 && game->enemies[i].cell.y <= game->player_cell.y + 10)
			{
				kill_enemy(game->map, &game->enemies[i]);
				game->enemy_count--;
			}
		}
		else if (game->player_direction == 'R')
		{
			if (game->enemies[i].cell.x >= game->player_cell.x - 10 && game->enemies[i].cell.x <= game->player_cell.x + 50 && game->enemies[i].cell.y >= game->player_cell.y - 24 && game->enemies[i].cell.y <= game->player_cell.y + 24)
			{
				kill_enemy(game->map, &game->enemies[i]);
				game->enemy_count--;
			}
		}
		else if (game->player_direction == 'L')
		{
			if (game->enemies[i].cell.x >= game->player_cell.x - 50 && game->enemies[i].cell.x <= game->player_cell.x + 10 && game->enemies[i].cell.y >= game->player_cell.y - 24 && game->enemies[i].cell.y <= game->player_cell.y + 24)
			{
				kill_enemy(game->map, &game->enemies[i]);
				game->enemy_count--;
			}
		}
		i++;
	}
	game->is_hitting = TRUE;
}