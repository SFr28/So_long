/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:15:50 by sfraslin          #+#    #+#             */
/*   Updated: 2025/01/20 11:36:27 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	if (i != '0' && i != '1' && i != 'E' && i != 'P' && i != 'C')
	{
		ft_error(-7);
		return (1);
	}
	return (0);
}

t_game	ft_check_errors(char *title, t_game game, int fd, char *str)
{
	if (ft_check_format(title) == 1)
		return (game);
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
	return (game);
}

int	ft_check_sprites(void)
{
	char	*str[6];
	int		i;
	int		fd;

	str[0] = "back.xpm";
	str[1] = "walls.xpm";
	str[2] = "earth.xpm";
	str[3] = "chara.xpm";
	str[4] = "exit.xpm";
	str[5] = "you_won.xpm";
	i = 0;
	while (i < 6)
	{
		fd = open(str[i], O_RDONLY);
		if (fd < 0)
			return (1);
		close(fd);
		i++;
	}
	return (0);
}
