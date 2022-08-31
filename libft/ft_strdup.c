/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:44:41 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/05 15:41:00 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		size;

	size = ft_strlen(s);
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (size)
		ft_strlcpy(str, s, size + 1);
	str[size] = '\0';
	return (str);
}
