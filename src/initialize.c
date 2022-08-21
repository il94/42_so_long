/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:26:25 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/21 20:26:25 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_enemies(t_game *game, t_data *enemies)
{
	int	count_enemies;

	count_enemies = count_entity(game->map, ENEMY);
	game->enemies = malloc(count_enemies * sizeof(t_data));
	game->enemies->count = count_enemies;
	game->enemies->index = count_enemies;
	game->enemies->state = 0;
	game->enemies->speed_animation = 200;
	read_map_and_array(game->map, game->enemies, ENEMY, &get_position_entities);
}

void	initialize_coins(t_game *game, t_data *coins)
{
	int	count_coins;

	count_coins = count_entity(game->map, COIN);
	game->coins = malloc(count_coins * sizeof(t_data));
	game->coins->count = count_coins;
	game->coins->index = count_coins;
	game->coins->state = 0;
	game->coins->speed_animation = 200;
	read_map_and_array(game->map, game->coins, COIN, &get_position_entities);
}

void	initialize_player(t_game *game, t_data *player)
{
	game->player.state = 0;
	game->player.speed_animation = 12;
	read_map(game->map, &game->player, PLAYER, &get_player_position);
	game->player_direction = 'P';
	game->player_steps = 0;
	game->is_hitting = FALSE;
	game->is_jumping = FALSE;
	game->move_up = FALSE;
	game->move_right = FALSE;
	game->move_down = FALSE;
	game->move_left = FALSE;
}
