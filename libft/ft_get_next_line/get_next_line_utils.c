/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:08:54 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/06 14:49:17 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_end_of_line(char *str)
{
	if (!ft_strchr_gnl(str, '\n'))
		return (0);
	else
		return (1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	result = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

void	get_line(char *line, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	while (line[i])
	{
		buffer[j] = line[i];
		line[i] = '\0';
		i++;
		j++;
	}
	buffer[j] = '\0';
}
