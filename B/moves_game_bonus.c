/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:58:06 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/16 21:17:40 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_map_2_bonus(char **map, int i, int j, t_obj_b *game)
{
	void	*m;
	void	*w;
	int		s;

	m = game->mlx;
	w = game->win;
	s = game->img_size;
	mlx_put_image_to_window(m, w, game->floor, j * s, i * s);
	if (i == 0 || i == game->len_line - 1 || j == 0 || j == game->size_line - 1)
		mlx_put_image_to_window(m, w, game->wall[1], j * s, i * s);
	else if (map[i][j] == '1')
		mlx_put_image_to_window(m, w, game->wall[0], j * s, i * s);
	if (map[i][j] == 'C')
		mlx_put_image_to_window(m, w, game->candy, j * s, i * s);
	else if (map[i][j] == 'P' && game->flag == 0)
		mlx_put_image_to_window(m, w, game->sonicl[game->frame], j * s, i * s);
	else if (map[i][j] == 'P' && game->flag == 1)
		mlx_put_image_to_window(m, w, game->sonicr[game->frame], j * s, i * s);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(m, w, game->exit[game->framee], j * s, i * s);
	else if (map[i][j] == 'M')
		mlx_put_image_to_window(m, w, game->enemy, j * s, i * s);
}

void	draw_map_bonus(char **map, t_obj_b *game)
{
	int		i;
	int		j;
	char	*move_count;

	i = -1;
	while (++i < game->len_line)
	{
		move_count = ft_itoa(game->move);
		mlx_string_put(game->mlx, game->win, 20, 20, 0xFFFFFF, move_count);
		free(move_count);
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			draw_map_2_bonus(map, i, j, game);
			j++;
		}
	}
}

void	lose_game_bonus(t_obj_b *game)
{
	ft_printf("You Are Lose The Game !!");
	exit_game_bonus(game);
}

void	move_player_bonus(t_obj_b *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	enemy_bonus(game);
	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_x][new_y] == 'E' && game->candyw == game->o_coin)
	{
		game->map[game->player_x][game->player_y] = '0';
		draw_map_bonus(game->map, game);
		ft_printf("You win!\n");
		game->move++;
		exit_game_bonus(game);
	}
	else if (game->map[new_x][new_y] != '1')
	{
		if (game->map[new_x][new_y] == 'C')
			game->candyw++;
		if (game->map[new_x][new_y] == 'M')
			lose_game_bonus(game);
		game->map[game->player_x][game->player_y] = '0';
		(1) && (game->player_x = new_x, game->player_y = new_y);
		(1) && (game->map[new_x][new_y] = 'P', game->move++);
		draw_map_bonus(game->map, game);
	}
}

int	key_hook_bonus(int keycode, t_obj_b *game)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		move_player_bonus(game, -1, 0);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		game->flag = 0;
		move_player_bonus(game, 0, -1);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_player_bonus(game, 1, 0);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		game->flag = 1;
		move_player_bonus(game, 0, 1);
	}
	else if (keycode == KEY_ESC)
	{
		ft_printf("You pressed ESC To Exit !!\n");
		exit_game_bonus(game);
	}
	anime_bonus(game);
	return (0);
}
