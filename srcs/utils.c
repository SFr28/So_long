/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:48:13 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/28 10:08:01 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_mvt(int count_mvt)
{
	count_mvt++;
	ft_putnbr_fd(count_mvt, 1);
	ft_putstr_fd("\r", 1);
	return (count_mvt);
}

void	ft_load_images(t_game *game, int w, int h)
{
	game->back = mlx_xpm_file_to_image(game->mlx, "back.xpm", &w, &h);
	game->walls = mlx_xpm_file_to_image(game->mlx, "walls.xpm", &w, &h);
	game->earth = mlx_xpm_file_to_image(game->mlx, "earth.xpm", &w, &h);
	game->chara = mlx_xpm_file_to_image(game->mlx, "chara.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "exit.xpm", &w, &h);
	game->end = mlx_xpm_file_to_image(game->mlx, "you_won.xpm", &w, &h);
	if (game->back == NULL || game->walls == NULL || game->earth == NULL
		|| game->chara == NULL || game->exit == NULL || game->end == NULL)
	{
		ft_putstr_fd("Error\nCorrupted sprites.\n", 2);
		ft_clear_tab(game->tab, game->count);
		ft_destroy_image(game);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit (0);
	}
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
