# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdakhlao <sdakhlao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 13:33:07 by sdakhlao          #+#    #+#              #
#    Updated: 2024/12/10 21:13:39 by sdakhlao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	cc

FLAG		=	-Wall -Werror -Wextra -g3 -pthread

C_FILE		=	init.c			\
				pars.c			\
				philo.c			\
				utils.c			\
				actions.c		\
				routine.c		\
				threads.c		\
				case_one.c		\
				error_exit.c	\
				malloc_mutex.c	\

SRC_DIR		=	./sources/

SRC			=	$(addprefix $(SRC_DIR), $(C_FILE))

OBJ_PATH	=	$(SRC_DIR)obj/
OBJ			=	$(C_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

$(OBJ_PATH)%.o: $(SRC_DIR)%.c
				@mkdir -p $(OBJ_PATH)
				$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;33m\nCOMPILING PHILO...\n"
	$(CC) $(OBJS) -o $(NAME)
	@echo "\033[1;32m./Philo created\n"

clean:
	@echo "\033[0;31mDeleting philo object files...\n"
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting philo executable...\n"
	@rm -f $(NAME)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re
