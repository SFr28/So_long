/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:18:57 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/20 17:26:01 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = 0;
	while (src[len_src])
		len_src++;
	if (n == 0)
		return (len_src);
	while (src[i] && i < n - 1)
	{
		dest[i] = (char)src[i];
		i++;
	}
	dest[i] = '\0';
	return (len_src);
}

/*#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	dest[15];

	printf("my function : %lu, %s\n", ft_strlcpy(dest, "", 15), dest);	
	printf("OG function : %lu, %s\n", strlcpy(dest, "", 15), dest);
	return (0);	
}*/
