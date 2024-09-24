/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:21:25 by saylital          #+#    #+#             */
/*   Updated: 2024/09/24 18:54:43 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack **a, int print)
{
	if (*a == NULL)
		return ;
	if ((*a)->next == *a)
		return ;
	*a = (*a)->prev;
	if (print)
		ft_printf("%s\n", "rra");
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack **b, int print)
{
	if (*b == NULL)
		return ;
	if ((*b)->next == *b)
		return ;
	*b = (*b)->prev;
	if (print)
		ft_printf("%s\n", "rrb");
}

// rra and rrb at the same time.
void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("%s\n", "rrr");
}
