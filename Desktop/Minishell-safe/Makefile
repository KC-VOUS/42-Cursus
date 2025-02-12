# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdakhlao <sdakhlao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 15:38:06 by sdakhlao          #+#    #+#              #
#    Updated: 2025/02/11 18:44:20 by sdakhlao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	gcc

FLAG		=	-Wall -Werror -Wextra -g3
LDFLAGS		=	-lreadline

C_FILE		=	minishell.c		\
				split.c			\
				lexer.c			\
				split_utils.c	\
				get_env.c		\
				lexer_utils.c	\
				builtin.c		\
				code.c			\
				split_utils_bis.c


SRC_DIR		=	./src/

SRC			=	$(addprefix $(SRC_DIR), $(C_FILE))

OBJ_PATH	=	$(SRC_DIR)obj/
OBJ			=	$(C_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

$(OBJ_PATH)%.o: $(SRC_DIR)%.c
				@mkdir -p $(OBJ_PATH)
				$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;33m\nCOMPILING MINISHELL...\n"
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "\033[1;32m./minishell created\n"

clean:
	@echo "\033[0;31mDeleting minishell object files...\n"
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting minishell executable...\n"
	@rm -f $(NAME)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re
