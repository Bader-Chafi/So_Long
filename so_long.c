/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:11:33 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/10 04:03:56 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void f() { system("leaks so_long"); }

void draw_map(char **map, object *game)
{
    int i;
    size_t j;
    void *m;
    void *w;
    int s;

    i = -1;
    m = game->mlx;
    w = game->win;
    s = game->img_size;
    while (++i < game->len_line)
    {
        j = -1;
        mlx_put_image_to_window(m, w, game->floor, s * j, s * i);
        while (map[i][++j] != '\n' && map[i][j])
        {
            if (i == 0 || i == game->len_line - 1 || j == 0 || j == game->size_line - 1)
                mlx_put_image_to_window(m, w, game->wall[1], j * s, i * s);
            else if (map[i][j] == '1')
                mlx_put_image_to_window(m, w, game->wall[0], j * s, i * s);
            if (map[i][j] == 'C')
                mlx_put_image_to_window(m, w, game->candy, j * s, i * s);
            if (map[i][j] == 'P')
                mlx_put_image_to_window(m, w, game->choper, j * s, i * s);
            if (map[i][j] == 'E')
                mlx_put_image_to_window(m, w, game->exit[1], j * s, i * s);
        }
    }
}

// void draw_wall(char **map, object *game)
// {
//     int i = 0;
//     size_t j;
//     while (i)
//     {
//         if (i = 0)
//         {
//             while ()
//             {
//                 /* code */
//             }
//         }
            
//         if (i == game->len_line - 1)
//         j = 0;
//         if (map[i])
//     }
// }
int main(int ac, char **av)
{
    object *game;
    int fd_map;

    game = NULL;
    game = (object *)malloc(sizeof(object));
    if (!game)
        return (0);
    if (ac != 2)
        ft_error("**the args are not 2.**", game);
    fd_map = check_arg_map(av[1], game);
    if (fd_map < 0)
        return 0;
    game = get_map(fd_map, game, av[1]);
    if (!game)
        return (free(game), 0);
    check_map(game);
    game->map_copy = copy_map(game);
    if (!game->map_copy)
        return (free_game(game), 0);
    flood_fill(game, game->player_x, game->player_y);
    check_map_copy(game->map_copy, game);
    game->width = 40 * game->size_line;
    game->height = 40 * game->len_line;
    initialise_struct(game);
    // draw_wall(game->map, game);
    draw_map(game->map, game);
    mlx_loop(game->mlx);
    char **map = game->map_copy;
    while (*map)
    {
        ft_printf("%s", *map);
        map++;
    }
    free(*map);
    ft_printf("\n");
    free_game(game);
    // atexit(f);
    return (0);
}
