/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:48:51 by ilyes             #+#    #+#             */
/*   Updated: 2022/07/06 14:47:25 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_toupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

void	add_flag(char *result, long long n, char flag, char flag_b)
{
	if (flag_b == '#' && n != 0 && (flag == 'x' || flag == 'X'))
	{
		result[0] = '0';
		result[1] = 'x';
	}
	else if (flag_b == ' ' && (flag == 'd' || flag == 'i') && n >= 0)
		result[0] = ' ';
	else if (flag_b == '+' && (flag == 'd' || flag == 'i') && n >= 0)
		result[0] = '+';
	if (flag == 'X')
		str_toupper(result);
}

int	add_size_flag_conversion(long long n, char flag, char flag_b)
{
	if (flag_b == '#' && n != 0 && (flag == 'x' || flag == 'X'))
		return (2);
	else if (flag_b == '+' && (flag == 'd' || flag == 'i') && n >= 0)
		return (1);
	else if (flag_b == ' ' && (flag == 'd' || flag == 'i') && n >= 0)
		return (1);
	else
		return (0);
}

int	get_second_flag(char c)
{
	if (c == '#' || c == '+' || c == ' ')
		return (c);
	else
		return (0);
}

int	get_flag(char c, char c1, char c2)
{
	if (c == '%' && c1 != '\0')
	{
		if (c1 == '#' || c1 == '+' || c1 == ' ')
		{
			if (c2 == 'c' || c2 == 's' || c2 == 'd' || c2 == 'i' || c2 == 'u'
				|| c2 == 'x' || c2 == 'X' || c2 == 'p' || c2 == '%')
				return (c2);
			else
				return (0);
		}
		else if (c1 == 'c' || c1 == 's' || c1 == 'd' || c1 == 'i' || c1 == 'u'
			|| c1 == 'x' || c1 == 'X' || c1 == 'p' || c1 == '%')
			return (c1);
	}
	return (0);
}
