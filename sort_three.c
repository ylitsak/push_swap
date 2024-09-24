/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:06:26 by saylital          #+#    #+#             */
/*   Updated: 2024/09/24 18:05:54 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->next->value < (*a)->next->next->value
		&& (*a)->value < (*a)->next->next->value)
		sa(a, 1);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value
		&& (*a)->value > (*a)->next->next->value)
		rra(a, 1);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value
		&& (*a)->value < (*a)->next->next->value)
		{
			rra(a, 1);
			sa(a, 1);
		}
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value < (*a)->next->next->value
		&& (*a)->value > (*a)->next->next->value)
		ra(a, 1);
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value
		&& (*a)->value > (*a)->next->next->value)
		{
			ra(a, 1);
			sa(a, 1);
		}
}
