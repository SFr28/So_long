/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:27:19 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/22 16:17:39 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_dest;
	size_t	j;
	size_t	len_src;

	len_dest = ft_strlen((const char *)dest);
	len_src = ft_strlen(src);
	j = 0;
	if (n == 0)
		return (len_src);
	if (n <= len_dest)
		return (len_src + n);
	while (src[j] && j < (n - len_dest -1))
	{
		dest[len_dest + j] = (char)src[j];
		j++;
	}
	dest[len_dest + j] = '\0';
	return (len_src + len_dest);
}

/*#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
		char	dest[10] = "a";
		char	dest2[10] = "a";

		printf("my function : %lu ; %s\n", 
			ft_strlcat(dest, "bonjour", 1), dest);
		printf("OG function : %lu ; %s\n", 
			strlcat(dest2, "bonjour", 1), dest2);
		return (0);
}*/
