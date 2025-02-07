/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:26:50 by lmouttap          #+#    #+#             */
/*   Updated: 2024/11/29 14:20:04 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		print_next_arg(char param, va_list argptr);
int		ft_putstr(char *str);
int		ft_putnbr(long long int nbr);
int		ft_putnbr_hexa(long long int nbr, char a);
int		ft_putptr(unsigned long long pointer, int isFirst);

#endif
