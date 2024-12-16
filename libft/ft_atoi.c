/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:37:17 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/20 16:02:18 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	nb;
	int			i;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
			sign *= -1;
			i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
			nb *= 10;
			nb += str[i] - 48;
			i++;
	}
	nb *= sign;
	return (nb);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	printf("my function : %d\n", ft_atoi((const char *)av[1]));
	printf("OG function : %d\n", atoi((const char *)av[1]));
	return (0);
}*/
