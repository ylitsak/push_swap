/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:17:29 by saylital          #+#    #+#             */
/*   Updated: 2024/10/06 14:04:46 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (*a == NULL || (*a)->next == *a)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;
	*a = second;
	if (print)
		ft_printf("%s\n", "sa");
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (*b == NULL || (*b)->next == *b)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;
	*b = second;
	if (print)
		ft_printf("%s\n", "sb");
}

// sa and sb at the same time
void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("%s\n", "ss");
}
