#include "so_long.h"

void ft_error(char *s, object *game)
{
    ft_printf("Error\n%s", s);
    free_game(game);
    exit(1);
}

void initialise_struct(object *game)
{
    game->len_line = 0;
    game->size_line = 0;
    game->map = NULL;
    game->map_copy = NULL;
    game->colectible = 0;
    game->old_colectible = 0;
    game->exit = 0;
    game->old_exit = 0;
    game->player = 0;
    game->player_x = 0;
    game->player_y = 0;
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

