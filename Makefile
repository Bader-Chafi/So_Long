BONUS = so_long_bonus
NAME = so_long
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

SOURCES_B = \
	bonus/so_long_bonus.c \
	bonus/helpers_bonus.c \
	bonus/parcing_bonus.c \
	bonus/moves_game_bonus.c \
	bonus/check_map_2_bonus.c \
	bonus/maping_function_bonus.c \
	utils/ft_printf.c \
	utils/ft_itoi.c \
	utils/get_next_line.c \
	utils/ft_printf_utils.c \
	utils/get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_B = $(SOURCES_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c bonus/so_long_bonus.h Mandatory/so_long.h
	cc $(CFLAGS) -c $< -o $@

bonus : $(NAME) $(BONUS)

$(BONUS): $(OBJECTS_B)
	cc $(CFLAGS) $(OBJECTS_B) -lmlx -framework OpenGL -framework AppKit -o $(BONUS) -o $@

clean:
	rm -rf $(OBJECTS) $(OBJECTS_B)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: all bonus clean
