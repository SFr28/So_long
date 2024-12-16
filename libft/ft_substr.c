/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:03:53 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/22 16:19:19 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (ft_strlen(s) < start || !s)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = (char)s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	size_t	len;
	unsigned int	start;
	char	*str;

	if (ac == 1)
		return (0);
	start = (unsigned int)atoi((const char *)av[2]);
	len = (size_t)atoi((const char *)av[3]);
	str = ft_substr((const char *)av[1], start, len);
	printf("%s\n", str);
	free (str);
	return (0);
}*/
