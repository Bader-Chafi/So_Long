/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:00:23 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/18 21:42:01 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>

int	check_arg_map_bonus(char *av)
{
	int	len;
	int	fd;

	fd = open(av, O_RDONLY, 666);
	if (fd < 0)
	{
		close(fd);
		ft_error_bonus("**the file is not exist.**");
	}
	len = ft_strlen(av);
	if (len < 4)
		return (-1);
	if (ft_strcmp(av + len - 4, ".ber"))
	{
		close(fd);
		ft_error_bonus("**the file is not final with .ber.**");
	}
	return (fd);
}

char	**copy_map_bonus(t_obj_b *game)
{
	int		i;
	char	**map_copy;

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

void	flood_fill_bonus(t_obj_b *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->len_line || y >= game->size_line)
		return ;
	if (game->map_copy[x][y] == '1' || game->map_copy[x][y] == 'V'
		|| game->map_copy[x][y] == 'M')
		return ;
	game->map_copy[x][y] = 'V';
	flood_fill_bonus(game, x + 1, y);
	flood_fill_bonus(game, x - 1, y);
	flood_fill_bonus(game, x, y + 1);
	flood_fill_bonus(game, x, y - 1);
	if (game->len_line < 3)
	{
		exit(1);
		return ;
	}
}

void	exit_game_bonus(t_obj_b *game)
{
	free_game_bonus(game);
	exit(EXIT_SUCCESS);
}

int	animate_exit_bonus(t_obj_b *game)
{
	static int	frame_counter;
	static int	frame_index;

	if (frame_index >= 4)
		return (0);
	if (frame_counter++ > 10)
	{
		game->framee = frame_index;
		frame_index++;
		frame_counter = 0;
		draw_map_bonus(game->map, game);
	}
	return (0);
}
