/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:02:52 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/11 23:02:52 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	increment_element_states(t_game *game)
{
	if (game->coins && game->i_coins.state++ >= game->i_coins.speed_animation)
		game->i_coins.state = 0;
	if (game->star_appeared
		&& game->i_star.state++ >= game->i_star.speed_animation)
		game->i_star.state = 0;
}

int	appearing_star(t_game *game, t_pos pos)
{
	game->map[pos.y][pos.x] = 'e';
	game->star_appeared = TRUE;
	game->land_displayed = FALSE;
	system("pkill vlc");
	system("cvlc sound/star_spawn.wav &");
	sleep(13);
	ft_lstclear(&game->enemies);
	system("cvlc sound/star_way.wav &");
	return (1);
}

int	enemy_proximity(char **map, t_pos player, t_pos pos)
{
	t_pos	trgt;

	trgt = pos;
	if (map[pos.y][pos.x] == 'D')
		trgt.y++;
	else if (map[pos.y][pos.x] == 'R')
		trgt.x++;
	else if (map[pos.y][pos.x] == 'U')
		trgt.y--;
	else if (map[pos.y][pos.x] == 'L')
		trgt.x--;
	if (player.x == trgt.x && player.y == trgt.y)
		return (1);
	if (is(ENEMY_OBSTACLE, map[trgt.y][trgt.x]) && is_near(map, pos, PLAYER))
		return (2);
	return (0);
}

void	spawn_enemies(char **map, t_list *elements)
{
	char	spawn;

	while (elements)
	{
		spawn = ft_toupper(map[elements->pos.y][elements->pos.x]);
		map[elements->pos.y][elements->pos.x] = spawn;
		elements = elements->next;
	}
}

int	player_is_moving(t_game *game)
{
	return (game->move_up || game->move_right
		|| game->move_down || game->move_left);
}
