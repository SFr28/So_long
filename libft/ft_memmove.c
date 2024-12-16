/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:48 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/22 16:15:30 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_overlap(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (dest == src)
			return (1);
		src ++;
		i++;
	}
	return (0);
}

static void	*ft_no_overlap(void *dest, const void *src, size_t n)
{
	const char	*ptr_src;
	char		*ptr_dest;
	size_t		i;

	i = 0;
	ptr_src = src;
	ptr_dest = dest;
	while (i < n - 1)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	ptr_dest[i] = ptr_src[i];
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*ptr_src;
	char		*ptr_dest;
	size_t		i;

	if (n == 0 || (dest == 0 && src == 0))
		return (dest);
	i = n - 1;
	ptr_dest = dest;
	ptr_src = src;
	if (ft_check_overlap(dest, src, n) == 0)
	{
		ft_no_overlap(dest, src, n);
		return (dest);
	}
	while (i > 0)
	{
		ptr_dest[i] = ptr_src[i];
		i--;
	}
	ptr_dest[0] = ptr_src[0];
	return (dest);
}

/*#include <stdio.h>
int	main(void)
{
		char	dest[100];

		printf("%s\n", (char*)ft_memmove(dest, "ceci est un test", 7));
		return (0);
}*/
