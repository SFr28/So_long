/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:53:49 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/20 15:50:20 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len
			&& big[i + j] && little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <bsd/string.h>
int	main(int ac, char **av)
{
		size_t	len;

		len = (size_t)atoi((const char*) av[3]);
		if (ac == 1)
				return (0);
		printf("my function : %s\n", 
			ft_strnstr((const char*)av[1], (const char*)av[2], len));
		printf("OG function : %s\n", 
			strnstr((const char*)av[1], (const char*)av[2], len));
		return (0);
}*/
