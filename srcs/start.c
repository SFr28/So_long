/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:26:41 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/20 11:36:48 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	**ft_clear_tab(int **tab, int count)
{
	int	y;

	y = 0;
	while (y < count)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
	return (NULL);
}

int	**ft_begin(char	*title, int count, int len)
{
	t_game	game;
	char	*str;
	int		fd;

	str = "";
	fd = open(title, O_RDONLY);
	game.tab = map_to_tab(fd, count, len, str);
	game.map = ft_p_coord(game, count, len);
	game.count_c = ft_map_check(game, count, len);
	if (game.count_c < 0)
	{
		ft_stop(game.count_c, count, fd, game.tab);
		return (NULL);
	}
	game.tab = ft_clear_tab(game.tab, count);
	close(fd);
	fd = open(title, O_RDONLY);
	game.tab = map_to_tab(fd, count, len, str);
	close(fd);
	len -= 1;
	ft_create(game, count, len);
	return (game.tab);
}

int	**map_to_tab(int fd, int count, int len, char *str)
{
	int		**tab;
	int		i;
	int		j;

	i = -1;
	tab = malloc(sizeof(int *) * count);
	if (tab == NULL)
		return (0);
	while (++i < count)
	{
		j = -1;
		str = get_next_line(fd);
		tab[i] = malloc(sizeof(int) * len);
		if (tab[i] == NULL)
		{
			ft_clear_tab(tab, i);
			free(str);
			return (0);
		}
		while (++j < len)
			tab[i][j] = str[j];
		free(str);
	}
	return (tab);
}

int	ft_count(int fd, int len)
{
	char	*str;
	int		count;

	count = 1;
	while (fd)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if ((size_t)len != ft_strlen(str))
		{
			free(str);
			ft_error(-4);
			return (0);
		}
		free(str);
		count++;
	}
	return (count);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;
	char	*str;

	if (ac != 2)
	{
		ft_error(ac);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFile does not exist.\n", 2);
		return (1);
	}
	str = "";
	game.count = 0;
	game = ft_check_errors(av[1], game, fd, str);
	if (game.count == 0)
		exit (1);
	game.tab = ft_begin(av[1], game.count, game.len - 1);
	if (game.tab != NULL)
		ft_clear_tab(game.tab, game.count);
	return (0);
}
