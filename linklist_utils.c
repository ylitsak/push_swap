/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:11:58 by saylital          #+#    #+#             */
/*   Updated: 2024/10/23 17:17:14 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes(t_stack *a)
{
	t_stack	*temp;
	int		count;

	temp = a;
	count = 0;
	while (1)
	{
		count++;
		temp = temp->next;
		if (temp == a)
			break ;
	}
	return (count);
}

int	check_if_sorted(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	if (!a)
		return (1);
	if (a->next == a)
		return (0);
	while (temp->next != a)
	{
		if (temp->value > temp->next->value)
		{
			return (1);
		}
		temp = temp->next;
	}
	return (0);
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

static void	list_add_back(t_stack *head, int argc, char **input, int i)
{
	t_stack	*new_node;
	t_stack	*tail;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		free_stack(head);
		error_and_free(argc, input, NULL);
	}
	new_node->value = ft_atoi(input[i]);
	tail = head->prev;
	tail->next = new_node;
	new_node->prev = tail;
	new_node->next = head;
	head->prev = new_node;
}

t_stack	*init_nodes(int argc, char **input)
{
	t_stack	*head;
	int		i;

	i = 1;
	head = NULL;
	head = new_head(head, argc, input);
	while (input[i])
	{
		list_add_back(head, argc, input, i);
		i++;
	}
	return (head);
}
