/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:37:46 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/18 21:58:22 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error_bonus(char *s)
{
	ft_printf("Error\n%s", s);
	exit(1);
}

void	img_play_exit_bonus(t_obj_b *game)
{
	int	s;

	game->sonicl[0] = mlx_xpm_file_to_image(game->mlx, "B/XPM/pl1.xpm", &s, &s);
	game->sonicl[1] = mlx_xpm_file_to_image(game->mlx, "B/XPM/pl2.xpm", &s, &s);
	game->sonicl[2] = mlx_xpm_file_to_image(game->mlx, "B/XPM/pl3.xpm", &s, &s);
	game->sonicl[3] = mlx_xpm_file_to_image(game->mlx, "B/XPM/pl4.xpm", &s, &s);
	game->sonicl[4] = mlx_xpm_file_to_image(game->mlx, "B/XPM/pl5.xpm", &s, &s);
	game->sonicr[0] = mlx_xpm_file_to_image(game->mlx, "B/XPM/pr1.xpm", &s, &s);
	game->sonicr[1] = mlx_xpm_file_to_image(game->mlx, "B/XPM/pr2.xpm", &s, &s);
	game->sonicr[2] = mlx_xpm_file_to_image(game->mlx, "B/XPM/pr3.xpm", &s, &s);
	game->sonicr[3] = mlx_xpm_file_to_image(game->mlx, "B/XPM/pr4.xpm", &s, &s);
	game->sonicr[4] = mlx_xpm_file_to_image(game->mlx, "B/XPM/pr5.xpm", &s, &s);
	game->exit[0] = mlx_xpm_file_to_image(game->mlx, "B/XPM/d1.xpm", &s, &s);
	game->exit[1] = mlx_xpm_file_to_image(game->mlx, "B/XPM/d2.xpm", &s, &s);
	game->exit[2] = mlx_xpm_file_to_image(game->mlx, "B/XPM/d3.xpm", &s, &s);
	game->exit[3] = mlx_xpm_file_to_image(game->mlx, "B/XPM/d4.xpm", &s, &s);
	if (!game->sonicl[0] || !game->sonicl[1] || !game->sonicl[2]
		|| !game->sonicl[3] || !game->sonicl[4] || !game->sonicr[0]
		|| !game->sonicr[1] || !game->sonicr[2] || !game->sonicr[3]
		|| !game->sonicr[4] || !game->exit[0] || !game->exit[1]
		|| !game->exit[2] || !game->exit[3])
		ft_puterror_bonus(game, "Error Failed to load an image");
}

void	initialise_struct_bonus(t_obj_b *game)
{
	int	s;

	game->img_size = 50;
	game->candyw = 0;
	game->move = 0;
	game->enemy_dir = 1;
	game->flag = 1;
	s = game->img_size;
	game->mlx = mlx_init();
	img_play_exit_bonus(game);
	game->win = mlx_new_window(game->mlx, game->width, game->height,
			"SO LONG ** Take all Collect then exit from the door **");
	game->floor = mlx_xpm_file_to_image(game->mlx, "B/XPM/back.xpm", &s, &s);
	game->wall[0] = mlx_xpm_file_to_image(game->mlx,
			"B/XPM/wallB.xpm", &s, &s);
	game->wall[1] = mlx_xpm_file_to_image(game->mlx, "B/XPM/wall.xpm", &s, &s);
	game->candy = mlx_xpm_file_to_image(game->mlx,
			"B/XPM/meatB.xpm", &s, &s);
	game->enemy = mlx_xpm_file_to_image(game->mlx,
			"B/XPM/playerri.xpm", &s, &s);
	if (!game->floor || !game->wall[0] || !game->wall[1] || !game->candy)
		ft_puterror_bonus(game, "Error: Failed to load an image");
	game->framee = 0;
	game->frame = 0;
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
		return (free(game), NULL);
	game = get_map_bonus(fd_map, game, av[1]);
	if (!game)
		return (NULL);
	check_map_bonus(game);
	game->map_copy = copy_map_bonus(game);
	if (!game->map_copy)
		return (free_game_bonus(game), NULL);
	flood_fill_bonus(game, game->player_x, game->player_y);
	check_map_copy_bonus(game->map_copy);
	game->map[game->exit_x][game->exit_y] = '0';
	return (game);
}
