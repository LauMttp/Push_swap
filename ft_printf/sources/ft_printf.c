/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:50:42 by lmouttap          #+#    #+#             */
/*   Updated: 2024/11/27 18:42:28 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_next_arg(char param, va_list argptr)
{
	char	c;

	if (param == 'c')
	{
		c = va_arg(argptr, int);
		return (write(1, &c, 1));
	}
	else if (param == 's')
		return (ft_putstr(va_arg(argptr, char *)));
	else if (param == 'p')
		return (ft_putptr(va_arg(argptr, unsigned long long), 1));
	else if (param == 'd' || param == 'i')
		return (ft_putnbr(va_arg(argptr, int)));
	else if (param == 'x' || param == 'X')
		return (ft_putnbr_hexa(va_arg(argptr, unsigned int), param));
	else if (param == 'u')
		return (ft_putnbr(va_arg(argptr, unsigned int)));
	else if (param == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;
	int		print_count;

	if (!str)
		return (-1);
	i = 0;
	print_count = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			print_count += print_next_arg(str[++i], argptr);
			i++;
		}
		else
		{
			write(1, &str[i++], 1);
			print_count++;
		}
	}
	va_end(argptr);
	return (print_count);
}
