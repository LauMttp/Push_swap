/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:28:01 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/12 14:56:42 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	set_target_a(t_stack *a, t_stack *b)
{
	t_node	*node_a;
	t_node	*node_b;
	t_node	*target_node_b;
	int		closest_value;

	node_a = a->head;
	while (node_a)
	{
		closest_value = MIN_INT;
		node_b = b->head;
		while (node_b)
		{
			if (node_b->value < node_a->value && node_b->value > closest_value)
			{
				closest_value = node_b->value;
				target_node_b = node_b;
			}
			node_b = node_b->next;
		}
		if (closest_value == MIN_INT)
			node_a->target = find_max(b);
		else
			node_a->target = target_node_b;
		node_a = node_a->next;
	}
}

void	set_push_cost(t_stack *a, t_stack *b)
{
	t_node	*current_a;

	current_a = a->head;
	while (current_a)
	{
		current_a->push_cost = current_a->index;
		if (!current_a->above_median)
			current_a->push_cost = a->current_size - current_a->index;
		if (current_a->target->above_median)
			current_a->push_cost += current_a->target->index;
		else
			current_a->push_cost += b->current_size - current_a->target->index;
		current_a = current_a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_node	*cheapest_node;
	t_node	*current_node;

	if (!stack || !stack->head)
		return ;
	current_node = stack->head;
	cheapest_node = stack->head;
	while (cheapest_node->next)
	{
		cheapest_node->cheapest = 0;
		cheapest_node = cheapest_node->next;
	}
	cheapest_node->cheapest = 0;
	while (current_node)
	{
		if (current_node->push_cost < cheapest_node->push_cost)
			cheapest_node = current_node;
		current_node = current_node->next;
	}
	cheapest_node->cheapest = 1;
}

t_node	*get_cheapest(t_stack *stack)
{
	t_node	*cheapest_node;

	if (!stack || !stack->head)
		return (NULL);
	cheapest_node = stack->head;
	while (cheapest_node)
	{
		if (cheapest_node->cheapest)
			return (cheapest_node);
		cheapest_node = cheapest_node->next;
	}
	return (NULL);
}

void	move_a_to_b(t_stack *a, t_stack *b)
{
	t_node	*cheapest_node_a;

	cheapest_node_a = get_cheapest(a);
	if (cheapest_node_a->above_median && cheapest_node_a->target->above_median)
		rotate_both(a, b, cheapest_node_a);
	else if (!cheapest_node_a->above_median
		&& !cheapest_node_a->target->above_median)
		reverse_rotate_both(a, b, cheapest_node_a);
	move_node_to_top(a, cheapest_node_a);
	move_node_to_top(b, cheapest_node_a->target);
	push_to_first(b, a);
}
