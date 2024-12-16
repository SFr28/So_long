/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:54:43 by sfraslin          #+#    #+#             */
/*   Updated: 2024/12/12 13:47:59 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_end(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		i++;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	char	*str;
	int		i;
	int		count;

	start = ft_start(s1, set);
	if (start >= ft_strlen(s1))
		return (ft_strdup(""));
	count = ft_end(s1, set) - start + 1;
	i = 0;
	if (set == 0)
		(count = ft_strlen(s1));
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	while ((start + i) <= ft_end(s1, set))
	{
		str[i] = (char)s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (&str[0]);
}

/*#include <stdio.h>
int	main(void)
{
	char	*str;
//	char	s1[] = 
	"	\t  \n\n \t\t  \n\nHello \t  Please\n Trim me !\n	\n \n \t\t\n  ";
//	char	s2[] = " \n\t	";
	char	s1[] = "   xxx   xxx";
	char	s2[] = " x";

	str = ft_strtrim(s1, s2);
//	if (ac == 1)
//		return (0);
//	printf("s2 : %s\n", s2);
	printf("my function : %s\n", str);
	free (str);
	return (0);
}*/
