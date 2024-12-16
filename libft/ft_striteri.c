/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:09:10 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/22 11:07:20 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (*s == 0 || (*f) == 0)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*void	ft_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

#include <stdio.h>
int	main(void)
{
	char	str1[] = "ceci est un test";
	char	str2[] = "1 Autre Test";

	ft_striteri(str1, &ft_upper);
	ft_striteri(str2, &ft_upper);
	printf("%s\n", str1);
	printf("%s\n", str2);
	return (0);
}*/
