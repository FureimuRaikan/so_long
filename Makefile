# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by yguinio           #+#    #+#              #
#    Updated: 2025/02/14 18:23:55 by yguinio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc

LIBFT_DIR = ./libft
MINILIBX_DIR = ./minilibx/
SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/

FILES = so_long.c init.c checks.c parsing.c utils.c checks1.c rules_usage.c errors_handling.c mlx_init.c put_image.c

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

MAKE = make
CFLAGS = -Wall -Werror -Wextra -g
INC_H = -I $(INC_DIR) -I $(LIBFT_DIR)/includes -I $(MINILIBX_DIR)
MLX_FLAGS = -L$(MINILIBX_DIR) -L$(LIBFT_DIR)
MLX_LIBS = -lmlx -lm -lz -lXext -lX11 -lft

DEFAULT = \033[0m
DEF_COLOR = \033[0;90m
WHITE = \033[1;37m
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m

all: $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MINILIBX_DIR) >> /dev/null
	@echo "$(GREEN)minilibx compiled!$(DEFAULT)"
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(INC_H) $(OBJ) $(MLX_FLAGS) $(MLX_LIBS) -o $(NAME)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean: 
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(NAME) object files cleaned!$(DEFAULT)"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MINILIBX_DIR) >> /dev/null
	@rm -f libmlx.a


fclean: clean
	@rm -rf $(NAME)
	@echo "$(CYAN)$(NAME) executables and objects removed succesfully!$(DEFAULT)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)libft executables and objects removed succesfully!$(DEFAULT)"
	
re: fclean all

go: all
	valgrind --leak-check=full ./$(NAME) map.ber

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re 
