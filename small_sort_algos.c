/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_algos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:06:26 by saylital          #+#    #+#             */
/*   Updated: 2024/10/06 14:36:45 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->value > (*a)->next->value && (*a)->next->value < (*a)->prev->value
		&& (*a)->value < (*a)->prev->value)
		sa(a, 1);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->prev->value
		&& (*a)->value > (*a)->prev->value)
		rra(a, 1);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->prev->value
		&& (*a)->value < (*a)->prev->value)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value < (*a)->prev->value
		&& (*a)->value > (*a)->prev->value)
		ra(a, 1);
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value > (*a)->prev->value
		&& (*a)->value > (*a)->prev->value)
	{
		ra(a, 1);
		sa(a, 1);
	}
}

void	sort_five(t_stack **a, t_stack **b, int count)
{
	int	min;
	int	max;

	if (count == 5)
		pb(a, b);
	pb(a, b);
	sort_three(a);
	min = (*a)->pos;
	max = (*a)->prev->pos;
	while (*b)
		move_to_a(a, b, &min, &max);
	sort_stack_to_order(a);
	return ;
}

void	move_to_a(t_stack **a, t_stack **b, int *min, int *max)
{
	if ((*b)->pos < *min)
	{
		while ((*a)->pos != *min)
			ra(a, 1);
		pa(a, b);
		*min = (*a)->pos;
	}
	else if ((*b)->pos > *max)
	{
		while ((*a)->prev->pos != *max)
			rra(a, 1);
		pa(a, b);
		ra(a, 1);
		*max = (*a)->prev->pos;
	}
	else
	{
		while (!((*b)->pos < (*a)->pos && (*b)->pos > (*a)->prev->pos))
			ra(a, 1);
		pa(a, b);
	}
}

void	sort_stack_to_order(t_stack **a)
{
	while ((*a)->pos != 0)
	{
		if ((*a)->pos > 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
}
