/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:48 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/21 18:03:38 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	printf("my function : %d\n", ft_isalnum(av[1][0]));
	printf("OG function : %d\n", isalnum(av[1][0]));
	return (0);
}*/
