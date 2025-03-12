#include "so_long.h"

void ft_error(char *s, object *game)
{
    ft_printf("Error\n%s", s);
    free_game(game);
    exit(1);
}

void initialise_struct(object *game)
{
    int s;
    game->img_size = 40;

    s = game->img_size;
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->width, game->height, "SO LONG ** Take all Collect then old_exit from the door **");
    game->floor = mlx_xpm_file_to_image(game->mlx, "imageXPM/floor1.xpm", &s, &s);
    game->wall[0] = mlx_xpm_file_to_image(game->mlx, "imageXPM/wallP.xpm", &s, &s);
    game->wall[1] = mlx_xpm_file_to_image(game->mlx, "imageXPM/wall.xpm", &s, &s);
    game->candy = mlx_xpm_file_to_image(game->mlx, "imageXPM/candy.xpm", &s, &s);
    game->choper = mlx_xpm_file_to_image(game->mlx, "imageXPM/player.xpm", &s, &s);
    game->exit = mlx_xpm_file_to_image(game->mlx, "imageXPM/exit1.xpm", &s, &s);
}

void free_game(object *game)
{
    char **tmp;
    int i = 2;

    tmp = game->map;
    while (i > 1)
    {
        while (*tmp)
        {
            free(*tmp);
            tmp++;
        }
        free(game->map);
        i--;
    }
    if (game->map_copy)
    {
        tmp = game->map_copy;
        while (*tmp)
        {
            free(*tmp);
            tmp++;
        }
        free(game->map_copy);
    }
    free(game);
}
