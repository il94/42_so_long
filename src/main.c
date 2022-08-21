/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:32:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/21 22:17:48 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (!is_valid_parameter(ac, av[1]) || !is_valid_map(&game, av[1]))
		exit (0);
	initialize_data_game(&game, av[1]);
	initialize_mlx(&game);
	destroy_all_elements(&game);
	return (0);
}
