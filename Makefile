NAME = cub3D

MINILBX = minilibx/libmlx.a

SRC = main.c parsing/parsing.c minilibft/string_functions.c

OBJ := $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iminilibx

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(MINILBX) $(OBJ)
	cc $(OBJ) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MINILBX):
	make -C ./minilibx

re: fclean all

clean:
	rm -rf $(OBJ)
	make clean -C ./minilibx
fclean: clean
	rm -rf $(NAME)

.PHONY: clean fclean all bonus re