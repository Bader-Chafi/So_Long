CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	Mandatory/so_long.c \
	Mandatory/helpers.c \
	Mandatory/parcing.c \
	Mandatory/moves_game.c \
	Mandatory/check_map_2.c \
	Mandatory/maping_function.c \
	utils/ft_printf.c \
	utils/get_next_line.c \
	utils/ft_printf_utils.c \
	utils/get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

all: so_long

so_long: $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o so_long

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf so_long

re: all clean
