/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:32:42 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/12 14:23:47 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	is_whitespace(char a)
{
	if (a == '\t' || a == '\v' || a == '\n'
		|| a == '\r' || a == '\f' || a == 32)
		return (1);
	return (0);
}

/*
** ft_atol removes all kind of spaces and tabs
** It accepts only 1 sign (+ or -)
** It returns (1) if s contain a non digit character
** It returns (1) if the value is higher than INT_MAX or lower than INT_MIN
** It assigns the value to num and return 0 in case of success
*/
int	ft_atol(const char *s, long *num)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while (s[i] && is_whitespace(s[i]))
		i++;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
	{
		if (s[i] == '-')
			sign *= (-1);
		i++;
	}
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = (res * 10) + (s[i] - 48);
		else
			return (1);
		i++;
	}
	*num = res * sign;
	return (0);
}

void	set_it_free(void **it)
{
	if (it && *it)
	{
		free(*it);
		*it = NULL;
	}
}

void	set_tab_free(char **tab, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}
