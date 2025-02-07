/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:18:40 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/06 23:37:15 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// create stack
t_stack	*initialize_stack(char name)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = NULL;
	new_stack->name = name;
	new_stack->max_size = 0;
	new_stack->current_size = 0;
	return (new_stack);
}

// Create & add a node to the given stack
int	append_node( t_stack *stack, int value)
{
	t_node	*current_node;
	t_node	*new_node;

	if (!stack)
		return (1);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (1);
	new_node->value = value;
	new_node->cheapest = 0;
	new_node->next = NULL;
	//to delete
	new_node->previous = NULL;
	if (!stack->head)
		stack->head = new_node;
	else
	{
		current_node = stack->head;
		while (current_node->next)
			current_node = current_node->next;
		current_node->next = new_node;
		new_node->previous = current_node;
	}
	refresh_stack(stack);
	return (0);
}

// return stack size
size_t	get_stack_size(t_stack *stack)
{
	int		i;
	t_node	*current_node;

	i = 0;
	if (!stack || !stack->head)
		return (i);
	current_node = stack->head;
	i++;
	while (current_node->next)
	{
		i++;
		current_node = current_node->next;
	}
	return (i);
}

// display stack
void	stack_display(t_stack *stack)
{
	t_node	*current_node;

	if (!stack)
		return ;
	current_node = stack->head;
	ft_printf("Stack %c: address %p, max_size: %d, current_size: %d,\n\n", stack->name, &stack, stack->max_size, stack->current_size);
	while (current_node)
	{
		ft_printf("value:%d, address:%p, index: %d, above_median: %d\n", current_node->value, &current_node, current_node->index, current_node->above_median);
		current_node = current_node->next;
	}
	ft_printf("\n");
}

// clear stack
void	clear_stack(t_stack *stack)
{
	t_node	*current_node;
	t_node	*next_node;

	if (!stack)
		return ;
	//stack_display(stack);
	if (stack->head)
	{
		current_node = stack->head;
		while (current_node)
		{
			next_node = current_node->next;
			free(current_node);
			current_node = NULL;
			current_node = next_node;
		}
	}
	free(stack);
	stack = NULL;
}
