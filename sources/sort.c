/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:32:59 by lmouttap          #+#    #+#             */
/*   Updated: 2025/01/31 23:27:24 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// is_stack_sorted checks if the given stack is sorted
// it returns 0 if it's true
// it returns 1 in case of error
// it returns 2 if it's false
int	is_stack_sorted(t_stack *stack)
{
	t_node	*current_node;

	if (!stack || !stack->head)
		return (1);
	current_node = stack->head;
	while (current_node->next != NULL)
	{
		if (current_node->value > current_node->next->value)
			return (2);
		current_node = current_node->next;
	}
	return (0);
}

t_node	*find_min(t_stack *stack)
{
	t_node	*current_node;
	t_node	*min_node;

	if (!stack || !stack->head)
		return (NULL);
	current_node = stack->head;
	min_node = stack->head;
	while (current_node)
	{
		if (current_node->value < min_node->value)
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}

t_node	*find_max(t_stack *stack)
{
	t_node	*current_node;
	t_node	*max_node;

	if (!stack || !stack->head)
		return (NULL);
	current_node = stack->head;
	max_node = stack->head;
	while (current_node)
	{
		if (current_node->value > max_node->value)
			max_node = current_node;
		current_node = current_node->next;
	}
	return (max_node);
}

void	sort_three(t_stack *stack)
{
	t_node	*max_node;

	if (!stack || !stack->head)
		return ;
	max_node = find_max(stack);
	if (max_node == stack->head)
		rotate(stack, 0);
	else if (max_node == stack->head->next)
		reverse_rotate(stack, 0);
	if (stack->head->value > stack->head->next->value)
		swap(stack, 0);
	return ;
}

void	sort_stack(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = initialize_stack('b');
	if (!stack_b)
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (stack_a->current_size > 3 && is_stack_sorted(stack_a) == 2)
		push_to_first(stack_b, stack_a);
	if (stack_a->current_size > 3 && is_stack_sorted(stack_a) == 2)
		push_to_first(stack_b, stack_a);
	while (stack_a->current_size > 3 && is_stack_sorted(stack_a) == 2)
	{
		find_next_a_move(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->head)
	{
		set_target_b(stack_a, stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	min_on_top(stack_a);
	clear_stack(stack_b);
}
