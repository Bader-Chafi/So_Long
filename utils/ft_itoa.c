/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:28:25 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/16 22:10:00 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../B/so_long_bonus.h"

static int	get_len(int nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		len;
	long	num;

	num = nbr;
	len = get_len(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (--len >= 0)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		if (len == 0 && str[0] == '-')
			break ;
	}
	return (str);
}
