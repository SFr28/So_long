/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:09:10 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/22 16:18:14 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (*s == 0 || (*f) == 0)
		return (ft_strdup(""));
	i = 0;
	while (s[i])
			i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
			str[i] = (*f)(i, (char)s[i]);
			i++;
	}
	str[i] = '\0';
	return (str);
}

/*char	ft_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 0)
		return (0);
	printf("%s\n", ft_strmapi((const char *)av[1], &ft_upper));
	return (0);
}*/
