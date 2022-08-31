/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:44:13 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/23 15:30:21 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	il_free_array(char **elements)
{
	int	i;

	i = 0;
	while (elements[i])
	{
		free(elements[i]);
		i++;
	}
	free(elements);
}

static int	get_size_word(char const *s, char c, int index)
{
	int	result;

	result = 0;
	while (s[index] && s[index] == c)
		index++;
	while (s[index] && s[index] != c)
	{
		result++;
		index++;
	}
	return (result);
}

static char	*get_word(char const *s, char c, int *index, int size_word)
{
	int		j;
	char	*result;

	j = 0;
	result = malloc((size_word + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s[*index] && s[*index] == c)
		*index += 1;
	while (s[*index] && s[*index] != c)
	{
		result[j] = s[*index];
		j++;
		*index += 1;
	}
	result[j] = '\0';
	return (result);
}

static int	count_words(char const *s, char c)
{
	int	result;
	int	i;

	if (!s || !s[0])
		return (0);
	if (!c)
		return (1);
	result = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c && s[i + 1] == c)
			result++;
		i++;
	}
	if (s[i - 1] != c)
		result++;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;
	int		i;
	int		j;
	int		size_word;

	words = count_words(s, c);
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		size_word = get_size_word(s, c, j);
		array[i] = get_word(s, c, &j, size_word);
		if (!array[i])
		{
			il_free_array(array);
			return (NULL);
		}
		i++;
	}
	array[words] = NULL;
	return (array);
}
