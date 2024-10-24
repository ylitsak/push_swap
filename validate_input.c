/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:09:00 by saylital          #+#    #+#             */
/*   Updated: 2024/10/24 12:41:42 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_if_duplicate(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (ft_atoi(input[i]) == ft_atoi(input[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_overflow(char **input)
{
	long	num;
	int		i;

	i = 0;
	while (input[i])
	{
		num = ft_atoi_long(input[i]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

static int	input_is_numbers(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		if (input[i][j] == '+' || input[i][j] == '-')
			j++;
		while (input[i][j])
		{
			if (input[i][j] < '0' || input[i][j] > '9')
				return (1);
			j++;
		}
		if (j == 0 || (j == 1 && (input[i][0] == '+' || input[i][0] == '-')))
			return (1);
		i++;
	}
	return (0);
}

int	validate_input(char **input)
{
	if (input_is_numbers(input) == 1)
		return (1);
	if (check_overflow(input) == 1)
		return (1);
	if (check_if_duplicate(input) == 1)
		return (1);
	return (0);
}
