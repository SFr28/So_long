/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:48 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/21 18:09:32 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = s;
	while (i < n)
	{
			*ptr = c;
			ptr++;
			i++;
	}
	return (s);
}

/*#include <stdio.h>
#include <string.h>
int	main (int ac, char **av)
{
	size_t	n;

	if (ac == 1)
		return (0);
	n = (size_t)atoi((const char *)av[3]);
	printf("my function : %s\n", (char *)ft_memset((void *)av[1], av[2][0], n));
	printf("OG function : %s\n", (char *)memset((void *)av[1], av[2][0], n));
	return (0);
}*/
