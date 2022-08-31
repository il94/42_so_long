/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:56:06 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/23 15:18:41 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array(char **elements)
{
	int	i;

	i = 0;
	while (elements[i])
	{
		ft_printf("%s\n", elements[i]);
		i++;
	}
}
