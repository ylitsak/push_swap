/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:33:44 by saylital          #+#    #+#             */
/*   Updated: 2024/10/15 14:59:23 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static	int find_highest_val(t_stack *a)
// {
// 	t_stack	*highest;
// 	int		max;

// 	highest = a;
// 	max = 0;
// 	while (1)
// 	{
// 		if (highest->value > a->value)
// 			max = highest->value;
// 		highest = highest->next;
// 		if (highest == a)
// 			break;
// 	}
// 	return (max);
// }

static	int count_bits(int high)
{
	int	count;

	count = 0;
	while (high > 0)
	{
		high = high >> 1;
		count++;
	}
	// maybe need to be count + 1 since we start at 0 pos, so i might skip bits?
	count += 1;
	return (count);
}

static	int find_highest_pos(t_stack *a)
{
	t_stack	*highest;
	int		max;

	highest = a;
	max = 0;
	while (1)
	{
		if (highest->pos > a->pos)
			max = highest->pos;
		highest = highest->next;
		if (highest == a)
			break;
	}
	return (max);
}

void	radix_sort(t_stack **a, t_stack **b, int count)
{
	int	high;
	int	bits;
	int	nodes;
	int	index;

	high = find_highest_pos(*a);
	bits = count_bits(high);
	index = 0;
	//ft_printf("highest pos -> %d bits -> %d", high, bits);
	while (bits)
	{
		// if (check_if_sorted(*a) == 0)
		// 	return ;
		nodes = count;
		while (nodes)
		{
			if (((*a)->pos >> index) & 1)
				ra(a, 1);
			else
				pb(a, b);
			nodes--;
		}
		while ((*b))
			pa(a, b);
		index++;
		bits--;
	}
}