/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:19:32 by saylital          #+#    #+#             */
/*   Updated: 2024/09/18 20:13:01 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*loop;

	if (*a == NULL)
		return ;
	if (*a && (*a)->next)
	{
		temp = *a;
		*a = (*a)->next;
		loop = *a;
		(*a)->prev = NULL;
		while (loop->next != NULL)
			loop = loop->next;
		loop->next = temp;
		temp->prev = loop;
		temp->next = NULL;
	}
	ft_printf("%s\n", "ra");
}
// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*loop;

	if (*b == NULL)
		return ;
	if (*b && (*b)->next)
	{
		temp = *b;
		*b = (*b)->next;
		loop = *b;
		(*b)->prev = NULL;
		while (loop->next != NULL)
			loop = loop->next;
		loop->next = temp;
		temp->prev = loop;
		temp->next = NULL;
	}
	ft_printf("%s\n", "rb");
}
// ra and rb at the same time.
void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
