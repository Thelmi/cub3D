NAME = cub3D

MINILBX = minilibx/libmlx.a

SRC = main.c parsing/parsing.c parsing/map_file_parsing.c parsing/textures_parsing.c parsing/parse_floor_color.c \
		parsing/parse_floor_color_utils.c minilibft/string_functions.c get_next_line/get_next_line.c minilibft/string_functions_two.c \
		get_next_line/get_next_line_utils.c parsing/parse_ceil_color.c \
		parsing/map_parsing.c parsing/map_parsing_utils.c parsing/map_parsing_utils_two.c minilibft/split.c \
		parsing/is_enclosed.c

OBJ := $(SRC:.c=.o)


CFLAGS = -Wall -Werror -Wextra -g3
#CFLAGS =  -Iminilibx -g3 -fsanitize=address

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	cc -g3 $(OBJ) -o $(NAME) $(CFLAGS)

re: fclean all

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

.PHONY: clean fclean all bonus re