/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:13:31 by saylital          #+#    #+#             */
/*   Updated: 2024/10/15 14:59:10 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//validate_input.c
int		validate_input(char **input);
//linklist_utils.c
t_stack	*init_nodes(int argc, char **input);
int		check_if_sorted(t_stack *a);
int		count_nodes(t_stack *a);
//error_handling.,c
void	free_all(char **free_data);
void	free_stack(t_stack *head);
void	error_and_free(int argc, char **input, char *msg);
//utility_funcs.c
long	ft_atoi_long(char *str);
void	print_nodes(t_stack *a, char c);
int		*make_array(int count, t_stack *a);
void	sort_array(int *arr, int count);
int		find_lowest_pos(t_stack *a);
void	add_node_position(t_stack *a, int *arr, int count);
// swap_stacks.c
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
// push_stack.c
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
// rotate_stack.c
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b);
// rev_rotate_stack.c
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b);
// small_sort_algos.c
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b, int count);
void	move_to_a(t_stack **a, t_stack **b, int *min, int *max);
void	sort_stack_to_order(t_stack **a);
// radix_sort.c
void	radix_sort(t_stack **a, t_stack **b, int count);

#endif