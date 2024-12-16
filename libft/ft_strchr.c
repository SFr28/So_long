/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:45:50 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/21 18:16:24 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (ptr);
		i++;
		ptr++;
	}
	if ((char)c == '\0')
		return (ptr);
	return (0);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	if (ac == 1)
		return (0);
	printf("my function : %s\n", ft_strchr((const char *)av[1], av[2][0]));
	printf("OG function : %s\n", strchr((const char *)av[1], av[2][0]));
	printf("my function : %s\n", ft_strchr("ceci est un test", 't' + 256));
	printf("my function : %s\n", ft_strchr("ceci est un test", 't' + 256));
	return (0);
}*/
