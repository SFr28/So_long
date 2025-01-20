/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:48:13 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/20 11:55:34 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_mvt(int count_mvt)
{
	ft_putnbr_fd(count_mvt, 1);
	ft_putstr_fd("\r", 1);
	count_mvt++;
	return (count_mvt);
}

int	ft_close(t_game *game)
{
	ft_clear_tab(game->tab, game->count);
	ft_destroy_image(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
}

void	ft_destroy_image(t_game *game)
{
	if (game->back != NULL)
		mlx_destroy_image(game->mlx, game->back);
	if (game->chara != NULL)
		mlx_destroy_image(game->mlx, game->chara);
	if (game->earth != NULL)
		mlx_destroy_image(game->mlx, game->earth);
	if (game->exit != NULL)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->walls != NULL)
		mlx_destroy_image(game->mlx, game->walls);
	if (game->end != NULL)
		mlx_destroy_image(game->mlx, game->end);
}

void	ft_stop(int count_c, int count, int fd, int **tab)
{
	if (count_c == -2)
		ft_error(-3);
	tab = ft_clear_tab(tab, count);
	close(fd);
}

t_coord	ft_p_coord(t_game game, int count, int len)
{
	int	x;
	int	y;

	x = 0;
	while (x < count)
	{
		y = 0;
		while (y < len)
		{
			if (game.tab[x][y] == 'E')
			{
				game.map.x = x;
				game.map.y = y;
			}
			y++;
		}
		x++;
	}
	return (game.map);
}
