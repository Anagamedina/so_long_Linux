# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 16:22:56 by anamedin          #+#    #+#              #
#    Updated: 2024/09/06 18:53:06 by anamedin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================= CONFIG==================== #


INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ===================================== #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR) $(INCLUDES) #-fsanitize=address

SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = minilibx-linux
LIBFT_DIR = libft
SO_LONG_H = includes/so_long.h

SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/init_mlx.c \
		$(SRC_DIR)/render_utils.c \
		$(SRC_DIR)/map_extensions.c \
		$(SRC_DIR)/map_items.c \
		$(SRC_DIR)/map_init.c \
		$(SRC_DIR)/init_structs.c \
		$(SRC_DIR)/handle_errors.c \
		$(SRC_DIR)/init_players.c \
		$(SRC_DIR)/exit_free.c \
		$(SRC_DIR)/sprites_player.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

# ==================================== #

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(SO_LONG_H)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ==================================== #
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# ==================================== #
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
