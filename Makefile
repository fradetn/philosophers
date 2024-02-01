# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Maekfile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 01:08:13 by marvin            #+#    #+#              #
#    Updated: 2024/02/01 01:08:13 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I./includes
VPATH = srcs srcs/utils srcs/input
RM = rm -rf

UTILS = ft_longatoi.c\
		handle_error.c\
		utils.c

INPUT = init_args.c\
		check_args.c

NAME = philo

SRCS = $(UTILS)\
		$(INPUT)\
		main.c

OBJ_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(OBJ_DIR):
	@echo "$(YELLOW)Création du répertoire $(OBJ_DIR)..."
	mkdir -p obj
	@echo "$(GREEN)Création terminée.\n"

$(OBJ_DIR)%.o: %.c
	@echo "$(YELLOW)Compilation de $<..."
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	@echo "$(GREEN)Compilation terminée.\n"

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "$(YELLOW)Compilation en cours..."
	$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME)
	@echo "$(GREEN)Compilation terminée.\n"

clean:
	@echo "$(RED)Nettoyage des fichiers objets..."
	$(RM) $(OBJ_DIR)
	
fclean: clean
	@echo "$(RED)Suppression de $(NAME)...\n"
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re

.SILENT: