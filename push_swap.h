/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:13:31 by saylital          #+#    #+#             */
/*   Updated: 2024/09/19 17:07:29 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//validate_input.c
int		validate_input(char **input);
//linklist_utils.c
t_stack	*init_nodes(int argc, char **input);
int		count_nodes(t_stack *a);
//error_handling.,c
void	free_all(char **free_data);
void	free_stack(t_stack *head);
void	error_and_free(int argc, char **input, char *msg);
//utility_funcs.c
long	ft_atoi_long(char *str);
int	is_stack_sorted(t_stack *a);
// swap_stacks.c
void	sa(t_stack **a);
void	sb(t_stack **b);
// push_stack.c
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
// rotate_stack.c
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
// rev_rotate_stack.c
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
// sort_three.c
void	sort_three(t_stack **a);

#endif