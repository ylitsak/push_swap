/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:34:23 by saylital          #+#    #+#             */
/*   Updated: 2024/09/25 19:07:45 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_nodes(t_stack **a, t_stack **b)
{
	int	count;

	count = count_nodes(*a);
	ft_printf("%d\n", count);
	// pb(a, b);
	// pb(a, b);
	// pa(a, b);
	print_nodes(*a, 'a');
	print_nodes(*b, 'b');
	if (check_if_sorted(*a) == 0)
	{
		ft_printf("LIST IS SORTED\n");
		return ;
	}
	if (count == 2)
	{
		sa(a, 1);
		return ;
	}
	// if (count == 3)
	// 	sort_three(a);
	// (void)b;
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
	if (validate_input(input) == 1 || argc == 1
		|| *input == NULL || input == NULL)
		error_and_free(argc, input, "Error");
	a = init_nodes(argc, input);
	b = NULL;
	if (argc == 2)
		free_all(input);
	sort_nodes(&a, &b);
	print_nodes(a, 'a');
	print_nodes(b, 'b');
	free_stack(a);
	return (0);
}
