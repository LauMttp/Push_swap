/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 02:56:47 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/06 23:41:50 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void     set_target_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current_node_a;
    t_node *current_node_b;
    t_node *target_node_a;
    int    closest_value;

    current_node_b = stack_b->head;
    while (current_node_b)
    {
        closest_value = MAX_INT;
        current_node_a = stack_a->head;
        while (current_node_a)
        {
            if (current_node_a->value > current_node_b->value 
                && current_node_a->value < closest_value)
            {
                closest_value = current_node_a->value;
                target_node_a = current_node_a;
           }
            current_node_a = current_node_a->next;
        }
        if (closest_value == MAX_INT)
            current_node_b->target = find_min(stack_a);
        else
            current_node_b->target = target_node_a;
        current_node_b = current_node_b->next;
    }
}

void     min_on_top(t_stack *stack)
{
    t_node *smaller_node;

    smaller_node = find_min(stack);
    while (stack->head != smaller_node)
    {
        if (smaller_node->above_median)
            rotate(stack, 0);
        else
            reverse_rotate(stack, 0);
    }
}