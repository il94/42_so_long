/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:17:05 by ilyes             #+#    #+#             */
/*   Updated: 2022/07/06 14:47:21 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert(char *result, long long n, int size_result, int size_base)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 0)
	{
		result[0] = '-';
		convert(result, n * (-1), size_result, size_base);
	}
	else if (n >= 0 && n < size_base)
		result[size_result - 1] = base[n];
	else
	{
		convert(result, n / size_base, size_result - 1, size_base);
		convert(result, n % size_base, size_result, size_base);
	}	
}

int	get_result_size(long long n, int size_base, char flag, char flag_b)
{
	int			result;
	long long	n_copy;

	n_copy = n;
	result = 0;
	if (n <= 0)
	{
		result = 1;
		n_copy *= (-1);
	}
	while (n_copy > 0)
	{
		result++;
		n_copy /= size_base;
	}
	result += add_size_flag_conversion(n, flag, flag_b);
	return (result);
}

int	get_size_base(char flag)
{
	if (flag == 'x' || flag == 'X')
		return (16);
	else
		return (10);
}

char	*convert_flag(long long n, char flag, char flag_b)
{
	char	*result;
	int		size_base;
	int		size_result;

	size_base = get_size_base(flag);
	size_result = get_result_size(n, size_base, flag, flag_b);
	result = malloc((size_result + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	convert(result, n, size_result, size_base);
	result[size_result] = '\0';
	add_flag(result, n, flag, flag_b);
	return (result);
}
