/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:48 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/21 14:16:02 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*ptr_src;
	char		*ptr;
	size_t		i;

	i = 0;
	if (dest == 0 && src == 0)
		return (dest);
	ptr = dest;
	ptr_src = src;
	while (i < n)
	{
			*ptr = *ptr_src;
			ptr_src++;
			ptr++;
			i++;
	}
	return (dest);
}

/*#include <stdio.h>
int	main(void)
{
		char	dest[100];

		printf("%s\n", (char*)ft_memcpy(dest, "ceci est un test", 7));
		return (0);
}*/
