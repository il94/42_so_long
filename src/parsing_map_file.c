/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:23:19 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/31 23:52:19 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_only_one_parameter(int ac)
{
	if (ac != 2)
	{
		ft_printf("Error\nInvalid number of parameters\n");
		return (0);
	}
	return (1);
}

int	file_exist(char *file, int fd)
{
	if (fd < 0)
	{
		ft_printf("Error\nFile doesn't exist\n");
		return (0);
	}
	return (1);
}

int	is_ber_file(char *file)
{
	if (!ft_strnstr(file + ft_strlen(file) - 4, ".ber", 4))
	{
		ft_printf("Error\nFile must be of type .ber\n");
		return (0);
	}
	return (1);
}

int	is_not_empty(char *file, int fd, char *buffer)
{
	if (read(fd, buffer, 1) <= 0)
	{
		ft_printf("Error\nEmpty file\n");
		return (0);
	}
	return (1);
}
