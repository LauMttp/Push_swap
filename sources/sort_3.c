/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:58:59 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/06 23:39:45 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void     find_next_a_move(t_stack *stack_a, t_stack *stack_b)
{
    set_target_a(stack_a, stack_b);
    set_push_cost(stack_a, stack_b);
    set_cheapest(stack_a);
}

void     rotate_both(t_stack *stack_a, t_stack *stack_b, t_node *cheapest_node)
{    
    while (cheapest_node != stack_a->head && cheapest_node->target != stack_b->head)
    {
        double_rotate(stack_a, stack_b);
    }
}

void     reverse_rotate_both(t_stack *stack_a, t_stack *stack_b, t_node *cheapest_node)
{    
    while (cheapest_node != stack_a->head && cheapest_node->target != stack_b->head)
    {
        double_reverse_rotate(stack_a, stack_b);
    }
}

// Boucle infinie car le cheapest node a ete sorti de la stack A... donc il ne remonte jamais en index 1 
void     move_node_to_top(t_stack *stack, t_node *cheapest_node)
{    
    //stack_display(stack);
    while (stack->head != cheapest_node)
    {
        if (cheapest_node->above_median)
            rotate(stack, 0);
        else
            reverse_rotate(stack, 0);
        //stack_display(stack);
        ft_printf("debug:: head_value: %d head_index: %d \ncheapest_node_value:%d cheapest_node_index: %d cheapest_node_above_median: %d\n\n", stack->head->value, stack->head->index, cheapest_node->value, cheapest_node->index, cheapest_node->above_median);
    }
}

void     move_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
    move_node_to_top(stack_a, stack_b->head->target);
    push_to_first(stack_a, stack_b);
}