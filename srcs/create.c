/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:36:21 by sfraslin          #+#    #+#             */
/*   Updated: 2024/12/13 19:39:26 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_create(int **tab, int count, int len)
{
    void    *mlx_ptr;
    void    *win_ptr;
	void	*back_img_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, (10*len), (10*count), "so_long");
    //mettre images
	back_img_ptr =  mlx_new_image(mlx_ptr, 10, 10);
	ft_draw_background(mlx_ptr, win_ptr, back_img_ptr);
	mlx_key_hook(win_ptr, ft_move, (void *)0);
	mlx_house_hook(win_ptr, deal_mouse, (void *)0);
    mlx_loop(mlx_ptr);
	return (0);
}

void	ft_draw_background(void *mlx_ptr, void *win_ptr, void *back_img_ptr) //je crois qu'il faut ajouter un truc...
{
	//recup tab, mettre background pour les 0
    mlx_put_image_to_window(mlx_ptr, win_ptr, back_img_ptr, x, y);
}

void	ft_move()
