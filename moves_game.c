#include "so_long.h"

void draw_map(char **map, object *game)
{
    int i;
    int j;
    void *m;
    void *w;
    int s;

    (1) && (i = -1, m = game->mlx, w = game->win, s = game->img_size);
    while (++i < game->len_line)
    {
        j = -1;
        while (map[i][++j] != '\n' && map[i][j])
        {
            mlx_put_image_to_window(m, w, game->floor, j * s, i * s);
            if (i == 0 || i == game->len_line - 1 || j == 0 || j == game->size_line - 1)
                mlx_put_image_to_window(m, w, game->wall[1], j * s, i * s);
            else if (map[i][j] == '1')
                mlx_put_image_to_window(m, w, game->wall[0], j * s, i * s);
            if (map[i][j] == 'C')
                mlx_put_image_to_window(m, w, game->candy, j * s, i * s);
            if (map[i][j] == 'P')
                mlx_put_image_to_window(m, w, game->choper, j * s, i * s);
            if (map[i][j] == 'E')
                mlx_put_image_to_window(m, w, game->exit, j * s, i * s);
        }
    }
}

void find_exit(object *game)
{
    int i;
    int j;

    i = -1;
    while (game->map[++i])
    {
        j = -1;
        while (game->map[i][++j])
        {
            if (game->map[i][j] == 'E')
            {
                (1) && (game->exit_x = i, game->exit_y = j);
                game->map[i][j] = '0';
                return;
            }
        }
    }
}

void move_player(int *move, object *game, int *candy, int dx, int dy)
{
    object *r = game;
    int new_x = r->player_x + dx;
    int new_y = r->player_y + dy;

    if (r->map[new_x][new_y] != '1' && r->map[new_x][new_y] != 'E')
    {
        if (r->map[new_x][new_y] == 'C')
            (*candy)++;

        r->map[r->player_x][r->player_y] = '0';
        r->player_x = new_x;
        r->player_y = new_y;
        r->map[new_x][new_y] = 'P';
        ft_printf("Move: %d\n", ++(*move));
    }
    else if (r->map[new_x][new_y] == 'E' && *candy == r->o_coin)
    {
        r->map[r->player_x][r->player_y] = '0';
        ft_printf("Move: %d\n", ++(*move));
        ft_printf("You win!\n");
        exit_game(r);
    }
}

void win_game(int *candy, object *game)
{
    if (*candy == game->o_coin)
    {
        game->map[game->exit_x][game->exit_y] = 'E';
        game->exit = mlx_xpm_file_to_image(game->mlx, "XPM/exit2.xpm", &game->img_size, &game->img_size);
        if (!game->exit)
            ft_error("error in the load of the image");
    }
    draw_map(game->map, game);
}

int key_hook(int keycode, object *game)
{
    static int candy;
    static int move;

    if (keycode == KEY_UP)
        move_player(&move, game, &candy, -1, 0);
    else if (keycode == KEY_LEFT)
        move_player(&move, game, &candy, 0, -1);
    else if (keycode == KEY_DOWN)
        move_player(&move, game, &candy, 1, 0);
    else if (keycode == KEY_RIGHT)
        move_player(&move, game, &candy, 0, 1);
    else if (keycode == 53)
    {
        ft_printf("You pressed ESC\n");
        exit_game(game);
    }
    win_game(&candy, game);
    return (0);
}
