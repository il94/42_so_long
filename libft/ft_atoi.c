/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:44:08 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/06 13:40:00 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	il_iswhitespace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	symb;
	int	result;

	i = 0;
	symb = 1;
	result = 0;
	while (il_iswhitespace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		symb *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
		result = result * 10 + (nptr[i++] - '0');
	return (result * symb);
}
