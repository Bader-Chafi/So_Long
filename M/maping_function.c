/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:54:40 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/16 05:50:55 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_store(char *map, int i, char **s, t_obj *t)
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

t_obj	*get_map(int fd, t_obj *g, char *fds)
{
	char	*map;
	int		i;
	char	**s_map;

	(1) && (i = 0, map = get_next_line(fd));
	if (!map)
		ft_error("** the map is empty **");
	while (map)
		(1) && (free(map), i++, map = get_next_line(fd));
	s_map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!s_map)
		return (free(g), NULL);
	(1) && (close(fd), fd = open(fds, O_RDONLY), i = 0);
	if (fd < 0)
		return (free(s_map), free(g), NULL);
	map = get_next_line(fd);
	while (map)
	{
		s_map[i++] = map;
		map = get_next_line(fd);
	}
	(1) && (s_map[i] = NULL, g->map = s_map, g->len_line = i);
	return (close(fd), g);
}

void	ft_puterror(t_obj *this, char *s)
{
	int	i;

	i = 0;
	while (this->map[i])
		free(this->map[i++]);
	free(this->map);
	free(this);
	ft_printf("Error\n%s", s);
	exit(EXIT_FAILURE);
}

int	ft_strlenmap(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

void	check_rectongle_map(t_obj *this)
{
	int		i;
	int		j;
	char	**map;

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
