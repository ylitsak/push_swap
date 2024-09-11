/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:29:45 by saylital          #+#    #+#             */
/*   Updated: 2024/09/11 20:16:41 by saylital         ###   ########.fr       */
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
