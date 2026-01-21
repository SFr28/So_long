/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:13:19 by sfraslin          #+#    #+#             */
/*   Updated: 2025/05/30 17:05:49 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
