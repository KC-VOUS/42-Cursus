NAME		=	so_long

CC			=	clang

FLAG		=	-Wall -Wextra -Werror

LIBFT_PATH	=	./libft/
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_FILE	=	libmlx.a
MLX_PATH	=	./mlx/
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_FLAG	=	-lX11 -lXext
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	map.c				\
				map_checker.c		\
				render.c			\
				render_mouv.c		\
				set.c				\
				texture.c			\
				utils.c				\

SRC_DIR		=	./source/
SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))
OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m./so_long created\n"

$(LIBFT_LIB):
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT_lib created\n"

$(MLX_LIB):
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
	@make -C $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created\n"

clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting So_long object files...\n"
	@rm -f $(OBJ)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting so_long executable...\n"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re

