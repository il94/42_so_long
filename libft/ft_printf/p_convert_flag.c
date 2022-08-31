/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_convert_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:15:09 by ilyes             #+#    #+#             */
/*   Updated: 2022/07/06 14:47:39 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_convert(char *result, unsigned long long n, int size_result)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
		result[size_result - 1] = base[n];
	else
	{
		p_convert(result, n / 16, size_result - 1);
		p_convert(result, n % 16, size_result);
	}	
}

int	p_get_result_size(unsigned long long n, char flag_b)
{
	int	result;

	result = 0;
	if (n == 0)
		result = 1;
	while (n > 0)
	{
		result++;
		n /= 16;
	}
	if (flag_b == ' ' || flag_b == '+')
		result++;
	return (result);
}

void	p_add_flag(char *result, char flag_b)
{
	int	i;

	i = 0;
	if (flag_b == ' ')
	{
		result[i] = ' ';
		i++;
	}
	else if (flag_b == '+')
	{
		result[i] = '+';
		i++;
	}
	result[i] = '0';
	result[i + 1] = 'x';
}

char	*p_convert_flag(unsigned long long n, char flag_b)
{
	char	*result;
	int		size_result;

	size_result = p_get_result_size(n, flag_b) + 2;
	result = malloc((size_result + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	p_convert(result, n, size_result);
	p_add_flag(result, flag_b);
	result[size_result] = '\0';
	return (result);
}
