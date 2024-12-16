/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:45:50 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/20 15:27:11 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s[i])
			i++;
	ptr = (char *)&s[i];
	if ((char)c == '\0')
		return (ptr);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (ptr);
		i--;
		ptr--;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	printf("my function : %s\n", ft_strrchr((const char *)av[1], av[2][0]));
	printf("OG function : %s\n", strrchr((const char *)av[1], av[2][0]));
	return (0);
}*/
