/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:37:37 by ilyes             #+#    #+#             */
/*   Updated: 2022/07/06 14:47:28 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(void *arg, char flag, char flag_b)
{
	int		size;
	char	*result;

	if (flag == 'd' || flag == 'i')
		result = convert_flag((int)(long long)(arg), flag, flag_b);
	else if (flag == 'u' || flag == 'x' || flag == 'X')
		result = convert_flag((unsigned int)(long long)(arg), flag, flag_b);
	else if (flag == 'p')
	{
		if (arg == NULL)
			result = ft_strdup("(nil)");
		else
			result = p_convert_flag((unsigned long long)(arg), flag_b);
	}
	size = ft_strlen(result);
	write(1, result, size);
	free(result);
	return (size);
}

int	print_ascii(void *arg, char flag, char flag_b)
{
	int	size;

	flag_b = flag_b;
	if (flag == 'c')
	{
		size = 1;
		write(1, &arg, 1);
	}
	else if (arg == NULL)
	{
		size = 6;
		write(1, "(null)", 6);
	}
	else
	{
		size = ft_strlen(arg);
		write(1, arg, ft_strlen(arg));
	}
	return (size);
}

int	print_flag(va_list args, char flag, char flag_b)
{
	if (flag == '%')
	{
		write(1, &flag, 1);
		return (0);
	}
	else if (flag == 'c' || flag == 's')
		return (print_ascii(va_arg(args, void *), flag, flag_b) - 1);
	else
		return (print_nbr(va_arg(args, void *), flag, flag_b) - 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		size;
	char	flag;
	char	flag_b;

	va_start(args, str);
	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (get_flag(str[i], str[i + 1], str[i + 2]))
		{
			flag = get_flag(str[i], str[i + 1], str[i + 2]);
			flag_b = get_second_flag(str[i + 1]);
			size += print_flag(args, flag, flag_b);
			i += 2;
			if (flag_b != 0)
				i += 1;
		}
		else
			write(1, &str[i++], 1);
		size++;
	}
	return (size);
}
