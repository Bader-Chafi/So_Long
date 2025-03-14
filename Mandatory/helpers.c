/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:37:46 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/14 21:41:51 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_error(char *s)
{
	ft_printf("Error\n%s", s);
	exit(1);
}

void initialise_struct(t_obj *game)
{
	int s;

	game->img_size = 40;
	game->candyw = 0;
	game->move = 0;
	s = game->img_size;
	game->flag = 1;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: mlx_init() failed\n");
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->width, game->height,
							   "SO LONG ** Take all Collect then exit from the door **");
	game->floor = mlx_xpm_file_to_image(game->mlx, "Mandatory/XPM/back.xpm", &s, &s);
	game->wall[0] = mlx_xpm_file_to_image(game->mlx, "Mandatory/XPM/wallBP.xpm", &s, &s);
	game->wall[1] = mlx_xpm_file_to_image(game->mlx, "Mandatory/XPM/wall.xpm", &s, &s);
	game->candy = mlx_xpm_file_to_image(game->mlx, "Mandatory/XPM/candy.xpm", &s, &s);
	game->choper[0] = mlx_xpm_file_to_image(game->mlx, "Mandatory/XPM/ple.xpm", &s, &s);
	game->choper[1] = mlx_xpm_file_to_image(game->mlx, "Mandatory/XPM/pri.xpm", &s, &s);
	if (!game->floor || !game->wall[0] || !game->wall[1] || !game->candy
		|| !game->choper[0] || !game->choper[1])
		ft_puterror(game, "Error Failed to load an image");
}

void free_game(t_obj *game)
{
	char **tmp;

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

void exit_game(t_obj *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
}

t_obj *ft_half_main(t_obj *game, char **av, int fd_map, int ac)
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
