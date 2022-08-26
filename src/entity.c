/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:58:45 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/26 20:13:49 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	kill_enemy(t_game *game, char **map, t_data *enemy)
{
	system("cvlc sound/goomba.wav &");
	if (enemy->pos.x != 0)
		map[enemy->pos.y][enemy->pos.x] = '0';
	enemy->pos.x = 1;
	enemy->pos.y = 1;
	enemy->cell.x = 24;
	enemy->cell.y = 24;
}

int	collision_player_coin(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->coins->index)
	{
		if (game->coins[i].cell.x >= game->player.cell.x - 10 /* left */
			&& game->coins[i].cell.x <= game->player.cell.x + 10 /* right */
			&& game->coins[i].cell.y >= game->player.cell.y - 25 /* up */
			&& game->coins[i].cell.y <= game->player.cell.y + 20) /* down */
			return (1);
		i++;
	}
	return (0);
}

int	collision_player_enemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemies->index)
	{
		if (game->enemies[i].cell.x >= game->player.cell.x - 20 /* left */
			&& game->enemies[i].cell.x <= game->player.cell.x + 20 /* right */
			&& game->enemies[i].cell.y >= game->player.cell.y - 25 /* up */
			&& game->enemies[i].cell.y <= game->player.cell.y + 25) /* down */
			return (1);
		i++;
	}
	return (0);
}

void	jump(t_game *game)
{
	int	i;

	i = 0;
	game->jumping = TRUE;
    system("cvlc sound/jump.wav &");
	while (i < game->enemies->index)
	{
		if (game->enemies[i].cell.x >= game->player.cell.x - 24 && game->enemies[i].cell.x <= game->player.cell.x + 24 && game->enemies[i].cell.y >= game->player.cell.y - 10 && game->enemies[i].cell.y <= game->player.cell.y + 50)
			swap_entities(game, &game->enemies[i]);
		i++;
	}
}

void	hammer_hit(t_game *game)
{
	int	i;
	t_pos	trgt;
	t_pos	death;

	death.x = 0;
	death.y = 0;
	i = 0;
	trgt = game->player.pos;
    system("cvlc sound/hammer.wav &");
	while (i < game->enemies->index)
	{
		if (game->player.direction == 'l' || game->player.direction == 'r')
		{
			if (game->enemies[i].cell.x >= game->player.cell.x - 24 && game->enemies[i].cell.x <= game->player.cell.x + 24 && game->enemies[i].cell.y >= game->player.cell.y - 50 && game->enemies[i].cell.y <= game->player.cell.y + 10)
				swap_entities(game, &game->enemies[i]);
		}
		else if (game->player.direction == 'R')
		{
			if (game->enemies[i].cell.x >= game->player.cell.x - 10 && game->enemies[i].cell.x <= game->player.cell.x + 50 && game->enemies[i].cell.y >= game->player.cell.y - 24 && game->enemies[i].cell.y <= game->player.cell.y + 24)
				swap_entities(game, &game->enemies[i]);
		}
		else if (game->player.direction == 'L')
		{
			if (game->enemies[i].cell.x >= game->player.cell.x - 50 && game->enemies[i].cell.x <= game->player.cell.x + 10 && game->enemies[i].cell.y >= game->player.cell.y - 24 && game->enemies[i].cell.y <= game->player.cell.y + 24)
				swap_entities(game, &game->enemies[i]);
		}
		i++;
	}
	game->hitting = TRUE;
}