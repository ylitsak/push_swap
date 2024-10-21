/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:13:56 by saylital          #+#    #+#             */
/*   Updated: 2024/10/20 11:33:09 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	if ((*b)->next == *b)
		*b = NULL;
	else
	{
		*b = (*b)->next;
		(*b)->prev = temp->prev;
		(*b)->prev->next = *b;
	}
	if (*a == NULL)
	{
		temp->next = temp;
		temp->prev = temp;
		*a = temp;
	}
	else
	{
		temp->prev = (*a)->prev;
		temp->next = *a;
		(*a)->prev->next = temp;
		(*a)->prev = temp;
		*a = temp;
	}
	ft_printf("%s\n", "pa");
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	if ((*a)->next == *a)
		*a = NULL;
	else
	{
		*a = (*a)->next;
		(*a)->prev = temp->prev;
		(*a)->prev->next = *a;
	}
	if (*b == NULL)
	{
		temp->next = temp;
		temp->prev = temp;
		*b = temp;
	}
	else
	{
		temp->prev = (*b)->prev;
		temp->next = *b;
		(*b)->prev->next = temp;
		(*b)->prev = temp;
		*b = temp;
	}
	ft_printf("%s\n", "pb");
}
