/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:06:00 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/26 01:06:00 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ennemy_sprite_can_move(t_game *game, t_axe pos, t_axe pos_trgt, char code)
{
	if (game->map[pos.y][pos.x] == 'U' && (!is("1", game->map[pos_trgt.y][pos_trgt.x])))
		return (1);
	else if (game->map[pos.y][pos.x] == 'R' && (!is("1", game->map[pos_trgt.y][pos_trgt.x])))
		return (1);
	else if (game->map[pos.y][pos.x] == 'D' && (!is("1", game->map[pos_trgt.y][pos_trgt.x])))
		return (1);
	else if (game->map[pos.y][pos.x] == 'L' && (!is("1", game->map[pos_trgt.y][pos_trgt.x])))
		return (1);
	else
		return (0);
}

char	get_code(t_game *game, t_axe pos, t_axe pos_trgt)
{
	if (pos.y > pos_trgt.y)
		return ('U');
	else if (pos.x > pos_trgt.x)
		return ('R');
	else if (pos.y < pos_trgt.y)
		return ('D');
	else if (pos.x < pos_trgt.x)
		return ('L');
}

void	move_ennemy_sprite(t_game *game, t_axe cell_trgt)
{
	game->move_ennemy++;
}

int	ennemy_position_can_move(t_game *game)
{
	if (game->move_ennemy == 48)
		return (1);
	return (0);
}

void	change_direction(t_game *game, t_axe pos)
{
	t_axe	trgt;

	trgt = pos;
	if (game->map[pos.y][pos.x] == 'D')
	{
		game->map[pos.y][pos.x] = 'R';
		trgt.x++;
	}
	else if (game->map[pos.y][pos.x] == 'R')
	{
		game->map[pos.y][pos.x] = 'U';
		trgt.y--;
	}
	else if (game->map[pos.y][pos.x] == 'U')
	{
		game->map[pos.y][pos.x] = 'L';
		trgt.x--;
	}
	else if (game->map[pos.y][pos.x] == 'L')
	{
		game->map[pos.y][pos.x] = 'D';
		trgt.y++;
	}
	move_ennemy_position(game, pos, trgt);
}

void	change_direction2(t_game *game, t_axe pos)
{
	t_axe	trgt;

	trgt = pos;
	if (game->map[pos.y][pos.x] == 'D')
	{
		game->map[pos.y][pos.x] = 'R';
		trgt.x++;
	}
	else if (game->map[pos.y][pos.x] == 'R')
	{
		game->map[pos.y][pos.x] = 'U';
		trgt.y--;
	}
	else if (game->map[pos.y][pos.x] == 'U')
	{
		game->map[pos.y][pos.x] = 'L';
		trgt.x--;
	}
	else if (game->map[pos.y][pos.x] == 'L')
	{
		game->map[pos.y][pos.x] = 'D';
		trgt.y++;
	}
}

void	move_ennemy_position(t_game *game, t_axe pos, t_axe trgt)
{
	if (game->map[trgt.y][trgt.x] == 'P')
		end_game(game, LOOSE);
	else if (game->map[trgt.y][trgt.x] == '0')
	{
		game->map[trgt.y][trgt.x] = ft_tolower(game->map[pos.y][pos.x]);
		game->map[pos.y][pos.x] = '0';
		game->move_ennemy = 0;
	}
	else if (is_near(game, pos, '0') || is_near_p(game, pos))
	{
		printf("lol\n");
		change_direction(game, pos);
	}
}

int	move_ennemy(t_game *game, t_axe pos, t_axe pos_trgt)
{
	char	code;
		
	code = get_code(game, pos, pos_trgt);
	if (ennemy_sprite_can_move(game, pos, pos_trgt, code))
	{
		printf("IF 1 move e = %d\n", game->move_ennemy);
		move_ennemy_sprite(game, pos_trgt);
		if (ennemy_position_can_move(game))
			move_ennemy_position(game, pos, pos_trgt);
	}
	else
	{
		change_direction2(game, pos);
		// move_ennemy(game, pos, pos_trgt);
	}
	return (0);
}

// int	move_ennemy(t_game *game, t_axe pos, t_axe trgt)
// {
// 	if (game->map[trgt.y][trgt.x] == 'P')
// 		end_game(game, LOOSE);
// 	else if (game->map[trgt.y][trgt.x] == '0')
// 	{
// 		game->map[trgt.y][trgt.x] = ft_tolower(game->map[pos.y][pos.x]);
// 		game->map[pos.y][pos.x] = '0';
// 	}
// 	else if (is_near(game, pos, '0') || is_near_p(game, pos))
// 		change_direction(game, pos);
// 	return (0);
// }

int	get_direction(t_game *game, t_axe pos, int (*f)(t_game *, t_axe, t_axe))
{
	t_axe	trgt;

	// ft_print_array(game->map);
	// printf("============\n");
	trgt = pos;
	if (game->map[pos.y][pos.x] == 'M')
		game->map[pos.y][pos.x] = 'D';
	if (game->map[pos.y][pos.x] == 'D')
		trgt.y++;
	else if (game->map[pos.y][pos.x] == 'R')
		trgt.x++;
	else if (game->map[pos.y][pos.x] == 'U')
		trgt.y--;
	else if (game->map[pos.y][pos.x] == 'L')
		trgt.x--;
	return ((*f)(game, pos, trgt));
}
