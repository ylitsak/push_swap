/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:24:56 by saylital          #+#    #+#             */
/*   Updated: 2024/10/24 15:49:48 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (*a == NULL || (*a)->next == *a)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;
	*a = second;
	if (print)
		ft_printf("%s\n", "sa");
}

void	ra(t_stack **a, int print)
{
	if (*a == NULL)
		return ;
	if ((*a)->next == *a)
		return ;
	*a = (*a)->next;
	if (print)
		ft_printf("%s\n", "ra");
}

void	rra(t_stack **a, int print)
{
	if (*a == NULL)
		return ;
	if ((*a)->next == *a)
		return ;
	*a = (*a)->prev;
	if (print)
		ft_printf("%s\n", "rra");
}
