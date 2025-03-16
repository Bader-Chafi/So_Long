/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:43:55 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/16 04:44:27 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/so_long.h"
#include "../bonus/so_long_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		lens1;
	int		i;
	char	*dup;

	lens1 = ft_strlen(s1);
	i = 0;
	dup = (char *)malloc(lens1 + 1);
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char	*ft_strchr(const char *s, int c)
{
	char	char_find;

	char_find = (char)c;
	if (char_find == '\0')
		return ((char *)s);
	while (*s)
	{
		if (*s == char_find)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
