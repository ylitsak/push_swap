/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:11:58 by saylital          #+#    #+#             */
/*   Updated: 2024/09/18 18:42:59 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes(t_stack *a)
{
	t_stack	*temp;
	int		count;

	temp = a;
	count = 0;
	while (temp != NULL)
	{
		ft_printf("adress prev %p, adress of value %p - {%d}, adress next: %p\n", temp->prev, &temp->value, temp->value, temp->next);

		temp = temp->next;
		count++;
	}
	return (count);
}

static t_stack	*new_head(t_stack *head, int argc, char **input)
{
	head = (t_stack *)malloc(sizeof(t_stack));
	if (head == NULL)
		error_and_free(argc, input, NULL);
	head->value = ft_atoi(input[0]);
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

static void	list_add_back(t_stack **current, int argc, char **input)
{
	t_stack	*new_node;
	int		i;

	new_node = NULL;
	i = 1;
	while (input[i])
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

t_stack	*init_nodes(int argc, char **input)
{
	t_stack	*head;
	t_stack	*current;

	head = NULL;
	head = new_head(head, argc, input);
	current = head;
	list_add_back(&current, argc, input);
	return (head);
}
