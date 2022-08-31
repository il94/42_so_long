/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:48:28 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/04 17:29:39 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert(char *result, long n, int size)
{
	if (n < 0)
		n *= -1;
	if (n >= 0 && n <= 9)
		result[size - 1] = n + '0';
	else
	{
		convert(result, n / 10, size - 1);
		convert(result, n % 10, size);
	}	
}

static int	get_size_result(long n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	n_long;
	int		size_result;

	n_long = n;
	size_result = get_size_result(n_long);
	result = malloc((size_result + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	convert(result, n_long, size_result);
	result[size_result] = '\0';
	return (result);
}
