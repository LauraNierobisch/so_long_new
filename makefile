# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 10:12:21 by lnierobi          #+#    #+#              #
#    Updated: 2024/11/27 12:49:14 by lnierobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
LDFLAGS = -fsanitize=address
OBJ_DIR := ./obj
DEP_DIR := $(OBJ_DIR)/.deps
INC_DIRS := .
SRC_DIRS := .
vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)
vpath %.d $(DEP_DIR)

LIBFT_DIR = libft
LIBFT = libft.a
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)
LIBFTFLAGS = -L$(LIBFT_DIR) -lft
LIBFT_REPO = https://github.com/LauraNierobisch/libft.git

MLXFT_DIR = ./mlx42
MLXFT = libmlx42.a
MLXFT_BUILD_DIR = ./mlx_build
MLXFT_LIB = $(MLXFT_BUILD_DIR)/$(MLXFT)
MLXFTFLAGS = -L$(MLXFT_BUILD_DIR) -lmlx42 -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit
MLXFT_REPO = https://github.com/codam-coding-college/MLX42.git

SRCS = main.c reading_map.c map_validation.c check_wall.c rendering_map.c floodfill.c

OBJECTS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

.PHONY: all clean fclean re libft mlx init-submodules remove-submodules

all: init-submodules $(NAME)

-include $(OBJECTS:.o=.d)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

init-submodules: init-libft init-mlx

init-libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git submodule add $(LIBFT_REPO) $(LIBFT_DIR) || (echo "$(RED)Failed to add libft submodule$(X)" && exit 1); \
	elif [ -z "$$(ls -A $(LIBFT_DIR) 2>/dev/null)" ]; then \
		git submodule update --init --recursive $(LIBFT_DIR) || (echo "$(RED)Failed to update libft submodule$(X)" && exit 1); \
	fi

remove-submodules: remove-libft remove-mlx

remove-libft:
	@if [ -d "$(LIBFT_DIR)" ]; then \
		git submodule deinit -q -f $(LIBFT_DIR) > /dev/null 2>&1; \
		git rm -q -f $(LIBFT_DIR) > /dev/null 2>&1; \
		rm -rf .git/modules/$(LIBFT_DIR) > /dev/null 2>&1; \
	fi

remove-mlx:
	@if [ -d "$(MLXFT_DIR)" ]; then \
		git submodule deinit -q -f $(MLXFT_DIR) > /dev/null 2>&1; \
		git rm -q -f $(MLXFT_DIR) > /dev/null 2>&1; \
		rm -rf .git/modules/$(MLXFT_DIR) > /dev/null 2>&1; \
		rm -rf ./mlx42 > /dev/null 2>&1; \
	fi

$(LIBFT_LIB): init-libft
	@if [ -d "$(LIBFT_DIR)" ] && [ -f "$(LIBFT_DIR)/Makefile" ]; then \
		$(MAKE) -C $(LIBFT_DIR); \
	else \
		exit 1; \
	fi

init-mlx:
	@if [ ! -d "$(MLXFT_DIR)" ]; then \
		git submodule add -q $(MLXFT_REPO) $(MLXFT_DIR) > /dev/null 2>&1 || (echo "$(RED)Failed to add MLX42 submodule$(X)" && exit 1); \
	elif [ -z "$$(ls -A $(MLXFT_DIR) 2>/dev/null)" ]; then \
		git submodule update --init --recursive -q $(MLXFT_DIR) > /dev/null 2>&1 || (echo "$(RED)Failed to update MLX42 submodule$(X)" && exit 1); \
	fi

$(MLXFT_LIB): init-mlx
	@cd $(MLXFT_DIR) && git checkout tags/v2.3.4 2>/dev/null
	@if [ ! -f "$(MLXFT_LIB)" ]; then \
		echo "$(YELLOW)Building MLX42...$(X)"; \
		mkdir -p $(MLXFT_BUILD_DIR); \
		cmake -S $(MLXFT_DIR) -B $(MLXFT_BUILD_DIR) && \
		cmake --build $(MLXFT_BUILD_DIR) --parallel || \
		(echo "$(RED)Failed to build MLX42$(X)" && exit 1); \
	fi

$(NAME): $(LIBFT_LIB) $(MLXFT_LIB) $(OBJECTS)
	@$(CC) -o $@ $(OBJECTS) $(LIBFTFLAGS) $(MLXFTFLAGS)
#$(LDFLAGS)
	@echo "$(SUCCESS)"

clean: remove-submodules
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLXFT_BUILD_DIR)
	@rm -rf $(LIBFT_DIR)
	@echo "$(RED)Objects deleted$(X)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)so_long deleted$(X)"

re: fclean all
