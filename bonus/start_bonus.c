/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:26:41 by sfraslin          #+#    #+#             */
/*   Updated: 2024/12/30 18:27:23 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

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

int	**ft_begin(char	*title, t_game game)
{
	char	*str;
	int		fd;

	str = "";
	fd = open(title, O_RDONLY);
	game.tab = map_to_tab(fd, game, str);
	game.map = ft_p_coord(game);
	game.count_c = ft_map_check(&game);
	if (game.count_c < 0)
	{
		if (game.count_c == -2)
			ft_error(-3);
		game.tab = ft_clear_tab(game.tab, game.count);
		return (NULL);
	}
	game.tab = ft_clear_tab(game.tab, game.count);
	close(fd);
	fd = open(title, O_RDONLY);
	game.tab = map_to_tab(fd, game, str);
	game.len -= 1;
	ft_create(game);
	return (game.tab);
}

int	**map_to_tab(int fd, t_game game, char *str)
{
	int		**tab;
	int		i;
	int		j;

	i = -1;
	tab = malloc(sizeof(int *) * game.count);
	if (tab == NULL)
		return (0);
	while (++i < game.count)
	{
		j = -1;
		str = get_next_line(fd);
		tab[i] = malloc(sizeof(int) * game.len);
		if (tab[i] == NULL)
		{
			ft_clear_tab(tab, i);
			free(str);
			return (0);
		}
		while (++j < game.len)
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
	if (ft_check_format(av[1]) == 1)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFile does not exist.\n", 2);
		return (1);
	}
	str = "";
	game = ft_check_errors(fd, str);
	if (game.count == 0)
		exit (1);
	game.tab = ft_begin(av[1], game);
	if (game.tab != NULL)
		ft_clear_tab(game.tab, game.count);
	return (0);
}
