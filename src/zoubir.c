/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoubir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:09:21 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/25 22:09:21 by ilandols         ###   ########.fr       */
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

int	is_char_content(char c, int *cep)
{
	int	i;

	i = 0;
	while (CHAR_CONTENT[i])
	{
		if (c == CHAR_CONTENT[i])
		{
			if (c == 'C')
				cep[0]++;
			else if (c == 'E')
				cep[1]++;
			else if (c == 'P')
				cep[2]++;
			return (1);
		}
		i++;
	}
	return (0);
}


int	is_collectibles(char c)
{
	int	i;

	i = 0;
	while (COLLECTIBLES[i])
	{
		if (c == COLLECTIBLES[i])
			return (1);
		i++;
	}
	return (0);
}
