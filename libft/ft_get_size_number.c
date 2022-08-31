/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 07:36:21 by ilandols          #+#    #+#             */
/*   Updated: 2022/08/16 07:42:42 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_size_number(int number)
{
	int	result;

	result = 0;
	if (number < 0)
		number *= -1;
	while (number > 0)
	{
		result++;
		number /= 10;
	}
	return (result);
}
