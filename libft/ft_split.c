/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:20:35 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/23 19:22:29 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i] == c && s[i])
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static int	ft_length(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*ft_strup(const char *s, char c, char *tab)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	tab = (char *)malloc(sizeof(char) * ft_length(s, c) + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char	**ft_freetab(char **tab, int i)
{
	i--;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (i < ft_count(s, c) && s[j])
	{
		while (s[j] == c && s[j])
			j++;
		tab[i] = ft_strup(&s[j], c, tab[i]);
		if (tab[i] == NULL)
		{
			ft_freetab(tab, i);
			return (NULL);
		}
		while (s[j] != c && s[j])
			j++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

/*#include <stdio.h>
int	main(void)
{
	char	**tab;
	char	*splitme;
	int		i;

	i = 0;
//	if (ac == 1)
//		return (0);
//	tab = ft_split((const char *)av[1], av[2][0]);
	splitme = ft_strdup("Tripouille");
	tab = ft_split (splitme, ' ');
	while (tab[i] != 0)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}*/
