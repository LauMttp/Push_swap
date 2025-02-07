/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:37:22 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/06 22:48:03 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	check_double(t_stack *stack)
{
	t_node	*current_node;
	t_node	*compared_node;

	current_node = stack->head;
	while (current_node->next)
	{
		compared_node = current_node->next;
		while (compared_node->next)
		{
			if (current_node->value == compared_node->value)
				return (1);
			compared_node = compared_node->next;
		}
		if (current_node->value == compared_node->value)
			return (1);
		current_node = current_node->next;
	}
	return (0);
}


// appeler atoi a chaque nouvel element du tableau
// creer un nouvel element de la liste si le retour d'atoi est valid
int	parse_arguments(t_stack *stack, int size, char **args)
{
	int		i;
	long	j;

	i = 1;
	j = 0;
	while (i < size)
	{
		if (ft_atol(args[i], &j))
			return (1);
		if (j > MAX_INT || j < MIN_INT)
            return (1);
		if (append_node(stack, j))
            return (1);
		i++;
	}
	return (0);
}

int	parse_in_stack(t_stack *stack, int ac, char **av)
{
	int	i;
	int	count;
	char	**args;

	i = 0;
	count = 0;
	args = NULL;
	if (ac == 2)
	{
		args = ft_split(av[1], &count);
		i = parse_arguments(stack, count, args);
		set_tab_free(args, count);
	}
	else
		i = parse_arguments(stack, ac, av);
	stack->max_size = stack->current_size;
	return (i);
}

// valgrind --leak-check=full ./push_swap "44 55 22 66 33 5 88 4 556"
int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac == 1)
		return (0);
	stack_a = initialize_stack('a');
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	if (parse_in_stack(stack_a, ac, av) || check_double(stack_a))
	{
		clear_stack(stack_a);
		return (write(2, "Error\n", 6), 1);
	}
	stack_display(stack_a);
	if (is_stack_sorted(stack_a) == 2)
	{
		if (stack_a->max_size == 2)
        	swap(stack_a, 0);
    	else if (stack_a->max_size == 3)
			sort_three(stack_a);
    	else
			sort_stack(stack_a);
	}
	clear_stack(stack_a);
	return (0);
}
