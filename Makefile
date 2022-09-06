NAME = snake

SRC = $(wildcard srcs/*.c)

HDRS = $(wildcard incl/*.h)

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o: %.c
	gcc -Wall -Wextra -Werror -Imlx -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
	@(make -C ./mlx/mlxo/) 2> /dev/null
	@gcc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[92m$(NAME) compiled succesfully.\033[0m"

all: $(NAME)

clean:
	@${RM} $(OBJ)
	@make -C ./mlx/mlxo/ clean

fclean: clean
	@${RM} $(NAME) ${OBJ}
	@make -C ./mlx/mlxo/ clean

re: fclean
	@make all

git:
	@git add srcs/*.c incl/*.h mlx/ Makefile
	git status

.PHONY: all clean fclean re
