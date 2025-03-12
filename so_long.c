/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:11:33 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/12 00:33:33 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void f() { system("leaks so_long"); }

void exit_game(object *game)
{
    free_game(game);
    exit(EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    object *game;
    int fd_map;

    game = NULL;
    if (ac != 2)
    {
        ft_printf("**the args are not 2.**");
        exit(1);
    }
    game = (object *)malloc(sizeof(object));
    if (!game)
        return (0);
    fd_map = check_arg_map(av[1], game);
    if (fd_map < 0)
        return 0;
    game = get_map(fd_map, game, av[1]);
    if (!game)
        return (free(game), 0);
    check_map(game);
    find_old_exit(game);
    game->map_copy = copy_map(game);
    if (!game->map_copy)
        return (free_game(game), 0);
    flood_fill(game, game->player_x, game->player_y);
    check_map_copy(game->map_copy, game);
    game->width = 40 * game->size_line;
    game->height = 40 * game->len_line;
    initialise_struct(game);
    draw_map(game->map, game);
    mlx_key_hook(game->win, key_hook, game);
    mlx_hook(game->win, 17, 0, close_window, game);
    mlx_loop(game->mlx);
    free_game(game);
    atexit(f);
    return (0);
}
