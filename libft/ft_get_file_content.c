/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:15:31 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/18 22:15:31 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_get_file_content(int fd)
{
	char	*line;
	char	*stash;
	char	**result;

	line = "";
	stash = NULL;
	while (line)
	{
		line = ft_get_next_line(fd);
		if (line)
		{
			stash = ft_strjoin_gnl(stash, line);
			if (!stash)
			{
				free(line);
				return (NULL);
			}
		}
		free(line);
	}
	result = ft_split(stash, '\n');
	free(stash);
	if (!result)
		return (NULL);
	return (result);
}
