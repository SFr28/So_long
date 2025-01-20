/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:33:58 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/20 12:02:54 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../includes/mlx.h"
# include "../includes/libft.h"
# include "../includes/mlx_int.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

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
	void	*dalek;
	void	*end;
	void	*ko;
	void	*mlx;
	void	*win;
	int		**tab;
	int		count_c;
	int		count_d;
	int		x_e;
	int		y_e;
	int		count;
	int		len;
}	t_game;

void	ft_check_path(int **tab, int x, int y);
int		ft_map_check(t_game *game);
int		ft_check_walls(int **tab, int count, int len);
int		ft_check_items(t_game *game, int count_c);
int		ft_items_valid(char i);
int		ft_check_format(char *title);
int		**map_to_tab(int fd, t_game game, char *str);
int		**ft_begin(char *title, t_game game);
int		**ft_clear_tab(int **tab, int count);

void	ft_create(t_game game);
void	ft_draw(t_game *game, int count_mvt);
void	ft_put_image(t_game *game, int x, int y);
void	ft_exit_game(t_game *game, int keycode);
void	ft_game_over(t_game *game, int keycode);
int		ft_close(t_game *game);

void	ft_error(int i);
t_game	ft_check_errors(int fd, char *str);
t_coord	ft_p_coord(t_game game);
int		ft_check_sprites(void);
void	ft_stop(int count_c, int count, int fd, int **tab);

void	ft_move(int keycode, t_game *game);
int		ft_up(t_game *game, int key);
int		ft_down(t_game *game, int key);
int		ft_left(t_game *game, int key);
int		ft_right(t_game *game, int key);
int		ft_path(t_game *game, int keycode);
int		ft_count(int fd, int len);

#endif
