/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:33:58 by sfraslin          #+#    #+#             */
/*   Updated: 2025/05/16 15:56:50 by sfraslin         ###   ########.fr       */
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
# include <X11/keysym.h>
# include <X11/X.h>

# define TEST 1

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_game
{
	t_coord	map;
	void	*back;
	void	*walls;
	void	*earth;
	void	*chara;
	void	*exit;
	void	*end;
	void	*mlx;
	void	*win;
	int		**tab;
	int		count_c;
	int		x_e;
	int		y_e;
	int		count;
	int		len;
}	t_game;

void	ft_check_path(int **tab, int x, int y);
int		ft_map_check(t_game game, int count, int len);
int		ft_check_walls(int **tab, int count, int len);
int		ft_check_items(int **tab, int count, int len);
int		ft_items_valid(char i);
int		ft_check_format(char *title);
int		**map_to_tab(int fd, int count, int len, char *str);
int		**ft_begin(char *title, int count, int len);
int		**ft_clear_tab(int **tab, int count);

void	ft_create(t_game game, int count, int len);
void	ft_load_images(t_game *game, int width, int height);
void	ft_draw(t_game *game);
void	ft_put_image(t_game *game, int x, int y);
void	ft_exit_game(t_game *game, int keycode);
int		ft_close(t_game *game);

t_game	ft_check_errors(char *title, t_game game, int fd, char *str);
t_coord	ft_p_coord(t_game game, int count, int len);
void	ft_error(int i);
int		ft_count_mvt(int count_mvt);
int		ft_check_sprites(void);
void	ft_stop(int count_c, int count, int fd, int **tab);
void	ft_destroy_image(t_game *game);

int		ft_move(int keycode, t_game *game);
int		ft_up(t_game *game);
int		ft_down(t_game *game);
int		ft_left(t_game *game);
int		ft_right(t_game *game);
int		ft_path(t_game *game, int keycode);
int		ft_count(int fd, int len);

#endif
