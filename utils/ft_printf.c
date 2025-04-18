/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchafi <bchafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:09:46 by bchafi            #+#    #+#             */
/*   Updated: 2025/03/16 06:18:39 by bchafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../M/so_long.h"
#include "../B/so_long_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static int	ft_unsigned(unsigned int num)
{
	int	count;

	count = 0;
	if (num > 9)
		count += ft_unsigned(num / 10);
	ft_putchr((num % 10) + '0');
	return (count + 1);
}

static int	ft_ayero(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchr(va_arg(args, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*format == 'x' || *format == 'X')
		count += ft_hexadecimal(va_arg(args, unsigned int), *format);
	else if (*format == 'u')
		count += ft_unsigned(va_arg(args, unsigned int));
	else if (*format == 'p')
	{
		count += ft_putstr("0x");
		count += ft_hexa_address(va_arg(args, unsigned long));
	}
	else if (*format == '%')
		count += ft_putchr(*format);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	if (write(1, 0, 0) < 0)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break ;
			count += ft_ayero(format, args);
		}
		else
			count += ft_putchr(*format);
		format++;
	}
	va_end(args);
	return (count);
}
