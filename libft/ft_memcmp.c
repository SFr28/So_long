/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:48 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/21 15:09:07 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (i < n && ptr_s1[i] == ptr_s2[i])
			i++;
	if (i == n)
		return (ptr_s1[i - 1] - ptr_s2[i - 1]);
	return (ptr_s1[i] - ptr_s2[i]);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	main(void)
{
	size_t	n;

	if (ac == 1)
		return (0);
	n = (size_t)atoi((const char *)av[3]);
	printf("my function : %d\n", 
		ft_memcmp((const void *)av[1], (const void *)av[2], n));
	printf("OG function : %d\n", 
		memcmp((const void *)av[1], (const void *)av[2], n));
	printf("my function : %d\n", 
		ft_memcmp("\xff\xaa\xde\x12", "\xff\xaa\xde\x12MACOSAAAAA", 4));
	printf("OG function : %d\n", 
		memcmp("\xff\xaa\xde\x12", "\xff\xaa\xde\x12MACOSAAAAA", 4));
	return (0);
}*/
