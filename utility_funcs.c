/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:59:43 by saylital          #+#    #+#             */
/*   Updated: 2024/10/21 10:47:36 by saylital         ###   ########.fr       */
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

int	*make_array(int count, t_stack *a)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(count * sizeof(int));
	if (!arr)
	{
		free_stack(a);
		exit(EXIT_FAILURE);
	}
	while (i < count)
	{
		arr[i] = a->value;
		i++;
		a = a->next;
	}
	return (arr);
}

void	sort_array(int *arr, int count)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	add_node_position(t_stack *a, int *arr, int count)
{
	t_stack	*temp;
	int		i;

	temp = a;
	while (1)
	{
		i = 0;
		while (i < count)
		{
			if (arr[i] == temp->value)
			{
				temp->pos = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
		if (temp == a)
			break ;
	}
}
