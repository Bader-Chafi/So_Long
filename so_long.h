/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:03:03 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/10 03:11:05 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <libc.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <stdarg.h>

int ft_printf(const char *format, ...);
int ft_strcmp(const char *s1, const char *s2);
int ft_putchr(int c);
int ft_putnbr(int n);
int ft_putstr(const char *str);
int ft_hexadecimal(unsigned int num, char buffer);
int ft_hexa_address(unsigned long num);

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char *get_next_line(int fd);
size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);
char *ft_strdup(const char *s1);
char *ft_strchr(const char *s, int c);
char *ft_strcat(char *s1, const char *s2);

typedef struct map
{
    int len_line;
    size_t size_line;
    char **map;
    char **map_copy;
    int colectible;
    int old_colectible;
    int old_exit;
    int player;
    int player_x;
    int player_y;
    int width;
    int height;
    int img_size;
    void *floor;
    void *wall[2];
    void *exit[2];
    void *candy;
    void *choper;
    void *mlx;
    void *win;
} object;

// win game
int close_window(void *pa);

// helpers
void ft_error(char *s, object *game);
void initialise_struct(object *game);
void free_game(object *game);

// parcing
void initialise_struct(object *game);
int  check_arg_map(char *av, object *game);
char **copy_map(object *game);
void flood_fill(object *game, int x, int y);

// check map 2
object *check_map(object *game);
void check_caracters(object *game);
void check_map_copy(char **c_map, object *game);

// map_func
object *get_map(int fd, object *game, char *fds);
void ft_puterror(object *this, char *s);
size_t ft_strlenmap(const char *s);
void check_rectongle_map(object *this);
char *free_store(char *map, int i, char **s, object *t);

#endif