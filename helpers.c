/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:37:46 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/15 00:09:18 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *s)
{
	ft_printf("Error\n%s", s);
	exit(1);
}

void img_play_exit(t_obj *game)
{
	int s; // Declare a temporary variable for size

	game->choperl[0] = mlx_xpm_file_to_image(game->mlx, "XPM/pl1.xpm", &s, &s);
	game->choperl[1] = mlx_xpm_file_to_image(game->mlx, "XPM/pl2.xpm", &s, &s);
	game->choperl[2] = mlx_xpm_file_to_image(game->mlx, "XPM/pl3.xpm", &s, &s);
	game->choperl[3] = mlx_xpm_file_to_image(game->mlx, "XPM/pl4.xpm", &s, &s);
	game->choperl[4] = mlx_xpm_file_to_image(game->mlx, "XPM/pl5.xpm", &s, &s);
	game->choperr[0] = mlx_xpm_file_to_image(game->mlx, "XPM/pr1.xpm", &s, &s);
	game->choperr[1] = mlx_xpm_file_to_image(game->mlx, "XPM/pr2.xpm", &s, &s);
	game->choperr[2] = mlx_xpm_file_to_image(game->mlx, "XPM/pr3.xpm", &s, &s);
	game->choperr[3] = mlx_xpm_file_to_image(game->mlx, "XPM/pr4.xpm", &s, &s);
	game->choperr[4] = mlx_xpm_file_to_image(game->mlx, "XPM/pr5.xpm", &s, &s);
	game->exit[0] = mlx_xpm_file_to_image(game->mlx, "XPM/d1.xpm", &s, &s);
	game->exit[1] = mlx_xpm_file_to_image(game->mlx, "XPM/d2.xpm", &s, &s);
	game->exit[2] = mlx_xpm_file_to_image(game->mlx, "XPM/d3.xpm", &s, &s);
	game->exit[3] = mlx_xpm_file_to_image(game->mlx, "XPM/d4.xpm", &s, &s);
}

void initialise_struct(t_obj *game)
{
    int s;

    game->img_size = 50;
    game->candyw = 0;
    game->move = 0;
    game->flag = 1;
    s = game->img_size;
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->width, game->height,
            "SO LONG ** Take all Collect then exit from the door **");
    game->floor = mlx_xpm_file_to_image(game->mlx, "XPM/back.xpm", &s, &s);
    img_play_exit(game);
    game->wall[0] = mlx_xpm_file_to_image(game->mlx, "XPM/wallBP.xpm", &s, &s);
    game->wall[1] = mlx_xpm_file_to_image(game->mlx, "XPM/wall.xpm", &s, &s);
    game->candy = mlx_xpm_file_to_image(game->mlx, "XPM/meatB.xpm", &s, &s);
    game->frame = 0;
    game->framee = 0;
    if (!game->floor || !game->wall[0] || !game->wall[1] || !game->candy)
        ft_puterror(game, "Error: Failed to load an image");
}


void	free_game(t_obj *game)
{
	char	**tmp;

	tmp = game->map;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(game->map);
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

void	exit_game(t_obj *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
}

t_obj	*ft_half_main(t_obj *game, char **av, int fd_map, int ac)
{
	if (ac != 2)
	{
		ft_printf("**the args are not 2.**");
		exit(1);
	}
	game = (t_obj *)malloc(sizeof(t_obj));
	if (!game)
		exit(1);
	fd_map = check_arg_map(av[1]);
	if (fd_map < 0)
		return (NULL);
	game = get_map(fd_map, game, av[1]);
	if (!game)
		return (free(game), NULL);
	check_map(game);
	game->map_copy = copy_map(game);
	if (!game->map_copy)
		return (free_game(game), NULL);
	flood_fill(game, game->player_x, game->player_y);
	check_map_copy(game->map_copy);
	return (game);
}
