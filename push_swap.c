/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:34:23 by saylital          #+#    #+#             */
/*   Updated: 2024/10/18 16:30:28 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_nodes(t_stack **a, t_stack **b)
{
	int count;
	int *arr;

	count = count_nodes(*a);
	if (check_if_sorted(*a) == 0)
		return;
	if (count == 2)
	{
		sa(a, 1);
		return;
	}
	if (count == 3)
	{
		sort_three(a);
		return;
	}
	arr = make_array(count, *a);
	sort_array(arr, count);
	add_node_position(*a, arr, count);
	// t_stack *temp = *a;
	// while (1)
	// {
	// 	ft_printf("a->value=%d ", (*a)->value);
	// 	ft_printf("a->pos=%d ", (*a)->pos);
	// 	ft_printf("a->index=%d\n", (*a)->index);
	// 	*a = (*a)->next;
	// 	if (temp == *a)
	// 		break;
	// }
	free(arr);
	if (count <= 5)
	{
		sort_five(a, b, count);
		return;
	}
	else
	{
		radix_sort(a, b, count);
		return ;
	}
}

int main(int argc, char *argv[])
{
	char **input;
	t_stack *a;
	t_stack *b;

	input = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else if (argc > 2)
		input = &argv[1];
	if (validate_input(input) == 1 || *input == NULL || input == NULL)
		error_and_free(argc, input, "Error");
	a = init_nodes(argc, input);
	b = NULL;
	if (argc == 2)
		free_all(input);
	sort_nodes(&a, &b);
	// t_stack *temp = a;
	// while (1)
	// {
	// 	ft_printf("a->value=%d ", (a)->value);
	// 	ft_printf("a->pos=%d ", (a)->pos);
	// 	ft_printf("a->index=%d\n", (a)->index);
	// 	a = (a)->next;
	// 	if (temp == a)
	// 		break;
	// }
	// print_nodes(a, 'a');
	// print_nodes(b, 'b');
	free_stack(a);
	return (0);
}
