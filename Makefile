# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 13:45:55 by rbestman          #+#    #+#              #
#    Updated: 2025/05/17 18:59:35 by rbestman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)

# Directories
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
SRC_DIR = src

# Uncomment the one you're using

MLX_DIR = minilibx
#MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm  # Linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit  # macOS


# libft + printf files
LIBFT = $(LIBFT_DIR)/libft.a
LIBFTPRINTF = $(PRINTF_DIR)/libftprintf.a

# Source files
SRC_FILES = $(SRC_DIR)/main.c \
	$(SRC_DIR)/get_next_line.c \
	$(SRC_DIR)/map_utils.c \
	$(SRC_DIR)/window_utils.c \
	$(SRC_DIR)/player_utils.c \
	$(SRC_DIR)/item_utils.c
#	$(SRC_DIR)/reward.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Output files
NAME = so_long

# Default rule
all: $(LIBFTPRINTF) $(LIBFT) $(NAME)

# Link program
$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFTPRINTF) $(LIBFT) -o $(NAME) $(MLX_FLAGS)
	@echo "$(NAME) compiled! ✔️"

# Call ft_printf's Makefile
$(LIBFTPRINTF):
	@make -C $(PRINTF_DIR) --silent
	@echo "$(LIBFTPRINTF) compiled! ✔️"

# Call libft's Makefile
$(LIBFT):
	@make -C $(LIBFT_DIR) --silent
	@echo "$(LIBFT) compiled! ✔️"

# Compile object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# clean & remake
clean:
	@rm -f $(OBJ_FILES) $(OBJ_BONUS)
	@make -C $(PRINTF_DIR) clean --silent
	@make -C $(LIBFT_DIR) clean --silent
	@echo "cleaned! 🧹"

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean --silent
	@make -C $(LIBFT_DIR) fclean --silent
	@echo "fully cleaned! 🗑️"

re: fclean all

.PHONY: all clean fclean re
