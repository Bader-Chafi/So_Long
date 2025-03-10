#include "so_long.h"

int check_arg_map(char *av, object *game)
{
    int len;
    int fd;

    fd = open(av, O_RDONLY, 666);
    if (fd < 0)
    {
        ft_error("**the file is not exist.**", game);
        return (-1);
    }
    len = ft_strlen(av);
    if (len < 4)
        return (-1);
    if (ft_strcmp(av + len - 4, ".ber"))
        ft_error("**the file is not final with .ber.**", game);
    return (fd);
}

char **copy_map(object *game)
{
    int i;
    char **map_copy;

    map_copy = (char **)malloc(sizeof(char *) * (game->len_line + 1));
    if (!map_copy)
        return (NULL);
    i = 0;
    while (game->map[i])
    {
        map_copy[i] = ft_strdup(game->map[i]);
        i++;
    }
    map_copy[i] = NULL;
    return (map_copy);
}

void flood_fill(object *game, int x, int y)
{
    if (game->map_copy[x][y] == '1' || game->map_copy[x][y] == 'V')
        return;
    game->map_copy[x][y] = 'V';
    flood_fill(game, x + 1, y);
    flood_fill(game, x - 1, y);
    flood_fill(game, x, y + 1);
    flood_fill(game, x, y - 1);
}

