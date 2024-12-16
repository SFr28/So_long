/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:48 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/21 14:40:03 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)s + i);
		ptr++;
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	size_t	n;

	if (ac == 1)
		return (0);
	n = (size_t)atoi((const char *)av[3]);
	printf("my function : %s\n", 
		(char *)ft_memchr((const void *)av[1], av[2][0], n));
	return (0);
}*/
