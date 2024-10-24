/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:48:52 by saylital          #+#    #+#             */
/*   Updated: 2024/10/24 14:28:42 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strjoinps(char const *s1, char const *s2)
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

static int	is_empty(char *input)
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

static char	*string_join_args(int argc, char **argv)
{
	int		i;
	char	*temp;
	char	*result;

	i = 3;
	if (is_empty(argv[1]) == 1 || is_empty(argv[2]) == 1)
		print_error(NULL, "Error");
	temp = ft_strjoinps(argv[1], argv[2]);
	if (temp == NULL)
		print_error(NULL, "Malloc failed");
	while (i < argc)
	{
		if (is_empty(argv[i]) == 1)
			print_error(temp, "Error");
		result = ft_strjoinps(temp, argv[i]);
		if (result == NULL)
			print_error(temp, "Malloc failed");
		free(temp);
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
			print_error(NULL, "Malloc failed");
	}
	else if (argc > 2)
	{
		join = string_join_args(argc, argv);
		input = ft_split(join, ' ');
		if (input == NULL)
			print_error(join, "Malloc failed");
		free(join);
	}
	return (input);
}
