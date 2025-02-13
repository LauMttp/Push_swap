/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:18:40 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/12 14:14:26 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Create stack
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
	if (!stack->head)
		stack->head = new_node;
	else
	{
		current_node = stack->head;
		while (current_node->next)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	refresh_stack(stack);
	return (0);
}

// Return stack size
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

// Free each node of the stack then free the stack
void	clear_stack(t_stack *stack)
{
	t_node	*current_node;
	t_node	*next_node;

	if (!stack)
		return ;
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
