/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:51:05 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/23 15:16:24 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnb(long int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*str;
	int			i;

	nb = n;
	i = ft_countnb(nb);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	str[i] = '\0';
	i--;
	while (nb >= 10)
	{
		str[i] = (nb % 10 + 48);
		nb /= 10;
		i--;
	}
	str[i] = nb + 48;
	return (&str[0]);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	int	n;
	
	if (ac == 1)
		return (0);
	n = atoi((const char *)av[1]);
	printf("%s\n", ft_itoa(n));
	return (0);
}*/
