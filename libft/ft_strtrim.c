/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:13:21 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/05 17:40:16 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char const *set)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_size_result(char const *s, char const *set, int size_s1)
{
	int	to_trim;
	int	i;

	to_trim = 0;
	i = 1;
	while (s[size_s1 - i] && is_charset(s[size_s1 - i], set))
	{
		to_trim++;
		i++;
	}
	if (to_trim == size_s1)
		return (0);
	i = 0;
	while (s[i] && is_charset(s[i], set))
	{
		to_trim++;
		i++;
	}
	return (size_s1 - to_trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		size_s1;
	int		size_result;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_result = get_size_result(s1, set, size_s1);
	if (size_result < 0)
		return (NULL);
	result = malloc((size_result + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] && is_charset(s1[i], set))
		i++;
	j = 0;
	while (j < size_result)
		result[j++] = s1[i++];
	result[j] = '\0';
	return (result);
}
