/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:15:47 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/20 11:15:47 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	verify_alloc(t_game *game, void *ptr)
{
	if (!ptr)
	{
		destroy_all_elements(game);
		exit (1);
	}
}

void	destroy_elements(void *mlx, t_img *data, int number_sprite)
{
	int	i;

	i = 0;
	while (i < number_sprite)
	{
		if (data[i].img)
			mlx_destroy_image(mlx, data[i].img);
		i++;
	}
}

void	destroy_lists(t_game *game)
{
	if (game->map)
		ft_free_array(game->map);
	if (game->enemies)
		ft_lstclear(&game->enemies);
	if (game->coins)
		ft_lstclear(&game->coins);
}

void	destroy_all_elements(t_game *game)
{
	if (game->mlx)
	{
		destroy_elements(game->mlx, game->s_items, 8);
		destroy_elements(game->mlx, game->s_goombas, 9);
		destroy_elements(game->mlx, game->s_land, 10);
		destroy_elements(game->mlx, game->s_bar, 15);
		destroy_elements(game->mlx, game->s_mario, 52);
		if (game->s_stepbar.img)
			mlx_destroy_image(game->mlx, game->s_stepbar.img);
		if (game->s_render.img)
			mlx_destroy_image(game->mlx, game->s_render.img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	destroy_lists(game);
	system("pkill vlc");
}
