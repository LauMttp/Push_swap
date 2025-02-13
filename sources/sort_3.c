/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:58:59 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/12 14:51:34 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	find_next_a_move(t_stack *a, t_stack *b)
{
	set_target_a(a, b);
	set_push_cost(a, b);
	set_cheapest(a);
}

void	rotate_both(t_stack *a, t_stack *b, t_node *cheapest)
{
	while (cheapest != a->head
		&& cheapest->target != b->head)
	{
		double_rotate(a, b);
	}
}

void	reverse_rotate_both(t_stack *a, t_stack *b, t_node *cheapest)
{
	while (cheapest != a->head
		&& cheapest->target != b->head)
	{
		double_reverse_rotate(a, b);
	}
}

void	move_node_to_top(t_stack *stack, t_node *cheapest)
{
	while (stack->head != cheapest)
	{
		if (cheapest->above_median)
			rotate(stack, 0);
		else
			reverse_rotate(stack, 0);
	}
}

void	move_b_to_a(t_stack *a, t_stack *b)
{
	move_node_to_top(a, b->head->target);
	push_to_first(a, b);
}
