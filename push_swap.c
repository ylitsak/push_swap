/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:34:23 by saylital          #+#    #+#             */
/*   Updated: 2024/10/23 17:16:50 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoinps(char const *s1, char const *s2)
{
	size_t	stringsize1;
	size_t	stringsize2;
	size_t	i;
	size_t	j;
	char	*ptr;

	stringsize1 = ft_strlen(s1);
	stringsize2 = ft_strlen(s2);
	i = 0;
	j = 0;
	ptr = malloc((stringsize1 + stringsize2 + 2) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = ' ';
	i++;
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

static void	sort_nodes(t_stack **a, t_stack **b, int count)
{
	int	*arr;

	if (check_if_sorted(*a) == 0)
		return ;
	if (count == 2)
	{
		sa(a, 1);
		return ;
	}
	if (count == 3)
	{
		sort_three(a);
		return ;
	}
	arr = make_array(count, *a);
	sort_array(arr, count);
	add_node_position(*a, arr, count);
	free(arr);
	// t_stack *temp = *a;
	// while (1)
	// {
	// 	ft_printf("%d\n", temp->value);
	// 	temp = temp->next;
	// 	if (temp == *a)
	// 		break ;
	// }
	if (count <= 50)
	{
		sort_small(a, b, count);
		return ;
	}
	radix_sort(a, b, count);
	return ;
}

char *string_join_args(int argc, char **argv)
{
	int	i;
	char *temp;
	char *res;

	i = 3;
	temp = ft_strjoinps(argv[1], argv[2]);
	while (i < argc)
	{
		res = ft_strjoinps(temp, argv[i]);
		free(temp);
		temp = res;
		i++;
	}
	return (temp);
}

int	main(int argc, char *argv[])
{
	char	**input;
	char	*join;
	t_stack	*a;
	t_stack	*b;
	int		count;

	if (argc == 1)
		return (0);
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		join = string_join_args(argc, argv);
		input = ft_split(join, ' ');
		free(join);
	}
	if (validate_input(input) == 1 || *input == NULL || input == NULL)
		error_and_free(argc, input, "Error");
	a = init_nodes(argc, input);
	b = NULL;
	free_all(input);
	count = count_nodes(a);
	sort_nodes(&a, &b, count);
	free_stack(a);
	return (0);
}
