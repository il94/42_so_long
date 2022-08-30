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

void	initialize_enemies(t_game *game, t_list **enemies, t_info *i_enemies)
{
	int	i;
	int	count_enemies;

	count_enemies = count_entity(game->map, ENEMY);
	i = 0;
	*enemies = NULL;
	if (count_enemies > 0)
		*enemies = ft_lstnew();
	while (i++ < count_enemies - 1)
		ft_lstadd_back(enemies, ft_lstnew());
	read_map_and_list(game->map, enemies, ENEMY, lget_position_entities);
	i_enemies->state = 0;
	i_enemies->speed_animation = 180;
}

void	initialize_coins(t_game *game, t_list **coins, t_info *i_coins)
{
	int	i;
	int	count_coins;

	count_coins = count_entity(game->map, COIN);
	i = 0;
	*coins = ft_lstnew();
	while (i++ < count_coins - 1)
		ft_lstadd_back(coins, ft_lstnew());
	read_map_and_list(game->map, coins, COIN, lget_position_entities);
	i_coins->state = 0;
	i_coins->speed_animation = 180;
}

void	initialize_star(t_game *game, t_list *star, t_info *i_star)
{
	read_map_and_list(game->map, &star, STAR, lget_position_entities);
	i_star->state = 0;
	i_star->speed_animation = 90;
	game->star_appeared = FALSE;
}

// void	initialize_bar(t_game *game, t_data *stepbar)
// {
// 	game->stepbar.pos.x = 0;
// 	game->stepbar.pos.y = 0;
// 	game->stepbar.cell.x = 0;
// 	game->stepbar.cell.y = 0;
// 	game->bar_display = FALSE;
// 	game->max_player_steps = FALSE;
// }

void	initialize_bar(t_game *game, t_list *stepbar)
{
	game->stepbar.pos.x = 0;
	game->stepbar.pos.y = 0;
	game->stepbar.cell.x = 0;
	game->stepbar.cell.y = 0;
	game->bar_display = FALSE;
	game->max_player_steps = FALSE;
}

void	initialize_player(t_game *game, t_list *player, t_info *i_player)
{
	read_map_and_list(game->map, &player, PLAYER, lget_position_entities);
	player->dir = 'L';
	player->next = NULL;
	player->prev = NULL;
	game->i_player.state = 0;
	game->i_player.speed_animation = 24;
	game->player_steps = 0;
	game->hitting = FALSE;
	game->jumping = FALSE;
	game->move_up = FALSE;
	game->move_right = FALSE;
	game->move_down = FALSE;
	game->move_left = FALSE;
}
