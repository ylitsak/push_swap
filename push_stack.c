/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:13:56 by saylital          #+#    #+#             */
/*   Updated: 2024/09/25 11:49:56 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (*b == NULL)
		return ;
	temp = *b;
	
	ft_printf("%s\n", "pa");
	
}
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (*a == NULL)
		return ;
	temp = *a;
	if (*a && (*a)->next)
	{
		(*a) = (*a)->next;
		(*a)->prev = NULL;
	}
	else
		(*a) = NULL;
	if (*b == NULL)
	{
		(*b) = temp;
		(*b)->next = NULL;
	}
	else
	{
		(*b)->prev = temp;
		temp->next = *b;
		*b = temp;
	}
	ft_printf("%s\n", "pb");
}
