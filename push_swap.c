/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:34:23 by saylital          #+#    #+#             */
/*   Updated: 2024/09/16 13:20:28 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stack(int argc, char **input)
{
	t_stack *head;
	t_stack *current;

	head = NULL;
	head = new_head(head, argc, input);
	current = head;
	list_add_back(&current, argc, input);
	return (head);
}

int	main(int argc, char *argv[])
{
	char	**input;
	t_stack *a;
	t_stack *b;

	input = NULL;
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else if (argc > 2)
		input = &argv[1];
	if (validate_input(input) == -1 || argc == 1
		|| *input == NULL || input == NULL)
		error_and_free(argc, input, "Error");
	 a = init_stack(argc, input);
	 if(argc == 2)
	 	free_all(input);
	 b = a;
	 while (b != NULL)
	 {
		ft_printf("%d\n", b->value);
		b = b->next;
	 }
	 free_stack(a);
	return (0);
}
