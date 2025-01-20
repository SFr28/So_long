/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:26:41 by sfraslin          #+#    #+#             */
/*   Updated: 2024/12/40 18:08:18 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_path(t_game *game, int key)
{
	int	i;

	i = 0;
	if (key == XK_w)
		i += ft_up(game);
	if (key == XK_a)
		i += ft_left(game);
	if (key == XK_s)
		i += ft_down(game);
	if (key == XK_d)
		i += ft_right(game);
	return (i);
}

int	ft_up(t_game *game)
{
	int	c;

	c = 0;
	if (game->tab[game->map.x - 1][game->map.y] != '1')
	{
		if (game->tab[game->map.x - 1][game->map.y] == 'C')
			c++;
		game->tab[game->map.x][game->map.y] = 0;
		game->tab[game->map.x - 1][game->map.y] = 'P';
		game->map.x = game->map.x - 1;
		return (c);
	}
	else
		return (c);
}

int	ft_down(t_game *game)
{
	int	c;

	c = 0;
	if (game->tab[game->map.x + 1][game->map.y] != '1')
	{
		if (game->tab[game->map.x + 1][game->map.y] == 'C')
			c++;
		game->tab[game->map.x][game->map.y] = 0;
		game->tab[game->map.x + 1][game->map.y] = 'P';
		game->map.x = game->map.x + 1;
		return (c);
	}
	else
		return (c);
}

int	ft_left(t_game *game)
{
	int	c;

	c = 0;
	if (game->tab[game->map.x][game->map.y - 1] != '1')
	{
		if (game->tab[game->map.x][game->map.y - 1] == 'C')
			c++;
		game->tab[game->map.x][game->map.y] = 0;
		game->tab[game->map.x][game->map.y - 1] = 'P';
		game->map.y = game->map.y - 1;
		return (c);
	}
	else
		return (c);
}

int	ft_right(t_game *game)
{
	int	c;

	c = 0;
	if (game->tab[game->map.x][game->map.y + 1] != '1')
	{
		if (game->tab[game->map.x][game->map.y + 1] == 'C')
			c++;
		game->tab[game->map.x][game->map.y] = 0;
		game->tab[game->map.x][game->map.y + 1] = 'P';
		game->map.y = game->map.y + 1;
		return (c);
	}
	else
		return (c);
}
