# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 16:32:41 by jowoundi          #+#    #+#              #
#    Updated: 2025/05/13 16:26:57 by jowoundi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address -g3
GREEN   = "\\033[32m"
YELLOW	= "\\033[33m"
NC      = "\\033[0m"

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I ./header -I $(LIBFT_DIR)

SRC_DIR = src/
OBJ_DIR = obj/

# Source files from the src directory
SRCS = main.c node.c stock_number.c movement.c sort_number.c parsing.c parsing_quote.c \
free.c sort_under_five.c sort_number_utils.c sort_move.c

OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0

# ARG := $(shell seq 100 | shuf | paste - -s -d ' ')

define progress_bar
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "\r$(YELLOW)Compiling push_swap... [%-$(TOTAL_FILES)s] %d/%d $(NC)" \
	$$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES)  ]; then echo ""; fi
endef

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call progress_bar)


LOGO = "\033[5;36m\
░█▀█░█░█░█▀▀░█░█░░░░░█▀▀░█░█░█▀█░█▀█ \n\
░█▀▀░█░█░▀▀█░█▀█░░░░░▀▀█░█▄█░█▀█░█▀▀ \n\
░▀░░░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀░░ \n\
\033[0m"


all:  $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf "\n"
	@printf $(LOGO)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(NC)"

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

# test: all
# 	./$(NAME) $(ARG) | wc -l	
# 	./$(NAME) $(ARG) | ./checker_linux $(ARG)

.PHONY: all clean fclean re test
