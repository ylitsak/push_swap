/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:59:43 by saylital          #+#    #+#             */
/*   Updated: 2024/09/24 18:53:47 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(char *str)
{
	int		neg;
	long	num;

	neg = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (*str - '0') + num * 10;
		str++;
	}
	return (num * neg);
}

int	is_nodes_sorted(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	if (!a)
		return (-1);
	while (temp->next != a)
	{
		if (temp->value > temp->next->value)
		{
			return (-1);
		}
		temp = temp->next;
	}
	if (temp->value > temp->next->value)
		return (-1);
	return (0);
}

void	print_nodes(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	if (!a)
		return ;
	while (1)
	{
		ft_printf("(adress prev %p), (adress of value %p) - {%d}, (adress next: %p)\n", temp->prev, &temp->value, temp->value, temp->next);
		temp = temp->next;
		if (temp == a)
			break ;
	}
}
