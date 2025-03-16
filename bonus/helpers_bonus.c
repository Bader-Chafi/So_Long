/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:37:46 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/16 04:47:41 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error_bonus(char *s)
{
	ft_printf("Error\n%s", s);
	exit(1);
}

void img_play_exit_bonus(t_obj_b *game)
{
	int s; // Declare a temporary variable for size

	game->sonicl[0] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/pl1.xpm", &s, &s);
	game->sonicl[1] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/pl2.xpm", &s, &s);
	game->sonicl[2] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/pl3.xpm", &s, &s);
	game->sonicl[3] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/pl4.xpm", &s, &s);
	game->sonicl[4] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/pl5.xpm", &s, &s);
	game->sonicr[0] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/pr1.xpm", &s, &s);
	game->sonicr[1] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/pr2.xpm", &s, &s);
	game->sonicr[2] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/pr3.xpm", &s, &s);
	game->sonicr[3] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/pr4.xpm", &s, &s);
	game->sonicr[4] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/pr5.xpm", &s, &s);
	game->exit[0] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/d1.xpm", &s, &s);
	game->exit[1] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/d2.xpm", &s, &s);
	game->exit[2] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/d3.xpm", &s, &s);
	game->exit[3] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/d4.xpm", &s, &s);
}

void initialise_struct_bonus(t_obj_b *game)
{
    int s;

    game->img_size = 50;
    game->candyw = 0;
    game->move = 0;
    game->enemy_dir = 1;
    game->flag = 1;
    s = game->img_size;
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->width, game->height,
            "SO LONG ** Take all Collect then exit from the door **");
    game->floor = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/back.xpm", &s, &s);
    img_play_exit_bonus(game);
    game->wall[0] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/wallBP.xpm", &s, &s);
    game->wall[1] = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/wall.xpm", &s, &s);
    game->candy = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/meatB.xpm", &s, &s);
    game->enemy = mlx_xpm_file_to_image(game->mlx, "bonus/XPM/playerri.xpm", &s, &s);
    game->frame = 0;
    game->framee = 0;
    if (!game->floor || !game->wall[0] || !game->wall[1] || !game->candy)
        ft_puterror_bonus(game, "Error: Failed to load an image");
}


void	free_game_bonus(t_obj_b *game)
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

void	exit_game_bonus(t_obj_b *game)
{
	free_game_bonus(game);
	exit(EXIT_SUCCESS);
}

t_obj_b	*ft_half_main_bonus(t_obj_b *game, char **av, int fd_map, int ac)
{
	if (ac != 2)
	{
		ft_printf("**the args are not 2.**");
		exit(1);
	}
	game = (t_obj_b *)malloc(sizeof(t_obj_b));
	if (!game)
		exit(1);
	fd_map = check_arg_map_bonus(av[1]);
	if (fd_map < 0)
		return (NULL);
	game = get_map_bonus(fd_map, game, av[1]);
	if (!game)
		return (free(game), NULL);
	check_map_bonus(game);
	game->map_copy = copy_map_bonus(game);
	if (!game->map_copy)
		return (free_game_bonus(game), NULL);
	flood_fill_bonus(game, game->player_x, game->player_y);
	check_map_copy_bonus(game->map_copy);
	return (game);
}
