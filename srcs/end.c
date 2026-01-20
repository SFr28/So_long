/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:15:16 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/28 10:10:12 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	ft_exit_game(t_game *game, int keycode)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->count)
	{
		y = 0;
		while (y <= game->len)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->back, y * 50, x * 50);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->end,
		game->len * 25 - 75, game->count * 25 - 75);
	if (keycode == XK_Escape)
		ft_close(game);
	return ;
}
