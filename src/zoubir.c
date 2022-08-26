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

void	swap_entities(t_game *game, t_data *entity)
{
	int	i;

	i = 0;
	t_data temp;

	entity->count--;
	game->map[entity[i].pos.y][entity[i].pos.x] = '0';
	entity[i].pos.x = 0;
	entity[i].cell.x = 0;
	entity[i].pos.y = 0;
	entity[i].cell.y = 0;
	entity[i].count = 0;
	entity[i].index = 0;
	entity[i].state = 0;
	entity[i].speed_animation = 0;
	while (i < entity->index)
	{
		temp = entity[i + 1];
		printf("kill\n");
		entity[i].pos = entity[i + 1].pos;
		entity[i].cell = entity[i + 1].cell;
		entity[i].count = entity[i + 1].count;
		entity[i].index = entity[i + 1].index;
		entity[i].state = entity[i + 1].state;
		entity[i].speed_animation = entity[i + 1].speed_animation;
		i++;
	}
	put_land(game, entity[i].pos);
}

int		player_is_moving(t_game *game)
{
	return (game->move_up || game->move_right || game->move_down || game->move_left);
}

void	get_player_position(t_data *entity, t_pos pos_trgt)
{
	entity->pos = pos_trgt;
	entity->cell.x = (pos_trgt.x * CELL) + (CELL / 2);
	entity->cell.y = (pos_trgt.y * CELL) + CELL - (CELL / 6);
}

void	get_position_entities(t_data *entities, t_pos pos_trgt)
{
	entities->pos = pos_trgt;
	entities->cell.x = pos_trgt.x * CELL + CELL / 2;
	entities->cell.y = pos_trgt.y * CELL + CELL / 2;
}

int	count_entity(char **map, char *target)
{
	int	result;
	t_pos	pos;

	result = 0;
	pos.y = 1;
	while (map[pos.y])
	{
		pos.x = 1;
		while (map[pos.y][pos.x])
		{
			if (is(target, map[pos.y][pos.x]))
				result++;;
			pos.x++;
		}
		pos.y++;
	}
	return (result);
}

int	player_get_coin(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->coins->index)
	{
		if (game->coins[i].cell.x >= game->player.cell.x - 20 /* left */
			&& game->coins[i].cell.x <= game->player.cell.x + 20 /* right */
			&& game->coins[i].cell.y >= game->player.cell.y - 25 /* up */
			&& game->coins[i].cell.y <= game->player.cell.y + 25) /* down */
		{
			system("cvlc sound/coin.wav &");
			if (game->coins[i].pos.x != 0)
				game->map[game->coins[i].pos.y][game->coins[i].pos.x] = '0';
			game->coins[i].pos.x = 0;
			game->coins[i].pos.y = 1;
			game->coins[i].cell.x = 1;
			game->coins[i].cell.y = 1;
			game->coins->count--;
			return (1);
		}
		i++;
	}
	return (0);
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
			else if (c == 'H')
				cep[3]++;
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
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (str[i]);
		i++;
	}
	return (0);
}
