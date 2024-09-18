/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:17:29 by saylital          #+#    #+#             */
/*   Updated: 2024/09/18 17:20:22 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (*a && (*a)->next)
	{
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->prev = NULL;
		second->next = first;
		first->prev = second;
		*a = second;
		ft_putendl_fd("sa", 1);
	}
}
// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack **b)
{
}
// sa and sb at the same time
void	ss(t_stack **a, t_stack **b)
{
}
