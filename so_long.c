/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:11:33 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/10 02:25:04 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void f() { system("leaks so_long"); }

void draw_map(void *mlx, void *win, char **map, object *game)
{
    int i;
    size_t j;
    void *wall;
    void *player;
    void *floor;
    void *coin;
    void *exit;
    int img_size = 40;

    i = 0;
    floor = mlx_xpm_file_to_image(mlx, "imageXPM/floor.xpm", &(game->width), &(game->height));
    wall = mlx_xpm_file_to_image(mlx, "imageXPM/wall.xpm", &img_size, &img_size);
    coin = mlx_xpm_file_to_image(mlx, "imageXPM/candy.xpm", &img_size, &img_size);
    player = mlx_xpm_file_to_image(mlx, "imageXPM/player.xpm", &img_size, &img_size);
    exit = mlx_xpm_file_to_image(mlx, "imageXPM/exit1.xpm", &img_size, &img_size);
    while (map[i])
    {
        j = 0;
        mlx_put_image_to_window(mlx, win, floor, j * img_size, i * img_size);
        while (map[i][j] != '\n' && map[i][j] != '\0')
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(mlx, win, wall, j * img_size, i * img_size);
            if (map[i][j] == 'C')
                mlx_put_image_to_window(mlx, win, coin, j * img_size, i * img_size);
            if (map[i][j] == 'P')
                mlx_put_image_to_window(mlx, win, player, j * img_size, i * img_size);
            if (map[i][j] == 'E')
                mlx_put_image_to_window(mlx, win, exit, j * img_size, i * img_size);
            j++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    object *game;
    int fd_map;

    game = NULL;
    game = (object *)malloc(sizeof(object));
    if (!game)
        return (0);
    initialise_struct(game);
    if (ac != 2)
        ft_error("**the args are not 2.**", game);
    fd_map = check_arg_map(av[1], game);
    if (fd_map < 0)
        return 0;
    game = get_map(fd_map, game, av[1]);
    if (!game)
        return (free(game), 0);
    check_map(game);
    // game->map_copy = copy_map(game);
    // if (!game->map_copy)
    //     return (free_game(game), 0);
    // flood_fill(game, game->player_x, game->player_y);
    // check_map_copy(game->map_copy);
    // void *mlx;
    // void *win;
    // mlx = mlx_init();
    // game->width = 40 * game->size_line;
    // game->height = 40 * game->len_line;
    // // ft_printf("%d", game->width);
    // win = mlx_new_window(mlx, game->width, game->height, "SO LONG");
    // draw_map(mlx, win, game->map, game);

    // mlx_hook(win, 17, 0, close_window, NULL);
    // mlx_loop(mlx);
    // char **map = game->map_copy;
    // while (*map)
    // {
    //     ft_printf("%s", *map);
    //     map++;
    // }
    // free(*map);
    // ft_printf("\n");
    free_game(game);
    // atexit(f);
    return (0);
}