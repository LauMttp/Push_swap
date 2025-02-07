/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:05:29 by lmouttap          #+#    #+#             */
/*   Updated: 2024/11/28 18:05:41 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putptr(unsigned long long pointer, int isFirst)
{
	char		*base;
	int			i;

	i = 0;
	base = "0123456789abcdef";
	if (pointer == 0)
		return (write(1, "(nil)", 5));
	if (isFirst)
		i += (write(1, "0x", 2));
	if (pointer >= 16)
		i += ft_putptr((pointer / 16), 0);
	i += (write(1, &base[pointer % 16], 1));
	return (i);
}
