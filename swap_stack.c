/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:17:29 by saylital          #+#    #+#             */
/*   Updated: 2024/09/24 18:51:36 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack **a, int print)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	if ((*a)->next == *a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	temp->next->prev = temp;
	temp->prev = *a;
	(*a)->prev = temp->prev;
	if (print)
		ft_printf("%s\n", "sa");
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack **b, int print)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	if ((*b)->next == *b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	temp->next->prev = temp;
	temp->prev = *b;
	(*b)->prev = temp->prev;
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
