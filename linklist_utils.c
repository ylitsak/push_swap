/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:11:58 by saylital          #+#    #+#             */
/*   Updated: 2024/09/16 13:22:12 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_head(t_stack *head, int argc, char **input)
{
	head = (t_stack *)malloc(sizeof(t_stack));
	if (head == NULL)
		error_and_free(argc, input, NULL);
	head->value = ft_atoi(input[0]);
	head->next = NULL;
	head->prev = NULL;
	return (head);
}
void list_add_back(t_stack **current, int argc, char **input)
{
	t_stack *new_node;
	int i;

	new_node = NULL;
	if (argc == 2)
	{
		i = 1;
		while (input[i] != NULL)
		{
			new_node = (t_stack *)malloc(sizeof(t_stack));
			if (new_node == NULL)
				error_and_free(argc, input, NULL);
			new_node->value = ft_atoi(input[i]);
			new_node->next = NULL;
			new_node->prev = *current;
			(*current)->next = new_node;
			*current = new_node;
			i++;
		}
	}
	else if (argc > 2)
	{
		i = 1;
		while (i < argc - 1)
		{
			new_node = (t_stack *)malloc(sizeof(t_stack));
			if (new_node == NULL)
				error_and_free(argc, input, NULL);
			new_node->value = ft_atoi(input[i]);
			new_node->next = NULL;
			new_node->prev = *current;
			(*current)->next = new_node;
			*current = new_node;
			i++;
		}
	}
}
