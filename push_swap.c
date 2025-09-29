/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:56:15 by hnogi             #+#    #+#             */
/*   Updated: 2025/09/27 21:42:09 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_arguments(int ac, char **av, t_stack *a)
{
	int		i;
	int		*values;
	long	num;

	values = malloc(sizeof(int) * (ac - 1));
	if (!values)
		return (0);
	i = ac - 1;
	while (i >= 1)
	{
		num = ft_atoi(av[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(values);
			return (0);
		}
		i = 0;
		while (i < ac - 1)
			push_node(a, values[i]);
		i++;
	}
	free(values);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		error_exit(a, b);
	if (!parse_arguments(ac, av, a))
		error_exit(a, b);
	if (!is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	rank_elements(a);
	if (a->size <= 5)
		sort_small(a, b);
	else
		radix_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
