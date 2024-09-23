/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:21:25 by saylital          #+#    #+#             */
/*   Updated: 2024/09/23 13:21:16 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack **a)
{
	t_stack	*loop;

	if (*a == NULL)
		return ;
	if (*a && (*a)->next)
	{
		loop = *a;
		while (loop->next != NULL)
		{
			loop = loop->next;
		}
		loop->prev->next = NULL;
		loop->prev = NULL;
		loop->next = *a;
		(*a)->prev = loop;
		*a = loop;
	}
	ft_printf("%s\n", "rra");
}
// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack **b)
{
	t_stack	*loop;

	if (*b == NULL)
		return ;
	if (*b && (*b)->next)
	{
		loop = *b;
		while (loop->next != NULL)
		{
			loop = loop->next;
		}
		loop->prev->next = NULL;
		loop->prev = NULL;
		loop->next = *b;
		(*b)->prev = loop;
		*b = loop;
	}
	ft_printf("%s\n", "rrb");
}
// rra and rrb at the same time.
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
