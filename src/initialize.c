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
	int	i;
	int	count_enemies;

	i = 0;
	count_enemies = count_entity(game->map, ENEMY);
	game->enemies = malloc((count_enemies + 1) * sizeof(t_data));
	while (i < count_enemies + 1)
	{
		game->enemies[i].count = count_enemies;
		game->enemies[i].index = count_enemies - i;
		game->enemies[i].state = 0;
		game->enemies[i].speed_animation = 30;
		i++;
	}
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
	game->coins->speed_animation = 32;
	read_map_and_array(game->map, game->coins, COIN, &get_position_entities);
}

void	initialize_star(t_game *game, t_data *star)
{
	int	count_star;

	count_star = count_entity(game->map, STAR);
	game->star = malloc(count_star * sizeof(t_data));
	game->star->count = count_star;
	game->star->index = count_star;
	game->star->state = 0;
	game->star->speed_animation = 90;
	read_map_and_array(game->map, game->star, STAR, &get_position_entities);
	game->star_appeared = FALSE;
}

void	initialize_bar(t_game *game, t_data *bar)
{
	game->bar.count = 1;
	game->bar.index = 1;
	game->bar.state = 0;
	game->bar.speed_animation = 12;
	game->bar_displayed = FALSE;
	game->max_player_steps = FALSE;
}

void	initialize_player(t_game *game, t_data *player)
{
	game->player.count = 1;
	game->player.index = 1;
	game->player.state = 0;
	game->player.speed_animation = 24;
	read_map(game->map, &game->player, PLAYER, &get_player_position);
	game->player.direction = 'L';
	game->player_steps = 0;
	game->is_hitting = FALSE;
	game->is_jumping = FALSE;
	game->move_up = FALSE;
	game->move_right = FALSE;
	game->move_down = FALSE;
	game->move_left = FALSE;
}
