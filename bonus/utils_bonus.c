/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:48:13 by sfraslin          #+#    #+#             */
/*   Updated: 2026/01/22 11:34:13 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

t_coord	ft_p_coord(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->count)
	{
		y = 0;
		while (y < game->len)
		{
			if (game->tab[x][y] == 'P')
			{
				game->map.x = x;
				game->map.y = y;
			}
			y++;
		}
		x++;
	}
	return (game->map);
}

void	ft_load_images(t_game *game, int w, int h)
{
	game->back = mlx_xpm_file_to_image(game->mlx, "./textures/back.xpm", &w, &h);
	game->walls = mlx_xpm_file_to_image(game->mlx, "./textures/walls.xpm", &w, &h);
	game->earth = mlx_xpm_file_to_image(game->mlx, "./textures/earth.xpm", &w, &h);
	game->chara = mlx_xpm_file_to_image(game->mlx, "./textures/chara.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &w, &h);
	game->dalek = mlx_xpm_file_to_image(game->mlx, "./textures/dalek.xpm", &w, &h);
	game->end = mlx_xpm_file_to_image(game->mlx, "./textures/you_won.xpm", &w, &h);
	game->ko = mlx_xpm_file_to_image(game->mlx, "./textures/game_over.xpm", &w, &h);
	game->chara_back = mlx_xpm_file_to_image(game->mlx,
			"./textures/chara_back.xpm", &w, &h);
	game->chara_left = mlx_xpm_file_to_image(game->mlx,
			"./textures/chara_left.xpm", &w, &h);
	game->chara_right = mlx_xpm_file_to_image(game->mlx,
			"./textures/chara_right.xpm", &w, &h);
	if (game->back == NULL || game->walls == NULL || game->earth == NULL
		|| game->chara == NULL || game->exit == NULL || game->end == NULL
		|| game->chara_back == NULL || game->chara_left == NULL
		|| game->chara_right == NULL || game->dalek == NULL
		|| game->ko == NULL)
	{
		ft_putstr_fd("Error\nCorrupted sprites.\n", 2);
		ft_close(game);
	}
}
