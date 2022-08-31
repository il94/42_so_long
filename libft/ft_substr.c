/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:06:19 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/05 17:55:20 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	size_t			size_s;

	size_s = ft_strlen(s);
	if (start > size_s)
	{
		str = malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (start + len > size_s)
		len = size_s - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	start -= 1;
	while (++i < len && s[++start])
		str[i] = s[start];
	str[i] = '\0';
	return (str);
}
