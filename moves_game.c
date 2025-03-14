/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 06:58:06 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/15 02:09:58 by bchafi           ###   ########.fr       */
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
		mlx_put_image_to_window(m, w, game->choperl[game->frame], j * s, i * s);
	else if (map[i][j] == 'P' && game->flag == 1)
		mlx_put_image_to_window(m, w, game->choperr[game->frame], j * s, i * s);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(m, w, game->exit[game->framee], j * s, i * s);
}

void	draw_map(char **map, t_obj *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->len_line)
	{
		char *move_count = ft_itoa(game->move);
		mlx_string_put(game->mlx, game->win, 20, 20, 0xFFFFFF, move_count);
		free(move_count);
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			draw_map_2(map, i, j, game);
			j++;
		}
	}
}

void move_player(t_obj *game, int dx, int dy)
{
    int  new_x;
    int  new_y;

    new_x = game->player_x + dx;
    new_y = game->player_y + dy;
    if (game->map[new_x][new_y] != '1' && game->map[new_x][new_y] != 'E')
    {
        if (game->map[new_x][new_y] == 'C')
            game->candyw++;
        game->map[game->player_x][game->player_y] = '0';
        game->player_x = new_x;
        game->player_y = new_y;
        game->map[new_x][new_y] = 'P';
		game->move++;
        draw_map(game->map, game);
    }
    else if (game->map[new_x][new_y] == 'E' && game->candyw == game->o_coin)
    {
        game->map[game->player_x][game->player_y] = '0';
        draw_map(game->map, game);
        ft_printf("You win!\n");
		game->move++;
        exit_game(game);
    }
}



int animate_exit(t_obj *game)
{
    static int frame_counter = 0;
    static int frame_index = 0;

    if (frame_index >= 4)
        return (0);
    if (frame_counter++ > 10)
    {
        game->framee = frame_index;
        frame_index++;
        frame_counter = 0;
        draw_map(game->map, game);
    }
    return (0);
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
		ft_printf("You pressed ESC\n");
		exit_game(game);
	}
	anime(game);
	return (0);
}
