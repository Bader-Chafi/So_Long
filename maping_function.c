/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:54:40 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/10 02:22:52 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *free_store(char *map, int i, char **s, object *t)
{
    if (!map)
    {
        while (--i >= 0)
            free(s[i]);
        free(s);
        return (free(t), NULL);
    }
    return (map);
}

object *get_map(int fd, object *game, char *fds)
{
    char *map;
    int i;
    char **store_map;

    i = 0;
    if (!(map = get_next_line(fd)))
    {
        ft_printf("Error\n** the map is empty **");
        exit(1);
        return NULL;
    }
    while (map)
    {
        free(map);
        i++;
        map = get_next_line(fd);
    }
    store_map = (char **)malloc(sizeof(char *) * (i + 1));
    if (!store_map)
    {
        free(game);
        return NULL;
    }
    close(fd);
    fd = open(fds, O_RDONLY);
    if (fd < 0)
    {
        free(store_map);
        free(game);
        return NULL;
    }
    i = 0;
    while ((map = get_next_line(fd)))
    {
        store_map[i++] = map;
    }
    store_map[i] = NULL;
    game->map = store_map;
    game->len_line = i;
    close(fd);
    return game;
}

void ft_puterror(object *this, char *s)
{
    int i = 0;
    while (this->map[i])
        free(this->map[i++]);
    free(this->map);
    free(this);
    ft_printf("Error\n%s", s);
    exit(EXIT_FAILURE);
}

size_t ft_strlenmap(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\0' && s[i] != '\n')
        i++;
    return (i);
}

void check_rectongle_map(object *this)
{
    int i;
    int j;
    char **map;

    (1) && (i = 0, j = 0, map = this->map);
    this->size_line = ft_strlenmap(*map);

    while (map[i])
    {
        if (this->size_line != ft_strlenmap(map[i]))
            ft_puterror(this, "**the map not rectogler.**");
        if (map[i][0] != '1')
            ft_puterror(this, "**the map is not cyrcel by the wall [0].**");
        i++;
    }
    i--;
    while (map[i][j] != '\n' && map[i][j])
    {
        if (map[i][j] != '1')
            ft_puterror(this, "**the map is not cyrcel by the wall");
        if (map[i][j + 1] == '\n' && !map[i][j + 1] && this->size_line)
            (1) && (j = 0, i = 0, this->size_line = 0);
        j++;
    }
}
