/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:19:32 by saylital          #+#    #+#             */
/*   Updated: 2024/09/24 18:55:07 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack **a, int print)
{
	if (*a == NULL)
		return ;
	if ((*a)->next == *a)
		return ;
	*a = (*a)->next;
	if (print)
		ft_printf("%s\n", "ra");
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack **b, int print)
{
	if (*b == NULL)
		return ;
	if ((*b)->next == *b)
		return ;
	*b = (*b)->next;
	if (print)
		ft_printf("%s\n", "rb");
}

// ra and rb at the same time.
void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("%s\n", "rr");
}
