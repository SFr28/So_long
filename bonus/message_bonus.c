/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:15:50 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/03 17:17:17 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	ft_error(int i)
{
	if (i == 0)
		ft_putstr_fd("Error\nInvalid walls.\n", 2);
	if (i > 2)
		ft_putstr_fd("Error\nToo many files.\n", 2);
	if (i == 1)
		ft_putstr_fd("Error\nNo file.\n", 2);
	if (i == -1)
		ft_putstr_fd("Error\nInvalid items.\n", 2);
	if (i == -2)
		ft_putstr_fd("Error\nInvalid format.\n", 2);
	if (i == -3)
		ft_putstr_fd("Error\nInvalid path.\n", 2);
	if (i == -4)
		ft_putstr_fd("Error\nNot rectangle.\n", 2);
	if (i == -5)
		ft_putstr_fd("Error\nMap too large.\n", 2);
	if (i == -6)
		ft_putstr_fd("Error\nEmpty file.\n", 2);
	if (i == -7)
		ft_putstr_fd("Error\nWrong data in map.\n", 2);
	if (i == -8)
		ft_putstr_fd("Error\nMissing sprites.\n", 2);
	return ;
}

int	ft_items_valid(char i)
{
	if (i != '0' && i != '1' && i != 'E' && i != 'P'
		&& i != 'C' && i != 'D')
	{
		ft_error(-7);
		return (1);
	}
	return (0);
}

t_game	ft_check_errors(int fd, char *str)
{
	t_game	game;

	game.count = 0;
	if (ft_check_sprites() == 1)
	{
		ft_error(-8);
		return (game);
	}
	str = get_next_line(fd);
	if (str == NULL)
	{
		ft_error(-6);
		return (game);
	}
	game.len = (int)ft_strlen(str);
	game.count = ft_count(fd, game.len);
	free(str);
	close(fd);
	if (game.len > 52 || game.count > 27)
	{
		ft_error(-5);
		game.count = 0;
		return (game);
	}
	return (game);
}

int	ft_check_sprites(void)
{
	char	*str[8];
	int		i;
	int		fd;

	str[0] = "back.xpm";
	str[1] = "walls.xpm";
	str[2] = "earth.xpm";
	str[3] = "chara.xpm";
	str[4] = "exit.xpm";
	str[5] = "you_won.xpm";
	str[6] = "dalek.xpm";
	str[7] = "game_over.xpm";
	i = 0;
	while (i < 8)
	{
		fd = open(str[i], O_RDONLY);
		if (fd < 0)
			return (1);
		close(fd);
		i++;
	}
	return (0);
}
