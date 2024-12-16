/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:26:41 by sfraslin          #+#    #+#             */
/*   Updated: 2024/12/13 19:09:08 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	**ft_clear_tab(int **tab, int count)
{
	int	y;

	y = 0;
	while (y < count)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
	return (NULL);
}

int	**ft_begin(char	*title, int count, int len)
{
	char	*str;
	int		**tab;
	int		fd;

	fd = open(title, O_RDONLY);
	len = ft_strlen(get_next_line(fd));
	while (fd)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if ((size_t)len != ft_strlen(str))
			{
				free(str);
				return (0);
			}
		free(str);
		count++;
	}
	close(fd);
	fd = open(title, O_RDONLY);
	tab = map_to_tab(fd, count, len, str);
	if (ft_map_check(tab, count, len) == 1)
	{
		tab = ft_clear_tab(tab, count);
		return (tab);
	}
	close(fd);
	fd = open(title, O_RDONLY);
	tab = ft_clear_tab(tab, count);
	tab = map_to_tab(fd, count, len, str);
	return (tab);
}

int **map_to_tab(int fd, int count, int len, char *str)
{
	int		**tab;
	int		i;
	int		j;

	i = 0;
	tab = malloc(sizeof(int *) * count);
	if (tab == NULL)
		return (0);
	while (i < count)
	{
		j = 0;
		str = get_next_line(fd);
		tab[i] = malloc(sizeof(int) * len);
		if (tab[i] == NULL)
		{
			while (i >= 0)
				free(tab[i--]);
			free(tab);
			free(str);
			return (0);
		}
		while (j <= len - 2)
		{
			tab[i][j] = str[j] - 48;
			j++;
		}
		i++;
	}
	free(str);
	return (tab);
}

int main(void)
{
	int	**tab;
	int	x;
	int	y;

	x = 0;
	y = 0;
	tab = ft_begin("map.ber", 1, y);
	if (tab == NULL)
	{
		ft_putstr_fd("Invalid map.\n", 2);
		return (1);
	}
	while (y <= 7)
	{
		x = 0;
		while(x < 19)
		{
			printf("%c", (tab[y][x] + 48));
			x++;
		}
		printf("\n");
		y++;
	}
	while (y >= 0)
	{
		free(tab[y]);
		y--;
	}
	free(tab);
    return (0);
}
