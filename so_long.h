/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:03:03 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/12 08:34:08 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define KEY_UP		126
# define KEY_LEFT	123
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define KEY_ESC		53

int		ft_putchr(int c);
int		ft_putstr(const char *str);
int		ft_putnbr(int n);
int		ft_hexadecimal(unsigned int num, char buffer);
int		ft_hexa_address(unsigned long num);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

typedef struct map
{
	int		len_line;
	int		size_line;
	char	**map;
	char	**map_copy;
	int		o_coin;
	int		o_exit;
	int		exit_y;
	int		exit_x;
	int		player;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
	int		img_size;
	void	*floor;
	void	*wall[2];
	void	*exit;
	void	*candy;
	void	*choper;
	void	*mlx;
	void	*win;
	int		candyw;
	int		move;
}	t_obj;

t_obj	*check_map(t_obj *game);
t_obj	*ft_half_main(t_obj *game, char **av, int fd_map, int ac);
t_obj	*get_map(int fd, t_obj *g, char *fds);
void	check_char_2(char **map, t_obj *game, int i, int j);
void	check_caracters(t_obj *game);
void	check_map_copy(char **c_map);
int		close_window(void);
void	ft_error(char *s);
void	initialise_struct(t_obj *game);
void	free_game(t_obj *game);
void	exit_game(t_obj *game);
char	*free_store(char *map, int i, char **s, t_obj *t);
void	ft_puterror(t_obj *this, char *s);
int		ft_strlenmap(const char *s);
void	check_rectongle_map(t_obj *this);
void	draw_map_2(char **map, int i, int j, t_obj *game);
void	draw_map(char **map, t_obj *game);
void	move_player(t_obj *game, int dx, int dy);
void	win_game(t_obj *game);
int		key_hook(int keycode, t_obj *game);
int		check_arg_map(char *av);
char	**copy_map(t_obj *game);
void	flood_fill(t_obj *game, int x, int y);

#endif
