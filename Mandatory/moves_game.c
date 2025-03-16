/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:58:06 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/15 21:55:16 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map_2(char **map, int i, int j, t_obj *game)
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
		mlx_put_image_to_window(m, w, game->choper[0], j * s, i * s);
	else if (map[i][j] == 'P' && game->flag == 1)
		mlx_put_image_to_window(m, w, game->choper[1], j * s, i * s);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(m, w, game->exit, j * s, i * s);
}

void	draw_map(char **map, t_obj *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->len_line)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			draw_map_2(map, i, j, game);
			j++;
		}
	}
}

void	move_player(t_obj *game, int dx, int dy)
{
	t_obj	*r;
	int		new_x;
	int		new_y;

	r = game;
	new_x = r->player_x + dx;
	new_y = r->player_y + dy;
	if (r->map[new_x][new_y] == 'E' && game->candyw == r->o_coin)
	{
		r->map[r->player_x][r->player_y] = '0';
		ft_printf("Move: %d\n", ++game->move);
		ft_printf("You win!\n");
		exit_game(r);
	}
	else if (r->map[new_x][new_y] != '1')
	{
		if (r->map[new_x][new_y] == 'C')
			game->candyw++;
		r->map[r->player_x][r->player_y] = '0';
		r->player_x = new_x;
		r->player_y = new_y;
		r->map[new_x][new_y] = 'P';
		ft_printf("Move: %d\n", ++game->move);
	}
}

void	win_game(t_obj *game)
{
	if (game->candyw == game->o_coin)
	{
		game->map[game->exit_x][game->exit_y] = 'E';
		game->exit = mlx_xpm_file_to_image(game->mlx,
				"Mandatory/XPM/exit2.xpm", &game->img_size, &game->img_size);
		if (!game->exit)
			ft_error("error in the load of the image");
	}
	draw_map(game->map, game);
}

int	key_hook(int keycode, t_obj *game)
{
	if (keycode == KEY_UP)
		move_player(game, -1, 0);
	else if (keycode == KEY_LEFT)
	{
		game->flag = 0;
		move_player(game, 0, -1);
	}
	else if (keycode == KEY_DOWN)
		move_player(game, 1, 0);
	else if (keycode == KEY_RIGHT)
	{
		game->flag = 1;
		move_player(game, 0, 1);
	}
	else if (keycode == KEY_ESC)
	{
		ft_printf("You Pressed ESC To Exit Game\n");
		exit_game(game);
	}
	win_game(game);
	return (0);
}
