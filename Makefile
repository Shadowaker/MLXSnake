NAME = snake

MAIN = srcs/main.c
GAMEPLAY = $(wildcard srcs/gameplay/*.c)
INPUTS = $(wildcard srcs/inputs/*.c)
UTILS = $(wildcard srcs/utils/*.c)
SRC = $(UTILS) $(GAMEPLAY) $(INPUTS) $(MAIN)
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

clean2:
	@${RM} $(NAME) ${OBJ}

fclean: clean
	@${RM} $(NAME) ${OBJ}
	@make -C ./mlx/mlxo/ clean

re: clean2
	@make all

git:
	@git add srcs/ incl/*.h mlx/ Makefile
	git status

.PHONY: all clean fclean re
