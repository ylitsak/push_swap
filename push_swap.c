/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:34:23 by saylital          #+#    #+#             */
/*   Updated: 2024/09/18 20:32:24 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_nodes(t_stack **a, t_stack **b)
{
	int	count;

	count = count_nodes(*a);
	// ft_printf("%d\n", count);
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
	// sort_nodes(&a, &b);
	count_nodes(a);
	// ra(&a);
	// ft_printf("node b\n");
	// count_nodes(b);
	ft_printf("before push\n");
	// pb(&a, &b);
	// pb(&a, &b);
	// pa(&a, &b);
	// rb(&b);
	rra(&a);
	ft_printf("after push\n");
	count_nodes(a);
	// ft_printf("node b\n");
	// count_nodes(b);
	free_stack(a);
	return (0);
}
