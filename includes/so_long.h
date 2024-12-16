/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:33:58 by sfraslin          #+#    #+#             */
/*   Updated: 2024/12/13 19:25:48 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include "mlx_int.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>

void    ft_check_path(int **tab, int x, int y);
int     ft_map_check(int **tab, int count, int len);
int     ft_check_walls(int **tab, int count, int len);
int     ft_check_items(int **tab, int count, int len);
int     **map_to_tab(int fd, int count, int len, char *str);
int     **ft_begin(char *title, int count, int len);
int     **ft_clear_tab(int **tab, int count);

void    ft_create(int **tab, int count, int len);
void	ft_draw_background(void *mlx_ptr, void *win_ptr, void *backimg_ptr);

#endif
