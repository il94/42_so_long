/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:58:20 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/06 13:34:26 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **elements)
{
	int	i;

	i = 0;
	while (elements[i])
	{
		free(elements[i]);
		i++;
	}
	free(elements);
}
