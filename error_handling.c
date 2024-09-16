/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:29:45 by saylital          #+#    #+#             */
/*   Updated: 2024/09/16 21:05:30 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **free_data)
{
	int	i;

	i = 0;
	if (free_data == NULL)
		return ;
	if (*free_data == NULL)
		return ;
	while (free_data[i])
	{
		free(free_data[i]);
		i++;
	}
	free(free_data);
}

void	free_stack(t_stack *head)
{
	t_stack	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	error_and_free(int argc, char **input, char *msg)
{
	if (msg != NULL)
		ft_putendl_fd(msg, 2);
	if (argc == 2)
		free_all(input);
	exit(EXIT_FAILURE);
}
