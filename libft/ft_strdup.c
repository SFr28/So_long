/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:29:18 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/22 16:16:40 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof (char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = (char)s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	char	*str;

	if (ac == 1)
		return (0);
	str = ft_strdup((const char *)av[1]);
	printf("my function : %s\n", str);
	free (str);
	str = strdup((const char *)av[1]);
	printf("OG function : %s\n", str);
	free (str);
	return (0);
}*/
