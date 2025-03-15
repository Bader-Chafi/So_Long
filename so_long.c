/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:11:33 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/15 00:39:46 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int animate_player(t_obj *game)
{
    static int counter = 0;
    
    if (counter++ >= 10)
    {
        game->frame = (game->frame + 1) % 3;
        counter = 0;
        draw_map(game->map, game);
        usleep(90000);
    }
    return (0);
}

int	anime(t_obj	*game)
{
	animate_player(game);
	if (game->candyw == game->o_coin)
	{
		game->map[game->exit_x][game->exit_y] = 'E';
		animate_exit(game);
	}
	draw_map(game->map, game);
	return 1;
}

int	main(int ac, char **av)
{
	t_obj	*game;
	int		fd_map;

	game = NULL;
	fd_map = 0;
	game = ft_half_main(game, av, fd_map, ac);
	if (!game)
		exit(1);
	game->width = 50 * game->size_line;
	game->height = 50 * game->len_line;
	initialise_struct(game);
	draw_map(game->map, game);
	mlx_hook(game->win, 2, 0, key_hook, game);
	mlx_loop_hook(game->mlx, anime, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	free_game(game);
}
