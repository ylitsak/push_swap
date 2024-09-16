/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:13:31 by saylital          #+#    #+#             */
/*   Updated: 2024/09/16 21:05:14 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//validate_input.c
int		validate_input(char **input);
//linklist_utils.c
t_stack	*init_nodes(int argc, char **input);
int		count_nodes(t_stack *a);
//error_handling.,c
void	free_all(char **free_data);
void	free_stack(t_stack *head);
void	error_and_free(int argc, char **input, char *msg);
//utility_funcs.c
long	ft_atoi_long(char *str);

#endif