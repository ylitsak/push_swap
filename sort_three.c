/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:06:26 by saylital          #+#    #+#             */
/*   Updated: 2024/09/25 20:14:23 by saylital         ###   ########.fr       */
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
