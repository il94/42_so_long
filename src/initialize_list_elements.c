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

int	initialize_coins(t_game *game, t_list **coins, t_info *i_coins)
{
	int	i;
	int	count_coins;

	count_coins = count_entity(game->map, COIN);
	i = 0;
	*coins = ft_lstnew();
	while (i++ < count_coins - 1)
		ft_lstadd_back(coins, ft_lstnew());
	get_position_entities(game->map, coins, COIN);
	i_coins->state = 0;
	i_coins->speed_animation = 180;
	return (ft_lstcorrect(game->coins, count_coins));
}

int	initialize_enemies(t_game *game, t_list **enemies, t_info *i_enemies)
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
	get_position_entities(game->map, enemies, ENEMY);
	i_enemies->state = 0;
	i_enemies->speed_animation = 180;
	return (ft_lstcorrect(game->enemies, count_enemies));
}
