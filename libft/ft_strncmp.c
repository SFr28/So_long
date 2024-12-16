/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:15:24 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/21 15:24:08 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	if ((ptr_s1[i] == 0 && ptr_s2[i] == 0) || n == 0)
		return (0);
	while (i < n && ptr_s1[i] == ptr_s2[i] && ptr_s1[i] && ptr_s2[i])
			i++;
	if (i == n)
		return (ptr_s1[i - 1] - ptr_s2[i - 1]);
	return (ptr_s1[i] - ptr_s2[i]);
}

/*#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
//	int	i;
//	int	j;
	size_t	n;

	n = (size_t)atoi((const char *)av[3]);
	if(ac == 1)
		return (0);
	printf("my function : %d\n", 
		ft_strncmp((const char *)av[1], (const char *)av[2], n));
	printf("OG function : %d\n", 
		strncmp((const char *)av[1], (const char *)av[2], n));
	printf("my function : %d\n", 
		ft_strncmp("abcdef", "abc\375xx", 5));
	printf("OG function : %d\n", 
		strncmp("abcdef", "abc\375xx", 5));
	printf("c = \375\n");
	i = 'd';
	j = '\375';
	printf ("i = %d, j = %d", i, j);
	return (0);
}*/
