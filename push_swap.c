/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:34:23 by saylital          #+#    #+#             */
/*   Updated: 2024/10/24 12:38:36 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoinps(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*ptr;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	ptr = malloc((len + 2) * sizeof(char));
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
	if (count <= 50)
	{
		sort_small(a, b, count);
		return ;
	}
	radix_sort(a, b, count);
	return ;
}

int	is_empty(char *input)
{
	int	i;

	i = 0;
	while (input[i] == ' ')
	{
		i++;
	}
	if (input[i] == '\0')
		return (1);
	return (0);
}

char	*string_join_args(int argc, char **argv)
{
	int		i;
	char	*temp;
	char	*result;

	i = 3;
	if (is_empty(argv[1]) == 1 || is_empty(argv[2]) == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	temp = ft_strjoinps(argv[1], argv[2]);
	if (temp == NULL)
	{
		ft_putendl_fd("Malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (is_empty(argv[i]) == 1)
		{
			free(temp);
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
		result = ft_strjoinps(temp, argv[i]);
		free(temp);
		if (result == NULL)
		{
			ft_putendl_fd("Malloc failed", 2);
			exit(EXIT_FAILURE);
		}
		temp = result;
		i++;
	}
	return (temp);
}

char	**get_input(int argc, char *argv[])
{
	char	**input;
	char	*join;

	input = NULL;
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (input == NULL)
		{
			ft_putendl_fd("Malloc failed", 2);
			exit(EXIT_FAILURE);		
		}
	}
	else if (argc > 2)
	{
		join = string_join_args(argc, argv);
		input = ft_split(join, ' ');
		free(join);
		if (input == NULL)
		{
			ft_putendl_fd("Malloc failed", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}

int	main(int argc, char *argv[])
{
	char	**input;
	t_stack	*a;
	t_stack	*b;
	int		count;

	if (argc == 1)
		return (0);
	input = get_input(argc, argv);
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
