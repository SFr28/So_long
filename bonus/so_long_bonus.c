/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:13:25 by sfraslin          #+#    #+#             */
/*   Updated: 2025/05/30 17:05:45 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;

	ft_bzero((void *)&game, sizeof(t_game));
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
	game = ft_check_errors(fd, "");
	if (game.count == 0)
		return (1);
	game.tab = ft_begin(av[1], &game);
	if (game.tab != NULL)
		ft_clear_tab(game.tab, game.count);
	return (0);
}
