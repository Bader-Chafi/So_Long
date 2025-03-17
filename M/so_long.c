/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:11:33 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/17 02:28:15 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_obj	*game;
	int		fd_map;

	game = NULL;
	fd_map = 0;
	game = ft_half_main(game, av, fd_map, ac);
	if (!game)
		exit(1);
	game->width = 40 * game->size_line;
	game->height = 40 * game->len_line;
	initialise_struct(game);
	draw_map(game->map, game);
	mlx_hook(game->win, 2, 0, key_hook, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	free_game(game);
}
