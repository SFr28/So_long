/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:54:02 by sfraslin          #+#    #+#             */
/*   Updated: 2024/12/12 18:13:52 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_items(int **tab, int count, int len)
{
	int	count_e;
	int	count_p;
	int	count_c;
	int	i;
	int j;

	i = -1;
	count_e = 0;
	count_p = 0;
	count_c = 0;
	while (++i < count)
	{
		j = -1;
		while (++j <= len - 2)
		{
			if (tab[i][j] + 48 == 'E')
				count_e++;
			if (tab[i][j] + 48 == 'P')
				count_p++;
			if (tab[i][j] + 48 == 'C')
				count_c++;
		}
	}
	if (count_e > 1 || count_p > 1 || count_c == 0)
		return (1);
	return (count_c);
}

int	ft_check_walls(int **tab, int count, int len)
{
	int		i;

	i = 0;
	while (i < count)
	{
		if (tab[i][0] != 1 || tab[i][len - 2] != 1)
			return (1);
		i++;
	}
	i = 0;
	while (i <= len - 2)
	{
		if (tab[0][i] != 1 || tab[count - 1][i] != 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_map_check(int **tab, int count, int len)
{
	int count_c;
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (ft_check_walls(tab, count, len) == 1)
		return (1);
	count_c = ft_check_items(tab, count, len);
	if (count_c == 1)
		return (1);
	ft_check_path(tab, x, y);
	while (x < count)
	{
		y = 0;
		while (y <= len - 2)
		{
			if (tab[x][y] != 1)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void	ft_check_path(int **tab, int x, int y)
{
	if (tab[x][y] == 1)
		return ;
	tab[x][y] = 1;
	if (tab[x + 1][y] == 0 || tab[x + 1][y] > 1)
		ft_check_path(tab, x + 1, y);
	if (tab[x - 1][y] == 0 || tab[x - 1][y] > 1)
		ft_check_path(tab, x - 1, y);
	if (tab[x][y + 1] == 0 || tab[x][y + 1] > 1)
		ft_check_path(tab, x, y + 1);
	if (tab[x][y - 1] == 0 || tab[x][y - 1] > 1)
		ft_check_path(tab, x, y - 1);
}
