/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:13:56 by saylital          #+#    #+#             */
/*   Updated: 2024/10/24 15:34:37 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	set_head(t_stack **temp, t_stack **stack)
{
	(*temp)->next = *temp;
	(*temp)->prev = *temp;
	*stack = *temp;
}

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
		set_head(&temp, a);
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
		set_head(&temp, b);
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
