/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:15:40 by lmouttap          #+#    #+#             */
/*   Updated: 2024/11/27 18:37:52 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_hexa(long long int nbr, char a)
{
	char		*base;
	int			i;

	i = 0;
	if (a == 'x')
		base = "0123456789abcdef";
	else if (a == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 0)
		return (i);
	if (nbr >= 16)
		i += ft_putnbr_hexa((nbr / 16), a);
	i += (write(1, &base[nbr % 16], 1));
	return (i);
}
