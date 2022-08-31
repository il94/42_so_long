/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:41:41 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/05 16:07:08 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	j = 0;
	if (size > 0)
	{
		while (src[j] && j < size - 1)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}
