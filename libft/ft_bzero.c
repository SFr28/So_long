/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:48 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/21 18:31:01 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = s;
	while (i < n)
	{
			*ptr = 0;
			ptr++;
			i++;
	}
}

/*#include <stdio.h>
#include <string.h>
int	main (void)
{
	char	s1[] = "test function";
	char	s2[] = "test function";
	
	ft_bzero((void *)s1, 5);
	bzero((void *)s2, 5);
	printf("my function : %s, %c\n", s1, s1[7]);
	printf("OG function : %s, %c\n", s2, s2[7]);
	return (0);
}*/
