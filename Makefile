RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m

NAME = so_long.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj/
SRC_DIR = src/
MLX_DIR = minilibx-linux/

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

MLX = $(MLX_DIR)libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	@echo "$(YELLOW)Compilation en cours..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -lX11 -lXext
	@echo "$(GREEN)Compilation terminée.\n"

$(OBJ_DIR):
	@echo "$(YELLOW)Création du répertoire $(OBJ_DIR)..."
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)Création terminée.\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compilation de $<..."
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@
	@echo "$(GREEN)Compilation terminée.\n"

$(MLX):
	@echo "$(YELLOW)Compilation de la bibliothèque MLX..."
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN)Compilation terminée.\n"

clean:
	@echo "$(RED)Nettoyage des fichiers objets..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Suppression de $(NAME)..."
	@rm -f $(NAME)
	@echo "$(YELREDLOW)Suppression de la bibliothèque MLX..."
	@$(MAKE) clean -C $(MLX_DIR) > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re
