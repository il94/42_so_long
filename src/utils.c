/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:36:43 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/31 18:36:43 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (str[i]);
		i++;
	}
	return (0);
}

int	is_near(char **map, t_pos pos, char *str)
{
	return (is(str, map[pos.y + 1][pos.x])
			|| is(str, map[pos.y][pos.x + 1])
			|| is(str, map[pos.y - 1][pos.x])
			|| is(str, map[pos.y][pos.x - 1]));
}

int	is_valid_char(char c, int *cep)
{
	int	i;

	i = 0;
	while (VALID_CHAR[i])
	{
		if (c == VALID_CHAR[i])
		{
			if (c == 'C')
				cep[0]++;
			else if (c == 'E')
				cep[1]++;
			else if (c == 'P')
				cep[2]++;
			else if (c == 'H')
				cep[3]++;
			return (VALID_CHAR[i]);
		}
		i++;
	}
	return (0);
}
