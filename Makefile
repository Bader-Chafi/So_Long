BONUS = so_long_bonus
NAME = so_long
CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	M/so_long.c \
	M/helpers.c \
	M/parcing.c \
	M/moves_game.c \
	M/check_map_2.c \
	M/maping_function.c \
	utils/ft_printf.c \
	utils/get_next_line.c \
	utils/ft_printf_utils.c \
	utils/get_next_line_utils.c

SOURCES_B = \
	B/so_long_bonus.c \
	B/helpers_bonus.c \
	B/parcing_bonus.c \
	B/moves_game_bonus.c \
	B/check_map_2_bonus.c \
	B/maping_function_bonus.c \
	utils/ft_printf.c \
	utils/ft_itoa.c \
	utils/get_next_line.c \
	utils/ft_printf_utils.c \
	utils/get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_B = $(SOURCES_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c B/so_long_bonus.h M/so_long.h
	cc $(CFLAGS) -c $< -o $@

bonus : $(NAME) $(BONUS)

$(BONUS): $(OBJECTS_B)
	cc $(CFLAGS) $(OBJECTS_B) -lmlx -framework OpenGL -framework AppKit -o $(BONUS) -o $@

clean:
	rm -rf $(OBJECTS) $(OBJECTS_B)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all
