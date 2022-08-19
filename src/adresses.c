/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adresses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:50:15 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/19 18:39:45 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_adresses_environnement(t_game *game)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		game->environnement[i].addr = mlx_get_data_addr(game->environnement[i].img, 
        	    &game->environnement[i].bpp, &game->environnement[i].line, &game->environnement[i].endian);
		i++;
	}
}

void	get_adresses_mobs(t_game *game)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		game->goombas[i].addr = mlx_get_data_addr(game->goombas[i].img, 
        	    &game->goombas[i].bpp, &game->goombas[i].line, &game->goombas[i].endian);
		i++;
	}
	i = 0;
	while (i < 44)
	{
		game->mario[i].addr = mlx_get_data_addr(game->mario[i].img, 
        	    &game->mario[i].bpp, &game->mario[i].line, &game->mario[i].endian);
		i++;
	}
}

void	get_adresses_collectibles(t_game *game)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		game->coin[i].addr = mlx_get_data_addr(game->coin[i].img, 
        	    &game->coin[i].bpp, &game->coin[i].line, &game->coin[i].endian);
		i++;
	}
}

void	get_adresses(t_game *game)
{
	get_adresses_environnement(game);
	get_adresses_mobs(game);
	get_adresses_collectibles(game);

/*============================================================================*/

	game->hammer.addr = mlx_get_data_addr(game->hammer.img, 
            &game->hammer.bpp, &game->hammer.line, &game->hammer.endian);

/*============================================================================*/

	game->menu.addr = mlx_get_data_addr(game->menu.img, 
            &game->menu.bpp, &game->menu.line, &game->menu.endian);
	game->menu_2.addr = mlx_get_data_addr(game->menu_2.img, 
            &game->menu_2.bpp, &game->menu_2.line, &game->menu_2.endian);
	game->menu_3.addr = mlx_get_data_addr(game->menu_3.img, 
            &game->menu_3.bpp, &game->menu_3.line, &game->menu_3.endian);
	game->step.addr = mlx_get_data_addr(game->step.img, 
            &game->step.bpp, &game->step.line, &game->step.endian);
	game->steps.addr = mlx_get_data_addr(game->steps.img, 
            &game->steps.bpp, &game->steps.line, &game->steps.endian);

/*============================================================================*/

	game->screen.addr = mlx_get_data_addr(game->screen.img, 
            &game->screen.bpp, &game->screen.line, &game->screen.endian);
	game->menu_full.addr = mlx_get_data_addr(game->menu_full.img, 
            &game->menu_full.bpp, &game->menu_full.line, &game->menu_full.endian);
	game->numbers[0].addr = mlx_get_data_addr(game->numbers[0].img, 
            &game->numbers[0].bpp, &game->numbers[0].line, &game->numbers[0].endian);
	game->numbers[1].addr = mlx_get_data_addr(game->numbers[1].img, 
            &game->numbers[1].bpp, &game->numbers[1].line, &game->numbers[1].endian);
	game->numbers[2].addr = mlx_get_data_addr(game->numbers[2].img, 
            &game->numbers[2].bpp, &game->numbers[2].line, &game->numbers[2].endian);
	game->numbers[3].addr = mlx_get_data_addr(game->numbers[3].img, 
            &game->numbers[3].bpp, &game->numbers[3].line, &game->numbers[3].endian);
	game->numbers[4].addr = mlx_get_data_addr(game->numbers[4].img, 
            &game->numbers[4].bpp, &game->numbers[4].line, &game->numbers[4].endian);
	game->numbers[5].addr = mlx_get_data_addr(game->numbers[5].img, 
            &game->numbers[5].bpp, &game->numbers[5].line, &game->numbers[5].endian);
	game->numbers[6].addr = mlx_get_data_addr(game->numbers[6].img, 
            &game->numbers[6].bpp, &game->numbers[6].line, &game->numbers[6].endian);
	game->numbers[7].addr = mlx_get_data_addr(game->numbers[7].img, 
            &game->numbers[7].bpp, &game->numbers[7].line, &game->numbers[7].endian);
	game->numbers[8].addr = mlx_get_data_addr(game->numbers[8].img, 
            &game->numbers[8].bpp, &game->numbers[8].line, &game->numbers[8].endian);
	game->numbers[9].addr = mlx_get_data_addr(game->numbers[9].img, 
            &game->numbers[9].bpp, &game->numbers[9].line, &game->numbers[9].endian);


/*============================================================================*/

}
