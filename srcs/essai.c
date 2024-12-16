/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essai.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:16:19 by sfraslin          #+#    #+#             */
/*   Updated: 2024/12/12 12:22:32 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

int	deal_key(int keycode, void *param) //
{
	(void)param;
	ft_putchar_fd('X', 1);
	if (keycode == 119)
		ft_putchar_fd('W', 1); //vers haut
	if (keycode == 97)
		ft_putchar_fd('A', 1); //vers gauche
	if (keycode == 115)
		ft_putchar_fd('S', 1); //vers bas
	if (keycode == 100)
		ft_putchar_fd('D', 1); //vers droite
	return (0);
}

int	deal_mouse(int button, void *param)
{
	(void)param;
	(void)button;
	ft_putchar_fd('M', 1);
	return (0);
}
// int	close_window(int button, int x, int y, void *param) //marche pas
#include "../includes/so_long.h"
// {
// 	if (x > 400 && y > 400)
// 		mlx_destroy_window(&param[0], &param[1]);
// 	return (0);
// }

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
//	void	*param_mouse;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 700, "essai");
	// param_mouse[0] = mlx_ptr;
	// param_mouse[1] = win_ptr;
	x = 100;
	y = 50;
	while (y < 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000);
		y++;
	}
	y = 75;
	while (x < 120)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x71AD05);
		x++;
	}
	y = 50;
	while (y < 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0000FF);
		y++;
	}
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_mouse_hook(win_ptr, deal_mouse, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
