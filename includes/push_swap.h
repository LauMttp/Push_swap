/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouttap <lmouttap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:38:51 by lmouttap          #+#    #+#             */
/*   Updated: 2025/02/12 14:01:14 by lmouttap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// -------------------libraries-----------------

# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/includes/ft_printf.h"

// --------------- Type definitions ------------
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_node {
	struct s_node		*target;
	struct s_node		*next;
	long				push_cost;
	long				cheapest;
	int					value;
	int					index;
	int					above_median;
}	t_node;

typedef struct s_stack {
	t_node	*head;
	char	name;
	int		current_size;
	int		max_size;
}	t_stack;

// -----------------Functions declarations ----------------
// ft_split.c ???? ----------------------------------------
char	**ft_split(char *str, int *count);
int		count_words(char *str);
int		guide_malloc_tab(char **tab, int index, int size);
int		ft_strlcpy(char *dest, char *src, int size);
int		store_words(char **tab, char *str);

// instructions_2.c ????????? --------------------------------------
int		push_to_first(t_stack *first_stack, t_stack *second_stack);
int		rotate(t_stack *stack, int printed);
int		double_rotate(t_stack *stack_a, t_stack *stack_b);
int		reverse_rotate(t_stack *stack, int printed);
int		double_reverse_rotate(t_stack *stack_a, t_stack *stack_b);

// instructions.c ????????? --------------------------------------
int		refresh_stack(t_stack *stack);
int		swap(t_stack *stack, int printed);
int		double_swap(t_stack *stack_a, t_stack *stack_b);

// push_swap.c ????????? --------------------------------------
int		check_double(t_stack *stack);
int		parse_arguments(t_stack *stack, int size, char **args);
int		parse_in_stack(t_stack *stack, int ac, char **av);
int		main(int ac, char **av);

// sort.c ???? ----------------------------------------
t_node	*find_min(t_stack *stack);
t_node	*find_max(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_stack(t_stack *stack_a);
int		is_stack_sorted(t_stack *stack);

// sort_2.c ???? ----------------------------------------
t_node	*get_cheapest(t_stack *stack);
void	set_target_a(t_stack *stack_a, t_stack *stack_b);
void	set_push_cost(t_stack *stack_a, t_stack *stack_b);
void	set_cheapest(t_stack *stack);
void	move_a_to_b(t_stack *stack_a, t_stack *stack_b);

// sort_3.c ???? ----------------------------------------
void	find_next_a_move(t_stack *stack_a, t_stack *stack_b);
void	rotate_both(t_stack *stack_a, t_stack *stack_b, t_node *cheapest_node);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b,
			t_node *cheapest_node);
void	move_node_to_top(t_stack *stack, t_node *cheapest_node);
void	move_b_to_a(t_stack *stack_a, t_stack *stack_b);

// sort_4.c ???? ----------------------------------------
void	set_target_b(t_stack *stack_a, t_stack *stack_b);
void	min_on_top(t_stack *stack);

// stack.c ????????? --------------------------------------
t_stack	*initialize_stack(char name);
size_t	get_stack_size(t_stack *stack);
void	stack_display(t_stack *stack);
void	clear_stack(t_stack *stack);
int		append_node( t_stack *stack, int value);

// utils.c ????????? --------------------------------------
void	set_it_free(void **it);
void	set_tab_free(char **tab, int size);
int		ft_atol(const char *s, long *num);
int		is_whitespace(char a);
// -----------------------------------------------

#endif
