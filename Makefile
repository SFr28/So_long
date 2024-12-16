# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 14:45:58 by sfraslin          #+#    #+#              #
#    Updated: 2024/12/13 18:41:08 by sfraslin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = ./srcs/test.c ./srcs/ft_map_check.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lmlx -lX11 -lXext -lm -lz

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/

all : $(NAME)

$(NAME) : libft_a libmlx_a $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -L$(MINILIBX) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft_a:
	make bonus -C ./libft/

libmlx_a: 
	make -C ./minilibx-linux/

clean:
	rm -f $(OBJS)
	make clean -C ./libft/
	make clean -C ./minilibx-linux/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/
	make clean -C ./minilibx-linux/

re: fclean all

.PHONY: all clean fclean re
