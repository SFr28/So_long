# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 14:45:58 by sfraslin          #+#    #+#              #
#    Updated: 2025/01/20 19:15:40 by sfraslin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

SRCS = ./srcs/start.c ./srcs/ft_map_check.c ./srcs/create.c ./srcs/move.c ./srcs/errors.c ./srcs/utils.c \
		./srcs/so_long.c ./srcs/end.c
SRCS_BONUS = ./bonus/start_bonus.c ./bonus/ft_map_check_bonus.c ./bonus/create_bonus.c ./bonus/move_bonus.c \
		./bonus/errors_bonus.c ./bonus/utils_bonus.c ./bonus/end_bonus.c ./bonus/so_long_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
HEADER = -I ./includes/so_long.h
HEADER_BONUS = -I ./bonus/so_long_bonus.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lmlx -lX11 -lXext -lm -lz

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a
DIR_MLX = ./minilibx-linux/

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -g -L$(DIR_MLX) $(MLX_FLAGS) $(HEADER) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(LIBFT) $(MINILIBX) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(LIBFT) -g -L$(DIR_MLX) $(MLX_FLAGS) $(HEADER_BONUS) -o $(NAME_BONUS)

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(HEADER) $(HEADER_BONUS) -c $< -o $@

$(LIBFT):
	make bonus --no-print-directory -C ./libft/

$(MINILIBX): 
	make --no-print-directory -C ./minilibx-linux/

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C ./libft/
	make clean -C ./minilibx-linux/

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C ./libft/
	make clean -C ./minilibx-linux/

re: fclean all

.PHONY: all clean fclean re bonus
