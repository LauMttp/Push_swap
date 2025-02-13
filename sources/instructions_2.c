/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:21:34 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/12 14:04:30 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// pa & pb
int	push_to_first(t_stack *first_stack, t_stack *second_stack)
{
	t_node	*node;

	if (!first_stack || !second_stack || !second_stack->head)
		return (1);
	node = second_stack->head;
	if (node->next)
		second_stack->head = node->next;
	else
		second_stack->head = NULL;
	node->next = first_stack->head;
	first_stack->head = node;
	ft_printf("p%c\n", first_stack->name);
	refresh_stack(first_stack);
	refresh_stack(second_stack);
	return (0);
}

// ra & rb
int	rotate(t_stack *stack, int printed)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->head || !stack->head->next)
		return (1);
	first = stack->head;
	last = first->next;
	while (last->next)
		last = last->next;
	stack->head = first->next;
	first->next = NULL;
	last->next = first;
	if (!printed)
		ft_printf("r%c\n", stack->name);
	refresh_stack(stack);
	return (0);
}

// rr 
int	double_rotate(t_stack *stack_a, t_stack *stack_b)
{
	if (rotate(stack_a, 1) || rotate(stack_b, 1))
		return (1);
	ft_printf("rr\n");
	return (0);
}

// rra & rrb
int	reverse_rotate(t_stack *stack, int printed)
{
	t_node	*current_last;
	t_node	*new_last;

	if (!stack || !stack->head || !stack->head->next)
		return (1);
	current_last = stack->head;
	while (current_last->next)
		current_last = current_last->next;
	new_last = stack->head;
	while (new_last->index < (stack->current_size - 2))
		new_last = new_last->next;
	current_last->next = stack->head;
	stack->head = current_last;
	new_last->next = NULL;
	if (!printed)
		ft_printf("rr%c\n", stack->name);
	refresh_stack(stack);
	return (0);
}

// rrr
int	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	if (reverse_rotate(stack_a, 1) || reverse_rotate(stack_b, 1))
		return (1);
	ft_printf("rrr\n");
	return (0);
}
