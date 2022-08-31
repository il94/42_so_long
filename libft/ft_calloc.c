/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:44:23 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/04 16:47:59 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*p;
	char		*c;

	if (nmemb == 0 || size == 0)
		p = malloc(1);
	else
		p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	c = p;
	ft_bzero(c, nmemb);
	return (p);
}
