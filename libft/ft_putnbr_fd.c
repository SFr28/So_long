/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:27:51 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/22 16:16:06 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		str[11];
	int			i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	while (nb >= 10)
	{
		str[i] = (nb % 10) + 48;
		nb = nb / 10;
		i++;
	}
	str[i] = nb + 48;
	while (i >= 0)
	{
		write(fd, &str[i], 1);
		i--;
	}
}
