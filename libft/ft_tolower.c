/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:48 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/21 18:19:19 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
		return (c);
	}
	else
		return (c);
}

/*#include <stdio.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	printf("my function : %d\n", ft_tolower(av[1][0]));
	printf("OG function : %d\n", tolower(av[1][0]));
	return (0);
}*/
