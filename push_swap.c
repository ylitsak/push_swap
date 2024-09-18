/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:34:23 by saylital          #+#    #+#             */
/*   Updated: 2024/09/18 21:04:42 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_nodes(t_stack **a, t_stack **b)
{
	int	count;

	count = count_nodes(*a);
	if (is_stack_sorted(*a) == 0)
		return ;
	if (count == 2)
	{
		sa(a);
		return ;
	}
	if (count == 3)
		sort_three(a);
	(void)b;
}

int	main(int argc, char *argv[])
{
	char	**input;
	t_stack	*a;
	t_stack	*b;

	input = NULL;
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else if (argc > 2)
		input = &argv[1];
	if (validate_input(input) == -1 || argc == 1
		|| *input == NULL || input == NULL)
		error_and_free(argc, input, "Error");
	a = init_nodes(argc, input);
	b = NULL;
	if (argc == 2)
		free_all(input);
	sort_nodes(&a, &b);
	count_nodes(a);
	free_stack(a);
	return (0);
}
