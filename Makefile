# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 13:05:36 by yguinio           #+#    #+#              #
#    Updated: 2025/02/27 10:46:09 by fureimu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
BONUS_FLAG = .bonus_compiled

LIBFT_DIR = ./libft
MINILIBX_DIR = ./minilibx/
SRC_DIR = ./srcs/
SRC_BONUS_DIR = ./srcs_bonus/
OBJ_DIR = ./obj/
BONUS_OBJ_DIR = ./bonus_obj/
INC = ./includes/

FILES = so_long.c rules.c map_checks.c map_checks2.c parsing.c mlx_utils.c game_utils.c game_utils2.c key_input.c display.c display_utils.c
BONUS_FILES = so_long.c rules.c map_checks.c map_checks2.c parsing.c mlx_utils.c game_utils.c game_utils2.c key_input.c display.c display_utils.c display2.c foes.c display_utils2.c

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_FILES:.c=.o))

MAKE = make
CFLAGS = -Wall -Werror -Wextra -g
INC_H = -I $(INC) -I $(LIBFT_DIR)/includes -I $(MINILIBX_DIR)
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
	@if [ -f $(BONUS_FLAG) ]; then \
		echo "$(YELLOW)Bonus compiled previously. Recompiling $(NAME)...$(DEFAULT)"; \
		rm -rf $(BONUS_FLAG); \
		rm -rf $(NAME); \
		rm -rf $(BONUS_OBJ_DIR); \
	fi
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MINILIBX_DIR) >> /dev/null
	@echo "$(GREEN)minilibx compiled!$(DEFAULT)"
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(INC_H) $(OBJ) $(MLX_FLAGS) $(MLX_LIBS) -o $(NAME)

$(BONUS_FLAG): $(BONUS_OBJ)
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MINILIBX_DIR) >> /dev/null
	@echo "$(GREEN)minilibx compiled!$(DEFAULT)"
	@echo "$(GREEN)$(NAME) compiled with bonus!$(DEFAULT)"
	@$(CC) $(CFLAGS) $(INC_H) $(BONUS_OBJ) $(MLX_FLAGS) $(MLX_LIBS) -o $(NAME)
	@touch $(BONUS_FLAG)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(BONUS_OBJ_DIR)%.o: $(SRC_BONUS_DIR)%.c | $(BONUS_OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INC_H) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	@mkdir -p $(BONUS_OBJ_DIR)

bonus: $(BONUS_FLAG)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BONUS_OBJ_DIR)
	@rm -rf $(BONUS_FLAG)
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
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) map.ber
	
gonus: bonus
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) map.ber

# Specify that these are not files to compile (just for safety)
.PHONY: all clean fclean re 