/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:03:03 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/12 00:24:07 by bchafi           ###   ########.fr       */
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

// Define the keycodes for movement (WASD and Arrow Keys)
// #define KEY_W 13    // W - Move up
// #define KEY_A 0     // A - Move left
// #define KEY_S 1     // S - Move down
// #define KEY_D 2     // D - Move right
// #define KEY_UP 65362    // Arrow Up
// #define KEY_LEFT 65361  // Arrow Left
// #define KEY_DOWN 65364  // Arrow Down
// #define KEY_RIGHT 65363 // Arrow Right
#define KEY_UP 126    // Up Arrow on macOS
#define KEY_LEFT 123  // Left Arrow on macOS
#define KEY_DOWN 125  // Down Arrow on macOS
#define KEY_RIGHT 124 // Right Arrow on macOS

char *get_next_line(int fd);
size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);
char *ft_strdup(const char *s1);
char *ft_strchr(const char *s, int c);
char *ft_strcat(char *s1, const char *s2);

typedef struct map
{
    int len_line;
    int size_line;
    char **map;
    char **map_copy;
    int o_coin;
    int o_exit;
    int exit_y;
    int exit_x;
    int player;
    int player_x;
    int player_y;
    int width;
    int height;
    int img_size;
    void *floor;
    void *wall[2];
    void *exit;
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
int ft_strlenmap(const char *s);
void check_rectongle_map(object *this);
char *free_store(char *map, int i, char **s, object *t);

// int key_hook(int keycode, object *game);
void draw_map(char **map, object *game);
void move_player(int *move, object *game, int *candy, int dx, int dy);
void win_game(int *candy, object *game);
int key_hook(int keycode, object *game);
void find_old_exit(object *game);

void exit_game(object *game);
void find_old_exit(object *game);


#endif