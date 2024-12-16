/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:56:38 by sfraslin          #+#    #+#             */
/*   Updated: 2024/12/09 10:23:00 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new_line(char *stash, char *str)
{
	int	len;

	if (stash[1] != '\0')
		str = ft_join(str, &stash[1], 0, BUFFER_SIZE);
	len = ft_len(str, BUFFER_SIZE);
	ft_cpy(stash, &stash[len], BUFFER_SIZE);
	return (str);
}

void	ft_stash(char *buffer, char *stash)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < BUFFER_SIZE)
		stash[i++] = '\0';
	stash[i] = '\0';
	while (buffer[j] != 10 && buffer[j])
		j++;
	i = ft_len(buffer, BUFFER_SIZE) - j;
	ft_cpy(stash, &buffer[j], i);
}

char	*ft_zero(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
		buffer[i++] = '\0';
	return (buffer);
}

char	*ft_read(char *str, char *stash, int fd, int i)
{
	char	*buffer;
	int		r;

	r = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (0);
	while (r == BUFFER_SIZE && str[i] != 10)
	{
		buffer = ft_zero(buffer);
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
		{
			free(buffer);
			return (0);
		}
		if (r > 0)
		{
			str = ft_join(str, buffer, 0, r);
			i = i + ft_len(&str[i], -1) - 1;
		}
	}
	ft_stash(buffer, stash);
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE];
	char		*str;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = "";
	i = 0;
	while (stash[i])
	{
		if (stash[0] == 10)
			str = ft_new_line(stash, str);
		if (ft_len(str, BUFFER_SIZE) == 0)
			break ;
		if (str[ft_len(str, BUFFER_SIZE) - 1] == 10)
			return (str);
		i++;
	}
	str = ft_read(str, stash, fd, 0);
	if (!str || str[0] == '\0')
		return (0);
	return (str);
}
