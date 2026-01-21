# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfraslin <sfraslin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 14:45:58 by sfraslin          #+#    #+#              #
#    Updated: 2026/01/21 12:11:24 by sfraslin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lmlx -lX11 -lXext -lm -lz

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a
DIR_MLX = ./minilibx-linux/

INCLUDES = -I ./includes/so_long.h
INCLUDES_BONUS = -I ./bonus/so_long_bonus.h

OBJS_DIR = objs/
OBJS_BONUS_DIR = objs_bonus/
SRCS_DIR = srcs/
SRCS_BONUS_DIR = bonus/

FILES =	main.c \
		start.c ft_map_check.c create.c end.c\
		move.c errors.c utils.c \
		
FILES_BONUS =	main_bonus.c \
				start_bonus.c ft_map_check_bonus.c create_bonus.c end_bonus.c \
				move_bonus.c errors_bonus.c utils_bonus.c  

SRCS = $(addprefix $(SRCS_DIR), $(FILES))
SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR), $(FILES_BONUS))
OBJS = $(addprefix $(OBJS_DIR), $(FILES:.c=.o))
OBJS_BONUS = $(addprefix $(OBJS_BONUS_DIR), $(FILES_BONUS:.c=.o))

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) -L$(DIR_MLX) $(MLX_FLAGS) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(LIBFT) $(MINILIBX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(INCLUDES_BONUS) $(LIBFT) -L$(DIR_MLX) $(MLX_FLAGS) -o $(NAME_BONUS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_BONUS_DIR)%.o : $(SRCS_BONUS_DIR)%.c
	mkdir -p $(OBJS_BONUS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@


$(LIBFT):
	make bonus --no-print-directory -C ./libft/

$(MINILIBX): 
	make --no-print-directory -C ./minilibx-linux/

clean:
	rm -rf $(OBJS_DIR)
	make clean -C ./libft/
	make clean -C ./minilibx-linux/

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean --no-print-directory -C ./libft/
	make clean --no-print-directory -C ./minilibx-linux/

re: fclean all

.PHONY: all clean fclean re bonus
