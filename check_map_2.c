#include "so_long.h"

void check_caracters(object *game)
{
    int i;
    int j;

    (1) && (i = -1, game->o_coin = 0, game->o_exit = 0, game->player = 0);
    while (game->map[++i])
    {
        j = -1;
        while (game->map[i][++j] != '\n' && game->map[i][j])
        {
            if (game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j] != 'C' && game->map[i][j] != 'P' && game->map[i][j] != 'E')
                ft_puterror(game, "the map must has : 0 1 C P E");
            if (game->map[i][j] == 'P')
                (1) && (game->player_x = i, game->player_y = j, game->player +=1);
            if (game->map[i][j] == 'C')
                game->o_coin += 1;
            if (game->map[i][j] == 'E')
                game->o_exit += 1;
        }
        game->size_line = j;
    }
    if (game->player != 1 || game->o_exit != 1 || game->o_coin < 1)
        ft_puterror(game, "**You Must have 1Player/1Exit more 1Coin**");
}

object *check_map(object *game)
{
    int i;
    char **map;
    i = 0;
    check_rectongle_map(game);
    map = game->map;
    while (map[i])
    {
        if (map[i][game->size_line - 1] && map[i][game->size_line - 1] != '1')
            ft_puterror(game, "**the map is not cyrcel by the wall.**");
        i++;
    }
    check_caracters(game);
    if (game->len_line < 3 || game->size_line < 5 || game->len_line > 35)
        ft_puterror(game, "**the map is not valid lines.**");
    return (game);
}

void check_map_copy(char **c_map, object *game)
{
    char **map;

    map = c_map;
    int i = 0;
    int j;
    while (c_map[i])
    {
        j = 0;
        while (c_map[i][j] != '\n' && c_map[i][j])
        {
            if (c_map[i][j] != 'V' && c_map[i][j] != '1' && c_map[i][j] != '0')
                ft_error("**the map is not Valid.**", game);
            j++;
        }
        i++;
    }
}
