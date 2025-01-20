/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:54:02 by sfraslin          #+#    #+#             */
/*   Updated: 2024/12/30 18:25:10 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

int	ft_check_items(t_game *game, int count_c)
{
	int	count_e_p;
	int	i;
	int	j;

	i = -1;
	count_e_p = 0;
	game->count_d = 0;
	while (++i < game->count)
	{
		j = -1;
		while (++j <= game->len - 2)
		{
			if (game->tab[i][j] == 'E' || game->tab[i][j] == 'P')
				count_e_p++;
			if (game->tab[i][j] == 'C')
				count_c++;
			if (game->tab[i][j] == 'D')
				game->count_d++;
			if (ft_items_valid(game->tab[i][j]) == 1)
				return (0);
		}
	}
	if (count_e_p != 2 || count_c == 0)
		count_c = 0;
	return (count_c);
}

int	ft_check_walls(int **tab, int count, int len)
{
	int		i;

	i = 0;
	while (i < count)
	{
		if (tab[i][0] != '1' || tab[i][len - 1] != '1')
		{
			ft_error(0);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i <= len - 1)
	{
		if (tab[0][i] != '1' || tab[count - 1][i] != '1')
		{
			ft_error(0);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_map_check(t_game *game)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (ft_check_walls(game->tab, game->count, game->len - 1) == 1)
		return (-1);
	game->count_c = ft_check_items(game, 0);
	if (game->count_c == 0)
	{
		ft_error(-1);
		return (-1);
	}
	ft_check_path(game->tab, game->map.x, game->map.y);
	while (x < game->count)
	{
		y = -1;
		while (++y <= game->len - 2)
		{
			if (game->tab[x][y] != '1' && game->tab[x][y] != 'D')
				return (-2);
		}
		x++;
	}
	return (game->count_c);
}

void	ft_check_path(int **tab, int x, int y)
{
	if (tab[x][y] == '1')
		return ;
	tab[x][y] = '1';
	if (tab[x + 1][y] == '0' || (tab[x + 1][y] > '1' && tab[x + 1][y] != 'D'))
		ft_check_path(tab, x + 1, y);
	if (tab[x - 1][y] == '0' || (tab[x - 1][y] > '1' && tab[x - 1][y] != 'D'))
		ft_check_path(tab, x - 1, y);
	if (tab[x][y + 1] == '0' || (tab[x][y + 1] > '1' && tab[x][y + 1] != 'D'))
		ft_check_path(tab, x, y + 1);
	if (tab[x][y - 1] == '0' || (tab[x][y - 1] > '1' && tab[x][y - 1] != 'D'))
		ft_check_path(tab, x, y - 1);
}

int	ft_check_format(char *title)
{
	size_t	i;

	i = ft_strlen(title);
	if (i <= 4 || title[i - 4] != '.' || title[i - 3] != 'b'
		|| title[i - 2] != 'e' || title[i - 1] != 'r')
	{
		ft_error(-2);
		return (1);
	}
	return (0);
}
