/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_algos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:06:26 by saylital          #+#    #+#             */
/*   Updated: 2024/10/21 15:02:28 by saylital         ###   ########.fr       */
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

static int	count_index(t_stack *a, int min)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = a;
	while (temp->next != a)
	{
		if (temp->pos == min)
			break ;
		count++;
		temp = temp->next;
	}
	return (count);
}

void	sort_small(t_stack **a, t_stack **b, int count)
{
	int	min;
	int	index;

	min = 0;
	while (count != 3)
	{
		if ((*a)->pos != min)
		{
			index = count_index(*a, min);
			while ((*a)->pos != min)
			{
				if (index < count / 2)
					ra(a, 1);
				else
					rra(a, 1);
			}
		}
		min++;
		pb(a, b);
		count--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
