/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:11:58 by saylital          #+#    #+#             */
/*   Updated: 2024/09/23 12:37:04 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes(t_stack *a)
{
	t_stack	*temp;
	int		count;

	temp = a;
	count = 1;
	while (temp->next != a)
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
	head->next = head;
	head->prev = head;
	return (head);
}

static void	list_add_back(t_stack **current, int argc, char **input, int i)
{
	t_stack	*new_node;
	t_stack	*head;

	new_node = NULL;
	head = (*current);
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		error_and_free(argc, input, NULL);
	new_node->value = ft_atoi(input[i]);
	while ((*current)->next != head)
	{
		(*current) = (*current)->next;
	}
	(*current)->next = new_node;
	new_node->next = head;
	new_node->prev = *current;
	head->prev = new_node;
}

t_stack	*init_nodes(int argc, char **input)
{
	t_stack	*head;
	t_stack	*current;
	int	i;

	i = 1;
	head = NULL;
	head = new_head(head, argc, input);
	while (input[i])
	{
		list_add_back(&head, argc, input, i);
		i++;
	}
	return (head);
}
