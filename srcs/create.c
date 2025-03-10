/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:36:21 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/20 11:56:10 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_create(t_game game, int count, int len)
{
	int	width;
	int	height;

	game.mlx = mlx_init();
	game.count = count;
	game.len = len;
	mlx_get_screen_size(game.mlx, &width, &height);
	if (game.len * 50 >= width || game.count * 50 >= height)
	{
		ft_error(-5);
		ft_close(&game);
	}
	game.win = mlx_new_window(game.mlx, 50 * (len + 1), 50 * count, "so_long");
	game.back = mlx_xpm_file_to_image(game.mlx, "back.xpm", &width, &height);
	game.walls = mlx_xpm_file_to_image(game.mlx, "walls.xpm", &width, &height);
	game.earth = mlx_xpm_file_to_image(game.mlx, "earth.xpm", &width, &height);
	game.chara = mlx_xpm_file_to_image(game.mlx, "chara.xpm", &width, &height);
	game.exit = mlx_xpm_file_to_image(game.mlx, "exit.xpm", &width, &height);
	game.end = mlx_xpm_file_to_image(game.mlx, "you_won.xpm", &width, &height);
	ft_draw(&game);
	mlx_key_hook(game.win, ft_move, &game);
	mlx_hook(game.win, 17, 1L << 17, ft_close, &game);
	mlx_loop(game.mlx);
}

void	ft_draw(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (x < game->count)
	{
		y = 0;
		while (y <= game->len)
		{
			ft_put_image(game, x, y);
			y++;
		}
		x++;
	}
}

void	ft_put_image(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->back, y * 50, x * 50);
	if (game->tab[x][y] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->walls, y * 50, x * 50);
	if (game->tab[x][y] == 'P')
	{
		game->map.x = x;
		game->map.y = y;
		mlx_put_image_to_window(game->mlx, game->win,
			game->chara, y * 50, x * 50);
	}
	if (game->tab[x][y] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->earth, y * 50, x * 50);
	if (game->tab[x][y] == 'E')
	{
		game->x_e = x;
		game->y_e = y;
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit, y * 50, x * 50);
	}
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
	if (game->len < 7 && game->count < 7)
		mlx_put_image_to_window(game->mlx, game->win, game->end,
			50, 0);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->end,
			game->len * 25 - 150, game->count * 25 - 150);
	if (keycode == XK_Escape)
		ft_close(game);
	return ;
}

int	ft_move(int key, t_game *game)
{
	static int	count_items;
	static int	count_mvt;

	if (count_items != game->count_c || (count_items == game->count_c
			&& (game->map.x != game->x_e || game->map.y != game->y_e)))
	{
		if ((key == XK_a && game->tab[game->map.x][game->map.y - 1] != '1') ||
			(key == XK_s && game->tab[game->map.x + 1][game->map.y] != '1') ||
			(key == XK_d && game->tab[game->map.x][game->map.y + 1] != '1') ||
			(key == XK_w && game->tab[game->map.x - 1][game->map.y] != '1'))
		{
			count_items += ft_path(game, key);
			count_mvt = ft_count_mvt(count_mvt);
		}
	}
	if (key == XK_Escape)
		ft_close(game);
	if (game->map.x != game->x_e || game->map.y != game->y_e)
		game->tab[game->x_e][game->y_e] = 'E';
	ft_draw(game);
	if (count_items == game->count_c)
		if (game->map.x == game->x_e && game->map.y == game->y_e)
			ft_exit_game(game, key);
	return (0);
}
