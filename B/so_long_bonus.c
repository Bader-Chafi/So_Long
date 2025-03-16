/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:11:33 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/16 21:27:46 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animate_player_bonus(t_obj_b *game)
{
	static int	counter;

	if (counter++ >= 10)
	{
		game->frame = (game->frame + 1) % 3;
		counter = 0;
		draw_map_bonus(game->map, game);
	}
	return (0);
}

int	anime_bonus(t_obj_b *game)
{
	animate_player_bonus(game);
	if (game->candyw == game->o_coin)
	{
		game->map[game->exit_x][game->exit_y] = 'E';
		animate_exit_bonus(game);
	}
	enemy_bonus(game);
	draw_map_bonus(game->map, game);
	return (1);
}

void	move_enemy_rl_bonus(t_obj_b *game, int x, int y)
{
	int	new_x;
	int	new_y;

	if (game->enemy_dir == 1)
		game->enemy_dir = 1;
	else
		game->enemy_dir = -1;
	(1) && (new_x = x, new_y = y + game->enemy_dir);
	if (game->map[new_x][new_y] == 'P')
		lose_game_bonus(game);
	if (game->map[new_x][new_y] == '1' || game->map[new_x][new_y] == 'C'
		|| game->map[new_x][new_y] == 'E')
	{
		if (game->enemy_dir == 1)
			game->enemy_dir = -1;
		else
			game->enemy_dir = 1;
		game->move_deley = 0;
		return ;
	}
	game->map[x][y] = '0';
	game->map[new_x][new_y] = 'M';
	game->enemy_x = new_x;
	game->enemy_y = new_y;
	draw_map_bonus(game->map, game);
}

void	enemy_bonus(t_obj_b *game)
{
	int			i;
	int			j;
	static int	frame_count;

	i = 0;
	frame_count++;
	if (frame_count < 30)
		return ;
	frame_count = 0;
	while (i < game->len_line)
	{
		j = 0;
		while (j < game->size_line)
		{
			if (game->map[i][j] == 'M')
			{
				game->enemy_x = i;
				game->enemy_y = j;
				move_enemy_rl_bonus(game, i, j);
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_obj_b	*game;
	int		fd_map;

	game = NULL;
	fd_map = 0;
	game = ft_half_main_bonus(game, av, fd_map, ac);
	if (!game)
		exit(1);
	game->width = 50 * game->size_line;
	game->height = 50 * game->len_line;
	initialise_struct_bonus(game);
	draw_map_bonus(game->map, game);
	mlx_hook(game->win, 2, 0, key_hook_bonus, game);
	mlx_loop_hook(game->mlx, anime_bonus, game);
	mlx_hook(game->win, 17, 0, close_window_bonus, game);
	mlx_loop(game->mlx);
	free_game_bonus(game);
}
