/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:32:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/24 23:30:42 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_ennemies(char c)
{
	int	i;

	i = 0;
	while (ENNEMIES[i])
	{
		if (c == ENNEMIES[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_ennemies_m(char c)
{
	int	i;

	i = 0;
	while (ENNEMIES_M[i])
	{
		if (c == ENNEMIES_M[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (!can_be_started(ac, av, &game))
		exit (0);
	srand(time(NULL));
	initialize_mlx(&game);	
	mlx_loop(game.mlx);
	destroy_elements(&game);
}
