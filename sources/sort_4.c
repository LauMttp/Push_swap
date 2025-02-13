/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 02:56:47 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/12 15:02:59 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	set_target_b(t_stack *a, t_stack *b)
{
	t_node	*node_a;
	t_node	*node_b;
	t_node	*target_node_a;
	int		closest_value;

	node_b = b->head;
	while (node_b)
	{
		closest_value = MAX_INT;
		node_a = a->head;
		while (node_a)
		{
			if (node_a->value > node_b->value && node_a->value < closest_value)
			{
				closest_value = node_a->value;
				target_node_a = node_a;
			}
			node_a = node_a->next;
		}
		if (closest_value == MAX_INT)
			node_b->target = find_min(a);
		else
			node_b->target = target_node_a;
		node_b = node_b->next;
	}
}

void	min_on_top(t_stack *stack)
{
	t_node	*smaller_node;

	smaller_node = find_min(stack);
	while (stack->head != smaller_node)
	{
		if (smaller_node->above_median)
			rotate(stack, 0);
		else
			reverse_rotate(stack, 0);
	}
}
