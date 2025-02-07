/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:05:53 by lmouttap          #+#    #+#             */
/*   Updated: 2025/01/31 22:54:57 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	count_words(char *str)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_whitespace(str[i]) && (!i || is_whitespace(str[i - 1])))
			count++;
		i++;
	}
	return (count);
}

int	guide_malloc_tab(char **tab, int index, int size)
{
	int	i;

	i = 1;
	tab[index] = (char *)malloc(sizeof(char) * (size + 1));
	if (tab[index] == NULL)
	{
		while (i < index)
		{
			free(tab[i++]);
			tab[i] = NULL;
		}
		free(tab);
		return (1);
	}
	return (0);
}

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (i);
}

int	store_words(char **tab, char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	while (str[i])
	{
		len = 0;
		while (str[i] && is_whitespace(str[i]))
			i++;
		while (str[i] && !is_whitespace(str[i]))
		{
			len++;
			i++;
		}
		if (len)
		{
			if (guide_malloc_tab(tab, j, len))
				return (1);
			ft_strlcpy(tab[j], &str[i - len], len);
			j++;
		}
	}
	return (0);
}

char	**ft_split(char *str, int *count)
{
	char	**tab;

	*count = count_words(str) + 1;
	if (!count)
		return (0);
	tab = (char **)malloc(sizeof(char *) * *count);
	if (tab == NULL)
		return (0);
	// tab[0] = (char *)malloc(sizeof(char));
	// // if (tab == NULL)
	// // {
	// //     free(tab);
	// //     return (0);
	// // }
	// // tab[0][0] = 0;
	if (store_words(tab, str))
		return (0);
	return (tab);
}
