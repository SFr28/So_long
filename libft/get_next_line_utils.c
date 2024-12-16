/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:36:00 by sfraslin          #+#    #+#             */
/*   Updated: 2024/12/06 15:03:48 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(char *str, int r)
{
	int	i;

	i = 0;
	if (r < 0)
	{
		while (str[i])
			i++;
		return (i);
	}
	while (str[i] && i < r)
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2, int j, int r)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_len(s1, -1) + ft_len(s2, r) + 1));
	if (str == NULL)
	{
		if (*s1)
			free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	if (*s1)
		free(s1);
	while (j < r && s2[j] != '\n' && s2[j])
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i++] = '\0';
	return (str);
}

void	ft_cpy(char *dest, char *src, long int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
