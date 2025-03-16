/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:03:03 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/16 21:32:16 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_ESC 53

# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_A 12

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

typedef struct game
{
	int		len_line;
	int		size_line;
	char	**map;
	char	**map_copy;
	int		o_coin;
	int		o_exit;
	int		o_enemy;
	int		exit_y;
	int		exit_x;
	int		player;
	int		player_x;
	int		player_y;
	int		enemy_x;
	int		enemy_y;
	int		width;
	int		height;
	int		img_size;
	void	*floor;
	void	*wall[2];
	void	*exit[4];
	void	*candy;
	void	*enemy;
	void	*sonicl[5];
	void	*sonicr[5];
	int		flag;
	int		enemy_dir;
	int		move_deley;
	int		frame;
	int		framee;
	void	*mlx;
	void	*win;
	int		candyw;
	int		move;
}	t_obj_b;

t_obj_b	*check_map_bonus(t_obj_b *game);
t_obj_b	*ft_half_main_bonus(t_obj_b *game, char **av, int fd_map, int ac);
t_obj_b	*get_map_bonus(int fd, t_obj_b *g, char *fds);
void	check_char_2_bonus(char **map, t_obj_b *game, int i, int j);
void	check_caracters_bonus(t_obj_b *game);
void	check_map_copy_bonus(char **c_map);
int		close_window_bonus(void);
void	ft_error_bonus(char *s);
void	initialise_struct_bonus(t_obj_b *game);
int		animate_player_bonus(t_obj_b *game);
void	free_game_bonus(t_obj_b *game);
void	exit_game_bonus(t_obj_b *game);
char	*free_store_bonus(char *map, int i, char **s, t_obj_b *t);
void	ft_puterror_bonus(t_obj_b *this, char *s);
int		ft_strlenmap_bonus(const char *s);
void	check_rectongle_map_bonus(t_obj_b *this);
void	draw_map_2_bonus(char **map, int i, int j, t_obj_b *game);
void	draw_map_bonus(char **map, t_obj_b *game);
void	move_player_bonus(t_obj_b *game, int dx, int dy);
int		key_hook_bonus(int keycode, t_obj_b *game);
int		check_arg_map_bonus(char *av);
char	**copy_map_bonus(t_obj_b *game);
void	flood_fill_bonus(t_obj_b *game, int x, int y);
int		anime_bonus(t_obj_b *game);
int		animate_exit_bonus(t_obj_b *game);
char	*ft_itoa(int nbr);
void	lose_game_bonus(t_obj_b *game);
int		anime_bonus(t_obj_b *game);
void	move_enemy_rl_bonus(t_obj_b *game, int x, int y);
void	enemy_bonus(t_obj_b *game);

#endif