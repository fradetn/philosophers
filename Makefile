RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m

OBJ_DIR = obj/
SRC_DIR = src/

NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = $(SRC_DIR)philo.c $(SRC_DIR)check_args.c $(SRC_DIR)ft_longatoi.c 

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compilation en cours..."
	@$(CC) -g $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compilation terminée.\n"

$(OBJ_DIR):
	@echo "$(YELLOW)Création du répertoire $(OBJ_DIR)..."
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)Création terminée.\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compilation de $<..."
	@$(CC) -g $(CFLAGS) -c $< -o $@ && \
		echo "$(GREEN)Compilation terminée.\n" || \
		(echo "$(RED)Erreur de compilation.\n" && exit 1)

clean:
	@echo "$(RED)Nettoyage des fichiers objets..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Suppression de $(NAME)...\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re