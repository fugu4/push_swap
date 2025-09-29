/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:08:34 by hnogi             #+#    #+#             */
/*   Updated: 2025/09/27 21:42:17 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	get_rank(int value, int *sorted, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	copy_values_to_arrays(t_stack *stack, int *values, int *sorted)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current)
	{
		values[i] = current->value;
		sorted[i] = current->value;
		current = current->next;
		i++;
	}
}

static void	assign_ranks(t_stack *stack, int *values, int *sorted)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current)
	{
		current->rank = get_rank(values[i], sorted, stack->size);
		current = current->next;
		i++;
	}
}

void	rank_elements(t_stack *stack)
{
	int	*values;
	int	*sorted;

	values = malloc(sizeof(int) * stack->size);
	sorted = malloc(sizeof(int) * stack->size);
	if (!values || !sorted)
	{
		if (values)
			free(values);
		if (sorted)
			free(sorted);
		return ;
	}
	copy_values_to_arrays(stack, values, sorted);
	bubble_sort(sorted, stack->size);
	assign_ranks(stack, values, sorted);
	free(values);
	free(sorted);
}
