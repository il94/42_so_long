/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:40:48 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/02 17:14:13 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p;
	const char	*q;

	if (dest < src)
	{
		p = dest;
		q = src;
		while (n--)
			*p++ = *q++;
	}
	else
	{
		p = dest + (n - 1);
		q = src + (n - 1);
		while (n--)
			*p-- = *q--;
	}
	return (dest);
}
