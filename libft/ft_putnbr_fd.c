/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:46:27 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/04 15:55:07 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	nl;

	nl = n;
	if (nl == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nl >= 0 && nl <= 9)
	{
		c = nl + '0';
		write(fd, &c, 1);
	}
	else if (nl < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(nl * (-1), fd);
	}
	else
	{
		ft_putnbr_fd(nl / 10, fd);
		ft_putnbr_fd(nl % 10, fd);
	}
}
