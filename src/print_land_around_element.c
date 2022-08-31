/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_land_around_element.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:48:38 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/31 18:48:38 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_land_around_player(t_game *game, t_pos pos_player)
{
	t_pos	pos_trgt;

	pos_trgt = pos_player;
	pos_trgt.y -= 2;
	if (pos_trgt.y < 0)
		pos_trgt.y = 0;
	while (pos_trgt.y <= pos_player.y + 1)
	{
		pos_trgt.x = pos_player.x - 1;
		if (pos_trgt.x < 0)
			pos_trgt.x = 0;
		while (pos_trgt.x <= pos_player.x + 1)
		{
			put_land(game, pos_trgt);
			pos_trgt.x++;
		}
		pos_trgt.y++;
	}
}

void	put_land_around_enemies(t_game *game, t_list *enemies)
{
	t_pos	pos_trgt;

	while (enemies)
	{
		pos_trgt = enemies->pos;
		pos_trgt.y--;
		while (pos_trgt.y <= enemies->pos.y + 1)
		{
			put_land(game, pos_trgt);
			pos_trgt.y++;
		}
		pos_trgt.y = enemies->pos.y;
		pos_trgt.x--;
		while (pos_trgt.x <= enemies->pos.x + 1)
		{
			put_land(game, pos_trgt);
			pos_trgt.x++;
		}
		enemies = enemies->next;
	}
}

void	put_land_on_coins(t_game *game, t_list *coins)
{
	while (coins)
	{
		put_land(game, coins->pos);
		coins = coins->next;
	}
}

void	put_land_around_bar(t_game *game, t_pos pos_stepbar)
{
	t_pos	pos_trgt;

	pos_trgt = pos_stepbar;
	while (pos_trgt.x <= game->max.x - 1)
	{
		put_land(game, pos_trgt);
		pos_trgt.x++;
	}
}
