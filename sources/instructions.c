/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:43:16 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/12 14:07:14 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	refresh_stack(t_stack *stack)
{
	int		i;
	t_node	*node;

	i = 0;
	if (!stack || !stack->head)
		return (1);
	stack->current_size = get_stack_size(stack);
	node = stack->head;
	while (node)
	{
		node->index = i;
		if (node->index < stack->current_size / 2)
			node->above_median = 1;
		else
			node->above_median = 0;
		node = node->next;
		i++;
	}
	return (0);
}

// sa & sb
int	swap(t_stack *stack, int printed)
{
	t_node	*a;
	t_node	*b;

	if (!stack || !stack->head || !stack->head->next)
		return (1);
	a = stack->head;
	b = a->next;
	stack->head = b;
	if (b->next)
		a->next = b->next;
	else
		a->next = NULL;
	b->next = a;
	if (!printed)
		ft_printf("s%c\n", stack->name);
	refresh_stack(stack);
	return (0);
}

// ss
int	double_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (swap(stack_a, 1) || swap(stack_b, 1))
		return (1);
	ft_printf("ss\n");
	return (0);
}
