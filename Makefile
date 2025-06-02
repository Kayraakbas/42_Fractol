# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakbas <omakbas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 20:06:24 by omakbas           #+#    #+#              #
#    Updated: 2025/06/02 14:39:28 by omakbas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = fractol

SRC        = main.c \
             math_utils.c \
             mlx_init.c \
             render.c \
             str_util.c \
             events.c

MLX_PATH   = ./minilibx-linux
MLX_LIB    = $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS  = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -I$(MLX_PATH)

CC         = cc
CFLAGS     = -Wall -Werror -Wextra

all: $(NAME)
$(NAME): $(MLX_LIB)
	@echo "Building $(NAME)..."
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(MLX_FLAGS)

$(MLX_LIB):
	@echo "Building MinilibX library..."
	make -s -C $(MLX_PATH)

clean:
	@echo "Cleaning MinilibX build files..."
	make -s -C $(MLX_PATH) clean

fclean: clean
	@echo "Removing executable $(NAME)..."
	rm -f $(NAME)
	make -s -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
