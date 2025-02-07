/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:15:40 by lmouttap          #+#    #+#             */
/*   Updated: 2024/11/15 17:36:18 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr(long long int nbr)
{
	int		i;
	char	a;

	i = 0;
	if (nbr < 0)
	{
		i += (write(1, "-", 1));
		nbr *= (-1);
	}
	if (nbr >= 10)
		i += ft_putnbr((nbr / 10));
	a = (nbr % 10) + 48;
	i += (write(1, &a, 1));
	return (i);
}
