/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:28:01 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/06 18:54:42 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void    set_target_a(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current_node_a;
    t_node *current_node_b;
    t_node *target_node_b;
    int     closest_value;

    current_node_a = stack_a->head;
    while (current_node_a)
    {
        closest_value = MIN_INT;
        current_node_b = stack_b->head;
        while (current_node_b)
        {
            if (current_node_b->value < current_node_a->value 
            && current_node_b->value > closest_value)
            {
                closest_value = current_node_b->value;
                target_node_b = current_node_b;
            }
            current_node_b = current_node_b->next;
        }
        if (closest_value == MIN_INT)
            current_node_a->target = find_max(stack_b);
        else
            current_node_a->target = target_node_b;
        current_node_a = current_node_a->next;
    }
}

void    set_push_cost(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current_node_a;

    current_node_a = stack_a->head;
    while (current_node_a)
    {
        current_node_a->push_cost = current_node_a->index;
        if (!current_node_a->above_median)
            current_node_a->push_cost = stack_a->current_size - current_node_a->index;
        if (current_node_a->target->above_median)
            current_node_a->push_cost += current_node_a->target->index;
        else
            current_node_a->push_cost += stack_b->current_size - current_node_a->target->index;
        current_node_a = current_node_a->next;
    }
}

void     set_cheapest(t_stack *stack)
{
    t_node *cheapest_node;
    t_node *current_node;

    if (!stack || !stack->head)
        return;
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

t_node     *get_cheapest(t_stack *stack)
{
    t_node *cheapest_node;

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

void     move_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
    t_node *cheapest_node_a;

    cheapest_node_a = get_cheapest(stack_a);
    if (cheapest_node_a->above_median && cheapest_node_a->target->above_median)
        rotate_both(stack_a, stack_b, cheapest_node_a);
    else if (!cheapest_node_a->above_median && !cheapest_node_a->target->above_median)
        reverse_rotate_both(stack_a, stack_b, cheapest_node_a);
    move_node_to_top(stack_a, cheapest_node_a);
    move_node_to_top(stack_b, cheapest_node_a->target);
    push_to_first(stack_b, stack_a);
}
