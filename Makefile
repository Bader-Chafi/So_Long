# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 17:23:26 by bchafi            #+#    #+#              #
#    Updated: 2025/03/11 21:29:30 by bchafi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
U = utils

SOURCES = \
	so_long.c win_game.c maping_function.c helpers.c parcing.c check_map_2.c moves_game.c\
	$(U)/ft_printf.c $(U)/ft_printf_utils.c \
	$(U)/get_next_line.c $(U)/get_next_line_utils.c \

OBJECTS = $(SOURCES:.c=.o)


all: so_long

so_long: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o so_long 

%.o : %.c so_long.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf so_long


re: all clean